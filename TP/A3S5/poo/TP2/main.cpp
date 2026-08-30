//TP2 : surcharge
// Victor Bouvier d'Acher
// Geoffroy Rodriguez
// Mohamed Arezki Meriane

#include <iostream>
#include <ctime>
#include "matrix.h"
using namespace std;

int** allouer_mat(int taille)			// cree la matrice
{
	int i;
	int** mat = new int*[taille];
	for(i=0; i<taille; i++)
		mat[i] = new int[taille];
	return mat;
}

void rand_mat(int** mat, int taille)	// affecte aleatoirement les variables de la matrice
{
	int i, j, a;
	for(i=0; i<taille; i++)
	{
		for(j=0; j<taille; j++)
		{
			a = rand() % 9;
			mat[i][j] = a;
		}
	}
}

int main()
{
	cout << "-----------------------------------\n";
	srand(time(NULL));
	int i, j;
	int** mat1 = allouer_mat(3);
	int** mat2 = allouer_mat(3);
	rand_mat(mat1, 3);
	rand_mat(mat2, 3);
	
	Matrice* matrice1 = new Matrice(3, mat1);		// initialisation par parametre
	Matrice* matrice2 = new Matrice(*matrice1);		// creation de matrice par copie
	Matrice* matrice3 = new Matrice(3);
	cin >> *matrice3;								// affecte les variables de la matrice par l'utilisateur

	cout << *matrice1;		// affiche la matrice
	cout << *matrice2;
	cout << *matrice3;

	*matrice3 = *matrice1;	// mat3 deviens = a mat1
	cout << *matrice3;
	
	*matrice1 + *matrice2;	// mat1 deviens mat1 + mat2
	*matrice2 - *matrice3;	// mat2 deviens mat2 - mat3
	// cout << *matrice1;
	*matrice3 * *matrice1;	// mat3 devient le produit matriciel de mat3 et mat1
	
	cout << *matrice1;
	cout << *matrice2;
	cout << *matrice3;

	delete matrice1;		// libere les matrices
	delete matrice2;
	delete matrice3;

	return 0;
}