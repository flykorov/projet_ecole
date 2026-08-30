#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#define clear() printf("\033[H\033[J") 
#define curseur(x,y) printf("\033[%d;%dH", (x), (y))

int validationResultat(int z, int order[], int resultat[])
{
	
