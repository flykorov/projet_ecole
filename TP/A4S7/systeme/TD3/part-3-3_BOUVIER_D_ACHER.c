#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/unistd.h>

int main(int argc, char *argv[])
{
	if(argc-1<1)
	{
		printf("vous n'avez pas mis d'argument\n");
		return 0;
	}

	char* nom = argv[1];
	if(access(nom, F_OK) < 0)
	{
		printf("le fichier n'existe pas\n");
		return -1;
	}

	if(access(nom, R_OK) == 0)
	{
		printf("le processus peut lire le fichier\n");
	}

	if(access(nom, W_OK) == 0)
	{
		printf("le processus peut ecrire le fichier\n");
	}

	if(access(nom, X_OK) == 0)
	{
		printf("le processus peut executer le fichier\n");
	}
}