#include <stdio.h>

int main()
{
	int x, y;
	float v;
	float z = 0;
	do
	{
		printf("Rank of the Harmonic serie?\n");
		if(scanf("%d", &x) == 1)
		{
			printf("1\n");
		}
		else
		{
			printf("Input error\n");
			return -1;	
		}		
	}while(x<=0);	
	
	for(y=1; y<x; y++)
	{
		printf("1/%d + ", y);
	}
	if(y=x)
	{
		printf("1/%d = ", x);
	}
	for(v=1; v<=x; v++)
	{
		z = z + 1/v;
	}
	printf("%f\n", z);			
		
	return 0;
}	
