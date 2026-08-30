#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dictio
{
	int size;
	char* mot;
};


void ajout_mot(struct dictio ordre[], int nbm)
{
	int i;
	char tamp[30];
	for(i=0; i<nbm; i++)
	{	
		scanf("%s", tamp);
		ordre[i].size = strlen(tamp);
		ordre[i].mot = malloc(strlen(tamp) * sizeof(char));
		strcpy(ordre[i].mot, tamp);
	}
	printf("\n");
}

void afficher_tab(struct dictio ordre[], int nbm)
{
	int i;
	printf("vous avez écrit :\n");
	for(i=0; i<nbm; i++)
	{
		printf("%s\n", ordre[i].mot);
	}
	printf("\n");
};


void mot_dans_dictio(struct dictio ordre[], int nbm)
{
	int i, j, t, v, y;
	char tamp[30];
	char tab[30];
	printf("choisisser un mot à comparez avec le dictionnaire\n");
	scanf("%s", tamp);
	t = strlen(tamp);
	for(i=0; i<nbm; i++)
	{
		strcpy(tab, ordre[i].mot);
		v = 0;
		if(t == ordre[i].size)
		{
			for(j=0; j<t; j++)
			{
				if(tab[j] == tamp[j])
				{
					v++;
				}
			}
			if(v == t)
			{
				y = 1;
			}
		}
	}
	if(y == 1)
	{
		printf("le mot est dans le dictionnaire\n");
	}else
	{
		printf("le mot n'est pas dans le dictionnaire\n");
	}
}

void lib_tab(struct dictio ordre[], int nbm)
{
	int i;
	for(i=0; i<nbm; i++)
	{
		free(ordre[i].mot);
		ordre[i].mot = NULL;
	}
}

int main()
{
	struct dictio ordre[100];
	int nbm;
	printf("entrez le nombre de mot que vous voulez entrez\n");
	scanf("%d", &nbm);
	ajout_mot(ordre, nbm);
	afficher_tab(ordre, nbm);
	mot_dans_dictio(ordre, nbm);
	lib_tab(ordre, nbm);
}
