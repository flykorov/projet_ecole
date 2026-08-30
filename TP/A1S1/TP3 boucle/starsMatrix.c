#include <stdio.h>
#include <stdlib.h>

int main()
{
	int nbl, x, y, z, v, alea;
	int w = 0;
	do
	{
		printf("Saisir un nombre de ligne :\n");
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
	
	for(x=0; x<nbl; x++)
	{
		for(y=60; y>0; y--)
		{
			alea = rand() % 2;
			if(alea==0)
			{
				printf(" ");
			}
			else
			{
				printf("*");
			}		
		}
	printf("\n");
	}
	return 0;
}		
