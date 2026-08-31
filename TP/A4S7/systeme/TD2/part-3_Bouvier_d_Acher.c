#include <stdio.h>
#include <stdlib.h>     // ajout de la bibliotheque stdlib.h
#include <string.h>

void affichetableau(char** sentence, int nbmot, int max) {

	int i,j;

	for(i=0; i<nbmot; i++) 
    {
        // printf("%s\n", sentence[i]);
		for(j=0; j<strlen(sentence[i]); j++) 
        {
            if(sentence[i][j] != '\0')              // pour eviter les espaces
                printf("%c", sentence[i][j]);       // changer le %s en %c
		}
        printf("\n");           //reviens a la ligne
	}
}

int main() {
    
    char** words;
    char sentence[150];
    int i=0, j=0, k=0, max=0, word=0;
        
    printf("Entrez votre phrase:");
    scanf("%[^\n]", sentence);          // prend une ligne jusqu'au \n (retour chariot)

    for(i=0; i<strlen(sentence); i++) 
    {
        if(sentence[i]==' ') 
        {
            word++;
            if(k>max) 
            {
                max=k;
            }
            k=0;
        }
        k++;

    }

    word++;         // incremente word pour avoir le bon nombre de mots
    words=(char**)malloc(sizeof(char*)*word);
        
    for(i=0;i<word;i++) 
    {
        words[i]=(char*)malloc(sizeof(char)*max);
    }
        
    i=0;
    j=0;
    k=0;
        
    while(sentence[i] != '\0')      //enleve l'incrementation
    {
        if(sentence[i] != ' ') 
        {
            words[j][k++] = sentence[i];
        }else 
        {
            words[j++][k] = '\0';
            k=0;
        }
        i++;                    // incremente a la fin de la boucle
    }
     
    affichetableau(words, word, max);

    	
    for(i=0; i<word; i++)           // libere l'allocation 
    {
	    free(words[i]);
    }
    free(words);

    return 0;
}
