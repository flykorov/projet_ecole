#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

void VERIF_CLE_ISBN(unsigned int tab[13])
{
	int i, a=0, b=0;
	for(i=0; i<6; i++)
	{
		a = a + tab[i*2];
		b = b + tab[i*2+1];
	}
	tab[13] = (10-((a)+(3*b))%10)%10;
	printf("a = %d\nb = %d\ntab[13] = %d\n", a, b, tab[13]);
	if(tab[13] == 1)
	{
		printf("Numéro ISBN Valide !\n");
	}else
	{
		printf("ATTENTION Numéro ISBN Non-Valide !\n");
	}
}

unsigned int DETERM_CLE_ISBN(unsigned int tab[13])
{
	int i, a;
	printf("Saisir un numéro ISBN:\n");
	do
	{
		a=0;
		printf("ecrire des chiffres contenu entre 0 et 9\n");
		for(i=0; i<12; i++)
		{
			scanf("%u", &tab[i]);
			if(tab[i] > 9 && tab[i] < 0)
			{
				printf("recommencez\n");
				a=1;
			}
		}
	}while(a == 1);
	VERIF_CLE_ISBN(tab);
	return *tab;
}

void VERIF_CLE_INSEE(unsigned long long int tab[15])
{
	unsigned long long int a=0, b; 
	int i, j=12;
	for(i=0; i<13; i++)
	{
		b = pow(10, j);
		a = a + tab[i]*b;
		printf("%lld\n", b);
		j--;
	}
	printf("a = %lld\n", a);
	a = 97 - (a%97);
	printf("a = %lld\n", a);
	if(a == 7)
	{
		printf("Numéro INSEE Valide !\n");
		tab[12] = 0;
		tab[13] = 7;
	}else
	{
		printf("ATTENTION Numéro INSEE Non-Valide !\n");
	}
}

unsigned int DETERM_CLE_INSEE(unsigned long long int tab[15])
{
	int i, a;
	printf("Saisir un numéro INSEE:\n");
	do
	{
		a=0;
		printf("ecrire des chiffres contenu entre 0 et 9\n");
		for(i=0; i<13; i++)
		{
			scanf("%llu", &tab[i]);
			if(tab[i] > 9 && tab[i] < 0)
			{
				printf("recommencez\n");
				a=1;
			}
		}
	}while(a == 1);
	VERIF_CLE_INSEE(tab);
	return *tab;
}

int main()
{
	unsigned int tab[13];
	unsigned long long int tabl[15];
	DETERM_CLE_ISBN(tab);
	DETERM_CLE_INSEE(tabl);
	return 0;
}