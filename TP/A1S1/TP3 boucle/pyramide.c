#include <stdio.h>

int main()
{
	int nbl, x, y, z, v;
	int w = -1;
	do
	{
		printf("Saisir le nombre de ligne de la pyramide inversée :\n");
		if(scanf("%d", &nbl) == 1)
		{
			printf("1\n");
		}
		else
		{
			printf("Input error\n");
			return -1;	
		}		
	}while(nbl<=0);	
	for(x=nbl; x>0; x--)
	{
		w = w + 1;
		for(v=w; v>0; v--)
		{
			printf(" ");
		}
		y = x * 2 - 1;
		for(z=0; z<y; z++)
		{			
			printf("*");		
		}	
		printf("\n");
		
	}
	return 0;
}		
