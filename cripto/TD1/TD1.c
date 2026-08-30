#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void CHARGER_CLE(char cle[26], char* nom_fic_cle)
{
	FILE* fic = fopen(nom_fic_cle, "r");
	fgets(cle, 27, fic);
	fclose(fic);
}

void CHIFF_MONO_ALPHA(char cle[26], char* nom_fic_clair, char* nom_fic_chiff)
{
	FILE* chiff = fopen(nom_fic_chiff, "w");
	FILE* fic = fopen(nom_fic_clair, "r");
	char nb, lettre;
	int i;
	while((lettre = fgetc(fic)) != EOF)
	{
		if(lettre >= 'a' && lettre <= 'z')
		{
			nb = lettre - 97;
			fputc(cle[nb], chiff);
		}
	}
	fclose(chiff);
	fclose(fic);
}

void DCHIFF_MONO_ALPHA(char cle[26], char* nom_fic_clair, char* nom_fic_chiff)
{
	FILE* chiff = fopen(nom_fic_chiff, "r");
	FILE* fic = fopen(nom_fic_clair, "w");
	char nb, lettre;
	int  i, j, y;
	while((lettre = fgetc(chiff)) != EOF)
	{
		if(lettre >= 'a' && lettre <= 'z')
		{
			for(j=0; j<26; j++)
			{
				if(lettre == cle[j])
				{
					y = j;
				} 
			}
			fputc(y+97, fic);
		}
	}
	fclose(chiff);
	fclose(fic);

}

int main(int argc, char** argv)
{
	int i;
	char cle[26];
	CHARGER_CLE(cle, argv[1]);
	printf("%s\n", cle);
	CHIFF_MONO_ALPHA(cle, argv[3], argv[2]);
	DCHIFF_MONO_ALPHA(cle, argv[5], argv[4]);
 	return 0;
}