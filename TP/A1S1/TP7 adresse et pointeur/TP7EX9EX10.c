#include <stdio.h>

//ex 9

void getMean(int size, int iArray[])
{
}		

void getMinMax(int size, int iArray[], int *p_min, int *p_max)
{
}

int getMode(int size, int iArray[])
{
}

int getMedian(int size, int iArray[])
{
}

int getMinModeMedian(int size, int iArray[], int *p_min, int *p_max)
{
}

//ex 10

void getMinMaxIndex(int size, int iArray[], int *p_min, int *p_max)
{
	int i, m, n;
	(*p_min) = iArray[0]; (*p_max) = iArray[0];
	for(i=1; i<size; i++)
	{
		if(iArray[i] < (*p_min))
		{
			(*p_min) = iArray[i];
			m = i;
		}
		else
		{
			if(iArray[i] > (*p_max))
			{
				(*p_max) = iArray[i];
				n = i;
			}
		}
	}
	printf("Index of min is: %d\n", m);
	printf("Index of max is: %d\n", n);
}

int getFirstIndexOfValue(int size, int iArray[], int value, int *p_index)
{
	int i;
	(*p_index) = value;
	for(i=0; i<size; i++)
	{
		if(iArray[i] == (*p_index))
		{
			(*p_index) = i;
			
		
			break;		
		}
		
	}
	if((*p_index) == i)
	{
		printf("1\n");
	}else
	{
		printf("0\n");
	}			
	
}

int main()
{
	int iArray[10] = {9, 6, 10, 12, 9, 3, 5, 12, -4, 8};
	int min = 0, max = 0;
	int value;
	getMinMaxIndex(10, iArray, &min, &max);
	printf("saisir une valeur:\n");
	if(scanf("%d", &value) == 1)
		{
		}
		else
		{
			printf("Input error\n");
			return -1;	
		}
	getFirstIndexOfValue(10, iArray, value, &value);
	printf("%d\n", value);//Si la fonction retourne 1 alors value = i, si la fonction retourne 0, alors value = value
	return 0;
}	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
