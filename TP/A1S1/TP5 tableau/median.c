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

void swap(int iArray[], int index1, int index2)
{
	int x;
	x = iArray[index1];
	iArray[index1] = iArray[index2];
	iArray[index2] = x;
}	

void bubbleSort(int size, int iArray[])
{
	int i, x, estTrie;
	do
	{
		estTrie = 1;
		for(i=0; i<=9; i++)
		{
			if (iArray[i] > iArray[i+1])
			{
				x = iArray[i];
				iArray[i] = iArray[i+1];
				iArray[i+1] = x;
				estTrie = 0;
			}
		}					
	}while (estTrie == 0);

}	

int getMedian(int size, int iArray[])
{
	int i;
	int u;
	u = size / 2 + 1;
	printf("%d\n", iArray[u]);
}	
	
int main()
{
	int iArray[10];
	loadArray(10, iArray);
	showArray(10, iArray);
	swap(iArray, 6, 3);
	showArray(10, iArray);
	bubbleSort(10, iArray);
	showArray(10, iArray);
	getMedian(10, iArray);
	return 0;
}	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
