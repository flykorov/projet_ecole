#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

//EX 1
int decimal_to_binary_horner(unsigned int a, int binaire[])
{
	int i, b;
	b = a;
	for(i=0; a > 0; i++)  
	{  
		binaire[i] = a % 2;  
    		a = a / 2;  
  	} 	
 	printf("Le nombre %d en binaire est = ", b);
 	for(i=i-1; i >= 0; i--)  
	{  
	printf("%d", binaire[i]);  
	}
	printf("\n");
}		 

//EX 2
int decimal_to_binary_power(unsigned int b, int binaire[])
{
	int residue;
	int c = 0;
	residue = b;
	while(residue >= 256)
	{
		c = 100000000;
		residue = residue - 256;
	}
	while(residue >= 128)
	{
		c = c + 10000000;
		residue = residue - 128;
	}
	while(residue >= 64)
	{
		c = c + 1000000;
		residue = residue - 64;
	}
	while(residue >= 32)
	{
		c = c + 100000;
		residue = residue -32;
	}
	while(residue >= 16)
	{
		c = c + 10000;
		residue = residue - 16;
	}
	while(residue >= 8)
	{
		c = c + 1000;
		residue = residue - 8;
	}
	while(residue >= 4)
	{
		c = c + 100;
		residue = residue - 4;
	}
	while(residue >= 2)
	{
		c = c + 10;
		residue = residue - 2;
	}
	while(residue >= 1)
	{	
		c = c + 1;
		residue = residue - 1;
	}
	printf("Le nombre %d en binaire est = %d\n", b, c);
}

//EX 3
int decimal_to_octal_horner(unsigned int c, int octal[])
{
	int i, b;
	b = c;
	for(i=0; c > 0; i++)  
	{  
		octal[i] = c % 8;  
    		c = c / 8;  
  	} 	
 	printf("Le nombre %d en octal est = ", b);
 	for(i=i-1; i >= 0; i--)  
	{  
	printf("%d", octal[i]);  
	}  
	printf("\n");
}	

//EX 4
int decimal_to_octal_power(unsigned int d, int octal[])
{
	int residue;
	int c = 0;
	residue = d;
	while(residue >= 256)
	{
		c = 400;
		residue = residue - 256;
	}
	while(residue >= 64)
	{
		c = c + 100;
		residue = residue - 64;
	}
	while(residue >= 8)
	{
		c = c + 10;
		residue = residue - 8;
	}
	while(residue >= 1)
	{	
		c = c + 1;
		residue = residue - 1;
	}
	printf("Le nombre %d en octal est = %d\n", d, c);
}

		 
 
  	
  	

	
	
int main()
{
	unsigned int a, b, c, d, e;
	int binaire[20];
	int octal[20];
	int heximal[20];
	printf("Saisir un entier:\n");  
	scanf("%d",&a); 
	decimal_to_binary_horner(a, binaire);
	printf("Saisir un entier:\n");  
	scanf("%d",&b);
	decimal_to_binary_power(b, binaire);
	printf("Saisir un entier:\n");  
	scanf("%d",&c);
	decimal_to_octal_horner(c, octal);
	printf("Saisir un entier:\n");  
	scanf("%d",&d);
	decimal_to_octal_power(d, octal);
	return 0;
}	







