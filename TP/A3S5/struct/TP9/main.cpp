// TP9
// Victor Bouvier d'Acher
// Geoffroy Rodriguez
// Arezki Meriane 

#include <iostream>
#include "arbreBST.cpp"
using namespace std;

void chargerArbre(AVLTree<int>& arbreAVL);

int main(int argc, char* argv[])
{
	AVLTree<int> arbreAVL;
	chargerArbre(arbreAVL);
	cout << arbreAVL;
	return 0;
}

void chargerArbre(AVLTree<int>& arbreAVL)
{
	int valeurs[] = { 3, 2, 1, 4, 5, 6, 7, 16, 15, 14, 13, 12, 11, 10, 8, 9 };
	int nbValeurs = sizeof valeurs / sizeof * valeurs;
	for (int x = 0; x < nbValeurs; x++)
	{
		arbreAVL.insert(valeurs[x]);
		// cout << arbreAVL << endl;
	}
	
}