#include <stdio.h>
#include <stdlib.h>

unsigned int Expo_Rap_Rec(unsigned int g, unsigned int e, unsigned int n, unsigned int l, unsigned int TAB[])
{
	unsigned int i;
	unsigned int m = 1; 
	unsigned int x = g;
	for(i=0; i<l; i++)
	{
		if(TAB[i] == 0)
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
	for(f=l; f>0; f--)
	{
		y = f - 1;
		scanf("%u", &TAB[y]);
	}
	Expo_Rap_Rec(g, e, n, l, TAB);
	return 0;
}				
			
