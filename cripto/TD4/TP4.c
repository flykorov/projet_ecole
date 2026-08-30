#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int DETERM_LONG_TEXTE(char* nom_fic_cle)
{
	int nb_lettre=0;
	FILE* fic = fopen(nom_fic_cle, "r");
	char lettre;
	while((lettre = fgetc(fic)) != EOF)
	{
		if(lettre >= 'a' && lettre <= 'z')
		{
			nb_lettre++;
		}
	}
	fclose(fic);
	return nb_lettre;
}

void CHARGER_CLE(int T, char cle[T], char* nom_fic_cle)
{
	int i=0;
	FILE* fic = fopen(nom_fic_cle, "r");
	char lettre;
	fgets(cle, T, fic);
	// while((lettre = fgetc(fic)) != EOF)
	// {
	// 	if(lettre >= 'a' && lettre <= 'z')
	// 	{
	// 		cle[i] = lettre;
	// 		i++;
	// 	}
	// }
	fclose(fic);
}

int let(char lettre)
{
	int i;
	char alpha[27] = "abcdefghijklmonpqrstuvwxyz";
	for(i=0; i<26; i++)
	{
		if(lettre == alpha[i])
			return i;
	}
}

void CHIFF_VIGENERE(int T, char cle[T], char* nom_fic_clair, char* nom_fic_chiff)
{
	FILE* fic = fopen(nom_fic_clair, "r");
	FILE* scrib = fopen(nom_fic_chiff, "w");
	char lettre;
	int i=0;
	while((lettre = fgetc(fic)) != EOF)
	{
		if(lettre >= 'a' && lettre <= 'z')
		{
			int v = let(cle[i]);
			if(lettre - v >= 'a')
			{
				fputc(lettre - v, scrib);
				i++;
				i = i % T;
			}
			else
			{
				fputc(lettre - v + 26, scrib);
				i++;
				i = i % T;
			}
		}
		if(lettre == ' ')
				fputc(lettre, scrib);
	}
	fclose(fic);
	fclose(scrib);
}

void DECHIFF_VIGENERE(int T, char cle[T], char* nom_fic_chiff, char* nom_fic_dechiff)
{
	FILE* fic = fopen(nom_fic_chiff, "r");
	FILE* scrib = fopen(nom_fic_dechiff, "w");
	char lettre;
	int i=0;
	while((lettre = fgetc(fic)) != EOF)
	{
		if(lettre >= 'a' && lettre <= 'z')
		{
			int v = let(cle[i]);
			if(lettre + v <= 'z')
			{
				fputc(lettre + v, scrib);
				i++;
				i = i % T;
			}
			else
			{
				fputc(lettre + v - 26, scrib);
				i++;
				i = i % T;
			}
		}
		if(lettre == ' ')
			fputc(lettre, scrib);
	}
	fclose(fic);
	fclose(scrib);
}

void RECHERCHE_CLE(char* nom_fic_clair, char* nom_fic_chiff, char* nom_fic_cle_rep)
{
	FILE* fic = fopen(nom_fic_clair, "r");
	FILE* chiff = fopen(nom_fic_chiff, "r");
	FILE* scrib = fopen(nom_fic_cle_rep, "w");
	char lettre, mot;
	while((lettre = fgetc(fic)) != EOF && (mot = fgetc(chiff)) != EOF)
	{
		if((lettre >= 'a' && lettre <= 'z') && (mot >= 'a' && mot <= 'z'))
		{
			if(lettre - mot + 97 >= 'a')
				fputc(lettre - mot + 97, scrib);
			else
				fputc(lettre - mot + 26 + 97, scrib);
		}
		// if(lettre == ' ' && mot == ' ')
		// 	fputc(lettre, scrib);
	}
	fclose(fic);
	fclose(scrib);
	fclose(chiff);
}

void EXTRACTION_CLE(char* nom_fic_cle_rep)
{	
	int nb_lettre = DETERM_LONG_TEXTE(nom_fic_cle_rep);
	FILE* fic = fopen(nom_fic_cle_rep, "r");
	char tab[nb_lettre];
	int i=0, j=0;
	int motif = 2;
	char lettre;
	// char rep[nb_lettre];
	while((lettre = fgetc(fic)) != EOF)
	{
		if(lettre >= 'a' && lettre <= 'z')
		{
			tab[i] = lettre;
			i++;
		}
	}
	while(1)
	{
		i=0;
		j=0;
		while(j < nb_lettre && tab[i%motif] == tab[j])
		{
			i++;
			j++;
		}
		if(j == nb_lettre)
			break;
		else
			motif++;
			
	}
	for(i=0; i<motif; i++)
		printf("%c", tab[i]);
	printf("\n");
	fclose(fic);
}

int main(int argc, char** argv)
{
	int nb_lettre, i;
	nb_lettre = DETERM_LONG_TEXTE(argv[1]);
	char cle[nb_lettre];
	CHARGER_CLE(nb_lettre+1, cle, argv[1]);
	// printf("%d %s\n", nb_lettre, cle);
	CHIFF_VIGENERE(nb_lettre, cle, argv[2], argv[3]);
	DECHIFF_VIGENERE(nb_lettre, cle, argv[3], argv[4]);
	RECHERCHE_CLE(argv[2], argv[3], argv[5]);
	EXTRACTION_CLE(argv[5]);
	return 0;
}