// TP11
// Victor Bouvier d'Acher
// Geoffroy Rodriguez
// Mohamed Arezki Meriane

#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <iterator>
#include "memoire.h"
using namespace std;

int** ouvrir_carte()
{
	ifstream fic("voyage.dat");
	int** mat = allouer_mat(11);
	int i, j;
	for(i=0; i<11; i++)
	{
		for(j=0; j<11; j++)
		{
			int a;
			fic >> a;
			mat[i][j] = a;
		}
	}

	return mat;
}

void afficher_carte(int** mat)	// affichage de la carte
{
	char lettre;
	int i, j;

	cout << "-------------------------------------------\n\t ";
	
	for(lettre='A'; lettre<'L'; lettre++)
	{
		cout << lettre << "  ";
	}
	cout << endl << endl;

	for(i=0, lettre='A'; i<11; i++, lettre++)
	{
		cout << lettre << "\t";
		for(j=0; j<11; j++)
		{
			printf("%2d ", mat[i][j]);
		}
		cout << endl;
	}

	cout << "-------------------------------------------\n";
}

void afficher_mat(int** mat)
{
	int i, j;
	cout << "\t";
	for(i=0; i<11; i++)
		cout << i << " ";
	cout << endl << endl;
	for(i=0; i<11; i++)
	{
		cout << i << "\t";
		for(j=0; j<11; j++)
		{
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int** mat_adj(int** carte)
{
	int** mat = allouer_mat(11);
	int i, j;
	for(i=0; i<11; i++)
		for(j=0; j<11; j++)
			if(carte[i][j] != 0)
				mat[i][j] = 1;
	return mat;
}

char affiche_lettre(int lettre)		// choisi la bonne lettre a afficher
{
	switch(lettre)
	{
		case 0 : return 'A';
			break;
		case 1 : return 'B';
			break;
		case 2 : return 'C';
			break;
		case 3 : return 'D';
			break;
		case 4 : return 'E';
			break;
		case 5 : return 'F';
			break;
		case 6 : return 'G';
			break;
		case 7 : return 'H';
			break;
		case 8 : return 'I';
			break;
		case 9 : return 'J';
			break;
		case 10 : return 'K';
			break;
	}
	return '1';
}

int extraire_min(vector<int> &F, vector<int> &C, int* d)		// extrait le minimum 
{
	int res=10000, del=-1;
	if(C.empty() == 1)					// si les sommet deja visite est vide on prend le premier chiffre
	{
		res = F.front();
		F.erase(F.begin());
	}else if(F.empty() == 0)
	{
		int i, j=0, min = 10000;
		for(i=0; i<F.size(); i++)		// extrait le minimum
		{
			if(min >= d[F[i]])
			{
				min = d[F[i]];
				res = F[i];
				del = i;
			}

		}
		vector<int>::iterator it;
		for(i=0, it=F.begin(); i<del; i++, it++);		// supprime le minimum dans F

		F.erase(it);
	}
	return res;
}

void distance(int** adj, int** carte, int source)
{
	int i, j, u=-1;
	int d[11], p[11];
	vector<int> F;
	vector<int> C;
	F.push_back(source);
	for(i=0; i<11; i++)			// initialise les tableaux et vector
	{
		d[i] = 1000000;
		p[i] = -1;
		if(F.front() != i)
			F.push_back(i);
	}
	d[source] = 0;
	while(F.empty() == 0)		// tant que tout les points n'ont pas ete visite 
	{
		u = extraire_min(F, C, d);
		C.push_back(u);
		cout << "Extraction " << affiche_lettre(u) << endl;
		for(i=0; i<11; i++)
		{
			if(carte[u][i] != 0)
			{
				cout << "Relachement de " << affiche_lettre(i) << endl;
				cout << endl;
				if(d[i] > d[u] + carte[u][i])
				{
					cout << "d[" << i << "] = " << d[i] << " --> " <<  d[u] + carte[u][i] << endl;
					cout << "p[" << i << "] = " << p[i] << " --> " << u << endl;
					d[i] = d[u] + carte[u][i];
					p[i] = u;
				}
			}
		}
	}
	cout << "LETTRE\tDIST\tPARENT\t\n";
	for(i=0; i<11; i++)		// affichage des resultats
	{
		cout << affiche_lettre(i) << "\t" << d[i] << "\t" << p[i] << endl;
	}
}