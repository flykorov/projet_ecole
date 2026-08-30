#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int factorielle_it(int n)
{
	int i, fact = 1;
	for(i=1; i<=n; i++)
	{
		fact = fact * i;
	}
	return fact;
}		
	
int factorielle_rec(int n)
{
	if(n == 0)
	{
		return 1;
	}else
	{
		return n * factorielle_rec(n-1);
	}	
}

int somme_entier(int n)
{
	if(n == 0)
	{
		return 0;
	}else
	{
		return n + somme_entier(n-1);
	}		
}

int pgcd(int a, int b)
{
	if(b == 0)
	{
		return a;
	}else
	{
		pgcd(b, a%b);
	}
}		

int fibonacci_it(int n)
{
	int i, Fn1, Fn2, Fn;
	if(n == 0)
	{
		return 0;
	}
	if(n == 1)
	{
		return 1;
	}
	Fn1 = 1;
	Fn2 = 0;
	for(i=2; i<=n; i++)
	{
		Fn = Fn1 + Fn2;
		Fn2 = Fn1;
		Fn1 = Fn;
	}
	return Fn;
}

int fibonacci_rec(int n)
{
	if(n == 0)
	{
		return 0;
	}
	if(n == 1)
	{
		return 1;
	}
	return fibonacci_rec(n-1) + fibonacci_rec(n-2);
}

int palin(char mot[], int str, int y)
{
	if(str < y)
	{
		return 1;
	}
	if(mot[str] == mot[y])
	{
		palin(mot, str-1, y+1);
	}else
	{
		return 0;
	}
}			
		

int main()
{
	int a, b, n, fact_it, fact_rec, fibo_it, fibo_rec, euclide, somme, str, y=0, res;
	char mot[100];
	printf("entrez un entier positif\n");
	scanf("%d", &n);
	fact_it = factorielle_it(n);
	fact_rec = factorielle_rec(n);
	printf("fact : it = %d, rec = %d\n", fact_it, fact_rec);
	somme = somme_entier(n);
	printf("somme = %d\n", somme);
	fibo_it = fibonacci_it(n);
	fibo_rec = fibonacci_rec(n);
	printf("fibo : it = %d, rec = %d\n", fibo_it, fibo_rec);
	printf("entrez 2 entier positif\n");
	scanf("%d %d", &a, &b);
	euclide = pgcd(a, b);
	printf("pgcd(%d, %d) = %d\n", a, b, euclide);
	printf("entrez un mot\n");
	scanf("%s", mot);
	str = strlen(mot);
	str--;
	res = palin(mot, str, y);
	if(res == 1)
	{
		printf("%s est un palindrome\n", mot);
	}else
	{
		printf("%s n'est pas un palindrome\n", mot);
	}
	return 0;	
}	
