//TP4 : template
// Victor Bouvier d'Acher
// Geoffroy Rodriguez
// Mohamed Arezki Meriane

#include <iostream>
// #include "matrix.h"
using namespace std;

template <typename T>
Matrice<T>::Matrice()
{
	int i, j;
	taille = 3;
	mat = new T*[taille];
	for(i=0; i<taille; i++)
		mat[i] = new T[taille];
	for(i=0; i<taille; i++)
		for(j=0; j<taille; j++)
			mat[i][j] = 0;
}

template <typename T>
Matrice<T>::Matrice(int t)
{
	int i, j;
	taille = t;
	mat = new T*[taille];
	for(i=0; i<taille; i++)
		mat[i] = new T[taille];
	for(i=0; i<taille; i++)
		for(j=0; j<taille; j++)
			mat[i][j] = 0;
}

template <typename T>
Matrice<T>::Matrice(Matrice<T> const& matri)		// copie de la matrice
{
	int i, j;
	taille = matri.getTaille();
	// mat = matri.getMat();
	mat = new T*[taille];
	for(i=0; i<taille; i++)
		mat[i] = new T[taille];
	for(i=0; i<taille; i++)
		for(j=0; j<taille; j++)
			mat[i][j] = matri.mat[i][j];
}

template <typename T>
Matrice<T>::~Matrice()					// libere la matrice
{
	int i;
	for(i=0; i<taille; i++)
		delete[] mat[i];
	delete[] mat;
}

template <typename T>
int Matrice<T>::getTaille() const
{
	return taille;
}

template <typename T>
T** Matrice<T>::getMat() const
{
	return mat;
}

template <typename T>
void Matrice<T>::setTaille(int t)
{
	taille = t;
}

template <typename T>
void Matrice<T>::setMat(T** m)
{
	mat = m;
}

// template <typename T>
// ostream& operator<<(ostream& os, Matrice<T> const & matrice)		// affichage de la matrice
// {
// 	os << "utilisation de Operator<<\n";
// 	os << "-----------------------------------\n";
// 	int i, j;
// 	os << "Affichage de la matrice\n";
// 	for(i=0; i<matrice.getTaille(); i++)
// 	{
// 		T** mat = matrice.getMat();
// 		for(j=0; j<matrice.getTaille(); j++)
// 		{
// 			os << mat[i][j] << " ";
// 		}
// 		os << endl;
// 	}
// 	os << "-----------------------------------\n";
// 	// os << endl;
// 	return os;
// }

// template <typename T>
// istream& operator>>(istream& is, Matrice<T> & matrice)			// affecte les variables de la matrice par l'utilisateur
// {
// 	cout << "utilisation de Operator>>\n";
// 	int i, j;
// 	cout << "entrer " << matrice.taille * matrice.taille<< " chiffres\n";
// 	for(i=0; i<matrice.taille; i++)
// 		for(j=0; j<matrice.taille; j++)
// 			is >> matrice.mat[i][j];
// 	return is;
// }

template <typename T>
Matrice<T>& Matrice<T>::operator+(const Matrice<T> & add)				// additionne deux matrices
{
	if(this == &add)
		return *this;
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

template <typename T>
Matrice<T>& Matrice<T>::operator-(const Matrice<T> & sous)			// soustrait deux matrices
{
	if(this == &sous)
		return *this;
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

template <typename T>
Matrice<T>& Matrice<T>::operator*(const Matrice<T> & mult)			// produit matriciel de deux matrices
{
	if(this == &mult)
		return *this;
	cout << "utilisation de Operator*\n";
	if(taille == mult.taille)
	{
		int i, j, k;
		T a, b;
		int u=0, v=0;
		T mathis[taille][taille];
		for(i=0; i<taille; i++)
		{		
			for(k=0; k<taille; k++)
			{
				b=0;
				for(j=0; j<taille; j++)
				{
					a = mat[i][j] * mult.mat[j][k];
					b += a;
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
			}
		}
	}
	return *this;
}

template <typename T>
Matrice<T>& Matrice<T>::operator=(const Matrice<T> & ass)				// egalise deux matrices
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