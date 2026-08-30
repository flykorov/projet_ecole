#include <stdio.h>

int min_TAB(int TAB[], int n)
{
	int i, min;
	min = TAB[0];
	for(i=1; i<n-1; i++)
	{
		if(TAB[i] < min)
		{
			min = TAB[i];
		}
	}
	printf("\n%d\n", min);
	return min;
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
  	min_TAB(TAB, n);
}	
  	
  	
  	
  	
  	
