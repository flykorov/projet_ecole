#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
// #include <sys/types.h>
// #include <sys/sysmacros.h>
#include <stdint.h>

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

	return 0;
}