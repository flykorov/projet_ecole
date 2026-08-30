#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

//EX 6
int binary_to_decimal(char *bin, int a)
{
	int i, b, d;
	int c = 0;
	for(i=0; i<a; i++)
	{
		if(bin[i] == 49)
		{
			b = pow(2, a -1 - i);
			c = c + b;
		}
	}	
	printf("Le nombre binaire %s en décimal est = %d\n", bin, c);
}	

//EX 7
int binary_to_octal(char *bin, int a)
{
	
	int i, b, d, z, y;
	int c = 0;
	int oct[20];
	for(i=0; i<a; i++)
	{
		if(bin[i] == 49)
		{
			b = pow(2, a -1 - i);
			c = c + b;
		}
	}
	z = c;
	for(i=0; z>0; i++)  
	{
		oct[i] = z % 8;  
    		z = z / 8;  
  	} 	
 	printf("Le nombre binaire %s en octal est = ", bin);
 	for(i=i-1; i >= 0; i--)  
	{  
		printf("%d", oct[i]);  
	}  
	printf("\n");
}
	
//EX 8

int binary_to_heximal(char *bin, int b, char *result)
{
	int i, a, c;
	
	for(i=b; i>=0; i--)
	{
		if(bin[i] == 48)
		{
			bin[i] = 0;
		}
		if(bin[i] == 49)
		{
			bin[i] = 1;
		}
	}
	printf("le nombre binaire %s en héxadécimal est = ", result);
	
	a = 1000 * bin[b-8] + 100 * bin[b-7] + 10 * bin[b-6] + bin[b-5];

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
	
	a = 1000 * bin[b-4] + 100 * bin[b-3] + 10 * bin[b-2] + bin[b-1];
  
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
	char bin[20];
	char result[20];
	int a, b, i;
	printf("Saisir un entier binaire:\n");  
	scanf("%[01]", bin);
	printf("%s\n", bin);
	a = strlen(bin);
	b = strlen(bin);
	for(i=0; i<=b; i++)
	{
		result[i] = bin[i];
	}
	binary_to_decimal(bin, a);
	binary_to_octal(bin, a);
	binary_to_heximal(bin, b, result);
	return 0;
}
