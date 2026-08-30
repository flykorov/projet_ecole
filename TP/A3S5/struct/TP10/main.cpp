// TP10
// Victor Bouvier d'Acher
// Geoffroy Rodriguez
// Mohamed Arezki Meriane

#include <iostream>
#include "parcours.h"
using namespace std;

int main()
{
	int a;
	int** mat1 = creer_matrice_adjacence("1.dat");
	afficher_mat(mat1, 6);
	cout << "SECTION #2 : METHODE DE PARCOURS\n\n";
	do
	{
		cout << "Choisir la methode de parcours (1-largeur/2-profondeur) : ";
		cin >> a;
		cout << endl;
		if(a==1)
			parcours_en_largeur(mat1, 6);
		else if(a==2)
			parcours_en_profondeur(mat1, 6);
	}while(a != 1 && a != 2);
	
	lib_mat(mat1, 6);

	int** mat2 = creer_matrice_adjacence("2.dat");
	afficher_mat(mat2, 17);
	do
	{
		cout << "Choisir la methode de parcours (1-largeur/2-profondeur) : ";
		cin >> a;
		cout << endl;
		if(a==1)
			parcours_en_largeur(mat2, 17);
		else if(a==2)	
			parcours_en_profondeur(mat2, 17);
	}while(a != 1 && a != 2);
	lib_mat(mat2, 17);

	return 0;
}