#include <stdio.h>
#include "code_TP9.h"

void AVANCER(int action)
{
	printf("Avancer\n");	
}		

void RECULER(int action)
{
	printf("Reculer\n");	
}	

void TOURNER_D(int action)
{
	printf("Tourner à droite\n");
}

void TOURNER_G(int action)
{
	printf("Tourner à gauche\n");
}	

void CONDUITE(FILE * fic)
{
	int action;
	int nb;
	int i=0;
	fscanf(fic, "%d", &nb);
	while(i < nb)
	{
		fscanf(fic, "%d", &action);
		if(action == 1)
		{
			AVANCER(action);
		}
		fscanf(fic, "%d", &action);
		if(action == 1)
		{
			RECULER(action);
		}	
		fscanf(fic, "%d", &action);
		if(action == 1)
		{
			TOURNER_D(action);
		}	
		fscanf(fic, "%d", &action);
		if(action == 1)
		{
			TOURNER_G(action);
		}
		i++;	
	}	
}
