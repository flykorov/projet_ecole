#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "struct.h"

//affichage

void affiche_sequence_codee(int** bin, int nb_char)
{
	printf("\naffichage de la sequence codee\n\n");
	int i, j;
	for(i=0; i<nb_char; i++)
	{
		for(j=0; j<9; j++)
		{
			if(bin[i][j] != -1)
				printf("%d ", bin[i][j]);
		}
		printf("\n");
	}
}

void affiche_poids_min(struct init_poids_min* ouaient)
{
	printf("\naffichage du poids min\n\n");
	int i;
	struct poids_min* poids = ouaient->debut;
	while(poids->suivant != NULL)
	{
		printf("%2d = ", poids->id);
		for(i=0; i<poids->nb_con; i++)
		{
			printf("%2d : %5.2f ", poids->connexion[i], poids->distance[i]);
		}
		printf("\n");
		poids = poids->suivant;
	}
}

void affiche_poids(float** poids, int nbl, int nbc)
{
	printf("\naffichage de la matrice de poids\n\n");
	int i, j;
	for(i=0; i<nbl; i++)
	{
		for(j=0; j<nbc; j++)
		{
			printf("%5.2f ", poids[i][j]);
		}
		printf("\n");
	}
}


void affiche_lettre(struct arbre* mec)
{
	if(mec->lewo != NULL)
		printf("gauche : %d\n", mec->lewo->num);
	if(mec->prawo != NULL)
		printf("droit : %d\n", mec->prawo->num);
}

void affiche_mec(struct arbre* mec)
{
	if(mec->gauche != NULL)
	{
		printf("gauche\n");
		affiche_mec(mec->gauche);
	}
	affiche_lettre(mec);
	if(mec->droit != NULL)
	{
		printf("droit\n");
		affiche_mec(mec->droit);
	}
}

void affiche_arbre(struct init_comp* pourquoi)
{
	printf("\naffichage de l'arbre\n\n");
	struct compression* comp = pourquoi->debut;
	struct arbre* mec = comp->debut;
	printf("occ : %d\n", comp->occ);
	affiche_mec(mec);
}

void affiche_distance(struct prems* lacrimatica)
{
	printf("\naffichage distance\n\n");
	struct cartographie* carto = lacrimatica->debut;
	int i, j=0;
	while(carto != NULL)
	{
		j++;
		printf("%2d = ", j);
		for(i=0; i<carto->nb_con; i++)
		{
			printf("%2d : %.2f, ", carto->connexion[i], carto->distance[i]);
		}
		printf("\n");
		carto = carto->suivant;
	}
}

void affiche_carte(int** carte, struct donne* donner)
{
	printf("\naffichage carte\n\n");
	int i, j;
	for(i=0; i<donner->ligne_carte; i++)
	{
		for(j=0; j<donner->colonne_carte; j++)
		{
			printf("%d ", carte[i][j]);
		}
		printf("\n");
	}
}

void affiche_coor(struct prems* lacrimatica)
{
	printf("\naffichage coordonées\n\n");
	struct cartographie* carto = lacrimatica->debut;
	int i=1;
	while(carto != NULL)
	{
		printf("%d : x=%d y=%d\n", i, carto->x, carto->y);
		i++;
		carto = carto->suivant;
	}
}

void affiche_dico(int** dico, int nb_char)
{
	printf("\naffichage du dico\n\n");
	int i, j;
	for(i=0; i<nb_char; i++)
	{
		for(j=0; j<2; j++)
		{
			printf("%d ", dico[i][j]);
		}
		printf("\n");
	}
}

void affiche_comp(struct init_comp* pourquoi)
{
	printf("\naffichage de pourquoi\n\n");
	struct compression* comp = pourquoi->debut;
	while(comp != NULL)
	{
		printf("num %d occ %d\n", comp->ouais->num, comp->occ);
		comp = comp->suivant;
	}
}

void affiche_tri_poids(int** pdf, float* con_depart)
{
	printf("\naffichage du poids trier\n\n");
	int i;
	for(i=0; i<70; i++)
	{
		printf("%f\n", con_depart[i]);
	}
	printf("affichage des coor du poids trier\n\n");
	for(i=0; i<70; i++)
	{
		printf("%d %d\n", pdf[i][0], pdf[i][1]);
	}
}

void affiche_new_tri_poids(int** con_mil, float* dis_mil)
{
	printf("\naffichage du poids trier\n\n");
	int i;
	for(i=0; i<35; i++)
	{
		printf("%f\n", dis_mil[i]);
	}
	printf("affichage des coor du poids trier\n\n");
	for(i=0; i<35; i++)
	{
		printf("%d %d\n", con_mil[i][0]+1, con_mil[i][1]+1);
	}
}

void affiche_rep_poids_min(float* dis_fin, int** con_final)
{
	printf("\naffichage du poids min\n\n");
	int i;
	for(i=0; i<16; i++)
	{
		printf("%d %d : %f\n", con_final[i][0]+1, con_final[i][1]+1 , dis_fin[i]);
	}
}