#include <stdio.h>

#define TRUE 1

int AFFICHAGE_TAB(int x, int TAB[])
{
	int i;
	for(i=0; i<x; i++)
	{
		printf("%d ", TAB[i]);
	}
	printf("\n");
}

int CREAT_TAB(int x, int TAB[])
{
	int i = 0;
	while (i<x)
  	{
   		scanf("%d", &TAB[i]);
    		i++;
	}
}


int PARTITION_HOARE(int TAB[], int g, int d)
{
	int x, i, j, f;
	x = TAB[g];
	i = g - 1;
	j = d + 1;
	while(TRUE)
	{
		do
		{
			j = j - 1;
		}while(TAB[j] > x);	
		do
		{
			i = i + 1;
		}while(TAB[i] < x);
		if(i < j)
		{
			f = TAB[i];
			TAB[i] = TAB[j];
			TAB[j] = f;
		}else
		{
			return j;
		}
	}
}

int TRI_RAPIDE(int TAB[], int g, int d)
{
	int m, f;
	if(g < d)
	{
		m = PARTITION_HOARE(TAB, g, d);
		TRI_RAPIDE(TAB, g, m);
		TRI_RAPIDE(TAB, m+1, d);
	}
}				
			
int main()
{
	int x;
	scanf("%d", &x);
	int TAB[x];
	int g = 0;
	int d = x - 1;
	CREAT_TAB(x, TAB);
	TRI_RAPIDE(TAB, g, d);
	AFFICHAGE_TAB(x, TAB);
}

// 2) La valeur retourner est 2
			
			
			
			
			
			
			

