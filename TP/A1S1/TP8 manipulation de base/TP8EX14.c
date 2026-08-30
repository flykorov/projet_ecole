#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

//EX 14
int hexa_to_octal(char *hexa, int z, char *result)
{
	int i, b, a, c, d, f;
	int realresult[20];

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
	b = 0;
	for(i=0; i<z; i++)
	{
		c = pow(16, z - 1 - i);
		b = b + (hexa[i] * c);
	}

	for(i=0; b > 0; i++)  
	{
		hexa[i] = b % 8;  
    		b = b / 8;  
  	} 	
 	printf("Le nombre héxadécimal %s en octal est = ", result);
 	for(i=i-1; i >= 0; i--)  
	{  
	printf("%d", hexa[i]);  
	}  
	printf("\n");
}	



int main()
{
	int i, z;
	char hexa[20];
	char result[20];
	printf("Saisir un entier hexadécimal:\n");  
	scanf("%[0123456789ABCDEF]", hexa);
	z = strlen(hexa);
	for(i=0; i<=z; i++)
	{
		result[i] = hexa[i];
	}
	hexa_to_octal(hexa, z, result);
}



