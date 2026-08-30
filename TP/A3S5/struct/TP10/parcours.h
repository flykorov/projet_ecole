// TP10
// Victor Bouvier d'Acher
// Geoffroy Rodriguez
// Mohamed Arezki Meriane

#include <iostream>
#include <list>
#include <iomanip>
#include "fonction.h"
using namespace std;

void chemin_largeur(int nb_sommet, int* d, int* pi)
{
	cout << "SECTION #5\n";
	int a=0;
	do
	{
		if(a>nb_sommet || a<0)
			cout << "Erreur\n";
		cout << "\nChoisir le sommet destination (0-" << nb_sommet << ") : ";
		cin >> a;
	}while(a>nb_sommet || a<0);
	cout << "CHEMIN : " << a;
	if(d[a] != -1)
	{
		while(pi[a] != -1)
		{
			a = pi[a];
			cout << " <- " << a;
		}
		cout << endl;
	}else
	{
		cout << "\nChemin impossible!\n";
	}
}

void parcours_en_largeur(int** adj, int nb_sommet)	// applique l'algo de parcours en largueur
{
	cout << "SECTION #3 : PARCOURS EN LARGEUR\n";

	int sommet=0;
	do
	{
		if(sommet>nb_sommet || sommet<0)
			cout << "Erreur\n";
		cout << "\nChoisir le sommet source (0-" << nb_sommet << ") : ";
		cin >> sommet;
	}while(sommet>nb_sommet || sommet<0);

	int d[nb_sommet];
	int pi[nb_sommet];
	char couleur[nb_sommet];
	list<int> som;
	som.push_back(sommet);
	int i, j;
	for(i=0; i<nb_sommet; i++)
	{
		couleur[i] = 'b';
		d[i] = -1;
		pi[i] = -1;
	}
	d[sommet] = 0;
	couleur[sommet] = 'g';
	while(som.empty() == 0)
	{
		for(i=0; i<nb_sommet; i++)
		{
			if(adj[som.front()][i] == 1)
			{
				if(couleur[i] == 'b')
				{
					couleur[i] = 'g';
					som.push_back(i);
					d[i] = d[som.front()]+1;
					pi[i] = som.front();
				}
			}
		}
		couleur[som.front()]= 'n';
		som.pop_front();
	}

	cout << "\nSECTION #4 : AFFICHAGE\n\n";

	cout << "---------------------------------------------------------\n";
	cout << "SOMMET\tPARENT\tDIST\tCOULEUR\n";
	for(i=0; i<nb_sommet; i++)
	{
		cout << i << "\t";
		cout << pi[i] << "\t";
		cout << d[i] << "\t";
		cout << couleur[i] << endl;
	}
	cout << endl;
	cout << "---------------------------------------------------------\n";
	chemin_largeur(nb_sommet, d, pi);
}

void chemin_profondeur(int nb_sommet, int* d, int* f)
{
	cout << "\nSECTION #5\n\nORDRE DE VISITE\n";
	int i=0, j, dec=0;
	int temps=1;
	while(temps <= nb_sommet*2)
	{
		if(d[i] == temps)
		{
			temps++;
			for(j=0; j<dec; j++)
				cout << "  ";
			cout << i << endl;
			i=0;
			dec++;
		}else if(f[i] == temps)
		{
			temps++;
			dec--;
			for(j=0; j<dec; j++)
				cout << "  ";
			cout << i << endl;
			i=0;
		}else
			i++;
	}
}

void visiteur(int sommet, int nb_sommet, int** adj, int* d, int* pi, int* f, char* couleur, int &temps)
{
	int i;
	couleur[sommet] = 'g';
	d[sommet] = ++temps;
	for(i=0; i<nb_sommet; i++)
	{
		if(adj[sommet][i] == 1)
		{
			if(couleur[i] == 'b')
			{
				pi[i] = sommet;
				visiteur(i, nb_sommet, adj, d, pi, f, couleur, temps);
			}
		}
	}
	couleur[sommet] = 'n';
	f[sommet] = ++temps;
}

void parcours_en_profondeur(int** adj, int nb_sommet)	// applique l'algo de parcours en profondeur
{
	cout << "SECTION #3 : PARCOURS EN PROFONDEUR\n\n";
	int* d = new int[nb_sommet];
	int* pi = new int[nb_sommet];
	int* f = new int[nb_sommet];
	char* couleur = new char[nb_sommet];
	int i, j, temps=0;
	for(i=0; i<nb_sommet; i++)
	{
		couleur[i] = 'b';
		d[i] = -1;
		pi[i] = -1;
		f[i] = -1;
	}

	for(i=0; i<nb_sommet; i++)
		if(couleur[i] == 'b')
			visiteur(i, nb_sommet, adj, d, pi, f, couleur, temps);

	cout << "\nSECTION #4 : AFFICHAGE\n\n";

	cout << "---------------------------------------------------------\n";
	cout << "SOMMET\tPARENT\tDIST\tFIN\tCOULEUR\n";
	for(i=0; i<nb_sommet; i++)
	{
		cout << i << "\t";
		cout << pi[i] << "\t";
		cout << d[i] << "\t";
		cout << f[i] << "\t";
		cout << couleur[i] << endl;
	}
	cout << endl;
	cout << "---------------------------------------------------------\n";


	chemin_profondeur(nb_sommet, d, f);

	delete[] f;
	delete[] couleur;
	delete[] d;
	delete[] pi;
}
