#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/unistd.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
	srand(time(NULL));

	if(argc-1<1)
	{
		printf("vous n'avez pas mis d'argument\n");
		return 0;
	}

	char* nom = argv[1];
	strcat(nom, ".xml");

	int fic;
	if((fic=open(nom, O_RDWR|O_CREAT,  00400)) < 0)
	{
		perror("Erreur lors de la création/ouverture du fichier\n");
		return -1;
	}

	if(write(fic, "<VBdA_user>\n", 12) < 0)
	{
		perror("erreur\n");
		return -1;
	}
	write(fic, "\t<VBdA_date>\n\t\t", 15);

	FILE* f = popen("date", "r");
	char d[100] = {0};
	fgets(d, 100, f);
	fclose(f);

	write(fic, d, strlen(d));
	write(fic, "\t</VBdA_date>\n", 14);


	char *utilisateur = getlogin();
    uid_t uid = getuid();
    char u[4];
    sprintf(u, "%d", uid);

	write(fic, "\t<VBdA_owner>\n\t\t", 16);
    write(fic, utilisateur, strlen(utilisateur));
    write(fic, "\n\t</VBdA_owner>\n", 16);

    write(fic, "\t<VBdA_uid>\n\t\t", 14);
    write(fic, u, strlen(u));
    write(fic, "\n\t</VBdA_uid>\n", 14);

    char mdp[11];
    for(int i=0; i<10; i++)
    {
    	mdp[i] = ' ' + rand()%93;
    	if(mdp[i]==62 || mdp[i]==60)
    		mdp[i]++;
    }

    write(fic, "\t<VBdA_mdp>\n\t\t", 14);
    write(fic, mdp, strlen(mdp));
    write(fic, "\n\t</VBdA_mdp>\n", 14);

    write(fic, "</VBdA_user>\n", 13);

	close(fic);


	return 0;
}