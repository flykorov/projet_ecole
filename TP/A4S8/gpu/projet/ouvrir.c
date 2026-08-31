#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char BYTE;

void ouvrir(char* nom)
{
	FILE* fic = fopen(nom, "r");

	char temp;
	int nb_mot = 100;
	char ligne[100][100];
	char mot[100];

	bool continuer = true; 
	while(continuer)
	{
		
		for(int i=0; i<100; i++)
		{

			if(fgets(mot, sizeof(mot), fic) == NULL)
			{
				continuer = false;
				nb_mot = i;
				break;
			}else
			{
				int m=0;
				while(mot[m] != '\n')
				{
					ligne[i][m] = mot[m];
					m++;
				}
				ligne[i][m]='\0';
			}
			
			
		}

		for(int i=0; i<nb_mot; i++)
		{
			printf("%s\n", ligne[i]);
		}
		break;
	}
}

int main()
{
	ouvrir("rockyou.txt");
}



// for(int j=0; j<100; j++)
			// {
			// 	temp = fgetc(fic);
			// 	if(temp != EOF)
			// 	{
			// 		if(temp != '\n')
			// 		{
			// 			ligne[i][j] = temp;
				
			// 		}else
			// 		{
			// 			break;
			// 		}
			// 	}else
			// 	{
			// 		continuer = false;
			// 		nb_mot = i;
			// 		break;
			// 	}
			// }