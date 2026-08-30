#ifndef MATRIX_h
#define MATRIX_h
#include <iostream>
using namespace std;

class Matrice
{
public:
	Matrice();
	Matrice(int t);
	Matrice(int t, int** m) : taille(t), mat(m) {}
	Matrice(Matrice const& matri);
	~Matrice();

	int getTaille() const;
	int** getMat() const;

	void setTaille(int t);
	void setMat(int** m);

	friend ostream& operator<<(ostream& os, Matrice const& matrice);
	friend istream& operator>>(istream& is, Matrice& matrice);

	Matrice& operator+(const Matrice& add);
	Matrice& operator-(const Matrice& sous);
	Matrice& operator*(const Matrice& mult);
	Matrice& operator=(const Matrice& ass);

private:
	int taille;
	int** mat;
};

#endif