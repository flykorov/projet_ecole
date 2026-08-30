// TP1 : bataille
// Victor Bouvier d'Acher


#include <iostream>
#include <new>
#include <random>
#include <ctime>
#include "bataille.h"

using namespace std;

int main()
{
	int choix;
	srand(time(NULL));
	int** grille_joueur;	// création des grilles de jeu
	int** grille_ordi;
	bool fin = false;		// bool pour le while 

	grille_ordi = allouer_mat();		// allocation dynamique des matrices
	grille_joueur = allouer_mat();		// evite les erreurs et les oublies de return

	affecter_mat_0(grille_ordi);
	affecter_mat_0(grille_joueur);

	generer_grille_alea(grille_ordi);	// generation au hasard de la grille du joueur
	cout << "voulez vous entrez manuellement une grille ou laisser le hasard le faire?\n";
	cout << " 0 (manuel)     1 (hasard)\n";
	cin >> choix;
	while(choix != 0 && choix != 1)		// choix de rentrer manuelement ou automatiquement la grille du joueur
	{
		cout << "Recommencez\n";
		cin >> choix;
	}
	if(choix == 1)		// genere la grille du joueur en fonction du choix
		generer_grille_alea(grille_joueur);
	else
		entrer_grille_joueur(grille_joueur);

	init_affiche();

	while(!fin)		// debut du jeu
	{
		afficher_grille(grille_ordi, grille_joueur);
		tour_joueur(grille_ordi);
		tour_ordi(grille_joueur);
		fin = verif_fin(grille_ordi);
		if(fin == true)		//verification du gagnant
		{
			cout << "Le gagnant est le joueur\n";
		}else
		{
			fin = verif_fin(grille_joueur);
			if(fin == true)
			{
				cout << "Le gagnant est l'ordi\n";
			}
		}
	}

	lib_mat(grille_ordi);		// liberation des matrices allouer
	lib_mat(grille_joueur);

	return 0;
}