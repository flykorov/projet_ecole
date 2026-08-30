#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "struct.h"

void cree_fic(struct prems* lacrimatica, int** con_final, struct donne* donner)	//ecriture de la solution dans un fichier
{
	FILE* fic = fopen("solution.txt", "w");
	int i=0;
	struct cartographie* comp;
	for(i=0; i<donner->con_fin; i++)
	{
		comp = lacrimatica->debut;
		while(con_final[i][0]+1 != comp->id)
		{
			comp = comp->suivant;
		}
		fprintf(fic, "%s <-> ", comp->nom);
		comp = lacrimatica->debut;
		while(con_final[i][1]+1 != comp->id)
		{
			comp = comp->suivant;
		}
		fprintf(fic, "%s\n", comp->nom);
	}
	fclose(fic);
}