#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string>
#include <string.h>
#include <cstring>
#include <ctime>
#include <time.h>
#include <fstream>
using namespace std;

struct tableau
{
	int pos[8];
	char* nom[9];
	int pid[8];
};

int main()
{
	srand(time(NULL));
	ofstream fichier("historique.txt");
	if(!fichier)
		return -1;

	struct tableau tab;

	char command[] = "ls";
	// const char* argument_list[] = {"ls", "-l", NULL};
	char cat[] = "cat";
	// const char* cati[] = {"cat", "fork.cpp", NULL};
	char pwd[] = "pwd";
	// const char* power[] = {"pwd", NULL};
	char mkdir[] = "mkdir";
	// const char* mk[] = {"mkdir", "test", NULL};
	char rmdir[] = "rmdir";
	// const char* rm[] = {"rmdir", "test", NULL};
	// char** nom_com = {"ls", "cat", "pwd", "mkdir", "rmdir"};
	const char* nom[][5] = {
							{"ls", "-l", NULL},
							{"cat", "fork.cpp", NULL},
							{"pwd", NULL},
							{"mkdir", "test", NULL},
							{"rmdir", "test", NULL}
						  };

	char** nom_com = new char*[6];
	nom_com[0] = command;
	nom_com[1] = cat;
	nom_com[2] = pwd;
	nom_com[3] = mkdir;
	nom_com[4] = rmdir;
	// const char* man = "man";
	// const char* manuel[] = {"man", NULL};
	
	int i, j, k, l, y=0;
	pid_t pid;

	for(i=0; i<100; i++)
	{
		j = rand() % 5;

		

		if(i<7)
		{
			l=i;
		}
		else
		{
			y++;
			l=7;
		}


		if ((pid = fork()) == 0)
		{
			

			int status_code = execvp(nom_com[j] , (char* const*)(&nom[j]));
			if (status_code == -1) 
			{
		      	cout << "Erreur execvp\n";
		      	return -1;
		  	}
			// cout << "bien le bonjour\n";

		}else
		{
			wait(NULL);
			// cout << "bijour\n";

			fichier << i+1 << "\t" << nom_com[j] << "\t" << pid << endl;
			cout << l << endl;
			if(l == 7 && y > 1)
			{
				for(k=0; k<l; k++)
				{
					// cout << "ba\n";
					tab.pos[k] = tab.pos[k+1];
					tab.pid[k] = tab.pid[k+1];
					tab.nom[k] = tab.nom[k+1];
					// cout << tab.pos[k] << "\t" << tab.nom[k] << "\t" << tab.pid[k] << endl;
					// cout << "bo\n";
				}
			}
			// cout << "bi\n";
			tab.pos[l] = i+1;
			// cout << "bou\n";
			tab.pid[l] = pid;
			// cout << "bon\n";
			// strcpy(tab.nom[k], nom_com[k+1]);
			tab.nom[l] = nom_com[j];
			// cout << "bai\n";
			for(k=0; k<l+1; k++)
				cout << tab.pos[k] << "\t" << tab.nom[k] << "\t" << tab.pid[k] << endl;
			// cout << "boi\n";
			// cout << "bu\n";

			// printf("bijour\n");
		}
		
		
	}

	fichier.close();
	delete[] nom_com;
	// status_code = execvp(command , (char* const*)argument_list);

	return 0;
}