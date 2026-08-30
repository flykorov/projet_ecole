#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

//EX 12
int hexa_to_decimal(char *hexa, int z, char *result)
{
	int i, c, d;
	int b = 0;
	for(i=0; i<=z; i++)
	{
		d = hexa[i];
		switch(d)
		{
			case 'A':
				hexa[i] = 10;
				break;
			case 'B':
				hexa[i] = 11;
				break;
			case 'C':
				hexa[i] = 12;
				break;
			case 'D':
				hexa[i] = 13;
				break;
			case 'E':
				hexa[i] = 14;
				break;
			case 'F':
				hexa[i] = 15;
				break;
			default:
				hexa[i] = hexa[i] - 48;	
		}
	}			
	for(i=0; i<z; i++)
	{
		c = pow(16, z - 1 - i);
		b = b + (hexa[i] * c);
	}
	printf("Le nombre hexadecimal %s en décimal est = %d\n", result, b);
}

//EX 13
int hexa_to_binary(char *hexa, int z, char *result)
{
	int i, b, a, c, d;
	
	for(i=0; i<=z; i++)
	{
		d = hexa[i];
		switch(d)
		{
			case 'A':
				hexa[i] = 10;
				break;
			case 'B':
				hexa[i] = 11;
				break;
			case 'C':
				hexa[i] = 12;
				break;
			case 'D':
				hexa[i] = 13;
				break;
			case 'E':
				hexa[i] = 14;
				break;
			case 'F':
				hexa[i] = 15;
				break;
			default:
				hexa[i] = hexa[i] - 48;	
		}
	}			
	for(i=0; i<z; i++)
	{
		c = pow(16, z - 1 - i);
		b = b + (hexa[i] * c);
	}

	for(i=0; a > 0; i++)  
	{  
		hexa[i] = a % 2;
    		a = a / 2;  
  	} 	
 	printf("Le nombre hexadecimal %s en binaire est = ", result);
 	for(i=i-1; i >= 0; i--)  
	{  
	printf("%d", hexa[i]);  
	}
	printf("\n");
}


	
int main()
{
	int i;
	char hexa[20];
	char result[20];
	int z;
	printf("Saisir un entier hexadécimal:\n");  
	scanf("%[0123456789ABCDEF]", hexa);
	z = strlen(hexa);
	for(i=0; i<=z; i++)
	{
		result[i] = hexa[i];
	}
	hexa_to_decimal(hexa, z, result);
	hexa_to_binary(hexa, z, result);
}		
		
		
		
		
		
