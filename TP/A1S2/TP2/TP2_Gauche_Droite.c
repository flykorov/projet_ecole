#include <stdio.h>
#include <stdlib.h>

unsigned int Expo_Rap_Rec(unsigned int g, unsigned int e, unsigned int n, unsigned int l, unsigned int TAB[])
{
	unsigned int i, w;
	unsigned int m = 1; 
	unsigned int x = g;
	for(i=l; l>0; i--)
	{
		if(TAB[i-1] == 0)
		{
		}else
		{
			m = (m * x) % n;
		}
		x = (x * x) % n;
	}
	printf("%u^%u mod %u = %u\n", g, e, n, m);
}		 

int main()
{
	unsigned int g, e, n, l, y;
	scanf("%u", &g);
	scanf("%u", &e);
	scanf("%u", &n);
	scanf("%u", &l);
	unsigned int TAB[l];
	unsigned int f;
	for(f=0; f<l; f++)
	{
		scanf("%u", &TAB[f]);
	}
	Expo_Rap_Rec(g, e, n, l, TAB);
	return 0;
}				
	
