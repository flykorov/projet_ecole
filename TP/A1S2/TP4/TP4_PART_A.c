#include <stdio.h>

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

int PARTITION_LOMUTO(int TAB[], int g, int d)
{
	int x, i, j, y, f;
	x = TAB[d];
	i = g-1;
	for(j=g; j<=d-1; j++)
	{
		if(TAB[j] <= x)
		{
			i = i + 1;
			f = TAB[i];
			TAB[i] = TAB[j];
			TAB[j] = f;
		}
	}
	y = TAB[i+1];
	TAB[i+1] = TAB[d];
	TAB[d] = y;
	return i+1;
}

int PARTITION_LOMUTO_D_G(int TAB[], int g, int d)
{
	int x, i, j, y, f;
	x = TAB[g];
	i = d+1;
	for(j=d; j>g; j--)
	{
		if(TAB[j] > x)
		{
			i = i - 1;
			f = TAB[i];
			TAB[i] = TAB[j];
			TAB[j] = f;
		}
	}
	y = TAB[i-1];
	TAB[i-1] = TAB[g];
	TAB[g] = y;
	return i-1;
}	

int TRI_RAPIDE(int TAB[], int g, int d)
{
	int m;
	if(g < d)
	{
		m = PARTITION_LOMUTO(TAB, g, d);
		TRI_RAPIDE(TAB, g, m-1);
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

// 3) la valeur de retour est 5







	
	
