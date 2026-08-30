#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void CHIFF_VERNAM_1 (char* nom_fic_clair, char* nom_fic_chiff, char* nom_fic_cle)
{
	FILE* fic = fopen(nom_fic_clair, "rb");
	FILE* scrib = fopen(nom_fic_chiff, "wb");
	FILE* cle = fopen(nom_fic_cle, "wb");
	int r, lettre;
	while((lettre = fgetc(fic)) != EOF)
	{
		r = rand() %256;
		fputc(r, cle);
		fputc(lettre^r, scrib);
	}
	fclose(fic);
	fclose(scrib);
	fclose(cle);
}

void DECHIFF_VERNAM_1(char* nom_fic_chiff, char* nom_fic_dechiff, char* nom_fic_cle)
{
    FILE*fic_chiff = fopen(nom_fic_chiff,"rb");
    FILE*fic_cle = fopen(nom_fic_cle,"rb");
    FILE*fic_dechiff = fopen(nom_fic_dechiff,"wb");
    int c;
    while((c=fgetc(fic_chiff))!=EOF)
    {
        int d = fgetc(fic_cle);
        fputc(d^c,fic_dechiff);
    }
    
    fclose(fic_dechiff);
    fclose(fic_chiff);
    fclose(fic_cle);
}



int main(int argc, char** argv)
{
	srand(time(NULL));
	CHIFF_VERNAM_1(argv[2], argv[3], argv[1]);
	DECHIFF_VERNAM_1(argv[3],argv[4],argv[1]);
	return 0;
}