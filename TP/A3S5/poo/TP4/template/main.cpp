//TP4 : template
// Victor Bouvier d'Acher
// Geoffroy Rodriguez
// Mohamed Arezki Meriane

#include <iostream>
#include <ctime>
#include "matrix.h"
using namespace std;

template <typename T>
T** allouer_mat(int taille)			// cree la matrice
{
	int i;
	T** mat = new T*[taille];
	for(i=0; i<taille; i++)
		mat[i] = new T[taille];
	return mat;
}

template <typename T>
void rand_mat(T** mat, int taille)	// affecte aleatoirement les variables de la matrice
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
	float** mat1 = allouer_mat<float>(3);
	// float** mat2 = allouer_mat<float>(3);
	rand_mat<float>(mat1, 3);
	// rand_mat(mat2, 3);
	
	Matrice<float> *matrice1 = new Matrice<float>(3, mat1);		// initialisation par parametre
	Matrice<float> *matrice2 = new Matrice<float>(*matrice1);		// creation de matrice par copie
	Matrice<float> *matrice3 = new Matrice<float>();
	cin >> *matrice3;								// affecte les variables de la matrice par l'utilisateur

	cout << *matrice1;		// affiche la matrice
	cout << *matrice2;
	cout << *matrice3;

	*matrice1 = *matrice3;	// mat3 deviens = a mat1
	cout << *matrice1;
	// cout << *matrice2;
	
	*matrice3 + *matrice2;	// mat1 deviens mat1 + mat2
	cout << *matrice3;

	*matrice2 - *matrice3;	// mat2 deviens mat2 - mat3
	cout << *matrice2;

	// cout << **matrice1;
	*matrice3 * *matrice1;	// mat3 devient le produit matriciel de mat3 et mat1
	cout << *matrice3;

	delete matrice1;
	delete matrice2;
	delete matrice3;

	return 0;
}