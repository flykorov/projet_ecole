#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "struct.h"

//fonction d'exo 1 a 5

struct prems* ouvre_carte(int** carte, struct prems* lacrimatica, struct donne* donner)
{
	struct cartographie* carto = lacrimatica->debut;
	FILE* fic = fopen("carte.txt", "r");
	if(fic == NULL)
	{
		printf("erreur ouverture fichier carte.txt\n");
		exit(EXIT_FAILURE);
	}
	int chiffre, i=0, j=0, etat=0;
	while((chiffre = fgetc(fic)) != EOF)
	{	
		if(etat == 1 && chiffre < 48)
		{
			carte[i][j]=1;
			carto->x = i;
			carto->y = j;
			carto = carto->suivant;
			j++;
			etat=2;
		}
		if(etat == 1 && chiffre >= 48)
		{
			carte[i][j] = 10 + chiffre-48;
			if(chiffre >= 48)
			{
				carto->x = i;
				carto->y = j;
				carto = carto->suivant;
			}
			j++;
			etat=2;
		}
		if(etat == 0 && chiffre >= 48)
		{
			if(chiffre == 49)
			{
				etat = 1;
			}else
			{
				carte[i][j] = chiffre-48;
				if(chiffre > 48)
				{
					carto->x = i;
					carto->y = j;
					carto = carto->suivant;
				}
				j++;
			}
		}
		if(etat == 2)
			etat=0;
		if(j!=0 && j%donner->colonne_carte == 0)
		{
			j=0;
			i++;
		}
	}
	fclose(fic);
	return lacrimatica;
}

struct prems* distance_ville(struct prems* lacrimatica)
{
	struct cartographie* carto = lacrimatica->debut;
	struct cartographie* morue = lacrimatica->debut;
	int i;
	while(carto != NULL)
	{
		for(i=0; i<carto->nb_con; i++)
		{
			while(morue->id != carto->connexion[i])
			{
				morue = morue->suivant;
			}
			carto->distance[i] = sqrt(pow(morue->x - carto->x, 2) + pow(morue->y - carto->y, 2));
			morue = lacrimatica->debut;

		}
		carto = carto->suivant;
	}
	return lacrimatica;
}


void init_poids(float** poids, struct donne* donner)
{
	int i, j;
	for(i=0; i<donner->nb_ville; i++)
	{
		for(j=0; j<donner->nb_ville; j++)
		{
			if(j==i)
				poids[i][j] = 0;
			else
				poids[i][j] = -1;
		}
	}
}

void matrice_de_poids(struct prems* lacrimatica, float** poids, struct donne* donner)
{
	init_poids(poids, donner);
	struct cartographie* carto = lacrimatica->debut;
	int i, j;
	for(j=0; j<donner->nb_ville; j++)
	{
		for(i=0; i<carto->nb_con; i++)
		{
			poids[j][carto->connexion[i]-1] = carto->distance[i];
			poids[carto->connexion[i]-1][j] = carto->distance[i];
		}
		carto = carto->suivant;
	}
}

void tri_poids(float** poids, int** pdf, float* con_depart, struct donne* donner)
{
	int i, j, k=0, l=0, temp;
	float tflo;
	bool etat=true;
	for(i=0; i<donner->nb_ville; i++)
	{
		for(j=0; j<donner->nb_ville; j++)
		{
			if(poids[i][j] > 0)
			{
				pdf[k][0] = i;
				pdf[k][1] = j;
				con_depart[k] = poids[i][j];
				k++;
			}
		}
	}
	while(etat)
	{
		etat=false;
		for(i=l; i<donner->nb_connexion; i++)
		{
			if(con_depart[l] > con_depart[i])
			{
				tflo = con_depart[l];
				con_depart[l] = con_depart[i];
				con_depart[i] = tflo;
				temp = pdf[l][0];
				pdf[l][0] = pdf[i][0];
				pdf[i][0] = temp;
				temp = pdf[l][1];
				pdf[l][1] = pdf[i][1];
				pdf[i][1] = temp;
				etat=true;
			}
		}
		l++;
	}
}

void sup_case(int** pdf, float* con_depart, struct donne* donner)
{
	int i, j=0;
	float a_sup;
	for(i=0; i<donner->nb_connexion; i++)
	{
		a_sup = con_depart[i];
		j=i+1;
		if(j < donner->nb_connexion)
		{
			while(a_sup == con_depart[j])
			{
				if(pdf[i][0] == pdf[j][1] && pdf[i][1] == pdf[j][0])
				{
					pdf[j][0] = -1;
					pdf[j][1] = -1;
					// con_depart[j] = -1;
				}
				j++;
				if(j >= donner->nb_connexion)
				{
					j--;
					a_sup = -2;
				}
			}
		}
	}
}

int cont_neg(int** pdf, struct donne* donner)
{
	int i, nb=0;
	for(i=0; i<donner->nb_connexion; i++)
	{
		if(pdf[i][0] == -1)
		{
			nb++;
		}
	}
	// printf("\n%d\n", nb);
	return nb;
}

void chang_tab(int** pdf, float* con_depart, int** con_mil, float* dis_mil, struct donne* donner)
{
	int i, j=0;
	for(i=0; i<donner->nb_connexion; i++)
	{
		if(pdf[i][0] != -1)
		{
			con_mil[j][0] = pdf[i][0];
			con_mil[j][1] = pdf[i][1];
			dis_mil[j] = con_depart[i];
			j++;
		}
	}
}

void poids_min(int** con_mil, float* dis_mil, float* dis_fin, int** con_final, struct donne* donner)		//algo de bruskal
{
	int i, j=0, k, l, v, u, m=1, n=1;
	bool etat, final;
	int verif[donner->nb_ville];							//pour savoir si deux villes son deja connecter entre elle (optimise)
	int adg[donner->nb_ville][donner->nb_ville];		//pour connaitre qui est connecter avec qui
	int tab_un[donner->nb_ville];
	int tab_deux[donner->nb_ville];
	for(i=0; i<donner->nb_ville; i++)			//init tout a 0
	{
		verif[i]=0;
		tab_un[i]=0;
		tab_deux[i]=0;
		for(j=0; j<donner->nb_ville; j++)
		{
			adg[i][j]=0;
		}
	}
	j=0;
	for(i=0; i<donner->nb_con; i++)
	{
		if(verif[con_mil[i][0]] == 0 || verif[con_mil[i][1]] == 0)	//verification de connection entre 2 villes si non alors les connectent
		{
			con_final[j][0] = con_mil[i][0];
			con_final[j][1] = con_mil[i][1];
			dis_fin[j] = dis_mil[i];
			verif[con_mil[i][0]]++;
			verif[con_mil[i][1]]++;
			adg[con_mil[i][0]][con_mil[i][1]] = 1;
			adg[con_mil[i][1]][con_mil[i][0]] = 1;
			j++;
		}else
		{
			k=0;
			l=0;
			m=1;
			n=1;
			tab_un[k] = con_mil[i][0];
			tab_deux[l] = con_mil[i][1];
			for(k=0; k<m; k++)				//creation des connections de la premiere ville
			{
				for(u=0; u<donner->nb_ville; u++)
				{
					if(adg[tab_un[k]][u] == 1)
					{
						etat = true;
						for(v=0; v<m; v++)
							if(tab_un[v] == u)
								etat = false;
						if(etat)
						{
							tab_un[m] = u;
							m++;
						}
					}
				}
			}
			for(l=0; l<n; l++)			//creation des connections de la deuxieme ville
			{
				for(u=0; u<donner->nb_ville; u++)
				{
					if(adg[tab_deux[l]][u] == 1)
					{
						etat = true;
						for(v=0; v<n; v++)
							if(tab_deux[v] == u)
								etat = false;
						if(etat)
						{
							tab_deux[n] = u;
							n++;
						}
					}
				}
			}
			
			final = true;
			for(u=0; u<m; u++)			//verification qu'aucune des deux villes n'est connecter a la meme ville(si oui leur tableau est le meme)
				for(v=0; v<n; v++)
					if(tab_un[u] == tab_deux[v])
						final = false;

			if(final)				//si il n'ont pas de ville en commun on les connectent
			{
				con_final[j][0] = con_mil[i][0];
				con_final[j][1] = con_mil[i][1];
				dis_fin[j] = dis_mil[i];
				verif[con_mil[i][0]]++;
				verif[con_mil[i][1]]++;
				adg[con_mil[i][0]][con_mil[i][1]] = 1;
				adg[con_mil[i][1]][con_mil[i][0]] = 1;
				j++;
			}

			for(u=0; u<donner->nb_ville; u++)		//reinitialise les 2 tableaux a 0
			{
				tab_deux[u] = 0;
				tab_un[u] = 0;
			}
		}
	}
}

float poids_aretes(float* dis_fin)
{
	int i;
	float resultat=0;
	for(i=0; i<16; i++)
	{
		resultat += dis_fin[i];
	}
	printf("\naffichage de la somme des arete de poids minimum\n\n%f\n", resultat);
	return resultat;
}