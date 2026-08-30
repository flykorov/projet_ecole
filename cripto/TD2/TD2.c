#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void CHIFF_CESAR(int k, char* nom_fic_clair, char* nom_fic_chiff)
{
	char lettre;
	FILE* fic = fopen(nom_fic_clair, "r");
	FILE* scrib = fopen(nom_fic_chiff, "w");
	while((lettre = fgetc(fic)) != EOF)
	{
		if(lettre >= 'a' && lettre <= 'z')
		{
			if(lettre+k <= 'z')
				fputc(lettre+k, scrib);
			else
				fputc(lettre+k-26, scrib);
		}
		if(lettre == ' ')
			fputc(lettre, scrib);
	}
	fclose(fic);
	fclose(scrib);
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

void chiff_ascii(int k, char* nom_fic_clair, char* nom_fic_chiff)
{
	char lettre;
	FILE* fic = fopen(nom_fic_clair, "r");
	FILE* scrib = fopen(nom_fic_chiff, "w");
	while((lettre = fgetc(fic)) != EOF)
	{
		fputc(lettre+k, scrib);
	}
	fclose(fic);
	fclose(scrib);
}

void dechiff_ascii(int k, char* nom_fic_chiff, char* nom_fic_dechiff)
{
	char lettre;
	FILE* scrib = fopen(nom_fic_dechiff, "w");
	FILE* fic = fopen(nom_fic_chiff, "r");
	while((lettre = fgetc(fic)) != EOF)
	{
		fputc(lettre-k, scrib);
	}
	fclose(fic);
	fclose(scrib);
}

int main(int argc, char** argv)
{
	int i, cle = 16;
	CHIFF_CESAR(cle, argv[1], argv[2]);
	DECHIFF_CESAR(cle, argv[2], argv[3]);
	DECHIFF_CESAR(cle, argv[4], argv[5]);
	chiff_ascii(cle, argv[6], argv[7]);
	dechiff_ascii(cle, argv[7], argv[8]);
	return 0;
}