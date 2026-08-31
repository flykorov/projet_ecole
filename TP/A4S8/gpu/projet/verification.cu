#include <stdio.h>

__global__ void verfification(int* indice, uint32_t* res, uint32_t* mot)
{
	int i = blockIdx.x * blockDim.x + threadIdx.x;

	for(int j=0; j<8; j++)
	{
		if(mot[j] != res[i+j])
		{
			break;
		}
	}


	if(indice != -1)
	{
		indice = i;
	}
}