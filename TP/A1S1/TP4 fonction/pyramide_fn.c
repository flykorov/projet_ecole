#include<stdio.h>
#include<stdlib.h>

int getIntegerGreaterThan(int nbl)
{
	do
	{
		printf("Please enter a value greater than 0:\n");
		if(scanf("%d", &nbl) == 1)
		{
			printf("1\n");
		}
		else
		{
			printf("Input Error\n");
			exit(-1);	
		}		
	}while(nbl<=0);
}

int printStar(int nbStar)
{
	int i = 0;
	for(i=0; i<nbStar; i++)
		{			
			printf("*");		
		}
}

int printSpace(int nbSpace)
{
	int i = 0;
	for(i=0; i<nbSpace; i++)
		{
			printf(" ");
		}
}					
int main()
{
	int nbl, nbStar, x;
	int nbSpace = -1;
	{
		printf("Height in lines of the pyramid?\n");
		nbl = getIntegerGreaterThan(nbl);
		for(x=nbl; x>0; x--)
		{
			nbSpace = nbSpace + 1;
			printSpace(nbSpace);
			nbStar = x * 2 - 1;	
			printStar(nbStar);
			printf("\n");
		}
		return 0;	
	}
}		
