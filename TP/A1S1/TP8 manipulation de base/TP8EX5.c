#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

//EX 5
int decimal_to_heximal(unsigned int e, char heximal[])
{
	int i, a, b;
	char c;
	b = e;
	char binaire[20];
	for(i=0; e > 0; i++)  
	{  
		binaire[i] = e % 2;  
    		e = e / 2;  
  	}
	
	printf("le nombre %d en hexadecimal = ", b);


	a = 1000 * binaire[7] + 100 * binaire[6] + 10 * binaire[5] + binaire[4];

	if(a == 851)
	{
		a = 1;
	}	
	if(a == 861)
	{
		a = 1;
	}
	
	if(a == 1111)
	{
		printf("F");
	}
	if(a == 1110)
	{
		printf("E");
	}
	if(a == 1101)
	{
		printf("D");
	}
	if(a == 1100)
	{
		printf("C");
	}
	if(a == 1011)
	{
		printf("B");
	}
	if(a == 1010)
	{
		printf("A");
	}
	if(a == 1001)
	{
		printf("9");
	}
	if(a == 1000)
	{
		printf("8");
	}
	if(a == 111)
	{
		printf("7");
	}
	if(a == 110)
	{
		printf("6");
	}
	if(a == 101)
	{
		printf("5");
	}
	if(a == 100)
	{
		printf("4");
	}
	if(a == 11)
	{
		printf("3");
	}
	if(a == 10)
	{
		printf("2");
	}
	if(a == 1)
	{
		printf("1");
	}
	if(a == 0)
	{
		printf("0");
	}
	
	a = 1000 * binaire[3] + 100 * binaire[2] + 10 * binaire[1] + binaire[0];
	
  	if(b == 1)
  	{
  		a = 1;
  	}
  	if(b == 0)
  	{
  		a = 0;
  	}
  	if(a == 1111)
	{
		printf("F");
	}
	if(a == 1110)
	{
		printf("E");
	}
	if(a == 1101)
	{
		printf("D");
	}
	if(a == 1100)
	{
		printf("C");
	}
	if(a == 1011)
	{
		printf("B");
	}
	if(a == 1010)
	{
		printf("A");
	}
	if(a == 1001)
	{
		printf("9");
	}
	if(a == 1000)
	{
		printf("8");
	}
	if(a == 111)
	{
		printf("7");
	}
	if(a == 110)
	{
		printf("6");
	}
	if(a == 101)
	{
		printf("5");
	}
	if(a == 100)
	{
		printf("4");
	}
	if(a == 11)
	{
		printf("3");
	}
	if(a == 10)
	{
		printf("2");
	}
	if(a == 1)
	{
		printf("1");
	}
	if(a == 0)
	{
		printf("0");
	}
	printf("\n");
}
  	
  	
  	
  int main()
{
	unsigned int e;
	char heximal[5];
	printf("Saisir un entier(environ 250 max):\n");  
	scanf("%d",&e);
	decimal_to_heximal(e, heximal);
	return 0;
}






