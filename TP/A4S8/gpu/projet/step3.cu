#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>


// Rotate bits right
__device__ uint32_t rotr(uint32_t x, uint16_t a)
{
	return (x >> a) | (x << (32 - a));
};

// Shift bits right
__device__ uint32_t shr(uint32_t x, uint16_t b)
{
	return (x >> b);
};

__device__ uint32_t SIG0(uint32_t x)
{
	return (rotr(x, 2) ^ rotr(x, 13) ^ rotr(x, 22));
};

__device__ uint32_t SIG1(uint32_t x)
{
	return (rotr(x, 6) ^ rotr(x, 11) ^ rotr(x, 25));
};

// Choose
__device__ uint32_t Ch(uint32_t x,uint32_t y,uint32_t z)
{
	return ((x & y) ^ (~(x)&z));
};

// Majority decision
__device__ uint32_t Maj(uint32_t x,uint32_t y,uint32_t z)
{
	return ((x & y) ^ (x & z) ^ (y & z));
};

// __global__ void step3(uint32_t *res, uint32_t a, uint32_t b, uint32_t c, uint32_t e, uint32_t f, uint32_t g, uint32_t h, uint32_t K, uint32_t W)
// {
// 	res[0] = h + SIG1(e) + Ch(e,f,g) + K + W;
// 	res[1] = SIG0(a) + Maj(a,b,c);
// }

__global__ void step3(uint32_t *H, uint32_t* K, uint32_t* W)
{

	uint32_t a=H[0], b=H[1], c=H[2], d=H[3], e=H[4], f=H[5], g=H[6], h=H[7];

	for(int i=0; i<64; i++)
	{
		uint32_t T1 = h + SIG1(e) + Ch(e,f,g) + K[i] + W[i];
		uint32_t T2 = SIG0(a) + Maj(a,b,c);
		h = g;
	    g = f;
	    f = e;
	    e = d + T1;
	    d = c;
	    c = b;
	    b = a;
	    a = T1 + T2;
	}

	H[0] = a;
    H[1] = b;
    H[2] = c;
    H[3] = d;
    H[4] = e;
    H[5] = f;
    H[6] = g;
    H[7] = h;
}


void gpu()
{

	uint32_t K[] =
    {
        0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 
        0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
        0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
        0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
        0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
        0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
        0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 
        0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967, 
        0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
        0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
        0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
        0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
        0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
        0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3, 
        0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
        0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
    };

    uint32_t H[8] = {
        0x6a09e667,
        0xbb67ae85,
        0x3c6ef372,
        0xa54ff53a,
        0x510e527f,
        0x9b05688c,
        0x1f83d9ab,
        0x5be0cd19
    };

    uint32_t W[64];

    for(int r=0; r<64; r++)
    {
    	W[r] = rand() & 0xFFFFFFFF; 
    }


	const int nb_thread = 16;
	uint32_t* host_H;
	uint32_t* device_H;

	// uint32_t a=H[0], b=H[1], c=H[2], d=H[3], e=H[4], f=H[5], g=H[6], h=H[7];

	// cpu_result = (uint32_t*)malloc(2 * sizeof(uint32_t));
	// cudaMalloc((void**) &result, 2 * sizeof(uint32_t));

	host_H = (uint32_t*)malloc(8 * sizeof(uint32_t));
	cudaMalloc((void**) &device_H, 8 * sizeof(uint32_t));

	// cpu_result[0] = 0;
	// cpu_result[1] = 0;

	// cudaMemcpy(result, cpu_result, 2 * sizeof(uint32_t), cudaMemcpyHostToDevice);

	for(int r=0; r<8; r++)
	{
		host_H[r] = H[r];
	}

	cudaMemcpy(device_H, host_H, 8 * sizeof(uint32_t), cudaMemcpyHostToDevice);

	dim3 grid(16, 16);
	dim3 block(nb_thread, nb_thread);

	cudaEvent_t eStart, eStop;
 	cudaEventCreate(&eStart);
 	cudaEventCreate(&eStop);

 	// step3<<<grid, block>>>(result, a, b, c, e, f, g, h, K[0], W[0]);


 	step3<<<grid, block>>>(H, K, W);

 	cudaEventCreate(&eStart);
 	step3<<<grid, block>>>(H, K, W);
 	cudaEventCreate(&eStop);

 	cudaMemcpy(device_H, host_H, 8 * sizeof(uint32_t), cudaMemcpyHostToDevice);

	cudaEventSynchronize(eStop);
	float gpuTime;
	cudaEventElapsedTime(&gpuTime, eStart, eStop);

	for(int i=0; i<8; i++)
	{
		printf("%d\n", host_H[i]);
	}

	printf("%f\n", gpuTime);

	free(host_H);
	cudaFree(device_H);
}

int main()
{

	gpu();

}