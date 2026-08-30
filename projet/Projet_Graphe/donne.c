#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "struct.h"

//reception des differante donnee de la carte 

int taille_colonnes()
{
	FILE* fic = fopen("carte.txt", "r");
	if(fic == NULL)
    	{
        	printf("erreur ouverture fichier carte.txt\n");
        	exit(EXIT_FAILURE);
    	}
	int i = 0;
	int chiffre;
	while ((chiffre=fgetc(fic)) != '\n')
	{
		if (chiffre != ' ')
			i++;
	}
    fclose(fic);
    // printf("%d\n", i-1);
    return i-1;
}

int taille_lignes()
{
    FILE* fic = fopen("carte.txt", "r");
    if(fic == NULL)
    {
        printf("erreur ouverture fichier carte.txt\n");
        exit(EXIT_FAILURE);
    }
    int i = 0;
    int chiffre;
    while((chiffre=fgetc(fic)) != EOF)
    {
        if (chiffre == '\n')
            i++;
    }
    fclose(fic);
    // printf("%d\n", i+1);
    return i+1;
}

int nb_ville()
{
    FILE* fic = fopen("carte.txt", "r");
    if(fic == NULL)
    {
        printf("erreur ouverture fichier carte.txt\n");
        exit(EXIT_FAILURE);
    }
    int j=0;
    bool n = true;
    int chiffre;
    while((chiffre=fgetc(fic)) != EOF)
    {
        if(n)
        {
            if(chiffre == 48+j/10 && j > 9)
            {
                j++;
                n=false;
            }else if(chiffre > 48 && chiffre < 58)
            {
                j++;
            }
        }else
        {
            n=true;
        }
    }
    fclose(fic);
    return j;
}