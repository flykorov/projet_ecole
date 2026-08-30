#include <stdio.h>

int Detrm_Nbre_Seq(int TAB[], int n)
{
	int i, j, b, d, f;
	i = 0;
	b = 0;
	d = 0;
	f = 0;
	while(i < n)
	{
		j = i;
		while(j != n-1 && TAB[j] < TAB[j+1])
		{
			j++;
		}
		b = b + 1;
		if((j-i) > (f-d))
		{
			d = i;
			f = j;
		}
	i = j + 1;
	}
	printf("\ntaille ss = %d\npetit indice = %d\ngrand indice = %d\n", b, d, f);
}

int main()
{
	int n;
	scanf("%d", &n);
	int TAB[n];
	int i=0;
  	while (i<n)
  	{
   		scanf("%d", &TAB[i]);
    		i++;
  	}
  	Detrm_Nbre_Seq(TAB, n);
}	
  	
  	
  	
