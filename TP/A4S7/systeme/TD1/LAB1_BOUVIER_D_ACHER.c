#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int taille_phrase = 1;

void afficher_phrase(char* phrase)
{
	char** words = malloc(sizeof(char*));
	words[0] = malloc(sizeof(char));
 	words[0][0] = '\0';
	int i=0,j=0,k=0;
    	do
        {
                if(phrase[i]!=' ')
		{	
			int nb = strlen(words[j]);
			words[j] = realloc(words[j], sizeof(char)*(nb+2));
                        words[j][k++] = phrase[i];
			words[j][k] = '\0';
		}
		else
                {
			int nb = strlen(words[j]);
			words[j] = realloc(words[j], sizeof(char)*(nb+2));
                        words[j++][k]='\0';
			words = realloc(words, sizeof(char*)*(j+1));
                        words[j] = malloc(sizeof(char));
			
			k=0;
			words[j][k] = '\0';
			
                }
        } while(phrase[i++]!='\0');
        for(i=0;i<j+1;i++)
                printf("%s\n",words[i]);

	for(i=0; i<j+1; i++)
	{
		free(words[i]);
	}
	free(words);
}

int main(void)
{
	char *phrase = malloc(sizeof(char)*taille_phrase);
	printf("Ecriver une phrase\n");
	char c = '\0';
	while(c != '\n')
	{
		if(scanf("%c", &c) != 1)
		{
			printf("saisie d'un caractere inconnu\n erreur\n");
			free(phrase);
			return 1;
		}
		taille_phrase++;
		phrase = realloc(phrase, sizeof(char)*taille_phrase);
		phrase[taille_phrase-2] = c;
		phrase[taille_phrase-1] = '\0';
	}

	//printf("%s\n", phrase);
	
	afficher_phrase(phrase);

	free(phrase);
        return 0;
}

