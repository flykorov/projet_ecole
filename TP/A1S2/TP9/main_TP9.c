#include <stdio.h>
#include "code_TP9.h"

int main()
{
	FILE * fic;
	fic = fopen("depl_voit.txt", "r");
	if(fic == NULL)
	{
		printf("ERREUR\n");
	}else
	{
		printf("ouvert\n");
	}		
	CONDUITE(fic);
	fclose(fic);
}
