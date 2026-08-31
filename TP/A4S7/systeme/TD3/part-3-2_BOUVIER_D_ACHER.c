#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <stdint.h>

void convertion(struct stat buffer, char* nom)
{
	printf("date de création du fichier : %s", ctime(&buffer.st_mtime));
}

int main(int argc, char *argv[])
{
	if(argc-1<1)
	{
		printf("vous n'avez pas mis d'argument\n");
		return 0;
	}
	char* nom = argv[1];
	struct stat buffer;
	
	if(stat(nom, &buffer) < 0)
	{
		perror("Erreur dans stat\n");
		return -1;
	}

	printf("numero inode: %ju\n", (uintmax_t) buffer.st_ino);
	convertion(buffer, nom);

	return 0;
}