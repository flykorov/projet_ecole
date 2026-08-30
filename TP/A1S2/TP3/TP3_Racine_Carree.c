#include <stdio.h>

int Racine_Carree(int n, int epsilon)		//j'ai réecri l'algo mais je ne savait pas à quoi correspondait epsilon
{
	int a, b, m;
	a = 0;
	b = n;
	while(b - a > epsilon)
	{
		m = (a+b)/2;
		if(m * m < n)
		{
			a = m;
		}else
		{
			b = m;
		}
	}
	printf("\na %d\n", a);
}	

int Ma_Version(int n)				//ma version de la fonction racine carré
{
	int e;
	int i = 1;
	int j = 1;
	int l = 1;
	while(j <= n)
	{
		e = j / i;
		l = l + 2;		
		j = j + l;		//la différence entre chaque puissance est l (1² -> 2² == 1 [(1²/i²/j)] + 3 [(l)]; 2² -> 3² == 4 [(2²/i²/j)] + 5 [(l)]; 3² -> 4² == 9 [(3²/i²/j)] + 7 [(l)]; etc... l étant le chiffre de droite et j (j = i²) le chiffre de gauche
		i++;
	}
	printf("\nla racine carré de %d est %d à +1 près\n", n, e);
}	

int main()
{
	int n, epsilon;
	scanf("%d", &n);
	Ma_Version(n);	
}	
	
