#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>


#define clear() printf("\033[H\033[J") 
#define gotoxy(x,y) printf("\033[%d;%dH", (x), (y))




int playerResultat(int z)
{
	int i, a, b, c, d, e, f, g;
	int resultat[z];
	for(i=0; i<z; i++)
	{
		f = i + 1;
		printf("Saisir la valeur du son mémoriser qui ce situe en %d position. (entre 1 et 48)\n", f);
		do
		{
			if(scanf("%d", &a) == 1)
			{
				resultat[i] = a;
				b = 0;
			}else	
			{
				printf("ntm met un chiffre positif entre 1 et 48\n");
				b = 1;
			}	
		}while(b == 1);
		printf("Voulez-vous changer une valeur saisie? (saisir 0 pour non et 1 pour oui)\n");
		do
		{
			if(scanf("%d", &c) == 1)
			{
				resultat[i] = a;
				b = 0;
			}else	
			{
				printf("ntm met un chiffre positif entre o et 1\n");
				b = 1;
			}
		}while(b == 1);	
		if(c == 0)
		{
		}
		if(c == 1)
		{
			printf("Saisir le numéro de la valeur à modifier (vous pouvez toujours annuler en appuyant sur 0)\n");
			scanf("%d", &d);
			if(d == 0)
			{
			}
			else
			{
				printf("Saisir la valeur qui prendra la place de l'ancienne\n");
				scanf("%d", &e);
				d = d - 1;
				resultat[d] = e;
			}	
		}
		for(g=0; g<=i; g++)  
			{  
			printf("%d  ", resultat[g]);  
			}
		printf("\n");
	}
}		

int curseur()
{
    	int number; 

    
    	system("cat maquettedif.txt");
    	printf("\033[%d;%dH", 44, 26);
    	scanf("%d", &number);
    	gotoxy(44, 34); 
    	scanf("%d", &number);
	gotoxy(44, 42); 	//8 par 8 (26 le premier)
   	scanf("%d", &number);

}

int main()
{
	curseur();
}	






















