#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void AFFIC_PLUS_GRDE_FREQ(float alpha[26])
{
	int i;
	char c=97;
	for(i=0; i<26; i++)
	{
		printf("%c : %f\n", c+i, alpha[i]);
	}
}

void CALC_FREQ_LETTRES_ALPHA(float alpha[26], char* nom_fic)
{
	int i, total=0;
	FILE* fic = fopen(nom_fic, "r");
	char lettre;
	while((lettre = fgetc(fic)) != EOF)
	{
		if(lettre >= 'a' && lettre <= 'z')
		{
			alpha[lettre-'a']++;
			total++;
		}
	}
	for(i=0; i<26; i++)
	{
		alpha[i] = alpha[i]/total;
	}
	AFFIC_PLUS_GRDE_FREQ(alpha);
	fclose(fic);
}

void DECHIFF_CESAR(int k, char* nom_fic_chiff, char* nom_fic_dechiff)
{
	char lettre;
	FILE* scrib = fopen(nom_fic_dechiff, "w");
	FILE* fic = fopen(nom_fic_chiff, "r");
	while((lettre = fgetc(fic)) != EOF)
	{
		if(lettre >= 'a' && lettre <= 'z')
		{
			if(lettre-k >= 'a')
				fputc(lettre-k, scrib);
			else
				fputc(lettre-k+26, scrib);
		}
		if(lettre == ' ')
			fputc(lettre, scrib);
	}
	fclose(fic);
	fclose(scrib);
}

void RECHERCHE_EXHAUSTIVE(char* fic_chiff, char* fic_dechiff)
{
	int i, c=25;
	char lettre;
	FILE* scrib = fopen(fic_dechiff, "w");
	for(i=0; i<26; i++)
	{
		FILE* fic = fopen(fic_chiff, "r");
		while((lettre = fgetc(fic)) != EOF)
		{
			if(lettre >= 'a' && lettre <= 'z')
			{
				if(lettre-c >= 'a')
					fputc(lettre-c, scrib);
				else
					fputc(lettre-c+26, scrib);
			}else
			{
				fputc(lettre, scrib);
			}
		}
		c--;
		fclose(fic);
	}
	fclose(scrib);
}

int main(int argc, char** argv)
{
	float alpha[26] = {0};
	CALC_FREQ_LETTRES_ALPHA(alpha, argv[1]);
	DECHIFF_CESAR(15, argv[1], argv[2]);
	RECHERCHE_EXHAUSTIVE(argv[3], argv[4]);
	return 0;
}