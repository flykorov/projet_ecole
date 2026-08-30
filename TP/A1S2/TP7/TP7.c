#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void CHARGEMENT_MAT(int NB_L, int NB_C, int MAT[NB_L][NB_C])
{
	int i, j;
	for(i=0; i<NB_L; i++)
	{
		for(j=0; j<NB_C; j++)
		{
			scanf("%d", &MAT[i][j]);
		}
	}			
}

void AFFICHAGE_MAT(int NB_L, int NB_C, int MAT[NB_L][NB_C])
{
	int i, j;
	for(i=0; i<NB_L; i++)
	{
		for(j=0; j<NB_C; j++)
		{
			printf("%d ", MAT[i][j]);
		}
		printf("\n");
	}
	printf("\n");	
}

int MINI(int a, int b, int c)
{
	int min = a;
	if(min>b)
	{
		min = b;
	}
	if(min>c)
	{
		min = c;
	}
	return min;		
}

int PLUS_GRAND_SOUS_CARRE(int NB_L, int NB_C, int MAT[NB_L][NB_C])
{
	int i, j, min, T;
	int TPGSC[NB_L][NB_C];
	for(j=0; j<NB_C; j++)
	{
		TPGSC[0][j] = 1;
	}
	for(i=1; i<NB_L; i++)
	{
		TPGSC[i][0] = 0;
	}
	T = 1;
	for(i=1; i<NB_L; i++)
	{
		for(j=1; j<NB_C; j++)
		{
			if(MAT[i][j] == MAT[i][j-1] && MAT[i][j] == MAT[i-1][j-1] && MAT[i][j] == MAT[i-1][j])
			{
				min = MINI(TPGSC[i][j-1], TPGSC[i-1][j-1], TPGSC[i-1][j]) + 1;
				TPGSC[i][j] = min;
				if(T < min)
				{
					T = min;
				}
			}else
			{
				TPGSC[i][j] = 1;
			}
		}
	}
	for(i=0; i<NB_L; i++)
	{
		for(j=0; j<NB_C; j++)
		{
			printf("%d ", TPGSC[i][j]);
		}
		printf("\n");
	}		
	return T;				
}

int PLUS_GRAND_SOUS_CARRE_2(int NB_L, int NB_C, int MAT[NB_L][NB_C], int TPGSC[NB_L][NB_C])
{
	int i, j, min, T, I, J;
	for(j=0; j<NB_C; j++)
	{
		TPGSC[0][j] = 1;
	}
	for(i=1; i<NB_L; i++)
	{
		TPGSC[i][0] = 0;
	}
	T = 1;
	for(i=1; i<NB_L; i++)
	{
		for(j=1; j<NB_C; j++)
		{
			if(MAT[i][j] == MAT[i][j-1] && MAT[i][j] == MAT[i-1][j-1] && MAT[i][j] == MAT[i-1][j])
			{
				min = MINI(TPGSC[i][j-1], TPGSC[i-1][j-1], TPGSC[i-1][j]) + 1;
				TPGSC[i][j] = min;
				if(T < min)
				{
					T = min;
					I = i;
					J = j;
				}
			}else
			{
				TPGSC[i][j] = 1;
			}
		}
	}
	for(i=0; i<NB_L; i++)
	{
		for(j=0; j<NB_C; j++)
		{
			printf("%d ", TPGSC[i][j]);
		}
		printf("\n");
	}
	printf("i = %d  j = %d\n", I, J);
	return T;
}

void GENERATION_FIC()
{
	int NB_L, NB_C, i, j, r;
	scanf("%d", &NB_L);
	scanf("%d", &NB_C);
	printf("NB_L = %d  NB_C = %d\n", NB_L, NB_C);
	for(i=0; i<NB_L; i++)
	{
		for(j=0; j<NB_C; j++)
		{
			r = rand()%4;
			if(r == 0)
			{
				printf("0 ");
			}else
			{
				printf("1 ");
			}
		}
	printf("\n");
	}				
}

void NBRE_DE_CHAQ_SS_CAR(int NB_L, int NB_C, int TPGSC[NB_L][NB_C], int L_MAX)
{
	int i, j;
	int TAB[L_MAX+1];
	for(i=0; i<=L_MAX; i++)
	{
		TAB[i] = 0;
	}
	for(i=0; i<NB_L; i++)
	{
		for(j=0; j<NB_C; j++)
		{
			TAB[TPGSC[i][j]]++;
		}
	}
	for(i=0; i<=L_MAX; i++)
	{
		printf("%d ", TAB[i]);
	}
	printf("\n");				
}

int main()
{
	srand(time(NULL));
	int NB_L, NB_C, L_MAX;
	scanf("%d", &NB_L);
	scanf("%d", &NB_C);
	int MAT[NB_L][NB_C];
	int TPGSC[NB_L][NB_C];
	CHARGEMENT_MAT(NB_L, NB_C, MAT);
	AFFICHAGE_MAT(NB_L, NB_C, MAT);
	L_MAX = PLUS_GRAND_SOUS_CARRE_2(NB_L, NB_C, MAT, TPGSC);
	NBRE_DE_CHAQ_SS_CAR(NB_L, NB_C, TPGSC, L_MAX);
}	
