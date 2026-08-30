//TP4 : template
// Victor Bouvier d'Acher
// Geoffroy Rodriguez
// Mohamed Arezki Meriane

#ifndef MATRIX_h
#define MATRIX_h
#include <iostream>
using namespace std;

template <typename T>
class Matrice
{
public:
	Matrice();
	Matrice(int t);
	Matrice(int t, T** m) : taille(t), mat(m) {}
	Matrice(Matrice const& matri);
	virtual ~Matrice();

	int getTaille() const;
	T** getMat() const;

	void setTaille(int t);
	void setMat(T** m);

	friend ostream& operator<<(ostream& os, Matrice const& matrice)
	{
		os << "utilisation de Operator<<\n";
		os << "-----------------------------------\n";
		int i, j;
		os << "Affichage de la matrice\n";
		for(i=0; i<matrice.getTaille(); i++)
		{
			T** mat = matrice.getMat();
			for(j=0; j<matrice.getTaille(); j++)
			{
				os << mat[i][j] << " ";
			}
			os << endl;
		}
		os << "-----------------------------------\n";
		// os << endl;
		return os;
	}

	friend istream& operator>>(istream& is, Matrice<T> & matrice)
	{
		cout << "utilisation de Operator>>\n";
		int i, j;
		cout << "entrer " << matrice.taille * matrice.taille<< " chiffres\n";
		for(i=0; i<matrice.taille; i++)
			for(j=0; j<matrice.taille; j++)
				is >> matrice.mat[i][j];
		return is;
	}

	Matrice& operator+(const Matrice& add);
	Matrice& operator-(const Matrice& sous);
	Matrice& operator*(const Matrice& mult);
	Matrice& operator=(const Matrice& ass);

private:
	int taille;
	T** mat;
};

#include "matrix.tpp"
#endif