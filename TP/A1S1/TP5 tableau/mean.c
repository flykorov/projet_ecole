#include<stdio.h>
#include<stdlib.h>

void loadArray(int size, int iArray[])
{
	int i, x;
	printf("Saisir dix integer:\n");
	for(i=0; i<size; i++)
	{
		if(scanf("%d", &x) == 1)
		{
			iArray[i] = x;
		}
		else
		{
			printf("Input error\n");
			exit(-1);
		}
	}	
}

void showArray(int size, int iArray[])
{
	int i;
	for(i=0; i<size; i++)
	{	
		printf("%d ", iArray[i]);
	}
	printf("\n");
}		

double getMean(int size, int iArray[])
{
	int i;
	double z;
	double y = 0;
	for(i=0; i<size; i++)
	{
		y = y + iArray[i];
	}
	z = y/size;
	return z;
}		
		
int main()
{
	double z;
	int iArray[10];
	loadArray(10, iArray);
	showArray(10, iArray);
	z = getMean(10, iArray);
	printf("The mean of the elements equals: %lf\n", z);
	return 0;
}	



