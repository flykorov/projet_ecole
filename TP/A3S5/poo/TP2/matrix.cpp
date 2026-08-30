#include <iostream>
#include "matrix.h"
using namespace std;


Matrice::Matrice()
{
	int i, j;
	taille = 2;
	mat = new int*[taille];
	for(i=0; i<taille; i++)
		mat[i] = new int[taille];
	for(i=0; i<taille; i++)
		for(j=0; j<taille; j++)
			mat[i][j] = 0;
}

Matrice::Matrice(int t)
{
	int i, j;
	taille = t;
	mat = new int*[taille];
	for(i=0; i<taille; i++)
		mat[i] = new int[taille];
	for(i=0; i<taille; i++)
		for(j=0; j<taille; j++)
			mat[i][j] = 0;
}

Matrice::Matrice(Matrice const& matri)		// copie de la matrice
{
	int i, j;
	taille = matri.taille;
	mat = new int*[taille];
	for(i=0; i<taille; i++)
		mat[i] = new int[taille];
	for(i=0; i<taille; i++)
		for(j=0; j<taille; j++)
			mat[i][j] = matri.mat[i][j];
}

Matrice::~Matrice()					// libere la matrice
{
	int i;
	for(i=0; i<taille; i++)
		delete[] mat[i];
	delete[] mat;
}

int Matrice::getTaille() const
{
	return taille;
}

int** Matrice::getMat() const
{
	return mat;
}

void Matrice::setTaille(int t)
{
	taille = t;
}

void Matrice::setMat(int** m)
{
	mat = m;
}

ostream& operator<<(ostream& os, Matrice const& matrice)		// affichage de la matrice
{
	os << "utilisation de Operator<<\n";
	os << "-----------------------------------\n";
	int i, j;
	os << "Affichage de la matrice\n";
	for(i=0; i<matrice.taille; i++)
	{
		for(j=0; j<matrice.taille; j++)
		{
			os << matrice.mat[i][j] << " ";
		}
		os << endl;
	}
	os << "-----------------------------------\n";
	// os << endl;
	return os;
}

istream& operator>>(istream& is, Matrice& matrice)			// affecte les variables de la matrice par l'utilisateur
{
	cout << "utilisation de Operator>>\n";
	int i, j;
	cout << "entrer " << matrice.taille * matrice.taille<< " chiffres\n";
	for(i=0; i<matrice.taille; i++)
		for(j=0; j<matrice.taille; j++)
			is >> matrice.mat[i][j];
	return is;
}

Matrice& Matrice::operator+(const Matrice& add)				// additionne deux matrices
{
	cout << "utilisation de Operator+\n";
	if(taille == add.taille)
	{
		int i, j;
		for(i=0; i<taille; i++)
			for(j=0; j<taille; j++)
				mat[i][j] += add.mat[i][j];
	}
	return *this;
}

Matrice& Matrice::operator-(const Matrice& sous)			// soustrait deux matrices
{
	cout << "utilisation de Operator-\n";
	if(taille == sous.taille)
	{
		int i, j;
		for(i=0; i<taille; i++)
			for(j=0; j<taille; j++)
				mat[i][j] -= sous.mat[i][j];
	}
	return *this;
}

// Matrice& Matrice::operator*(const Matrice& mult)
// {
// 	if(taille == mult.taille)
// 	{
// 		int i, j;
// 		for(i=0; i<taille; i++)
// 		{
// 			for(j=0; j<taille; j++)
// 			{
// 				mat[i][j] *= mult.mat[i][j];
// 			}
// 		}
// 	}
// 	return *this;
// }

Matrice& Matrice::operator*(const Matrice& mult)			// produit matriciel de deux matrices
{
	cout << "utilisation de Operator*\n";
	if(taille == mult.taille)
	{
		int i, j, k, a, b, u=0, v=0;
		int mathis[taille][taille];
		for(i=0; i<taille; i++)
		{		
			for(k=0; k<taille; k++)
			{
				b=0;
				for(j=0; j<taille; j++)
				{
					a = mat[i][j] * mult.mat[j][k];
					b += a;
					// cout << i << " " << j << endl << a << endl << b << endl;
				}
				mathis[u][v] = b;
				v++;
				if(v%taille == 0)
				{
					v=0;
					u++;
				}
			}
		}
		for(i=0; i<taille; i++)
		{
			for(j=0; j<taille; j++)
			{
				mat[i][j] = mathis[i][j];
				// cout << mat[i][j] << " " << mathis[i][j] << " ";
			}
			// cout << endl;
		}
	}
	return *this;
}

Matrice& Matrice::operator=(const Matrice& ass)				// egalise deux matrices
{
	cout << "utilisation de Operator=\n";
	if(taille == ass.taille)
	{
		int i, j;
		for(i=0; i<taille; i++)
			for(j=0; j<taille; j++)
				mat[i][j] = ass.mat[i][j];
	}
	return *this;
}