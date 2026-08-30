#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void init(int* tab, int n)
{
	int a, i;
	for(i=0; i<n; i++)
	{
		a = rand() % 100;
		tab[i] = a;
	}
}

void init_mano(int* tab, int n)
{
	int i;
	printf("entrez %d valeurs pour le tableau\n", n);
	for(i=0; i<n; i++)
	{
		scanf("%d", &tab[i]);
	}
}		

void invert_it(int* tab, int n)
{
	int i, c, d;
	c = n/2;
	n--;
	for(i=0; i<c; i++)
	{
		d = tab[i];
		tab[i] = tab[n];
		tab[n] = d;
		n--;
	}
}

void invert_rec(int* tab, int m, int y)
{
	int c;
	c = tab[m];
	tab[m] = tab[y];
	tab[y] = c;
	if(m > y)
	invert_rec(tab, m-1, y+1);
}

int test_it(int* tab, int* tab_1, int n)
{
	int i, y=0;
	for(i=0; i<n; i++)
	{
		if(tab[i] == tab_1[i])
		{
			y++;
		}else
		{
			y=0;
		}
	}
	if(y == n)
	{
		return 1;
	}else
	{
		return 0;
	}
}

int test_rec(int* tab_1, int* tab_2, int y, int n)
{
	if(y == n)
	{
		return 1;
	}	
	if(tab_1[y] == tab_2[y])
	{
		test_rec(tab_1, tab_2, y+1, n);
	}else
	{
		return 0;
	}
}			

void affiche_tab(int* tab, int n)
{
	int i;
	for(i=0; i<n; i++)
	{
		printf("%d ", tab[i]);
	}
	printf("\n");
}

void lib_mat(int* tab)
{
	free(tab);
	MAT = NULL;	
}				

int main()
{
	srand(time(NULL));
	int n, y=0, m, res_it, res_rec;
	int* tab;
	int* tab_1;
	int* tab_2;
	printf("entrez un entier positif\n");
	scanf("%d", &n);
	m = n-1;
	tab = malloc(n * sizeof(int));
	tab_1 = malloc(n * sizeof(int));
	tab_2 = malloc(n * sizeof(int));
	init(tab, n);
	init_mano(tab_1, n);
	init_mano(tab_2, n);
	printf("tab de base :    ");
	affiche_tab(tab, n);
	invert_it(tab, n);
	printf("tab invert it :  ");
	affiche_tab(tab, n);
	printf("tab invert rec : ");
	invert_rec(tab, m, y);
	affiche_tab(tab, n);
	res_it = test_it(tab_2, tab_1, n);
	if(res_it == 1)
	{
		printf("it : les tableaux sont identiques\n");
	}else
	{
		printf("it : les tableaux ne sont pas identiques\n");
	}
	res_rec = test_rec(tab_1, tab_2, y, n);
	if(res_rec == 1)
	{
		printf("rec : les tableaux sont identiques\n");
	}else
	{
		printf("rec : les tableaux ne sont pas identiques\n");
	}
	lib_tab(tab);
	lib_tab(tab_1);
	lib_tab(tab_2); 
	return 0;		
}		
	
	
