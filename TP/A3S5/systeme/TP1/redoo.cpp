// TP1
// Victor Bouvier d'Acher
// Geoffroy Rodriguez
// Mohamed Arezki Meriane

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
#include <vector>
using namespace std;

struct tableau		// structure de donnee qui va enregistrer les differentes donnees (position, pid, nom) et va le mettre dans historique
{
	vector<int> pos;
	vector<vector<string>> nom;
	vector<int> pid;
};

int choix_nom_colonne(int taille, int num)		// numero de colonne du vecteur nom_fic pour ouvrir le bon fichier
{
	int i, sous;
	switch(taille)
	{
		case 100:
			i=1;
			sous = 50;
			break;
		case 500:
			i=4;
			sous = 100;
			break;
		case 1000:
			taille += 200;
			i=7;
			sous = 150;
			break;
		default:
			return 0;
	} 
	while(taille-sous > num)
	{
		taille -= sous;
		i--;
	}
	return i;
}

int choix_nom_ligne(int taille)		// numero de ligne du vecteur nom_fic pour ouvrir le bon fichier
{
	int i;
	switch(taille)
	{
		case 100: i=0;
			break;
		case 500: i=1;
			break;
		case 1000: i=2;
			break;
		default:
			return 3;
	}
	return i;
}
		
void ecrire_fichier(struct tableau tab, vector<vector<string>> nom, int taille, int num)		// ecriture dans le fichier
{
	int arret=0, i, j, u, v;
	u = choix_nom_ligne(taille);			// fonction pour choisir le bon nom de fichier
	v = choix_nom_colonne(taille, num);		// de meme
	ofstream fichier(nom[u][v]);
	if(!fichier)
		exit(-1);
	if(tab.pid.size()>100)					// choisi le nombre de charactere a afficher
		arret = 100;
	else
		arret = tab.pid.size();

	for(i=0; i<arret; i++)					// insert dans le fichier l'historique
	{
		fichier << tab.pos[i] << "\t";
		for(j=0; j<tab.nom[i].size(); j++)
			fichier << tab.nom[i][j] << " ";
		fichier << "\t" << tab.pid[i] << endl;
	}	

	fichier.close();
}

int main()
{
	srand(time(NULL));		// le hasard
	int i, j=0, y=0, k, l=0, m, arret=0, taille;
	pid_t pid;
	struct tableau tab;
	vector<vector<string>> nom_fic {	//pour le nom du fichier a ouvrir
		{"historique/100/historique1_50.txt", "historique/100/historique1_100.txt"},
		{"historique/500/historique2_100.txt", "historique/500/historique2_200.txt", "historique/500/historique2_300.txt", "historique/500/historique2_400.txt", "historique/500/historique2_500.txt"},
		{"historique/1000/historique3_150.txt", "historique/1000/historique3_300.txt", "historique/1000/historique3_450.txt", "historique/1000/historique3_600.txt", "historique/1000/historique3_750.txt", "historique/1000/historique3_900.txt", "historique/1000/historique3_1000.txt"},
		{"historique/historique.txt"}
	};
	cin >> taille;

	while(true)
	{
		bool att = true;
		char command[128];
		cout << "d'Acher-Rodriguez-Meriane<";
		vector<string> temp;
		cin.getline(command, 128);
		if(strlen(command) != 0)
		{
			if(strcmp(command, "exit") == 0 || strcmp(command, "stop") == 0)		// arret du programme 
			{
				cout << "\n\nNombre de commandes entrer : " << j << endl;
				return 0;
			}
			if(strcmp(command, "historique") == 0)			// affiche l'historique des 8 dernieres commande
			{
				if(tab.nom.size()>8)						// si il y a eu moins de 8 commandes affichera les 8-n premiere commande
					arret = 8;
				else
					arret = tab.nom.size();
				for(k=0; k<arret; k++)
				{
					cout << tab.pos[k] << "\t";
					for(m=0; m<tab.nom[k].size(); m++)
					{
						cout << tab.nom[k][m] << " ";
					}
					cout << "\t" << tab.pid[k] << endl;
				}
				// sleep(1);
			}else
			{

				vector<char*> com;
				char* prog = strtok(command, " ");
				char* tmp = prog;

				while(tmp != NULL)
				{
					if(strcmp(tmp, "&") == 0)		// pour le background
					{
						att = false;
						tmp = strtok(NULL, " ");
					}else
					{
						com.push_back(tmp);
						tmp = strtok(NULL, " ");
					}
				}

				char** nom = new char*[com.size()+1];

				for(i=0; i<com.size(); i++)
					nom[i] = com[i];

				nom[com.size()] = NULL;
				
				if(prog[0] == '.')
				{
					system(com[0]);
				}else
				{
					pid = fork();
					if(pid < 0)
					{
						perror("Could not fork\n");
						return -1;
					}else if(pid == 0)
					{
						execvp(prog, nom);			// lance la commande
					}else
					{
						if(att)						// verifie si la commande est en background ou feroground
							if(waitpid(pid, 0, 0) < 0)
								return -1;
						string affect;
						tab.pos.insert(tab.pos.begin(), j+1);			// copie les caracteristique dans ma structure de donnee pour l'historique
						tab.pid.insert(tab.pid.begin(), pid);			// ~~~~
						for(k=0; k<com.size(); k++)
						{
							affect = com[k];
							temp.push_back(affect);
						}
						tab.nom.insert(tab.nom.begin(), temp);			// ~~~~
						ecrire_fichier(tab, nom_fic, taille, j);		// ecrit dans le fichier
						j++;
					}
					com.clear();
					temp.clear();
					cin.clear();
					att = true;
					delete[] nom;
				}
			}
		}
	}
	return 0;
}
