// TP11
// Victor Bouvier d'Acher
// Geoffroy Rodriguez
// Mohamed Arezki Meriane

#include <iostream>
#include "carte.h"
using namespace std;

int main()
{
	int** carte = ouvrir_carte();
	afficher_carte(carte);
	int** adj = mat_adj(carte);
	afficher_mat(adj);
	distance(adj, carte, 0);
	
	lib_mat(carte, 11);
	lib_mat(adj, 11);
	return 0;
}
