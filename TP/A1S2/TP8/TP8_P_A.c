#include <stdio.h>
#include <stdlib.h>

int* ALLOCATION_TAB_DYN(int n)
{
	int* TAB;
	TAB = malloc(n * sizeof(int));
	return TAB;
}

void CHARGEMENT_TAB(int n, int* TAB)
{
	int i;
	for(i=0; i<n; i++)
	{
		scanf("%d", &*(TAB+i));
	}
}		

void AFFICHAGE_TAB(int n, int* TAB)
{
	int i;
	for(i=0; i<n; i++)
	{
		printf("%d ", *(TAB+i));
	}
	printf("\n");
	free(TAB);
	TAB = NULL;
}		

int main()
{
	int n;
	int* TAB;
	scanf("%d", &n);
	TAB = ALLOCATION_TAB_DYN(n);
	CHARGEMENT_TAB(n, TAB);
	AFFICHAGE_TAB(n, TAB);
	return 0;
}
