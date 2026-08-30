// TP11
// Victor Bouvier d'Acher
// Geoffroy Rodriguez
// Mohamed Arezki Meriane

#include <iostream>
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