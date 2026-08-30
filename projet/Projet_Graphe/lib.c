#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "struct.h"

//liberation de toute les allocations

void lib_lettre(struct arbre* mec)
{
	if(mec->lewo != NULL)
		free(mec->lewo);
	if(mec->prawo != NULL)
		free(mec->prawo);
}

void lib_mec(struct arbre* mec)
{
	if(mec->gauche != NULL)
	{
		lib_mec(mec->gauche);
	}
	if(mec->droit != NULL)
	{
		lib_mec(mec->droit);
	}
	lib_lettre(mec);
	free(mec);
}

void lib_pourquoi(struct init_comp* pourquoi)
{
	struct compression* sup;
	while(pourquoi->debut != NULL)
	{
		sup = pourquoi->debut;
		pourquoi->debut = pourquoi->debut->suivant;
		if(sup->ouais != NULL)
			free(sup->ouais);
		if(sup->debut != NULL)
			lib_mec(sup->debut);
		free(sup);
	}
	free(pourquoi);
}

void lib_struct(struct prems* lacrimatica)
{
	struct cartographie* sup;
	while(lacrimatica->debut != NULL)
	{
		sup = lacrimatica->debut;
		lacrimatica->debut = lacrimatica->debut->suivant;
		free(sup->nom);
		free(sup->connexion);
		free(sup->distance);
		free(sup);
	}
	free(lacrimatica);
}

void lib_poids_min(struct init_poids_min* str_poids_min)
{
	struct poids_min* sup;
	while(str_poids_min->debut != NULL)
	{
		sup = str_poids_min->debut;
		str_poids_min->debut = str_poids_min->debut->suivant;
		free(sup->connexion);
		free(sup->distance);
		free(sup);
	}
	free(str_poids_min);
}


void lib_tab(int* tab)
{
	free(tab);
}

void liber_mat(int** mat, int nbl)
{
	int i;
	for(i=0; i<nbl; i++)
	{
		free(mat[i]);
		mat[i] = NULL;
	}
	free(mat);
	mat = NULL;
}

void liber_mat_float(float** mat, int nbl)
{
	int i;
	for(i=0; i<nbl; i++)
	{
		free(mat[i]);
		mat[i] = NULL;
	}
	free(mat);
	mat = NULL;
}

void liber_mat_char(char** mat, int nbl)
{
	int i;
	for(i=0; i<nbl; i++)
	{
		free(mat[i]);
		mat[i] = NULL;
	}
	free(mat);
	mat = NULL;
}

void lib_mat(int** mat, struct donne* donner)
{
	int i;
	for(i=0; i<donner->ligne_carte; i++)
	{
		free(mat[i]);
		mat[i] = NULL;
	}
	free(mat);
	mat = NULL;
}
