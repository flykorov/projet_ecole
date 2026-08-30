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

int getMax(int size, int iArray[])
{
	int i;
	int a = iArray[0];
	for(i=0; i<size; i++)
	{
		if(iArray[i] >= a)
		{
			a = iArray[i];
		}
	}
	printf("Valeur maximale saisie : %d\n", a);
}		

int getMin(int size, int iArray[])
{
	int i;
	int a = iArray[0];
	for(i=0; i<size; i++)
	{
		if(iArray[i] <= a)
		{
			a = iArray[i];
		}
	}
	printf("Valeur minimale saisie : %d\n", a);
}		

int getMaxIndex(int size, int iArray[])
{
	int i, c;
	int a = iArray[0];
	int b = 0;
	for(i=0; i<size; i++)
	{
		c = i;
		if(iArray[i] > a)
		{
			a = iArray[i];
			b = c;
		}
	}
	printf("Indice de la valeur maximale saisie : %d\n", b);
}	

int getMinIndex(int size, int iArray[])
{
	int i, c;
	int b = 0;
	int a = iArray[0];
	for(i=0; i<size; i++)
	{
		c = i;
		if(iArray[i] < a)
		{
			a = iArray[i];
			b = c;
		}
	}
	printf("Indice de la valeur minimale saisie : %d\n", b);
}	

int getMode(int size, int iArray[])
{
	int occurenceArray[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int i, o, j, c;
	int p = 0;
	for(i=0; i<size; i++)
	{
		o = iArray[i];
		occurenceArray[o]++;
	}
	int a = occurenceArray[0];
	int b = 0;
	for(j=0; j<size; j++)
	{
		c = j;
		if(occurenceArray[j] > a)
		{
			a = occurenceArray[j];
			b = c;
		}
	}
	printf("Le mode du tableau est : %d\n", b);
}	
	

int main()
{
	int iArray[10];
	loadArray(10, iArray);
	showArray(10, iArray);
	getMax(10, iArray);
	getMin(10, iArray);
	getMaxIndex(10, iArray);
	getMinIndex(10, iArray);
	getMode(10, iArray);
	return 0;
}

























		
		
		
			





