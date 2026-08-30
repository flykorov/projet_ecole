// TP10
// Victor Bouvier d'Acher
// Geoffroy Rodriguez
// Mohamed Arezki Meriane

#include <iostream>
#include <fstream>
using namespace std;

int** allouer_mat(int n)
{
	int i, j;
	int** mat;
	mat = new int*[n];
	for(i=0; i<n; i++)
	{
		mat[i] = new int[n];
	}
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			mat[i][j] = 0;

	return mat;
}

void lib_mat(int** mat, int n)
{
	int i;
	for(i=0; i<n; i++)
		delete[] mat[i];
	delete[] mat;
}

int nb_ligne(string nom_fic)
{
	ifstream lec(nom_fic);
	string a;
	int res=0;
	while(getline(lec, a))
		res++;
	return res-1;
}

int** creer_matrice_adjacence(string nom_fic)
{
	cout << "SECTION #1 : CHARGEMENT DE LA LISTE D'ADJACENCE\n\n";
	int nb_l = nb_ligne(nom_fic);
	ifstream lec(nom_fic);
	int taille, i, j, a, b;
	lec >> taille;
	int** mat = allouer_mat(taille);
	cout << "---------------------------------------------------------\n";
	cout << "Source\tDestination\n";
	for(i=0; i<nb_l; i++)
	{
		lec >> a >> b;
		cout << a << "\t" << b << endl;
		mat[a][b] = 1;
	}
	cout << "---------------------------------------------------------\n";
	lec.close();
	return mat;
}

void afficher_mat(int** mat, int taille)
{
	cout << "SECTION #1 : AFFICHAGE DE LA MATRICE D'ADJACENCE\n\n";
	int i, j;
	cout << "---------------------------------------------------------\n";
	cout << "\t";
	for(i=0; i<taille; i++)
		cout << i << " ";
	cout << endl << endl;
	for(i=0; i<taille; i++)
	{
		cout << i << "\t";
		for(j=0; j<taille; j++)
		{
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
	cout << "---------------------------------------------------------\n";
	cout << endl;
}