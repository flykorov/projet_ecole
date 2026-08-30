#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void REMPLISSAGE_TAB(int n, int TAB[])
{
	int i;
	for(i=0; i<n; i++)
	{
		TAB[i] = rand() % 100;
	}
}

void AFFICHAGE_TAB(int n, int TAB[])
{
	int i;
	for(i=0; i<n; i++)
	{
		printf("%d ", TAB[i]);
	}
	printf("\n");
}


int FUSION(int n, int TAB[], int a, int m, int b)
{
	int i, j, k, l;
	int TEMP[b-a+1];
	i = a;
	j = m + 1;
	k = 0;
	while(i <= m && j <= b)
	{
		if(TAB[i] < TAB[j])
		{
			TEMP[k] = TAB[i];
			i = i + 1;
		}else
		{
			TEMP[k] = TAB[j];
			j = j + 1;
		}
		k = k + 1;
	}
	while(i <= m)
	{
		TEMP[k] = TAB[i];
		k = k + 1;
		i = i + 1;
	}
	while(j <= b)
	{
		TEMP[k] = TAB[j];
		k = k + 1;
		j = j + 1;
	}
	k = 0;
	for(i=a; i<=b; i++)
	{
		TAB[i] = TEMP[k];
		k = k + 1;
	}
}
int TRI_FUSION(int n, int TAB[], int a, int b)
{
	int m;
	if(a != b)
	{
		m = (a+b)/2;
		TRI_FUSION(n, TAB, a, m);
		TRI_FUSION(n, TAB, m+1, b);
		FUSION(n, TAB, a, m, b);
	}
}
	
		 	 	
int main()
{
	srand(time(NULL));
	int n;
	scanf("%d", &n);
	int TAB[n];
	int a = 0;
	int b = n - 1;
	REMPLISSAGE_TAB(n, TAB);
	AFFICHAGE_TAB(n, TAB);
	TRI_FUSION(n, TAB, a, b);
	AFFICHAGE_TAB(n, TAB);
}	
	
