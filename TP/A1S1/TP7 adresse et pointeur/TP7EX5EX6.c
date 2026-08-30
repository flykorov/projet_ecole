#include <stdio.h>

//ex 5

void getMinMax(int size, int iArray[], int *p_min, int *p_max)
{
	int i;
	(*p_min) = iArray[0]; (*p_max) = iArray[0];
	for(i=1; i<size; i++)
	{
		if(iArray[i] < (*p_min))
		{
			(*p_min) = iArray[i];
		}
		else
		{
			if(iArray[i] > (*p_max))
			{
				(*p_max) = iArray[i];
			}
		}
	}
}
					
//ex 6

void swap(int iArray[])
{
	int l;
	l = iArray[2];
	iArray[2] = iArray[7];
	iArray[7] = l;
}
	

int main()
{
	int iArray[10] = {9, 6, 10, 12, 9, 3, 5, 12, -4, 8};
	int min = 0, max = 0;
	int i;
	printf("Min = %d, Max = %d\n", min, max);
	getMinMax(10, iArray, &min, &max);
	printf("Min = %d, Max = %d\n", min, max);
	for(i=0; i<10; i++)
	{
		printf("%d ", iArray[i]);
	}	
	printf("\n");
	swap(iArray);//On échange la valeur de iArray[7] avec iArray[2]
	for(i=0; i<10; i++)
	{
		printf("%d ", iArray[i]);
	}	
	printf("\n");
	return 0;
}
	
