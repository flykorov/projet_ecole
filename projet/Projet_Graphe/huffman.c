#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "struct.h"

struct compression* allouer_arbre(struct compression* comp, struct init_comp* pourquoi)		//creation de l'arbre binaire de huffman
{
	struct arbre* mec = malloc(sizeof(struct arbre));
	struct compression* change = malloc(sizeof(struct compression));
	if(comp->debut == NULL)			//verification pour l'implementation du nouvelle arbre
	{
		mec->lewo = comp->ouais;
		mec->gauche = NULL;
	}else
	{
		mec->lewo = NULL;
		mec->gauche = comp->debut;
	}
	if(comp->suivant->debut == NULL)
	{
		mec->prawo = comp->suivant->ouais;
		mec->droit = NULL;
	}else
	{
		mec->prawo = NULL;
		mec->droit = comp->suivant->debut;
	}
	change->debut = mec;
	change->occ = comp->suivant->occ + comp->occ;
	change->ouais = NULL;
	if(comp->suivant->suivant == NULL)		//lib des structure inutile + verification de l'endroit ou les mettre
	{
		change->suivant = NULL;
		pourquoi->debut = change;
		free(comp->suivant);
		free(comp);
		return pourquoi->debut;
	}
	else
	{
		if(change->occ <= comp->suivant->suivant->occ)
		{
			change->suivant = comp->suivant->suivant;
			pourquoi->debut = change;
			free(comp->suivant);
			free(comp);
			return pourquoi->debut;
		}
		pourquoi->debut = comp->suivant->suivant;
		free(comp->suivant);
		free(comp);
		comp = pourquoi->debut->suivant;
		struct compression* affect = pourquoi->debut;
		while(comp != NULL)
		{
			if(change->occ <= comp->occ)
			{
				change->suivant = comp;
				affect->suivant = change;
				return affect;
			}else
			{
				affect = affect->suivant;
				comp = comp->suivant;
			}
		}
		change->suivant = comp;
		affect->suivant = change;
		return affect;
	}
}

struct init_comp* creer_arbre(struct init_comp* pourquoi)
{
	struct compression* comp = pourquoi->debut;
	// struct compression* bou;
	while(comp->suivant != NULL)
	{
		/*bou = */allouer_arbre(comp, pourquoi);
		comp = pourquoi->debut;
	}
	return pourquoi;
}

int nb_char_dico(char* s)
{
	FILE* fic = fopen(s, "r");
	if(fic == NULL)
	{
		printf("erreur ouverture fichier carte.txt\n");
		exit(EXIT_FAILURE);
	}
	int nb_char=0, chiffre, i;
	bool etat=true;
	int tab[100] = {0};
	while((chiffre = fgetc(fic)) != EOF)
	{
		for(i=0; i<100; i++)
		{
			if(tab[i] == chiffre)
				etat=false;
		}
		if(etat)
		{
			tab[nb_char]=chiffre;
			nb_char++;
		}
		etat=true;
	}
	fclose(fic);
	return nb_char;
}

void init_mat(int** mat, int nbl, int nbc)
{
	int i, j;
	for(i=0; i<nbl; i++)
		for(j=0; j<nbc; j++)
			mat[i][j]=0;
}

void creation_dico(int** dico, int nb_char, char* s)		//vrai triage du dico inutiles cependant
{
	FILE* fic = fopen(s, "r");
	if(fic == NULL)
	{
		printf("erreur ouverture fichier carte.txt\n");
		exit(EXIT_FAILURE);
	}
	init_mat(dico, nb_char, 2);
	int i, chiffre;
	bool etat;
	while((chiffre = fgetc(fic)) != EOF)
	{
		etat=false;
		for(i=0; i<nb_char; i++)
		{
			if(dico[i][0] == chiffre && etat == false)
			{
				etat=true;
				dico[i][1]++;
			}
		}
		if(etat == false)
		{
			for(i=0; i<nb_char; i++)
			{
				if(dico[i][0] == 0 && etat == false)
				{
					dico[i][0] = chiffre;
					dico[i][1]++;
					etat=true;
				}
			}
		}
	}
	fclose(fic);
}

void tri_dico(int** dico, int nb_char)
{
	int tamp, i, j=0;
	bool etat=true;
	while(etat)
	{
		etat=false;
		for(i=j+1; i<nb_char; i++)
		{
			if(dico[j][0] > dico[i][0])
			{
				tamp = dico[j][0];
				dico[j][0] = dico[i][0];
				dico[i][0] = tamp;
				tamp = dico[j][1];
				dico[j][1] = dico[i][1];
				dico[i][1] = tamp;
				etat=true;
			}
		}
		j++;
	}
}

void fake_tri_dico(int** dico_tri, int nb_char)		//tri du dictionaire de maniere a facilite les allocations (pas comme dans le cours)
{
	int tamp, i, j=0;
	bool etat=true;
	while(etat)
	{
		etat=false;
		for(i=j+1; i<nb_char; i++)
		{
			if(dico_tri[j][1] < dico_tri[i][1])
			{
				tamp = dico_tri[j][0];
				dico_tri[j][0] = dico_tri[i][0];
				dico_tri[i][0] = tamp;
				tamp = dico_tri[j][1];
				dico_tri[j][1] = dico_tri[i][1];
				dico_tri[i][1] = tamp;
				etat=true;
			}
		}
		j++;
	}
	etat=true;
	while(etat)
	{
		etat=false;
		j=0;
		i=1;
		while(i<nb_char)
		{
			if(dico_tri[j][1] == dico_tri[i][1] && dico_tri[j][0] > dico_tri[i][0])
			{
				tamp = dico_tri[j][0];
				dico_tri[j][0] = dico_tri[i][0];
				dico_tri[i][0] = tamp;
				tamp = dico_tri[j][1];
				dico_tri[j][1] = dico_tri[i][1];
				dico_tri[i][1] = tamp;
				etat=true;
			}
			i++;
			j++;
		}
	}
}

void ecrire_mec(int nb, struct lettre* poete, char* s)		//ecriture dans le fichier
{
	FILE* fic = fopen(s, "a");
	if(nb == 1)
	{
		fprintf(fic, "1 ");
	}else
	{
		fprintf(fic, "0%d ", poete->num);
	}
	fclose(fic);
}

void cal_mec(struct arbre* mec, char* s)		//ecriture de l'arbre dans un fichier
{
	if(mec->gauche != NULL)
	{
		ecrire_mec(1, mec->lewo, s);
		cal_mec(mec->gauche, s);
	}
	if(mec->lewo != NULL)
		ecrire_mec(0, mec->lewo, s);
	if(mec->droit != NULL)
	{
		ecrire_mec(1, mec->prawo, s);
		cal_mec(mec->droit, s);
	}
	if(mec->prawo != NULL)
		ecrire_mec(0, mec->prawo, s);
}

void arbre_de_codage(struct init_comp* pourquoi, char* s)
{
	struct arbre* mec = pourquoi->debut->debut;
	// struct arbre_codage* troispremierephrase = memepasjaiditdeuxmot->debut;
	cal_mec(mec, s);
}

void ecrire_sequence(int* nb, struct lettre* poete, int i, char* s)		//ecriture dans le fichier
{
	FILE* fic = fopen(s, "a");
	// printf("%d\n", i);
	fprintf(fic, "%d ", poete->num);
	for(int j=0; j<i; j++)
		fprintf(fic, "%d", nb[j]);
	fprintf(fic, "\n");
	fclose(fic);
}

void cal_sequence(struct arbre* mec, int* tab, int i, char* s)			//on ecrit la sequence dans un fichier
{
	if(mec->gauche != NULL)
	{
		tab[i] = 0;
		// ecrire_sequence(0, mec->lewo, 0);
		i++;
		cal_sequence(mec->gauche, tab, i, s);
		i--;
	}
	if(mec->lewo != NULL)
	{
		tab[i] = 0;
		i++;
		ecrire_sequence(tab, mec->lewo, i, s);
		i--;
	}
	if(mec->droit != NULL)
	{
		tab[i] = 1;
		i++;
		// ecrire_sequence(1, mec->prawo, 1);
		cal_sequence(mec->droit, tab, i, s);
		i--;
	}
	if(mec->prawo != NULL)
	{
		tab[i] = 1;
		i++;
		ecrire_sequence(tab, mec->prawo, i, s);
		i--;
	}
}

void sequence_codee(struct init_comp* pourquoi, char* s)
{
	struct arbre* mec = pourquoi->debut->debut;
	int* tab = malloc(100 * sizeof(int));
	cal_sequence(mec, tab, 0, s);
	free(tab);
}

void reception_codee(int** bin, int nb_char, char* s)		//on ecrit la sequence binaire des caracteres dans une matrice
{
	FILE* fic = fopen(s, "r");
	int i, j, chiffre;
	for(i=0; i<nb_char; i++)
	{
		fscanf(fic, "%d \n", &bin[i][0]);
		j=1;
		while((chiffre = fgetc(fic)) != '\n')
		{
			bin[i][j] = chiffre-48;
			j++;
		}
		// printf("%d %d\n", bin[i][0], bin[i][1]);
	}
	fclose(fic);
}

void compression_bin(int** bin, int nb_char, char* s1, char* s2)	//on ecrit le texte en binaire
{
	FILE* fic = fopen(s1, "r");
	FILE* scrib = fopen(s2, "w");
	int chiffre, j, i;
	while((chiffre = fgetc(fic)) != EOF)
	{
		for(i=0; i<nb_char; i++)
		{
			if(chiffre == bin[i][0])
			{
				for(j=1; j<9; j++)
					if(bin[i][j] != -1)
						fprintf(scrib, "%d", bin[i][j]);
			}
		}
		fprintf(scrib, " ");
	}
	fprintf(scrib, "0000");
	fclose(fic);
	fclose(scrib);
}

void fichier_compresser(struct init_comp* pourquoi, char* s1, char* s2, char* s3) //on prend tout les fichiers et les regroupent dans un seul
{
	FILE* scrib = fopen(s1, "w");
	FILE* fic_bin = fopen(s2, "r");
	FILE* fic_arbre = fopen(s3, "r");
	fprintf(scrib, "%d\n", pourquoi->debut->occ);
	int chiffre;
	while((chiffre = fgetc(fic_arbre)) != EOF)
	{
		if(chiffre != ' ')
			fprintf(scrib, "%d", chiffre-48);
	}
	fprintf(scrib, "\n");
	while((chiffre = fgetc(fic_bin)) != EOF)
	{
		if(chiffre != ' ')
			fprintf(scrib, "%d", chiffre-48);
	}
	fprintf(scrib, "\n");
	fclose(scrib);
	fclose(fic_bin);
	fclose(fic_arbre);
}

struct lettre* al_lettre(int i, int** tab)	//fonction inutilisé
{
	int n;
	n = tab[i][0]*10 + tab[i][1];
	struct lettre* poete = malloc(sizeof(struct lettre));
	poete->num = n;
	return poete;
}

struct arbre* al_arbre()	//fonction inutilisé
{
	struct arbre* mec = malloc(sizeof(struct arbre));
	mec->gauche = NULL;
	mec->droit = NULL;
	mec->lewo = NULL;
	mec->prawo = NULL;
	return mec;
}

struct compression* recreer_arbre(int** mat, int** tab)	//fonction inutilisé
{
	int i, k, v, u=0;
	struct arbre* mec;
	struct compression* comp;
	// struct lettre* poete;
	comp = malloc(sizeof(struct compression));
	comp->suivant = NULL;
	comp->ouais = NULL;
	mec = al_arbre();
	comp->debut = mec;
	for(k=0; k<13; k++)
	{
		i=0;
		mec = comp->debut;
		u=0;
		while(u != -1 && i < 8)
		{
			v = mat[k][i];
			// printf("1\n");
			if(v == 0)
			{
				if(mec->gauche != NULL)
					mec = mec->gauche;
				else
				{
					if(i == 7)
					{
						mec->lewo = al_lettre(k, tab);
					}else
					{
						u = mat[k][i+1];
						if(u == -1)
						{
							mec->lewo = al_lettre(k, tab);
						}else
						{
							mec->gauche = al_arbre();
						}
					}
				}
			}
			if(v == 1)
			{
				if(mec->droit != NULL)
				{
					mec = mec->droit;
				}else
				{
					if(i == 7)
					{
						mec->prawo = al_lettre(k, tab);
					}else
					{
						u = mat[k][i+1];
						if(u == -1)
						{
							mec->prawo = al_lettre(k, tab);
						}else
						{
							mec->droit = al_arbre();
						}
					}
				}
			}
			printf("%d\n", u);
			i++;
		}
	}
	return comp;
}

void dechiffre_sequence(int** mat, int** tab, char* s1, char* s2, int nb_char, int bin)
{
	FILE* fic = fopen(s1, "r");
	int i=0, j=0, k, l, f, nb_occ, chiffre;
	for(i=0; i<nb_char; i++)
	{
		for(j=0; j<bin; j++)
		{
			mat[i][j] = -1;				//init à -1 pour facilite la lecture et verification
		}
	}
	i=0;
	j=0;
	fscanf(fic, "%d\n", &nb_occ);
	while((chiffre = fgetc(fic)) != '\n')		//recreation de la sequence binaire de chaque caractere ASCII
	{
		// printf("%d\n", chiffre);
		// printf("%d %d\n", i, j);
		if(chiffre == 49)
		{
			mat[i][j] = 0;					//mat est le sequence binaire du chiffre
			j++;
		}
		if(chiffre == 48)
		{
			// mat[i][j] = 1;
			f = fgetc(fic);
			tab[i][0] = f-48;				//tab est le chiffre pour les ASCII
			f = fgetc(fic);
			tab[i][1] = f-48;
			// i++;
			for(l=0; l<bin; l++)
			{
				if(mat[i][l] == 0)
					k=l;
			}
			i++;
			if(i < nb_char)
			{
				for(l=0; l<k; l++)
					mat[i][l] = mat[i-1][l];
				mat[i][k] = 1;
			}
			j=l+1;
		}
	}
	// printf("%d\n", chiffre);
	// chiffre = fgetc(fic);
	// printf("%d\n", chiffre);
	// printf("bebou\n");
	// for(i=0; i<nb_char; i++)
	// {
	// 	printf("%d%d : ", tab[i][0], tab[i][1]);
	// 	for(j=0; j<bin; j++)
	// 	{
	// 		if(mat[i][j] != -1)
	// 			printf("%d ", mat[i][j]);
	// 	}
	// 	printf("\n");
	// }
	FILE* scrib = fopen(s2, "w");
	// bool etat = false;
	i=0;
	j=0;
	int n;
	int compteur;
	int pouce[nb_char];				//tableau servant à connaitre le caractère
	for(i=0; i<nb_char; i++)
		pouce[i] = 1;
	// fputc(49, scrib);
	l=0;
	// for(i=0; i<nb_char; i++)
	// {
	// 	printf("%d\n", pouce[i]);
	// }
	// printf("%d\n", chiffre);
	while(l < nb_occ)		//decompression du fichier en l'écrivant dans un nouveau
	{
		// printf("1\n");
		compteur = 0;
		// printf("%d\n", compteur);
		chiffre = fgetc(fic);
		// printf("%d %d\n", l, chiffre);
		for(i=0; i<nb_char; i++)
		{
			if(mat[i][j] == chiffre-48 && pouce[i] == 1)
			{
				pouce[i] = 1;			//si = 1 sequence binaire d'un chiffre corect
				compteur++;
			}else
			{
				pouce[i] = 0;			//si = 0 sequence binaire incorect
			}
		}
		j++;
		if(compteur == 1)
		{
			for(i=0; i<nb_char; i++)
			{
				if(pouce[i] == 1)
				{
					k=i;
					pouce[i] = 0;
				}
			}
			n = tab[k][0]*10 + tab[k][1];
			fputc(n, scrib);
			l++;
			j=0;
			for(i=0; i<nb_char; i++)
			{
				pouce[i] = 1;
			}
		}
		// if(compteur == 0)
		// 	etat = false;
	}
	fclose(scrib);
	fclose(fic);
}

