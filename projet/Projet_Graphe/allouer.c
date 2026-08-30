#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "struct.h"

//allocation

int** alloue_mat(struct donne* donner)
{
	int i;
	int** mat;
	mat = malloc(donner->ligne_carte * sizeof(int*));
	for(i=0; i<donner->ligne_carte; i++)
	{
		mat[i] = malloc(donner->colonne_carte * sizeof(int));
	}
	return mat;
}

int** allouer_mat(int nbl, int nbc)
{
	int i;
	int** mat;
	mat = malloc(nbl * sizeof(int*));
	for(i=0; i<nbl; i++)
	{
		mat[i] = malloc(nbc * sizeof(int));
	}
	return mat;
}

float** allouer_mat_float(int nbl, int nbc)
{
	int i;
	float** mat;
	mat = malloc(nbl * sizeof(float*));
	for(i=0; i<nbl; i++)
	{
		mat[i] = malloc(nbc * sizeof(float));
	}
	return mat;
}

char** allouer_mat_char(int nbl, int nbc)
{
	int i;
	char** mat;
	mat = malloc(nbl * sizeof(char*));
	for(i=0; i<nbl; i++)
	{
		mat[i] = malloc(nbc * sizeof(char));
	}
	return mat;
}

int* allouer_tab(int nb)
{
	int* tab;
	tab = malloc(nb * sizeof(int));
	return tab;
}

void mat_neg1(int** mat, int nbl, int nbc)
{
	int i, j;
	for(i=0; i<nbl; i++)
		for(j=0; j<nbc; j++)
			mat[i][j] = -1;
}

struct prems* alloue_struct(struct prems* lacrimatica, struct donne* donner)
{
	FILE* fic = fopen("lien_ville.txt", "r");
	int nb_char, i, j;
	if(fic == NULL)
	{
		printf("erreur ouverture fichier lien_ville.txt\n");
		exit(EXIT_FAILURE);
	}
	for(i=0; i<donner->nb_ville; i++)
	{
		struct cartographie* carto = malloc(sizeof(struct cartographie));
		fscanf(fic, "%d\n%d\n", &carto->id, &nb_char);
		carto->x = 0;
		carto->y = 0;
		// printf("%d %d\n", carto->id, nb_char);
		carto->nom = malloc((nb_char+1) * sizeof(char));
		fscanf(fic, "%s\n%d\n", carto->nom, &carto->nb_con);
		carto->marque = 0;
		// printf("%d\n", carto->nb_con);
		carto->connexion = malloc(carto->nb_con * sizeof(int));
		carto->distance = malloc(carto->nb_con * sizeof(float));
		for(j=0; j<carto->nb_con; j++)
		{
			fscanf(fic, "%d ", &carto->connexion[j]);
		}
		fscanf(fic, "\n\n");
		carto->suivant = lacrimatica->debut;
		lacrimatica->debut = carto;
	}
	fclose(fic);
	// printf("a\n");
	return lacrimatica;
}

struct prems* creer_prems(struct donne* donner)
{
	struct prems* lacrimatica = malloc(sizeof(struct prems));
	lacrimatica->debut = NULL;
	lacrimatica = alloue_struct(lacrimatica, donner);
	return lacrimatica;
}

struct init_comp* alloue_comp(struct init_comp* pourquoi, int** dico_tri, int nb_char)
{
	int i;
	for(i=0; i<nb_char; i++)
	{
		struct compression* comp = malloc(sizeof(struct compression));
		struct lettre* poete = malloc(sizeof(struct lettre));
		poete->num = dico_tri[i][0];
		comp->ouais = poete;
		comp->occ = dico_tri[i][1];
		comp->debut = NULL;
		comp->suivant = pourquoi->debut;
		pourquoi->debut = comp;
	}
	return pourquoi;
}

struct init_comp* creer_init_comp()
{
	struct init_comp* pourquoi = malloc(sizeof(struct init_comp));
	pourquoi->debut = NULL;
	// pourquoi->depart = NULL;
	return pourquoi;
}

struct init_poids_min* creer_poids_min(struct init_poids_min* str_poids_min, struct donne* donner)
{
	int i;
	for(i=donner->nb_ville; i>0; i--)
	{
		struct poids_min* poids = malloc(sizeof(struct poids_min));
		poids->id = i;
		poids->nb_con = 0;
		poids->marque = 0;
		poids->connexion = malloc(0 * sizeof(int));
		poids->distance = malloc(0 * sizeof(int));
		poids->suivant = str_poids_min->debut;
		str_poids_min->debut = poids;
	}
	return str_poids_min;
}

struct init_poids_min* creer_init_poids_min(struct donne* donner)
{
	struct init_poids_min* str_poids_min = malloc(sizeof(struct init_poids_min));
	str_poids_min->debut = NULL;
	str_poids_min = creer_poids_min(str_poids_min, donner);
	return str_poids_min;
}


void reint_fic_cod(char* s)
{
	FILE* fic = fopen(s, "w");
	fprintf(fic, "1 ");
	fclose(fic);
}

void reint_fic(char* s)
{
	FILE* fic = fopen(s, "w");
	fclose(fic);
}

struct donne* allouer_donne()
{
	struct donne* donner = malloc(sizeof(struct donne));
	// donner->ligne_carte = 0;
	// donner->colonne_carte = 0;
	// donner->taille_carte = 0;
	// donner->nb_ville = 0;
	// donner->nb_connexion = 0;
	// donner->nb_con = 0;
	// donner->con_fin = 0;
	return donner;
}