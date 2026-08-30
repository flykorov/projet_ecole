#include <stdio.h>
#include <stdlib.h>

int** ALLOCATION_MAT_DYN(int nb_l, int nb_c)
{
	int i;
	int** MAT;
	MAT = malloc(nb_l * sizeof(int*));
	for(i=0; i<nb_l; i++)
	{
		*(MAT+i) = malloc(nb_c * sizeof(int));	
	}
	return MAT;
}

void CHARGEMENT_MAT(int nb_l, int nb_c, int** MAT)
{
	int i, j;
	for(i=0; i<nb_l; i++)
	{
		for(j=0; j<nb_c; j++)
		{
			scanf("%d", &MAT[i][j]);		
		}
	}
}

void AFFICHAGE_MAT(int nb_l, int nb_c, int** MAT)
{
	int i, j;
	for(i=0; i<nb_l; i++)
	{
		for(j=0; j<nb_c; j++)
		{
			printf("%d ", MAT[i][j]);
		}
		printf("\n");
	}
}	

void LIB_MAT(int nb_l, int** MAT)
{
	int i;
	for(i=0; i<nb_l; i++)
	{
		free(MAT[i]);
		MAT[i] = NULL;
	}
	free(MAT);
	MAT = NULL;	
}

int main()
{
	int nb_l, nb_c;
	int** MAT;
	scanf("%d", &nb_l);
	scanf("%d", &nb_c);
	MAT = ALLOCATION_MAT_DYN(nb_l, nb_c);
	CHARGEMENT_MAT(nb_l, nb_c, MAT);
	AFFICHAGE_MAT(nb_l, nb_c, MAT);
	LIB_MAT(nb_l, MAT);
	return 0;
}	

