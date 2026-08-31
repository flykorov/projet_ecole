#include <stdio.h>
#include <fitsio.h>

#define HANDLE_ERROR(call) { \
    cudaError_t err = call; \
    if(err != cudaSuccess) { \
        fprintf(stderr, "CUDA Error: %s\n", cudaGetErrorString(err)); \
        exit(EXIT_FAILURE); \
    } \
}

#define CHECK_FITS_ERROR(status) { \
    if(status) { \
        fits_report_error(stderr, status); \
        exit(EXIT_FAILURE); \
    } \
}

__global__ void calibrateImage(float *raw, float *dark, float *flat, float *calibrated, int width, int height) {
    int idx = blockIdx.x * blockDim.x + threadIdx.x;
    int idy = blockIdx.y * blockDim.y + threadIdx.y;
    int index = idy * width + idx;

    if(idx < width && idy < height) {
        calibrated[index] = (raw[index] - dark[index]) * flat[index];
    }
}

int main() {

	fitsfile *rawFile, *darkFile, *flatFile;
    int status = 0;
    long naxes[2];
    float *rawData, *darkData, *flatData, *calibratedData;

    CCfits::FITS rawFile("wfsFrame.fits", CCfits::Read);
    CCfits::FITS darkFile("darkFrame.fits", CCfits::Read);
    CCfits::FITS flatFile("flatFrame.fits", CCfits::Read);

    CCfits::ExtHDU& rawHDU = rawFile.extension();
    CCfits::ExtHDU& darkHDU = darkFile.extension();
    CCfits::ExtHDU& flatHDU = flatFile.extension();

    size_t dataSize = naxes[0] * naxes[1] * sizeof(float);

	HANDLE_ERROR(cudaMalloc(&calibratedData, dataSize));

    HANDLE_ERROR(cudaMemcpy(calibratedData, rawData, dataSize, cudaMemcpyHostToDevice));

    dim3 blockDim(16, 16);
    dim3 gridDim((naxes[0] + blockDim.x - 1) / blockDim.x, (naxes[1] + blockDim.y - 1) / blockDim.y);

    calibrateImage<<<gridDim, blockDim>>>(rawData, darkData, flatData, calibratedData, naxes[0], naxes[1]);

    HANDLE_ERROR(cudaMemcpy(rawData, calibratedData, dataSize, cudaMemcpyDeviceToHost));

    fitsfile *calibratedFile;
    fits_create_file(&calibratedFile, "calibrated.fits", &status);
    fits_create_img(calibratedFile, TFLOAT, 2, naxes, &status);
    fits_write_img(calibratedFile, TFLOAT, 1, naxes[0] * naxes[1], rawData, &status);

    cudaFree(calibratedData);

    free(rawData);
    free(darkData);
    free(flatData);

    fits_close_file(rawFile, &status);
    fits_close_file(darkFile, &status);
    fits_close_file(flatFile, &status);
    fits_close_file(calibratedFile, &status);

    return 0;
}