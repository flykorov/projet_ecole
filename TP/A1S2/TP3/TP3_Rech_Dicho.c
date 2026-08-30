#include <stdio.h>

int Recherche_Dicho(int TAB[], int n, int ELT)
{
	int a, b, m;
	a = 0;
	b = n;
	while(a < b)
	{
		m = (a+b)/2;
		if(TAB[m] >= ELT)
		{
			b = m;
		}else
		{
			a = m + 1;
		}
	}
	printf("\n%d\n", b);
	return b;
}				


int main()
{
	int n, ELT;
	scanf("%d", &n);
	int TAB[n];
	int i=0;
  	while (i<n)
  	{
   		scanf("%d", &TAB[i]);
    		i++;
  	}
  	printf("\n");
  	scanf("%d", &ELT);
	Recherche_Dicho(TAB, n, ELT);
}	
	
