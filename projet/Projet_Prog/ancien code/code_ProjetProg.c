#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<unistd.h>
#include<time.h>
#include "code_ProjetProg.h"
#define curseur(x,y) printf("\033[%d;%dH", (x), (y))

int MODE_DIF()
{
	int system(const char *command); char difficulte[10]; int mode;
	system("clear"); /* Permet de ''nettoyer'' l'interface du terminal */
	system("cat menu.txt");
	curseur(9, 21);
	scanf("%d", &mode);
	if (mode == 1) /* Mode avec Image */
	{
		curseur(9, 50);
		scanf("%s", difficulte);
		curseur(11, 1);
		if (strlen(difficulte) == 6) /* Difficulté Facile */
		{
			printf("C'est la difficulté facile du mode image\n");
		}
		if (strlen(difficulte) == 9) /* Difficulté Difficile */
		{
			printf("C'est la difficulté difficile du mode image\n");
		}
	}
	if (mode == 2) /* Mode avec Chiffres */
        {
		 curseur(9, 50);
                scanf("%s", difficulte);
                curseur(11, 1);
                if (strlen(difficulte) == 6) /* Difficulté Facile */
                {
                        printf("C'est la difficulté facile du mode chiffres\n");
                }
                if (strlen(difficulte) == 9) /* Difficulté Difficile */
                {
                        printf("C'est la difficulté difficile du mode chiffres\n");
                }
        }
        sleep(2);
}

int** INI_TAB_BI()
{
	printf("a\n");
	printf("a\n");
	printf("a\n");
	printf("a\n");
	int i;
	int** MAT;
	MAT = malloc(3 * sizeof(int));
	for(i=0; i<3; i++)
	{
		*(MAT+i) = malloc(3 * sizeof(int));	
	}
	return MAT;
}

void CHARG_MAT_ORDER(int** ORDER_TAB)
{
	int i, j;
	int v = 1;
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			ORDER_TAB[i][j] = v;
			v++;	
		}
	}
}

void CHARG_MAT_NUM(int** NUM_IN_GAME)
{
	int i, j, k, l, a, t;
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			NUM_IN_GAME[i][j] = 0;	
		}
	}
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
		
			
			do
			{
				t = 1;
				a = rand() % 9;
				a = a + 1;
				for(k=0; k<3; k++)
				{
					for(l=0; l<3; l++)
					{
						
						if(NUM_IN_GAME[k][l] == a)
						{
							t = 0;
						}
					}
				}
			}while(t == 0);
			NUM_IN_GAME[i][j] = a;
		}
	}			
}

void AFFICH_MAT_ORDER(int** ORDER_TAB)
{
	int i, j;
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			printf("%d ", ORDER_TAB[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}	

void AFFICH_MAT_NUM(int** NUM_IN_GAME)
{
	int i, j;
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			printf("%d ", NUM_IN_GAME[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}	

void LIB_MAT_ORDER(int** ORDER_TAB)
{
	int i;
	for(i=0; i<3; i++)
	{
		free(ORDER_TAB[i]);
		ORDER_TAB[i] = NULL;
	}
	free(ORDER_TAB);
	ORDER_TAB = NULL;	
}

void LIB_MAT_NUM(int** NUM_IN_GAME)
{
	int i;
	for(i=0; i<3; i++)
	{
		free(NUM_IN_GAME[i]);
		NUM_IN_GAME[i] = NULL;
	}
	free(NUM_IN_GAME);
	NUM_IN_GAME = NULL;	
}

	
