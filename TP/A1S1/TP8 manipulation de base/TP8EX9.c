#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

//EX 9
int octal_to_decimal(char *oct, int a)
{
	int i, b, d;
	int c = 0;
	for(i=0; i<a; i++)
	{
		b = pow(8, a -1 - i);
		c = c + ((oct[i] - 48) * b);
	}	
	printf("Le nombre octale %s en décimal est = %d\n", oct, c);
}

//EX 10
int octal_to_binary(char *oct, int a)
{
	int i, b, d;
	int c = 0;
	int binaire[100];
	for(i=0; i<a; i++)
	{
		b = pow(8, a -1 - i);
		c = c + ((oct[i] - 48) * b);
	}	
	for(i=0; c > 0; i++)  
	{  
		binaire[i] = c % 2;  
    		c = c / 2;  
  	} 	
 	printf("Le nombre octale %s en binaire est = ", oct);
 	for(i=i-1; i >= 0; i--)  
	{  
		printf("%d", binaire[i]);  
	}
	printf("\n");
}

//EX 11
int octal_to_hexa(char *oct, int a)
{
	int i, b, d;
	int c = 0;
	int bin[100];
	for(i=0; i<a; i++)
	{
		b = pow(8, a -1 - i);
		c = c + ((oct[i] - 48) * b);
	}	
	for(i=0; c > 0; i++)  
	{  
		bin[i] = c % 2;  
    		c = c / 2;  
  	}

	printf("le nombre octale %s en héxadécimal est = ", oct);
	
	if(bin[4] == 1)
	{
		d = bin[4];
	}
	if(bin[5] == 1)
	{
		d = 10 * bin[5] + bin[4];
	}
	if(bin[6] == 1)
	{
		d = 100 * bin[6] + 10 * bin[5] + bin[4];
	}
	if(bin[7] == 1)
	{
		d = 1000 * bin[7] + 100 * bin[6] + 10 * bin[5] + bin[4];
	}
	
	
		
	if(d == 851)
	{
		d = 1;
	}	
	if(d == 861)
	{
		d = 1;
	}
	
	if(d == 1111)
	{
		printf("F");
	}
	if(d == 1110)
	{
		printf("E");
	}
	if(d == 1101)
	{
		printf("D");
	}
	if(d == 1100)
	{
		printf("C");
	}
	if(d == 1011)
	{
		printf("B");
	}
	if(d == 1010)
	{
		printf("A");
	}
	if(d == 1001)
	{
		printf("9");
	}
	if(d == 1000)
	{
		printf("8");
	}
	if(d == 111)
	{
		printf("7");
	}
	if(d == 110)
	{
		printf("6");
	}
	if(d == 101)
	{
		printf("5");
	}
	if(d == 100)
	{
		printf("4");
	}
	if(d == 11)
	{
		printf("3");
	}
	if(d == 10)
	{
		printf("2");
	}
	if(d == 1)
	{
		printf("1");
	}
	if(d == 0)
	{
		printf("0");
	}
	
	d = 1000 * bin[3] + 100 * bin[2] + 10 * bin[1] + bin[0];

  	if(d == 1111)
	{
		printf("F");
	}
	if(d == 1110)
	{
		printf("E");
	}
	if(d == 1101)
	{
		printf("D");
	}
	if(d == 1100)
	{
		printf("C");
	}
	if(d == 1011)
	{
		printf("B");
	}
	if(d == 1010)
	{
		printf("A");
	}
	if(d == 1001)
	{
		printf("9");
	}
	if(d == 1000)
	{
		printf("8");
	}
	if(d == 111)
	{
		printf("7");
	}
	if(d == 110)
	{
		printf("6");
	}
	if(d == 101)
	{
		printf("5");
	}
	if(d == 100)
	{
		printf("4");
	}
	if(d == 11)
	{
		printf("3");
	}
	if(d == 10)
	{
		printf("2");
	}
	if(d == 1)
	{
		printf("1");
	}
	if(d == 0)
	{
		printf("0");
	}
	printf("\n");
}	



int main()
{
	char oct[20];
	int a;
	printf("Saisir un entier octale:\n");  
	scanf("%[01234567]", oct);
	printf("%s\n", oct);
	a = strlen(oct);
	octal_to_decimal(oct, a);
	octal_to_binary(oct, a);
	octal_to_hexa(oct, a);
	return 0;
}	
	
	
	
	
	
	
	
	
	
