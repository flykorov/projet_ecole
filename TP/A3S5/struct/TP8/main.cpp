// TP8
// Victor Bouvier d'Acher
// Geoffroy Rodriguez
// Mohamed Arezki Meriane

#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include "Prisme.h"
#include "arbreBST.cpp"

using namespace std;

void chargerPrismes(BinarySearchTree<Prisme>& prismes);
void supprimerPiresCas(BinarySearchTree<Prisme>& prismes);
Prisme creerRecherche();
void rechercherPrisme(BinarySearchTree<Prisme>& prismes, Prisme prismeRecherche);
void rechercherPrisme(BinarySearchTree<Prisme>& prismes);
void imprimerPrismes(BinarySearchTree<Prisme>& prismes);

int main(int argc, char *argv[])
{
	BinarySearchTree<Prisme> prismes;
	chargerPrismes(prismes);

	cout << "----------------------------------------------------" << endl;
	cout << "ETAPE #1 : Impression de l'arbre dans un fichier" << endl;
	cout << "----------------------------------------------------" << endl;
	imprimerPrismes(prismes);

	cout << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "ETAPE #2 : Recherche d'une valeur" << endl;
	cout << "----------------------------------------------------" << endl;
	rechercherPrisme(prismes);

	cout << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "ETAPE #3 : Suppression des pires cas" << endl;
	cout << "----------------------------------------------------" << endl;
	supprimerPiresCas(prismes);

	cout << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "ETAPE #4 : Recherche du meilleur cas selon des criteres" << endl;
	cout << "----------------------------------------------------" << endl;
	rechercherPrisme(prismes, creerRecherche());

	prismes.~BinarySearchTree();
    return EXIT_SUCCESS;
}

/* 
	A FAIRE :	Charger tous les prismes a partir du fichier "prismes.dat"
				Inserer dans l'arbre dans l'ordre de lecture
*/
void chargerPrismes(BinarySearchTree<Prisme>& prismes)
{
	int i, lon, lar, pro;
	string nom;
	ifstream aff("prismes.dat");
	for(i=0; i<12; i++)
	{
		aff >> nom;
		aff >> lon;
		aff >> lar;
		aff >> pro;
		Prisme pri(nom, lar, lon, pro);
		prismes.insert(pri);
	}
	aff.close();
}

/* 
	A FAIRE :	Completer la surcharge de l'operateur << dans l'arbre afin d'afficher tous les prismes en ordre croissant de volume dans le fichier
				(Refererence : methode parcours dans la theorie)
*/
void imprimerPrismes(BinarySearchTree<Prisme>& prismes)
{
	ofstream out ("prismes.txt");
	out << prismes;
	out.close();
}

/* 
	A FAIRE :	Supprime les pires cas de l'arbre
				Attention de ne pas supprimer plus de prismes que ceux contenus dans l'arbre!!!
*/
void supprimerPiresCas(BinarySearchTree<Prisme>& prismes)
{
	int i, nb_pire;
	cout << "Combien de pires cas doivent etre supprimes? ";
	cin >> nb_pire;
	for(i=0; i<nb_pire; i++)
	{
		auto t = prismes.findMin();
		cout << t;
		prismes.remove(t);
	}
}

/* 
	A FAIRE :	Recherche le MEILLEUR prisme qui correspond aux criteres minimums de la recherche
				Si le meilleur prisme ne correspond pas, on passe au meilleur suivant
				Si il correspond, on l'affiche
				Attention de ne pas planter si on vide completement l'arbre  (vos criteres sont trop eleves !??!)
*/
void rechercherPrisme(BinarySearchTree<Prisme>& prismes, Prisme prismeRecherche)
{
	int i, nb_meilleur;
	bool verif = true;
	while(verif)
	{
		Prisme t = prismes.findMax();
		if(t.getProfondeur() == -1)
		{
			cout << "Le prisme avec le profil n'existe pas\n";
			prismes.remove(t);
			return;
		}
		if(prismeRecherche.getLargeur() == 0)	// on cherche pour chaque caractéristique
		{
			if(prismeRecherche.getLongueur() == 0)
			{
				if(prismeRecherche.getProfondeur() == 0)
				{
					verif = false;
					cout << "aucun criteres de recherche\n";
				}else
				{
					if(prismeRecherche.getProfondeur() <= t.getProfondeur())
					{
						verif = false;
						cout << t;
					}else
					{
						prismes.remove(t);
					}
				}
			}else
			{
				if(prismeRecherche.getProfondeur() == 0)
				{
					if(prismeRecherche.getLongueur() <= t.getLongueur())
					{
						verif = false;
						cout << t;
					}else
					{
						prismes.remove(t);
					}
				}else
				{
					if(prismeRecherche.getProfondeur() <= t.getProfondeur() && prismeRecherche.getLongueur() <= t.getLongueur())
					{
						verif = false;
						cout << t;
					}else
					{
						prismes.remove(t);
					}
				}
			}
		}else
		{
			if(prismeRecherche.getLongueur() == 0)
			{
				if(prismeRecherche.getProfondeur() == 0)
				{
					if(prismeRecherche.getLargeur() <= t.getLargeur())
					{
						verif = false;
						cout << t;
					}else
					{
						prismes.remove(t);
					}
				}else
				{
					if(prismeRecherche.getProfondeur() <= t.getProfondeur() && prismeRecherche.getLargeur() && t.getLargeur())
					{
						verif = false;
						cout << t;
					}else
					{
						prismes.remove(t);
					}
				}
			}else
			{
				if(prismeRecherche.getProfondeur() == 0)
				{
					if(prismeRecherche.getLongueur() <= t.getLongueur() && prismeRecherche.getLargeur() <= t.getLargeur())
					{
						verif = false;
						cout << t;
					}else
					{
						prismes.remove(t);
					}
				}else
				{
					if(prismeRecherche.getProfondeur() <= t.getProfondeur() && prismeRecherche.getLongueur() <= t.getLongueur() && prismeRecherche.getLargeur() <= t.getLargeur())
					{
						verif = false;
						cout << t;
					}else
					{
						prismes.remove(t);
					}
				}
			}
		}
	}
}	

/* 
	A FAIRE :	Recherche d'un prisme par VOLUME
				Attention de valider les valeurs possibles de la recherche!!!
*/
void rechercherPrisme(BinarySearchTree<Prisme>& prismes)
{
	int volume;
	cout << "Entrer un volume a rechercher (valeur positive exacte) : ";
	do
	{
		cin >> volume;
		if(volume < 0)
			cout << "Volume invalide. valeur positive seulement\n";
	}while(volume < 0);
	Prisme bidon("RECHERCHE", volume, 1, 1);		// variable temp
	if(prismes.contains(bidon))
		cout << "Ce profil existe bien\n";
	else
		cout << "Un prisme avec le profil demande n'existe pas\n";

}

// Celle la est complete!
Prisme creerRecherche()
{
	Prisme p("RECHERCHE", 0, 0, 0);
	int valeur;

	cout << "Entrer vos critères de recherche  (0 = aucun)" << endl;
	cout << "  Entrer la largeur minimum : ";
	cin >> valeur;
	p.setLargeur(valeur);

	cout << "  Entrer la longueur minimum : ";
	cin >> valeur;
	p.setLongueur(valeur);

	cout << "  Entrer la profondeur minimum : ";
	cin >> valeur;
	p.setProfondeur(valeur);

	return p;
}
