// TP4
// Victor Bouvier d'Acher
// Geoffroy Rodriguez
// Mohamed Arezki Meriane
//
// le tp a ete fait a 3 puisque arezki est arrive tardivement a l'uqac
// en effet il est arriver le 3 octobre a Chicoutimi

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <iterator>
#include "pixel.h"
using namespace std;

void genererPixels(vector<Pixel>& v);
int menu();
void afficherPixels(vector<Pixel>& v);
void afficherOccurences(vector<Pixel>& v);
void rechercherPixel(vector<Pixel>& v);
void modifierTeinte(vector<Pixel>& v);
void insererPixel(vector<Pixel>& v);

int main()
{
	vector<Pixel> v;
	int choix = -1;
	srand(time(NULL));

	genererPixels(v);
	while(choix != 0)
	{
		choix = menu();
		switch(choix)
		{
			case 0 : cout << "fermeture du programme\n";
			case 1 : afficherPixels(v);
					 break;
			case 2 : afficherOccurences(v);
					 break;
			case 3 : rechercherPixel(v);
					 break;
			case 4 : modifierTeinte(v);
					 break;
			case 5 : insererPixel(v);
					 break;
			default : cout << "erreur lors de la prise de valeur\n\n";
		}
	}
	// fuite de m�moire ici mais ne pas consid�rer pour ce travail
	return 0;
}

int menu()	// affichage des different choix possible
{
	int choix = -1;

	cout << "*** MENU ***" << endl;
	cout << " 0 - Quitter" << endl;
	cout << " 1 - Afficher les pixels" << endl;
	cout << " 2 - Afficher les occurences" << endl;
	cout << " 3 - Rechercher un pixel" << endl;
	cout << " 4 - Modifier une teinte" << endl;
	cout << " 5 - Inserer un nouveau pixel" << endl;
	cout << " Votre choix? ";

	cin >> choix;		// controle de la valeur mise dans le switch
	cout << endl;

	return choix;
}

///////  SECTION A COMPLETER  /////////

/*
	Demande le nombre de pixels
	G�n�rer (au hasard) et ajoute n pixels dans le vecteur
	Consignes
	- Utiliser la m�thode "push_back" pour l'insertion
*/
void genererPixels(vector<Pixel>& v)
{
	int i, nb_pix, rouge, bleu, vert, position;
	cout << "*** GENERATIONS DES PIXELS ***" << endl;
	cout << " Nombre de pixels? ";
	cin >> nb_pix;
	for(i=0; i<nb_pix; i++)
	{
		rouge = rand() % 256;	// rand() choisi un chiffre aleatoire
		bleu = rand() % 256;
		vert = rand() % 256;
		Pixel pixel(rouge, vert, bleu);
		v.push_back(pixel);		// insere le pixel a la fin
	}
}


/*
	Affiche tous les pixels du vecteur
	Consignes
	- Utiliser un it�rateur constant
	- Ne pas utiliser les op�rateurs []
*/
void afficherPixels(vector<Pixel>& v)
{
	cout << "*** AFFICHER LES PIXELS ***" << endl;
	vector<Pixel>::const_iterator cit;	// cit pour constant iterator
	for(cit = v.begin(); cit < v.end(); cit++)
		cout << " " << *cit << endl;	// afficher grace a l'operateur <<
	cout << endl;
}

/*
	Compte et affiche le nombre de couleurs PURES
		(255, 0, 0), (0, 255, 0) et (0, 0, 255)
	Consignes
	- Utiliser un it�rateur constant
	- Ne pas utiliser les op�rateurs []
*/
void afficherOccurences(vector<Pixel>& v)
{
	int red=0, green=0, blue=0;
	cout << "*** AFFICHER LES OCCURENCES ***" << endl;
	vector<Pixel>::const_iterator cit;
	const Pixel rouge(255, 0, 0);
	const Pixel vert(0, 255, 0);
	const Pixel bleu(0, 0, 255);
	for(cit = v.begin(); cit < v.end(); cit++)		// compte le nombre de rouge, bleu et vert
	{
		if(*cit == rouge)
			red++;
		if(*cit == vert)
			green++;
		if(*cit == bleu)
			blue++;
	}
	cout << " Nombre de rouge : " << red << endl;		// les affiches
	cout << " Nombre de vert : " << green << endl;
	cout << " Nombre de bleu : " << blue << endl << endl;
}

/*
	Recherche une couleur en particulier
	On affiche la position de chaque pixel trouv� correspondant � la recherche
	Consignes
	- Ne pas utiliser d'it�rateur
	- Utiliser les op�rateurs []
*/
void rechercherPixel(vector<Pixel>& v)
{
	int rouge, vert, bleu, i;
	cout << "*** RECHERCHE UN PIXEL ***" << endl;
	cout << " Rouge (0-255)? ";
	cin >> rouge;
	while(rouge < 0 || rouge > 255)		// verifie les entrer
	{
		cout << "Reesayer : ";
		cin >> rouge;
	}
	cout << " Vert (0-255)? ";
	cin >> vert;
	while(vert < 0 || vert > 255)
	{
		cout << "Reesayer : ";
		cin >> vert;
	}
	cout << " Bleu (0-255)? ";
	cin >> bleu;
	while(bleu < 0 || bleu > 255)
	{
		cout << "Reesayer : ";
		cin >> bleu;
	}
	Pixel pixel(rouge, vert, bleu);		// cree un nouveau pixel

	for(i=0; i<v.size(); i++)
	{
		if(v[i] == pixel)				// compare le nouveau pixel au vecteur de pixel
			cout << " POSITION : " << i << endl;
	}
	cout << endl;
}

/*
	Choisir une couleur (r/v/b)
	Choisir la quantit� de "couleur" � ajouter
	Pour chaque pixel, ajouter la quantit� de couleur
	Consignes
	- Utiliser un it�rateur (pas constant... �videmment)
	- Ne pas utiliser les op�rateurs []
	- utiliser les m�thodes "ajusterXXX" de l'objet Pixel
*/
void modifierTeinte(vector<Pixel>& v)
{
	char couleur;
	int ajustement;
	cout << "*** MODIFIER LA TEINTE ***" << endl;
	cout << " Quel couleur (r/v/b)? ";
	cin >> couleur;
	cout << "\n Modification de couleur? ";
	cin >> ajustement;
	vector<Pixel>::iterator it;		// it pour iterator
	for(it=v.begin(); it<v.end(); it++)
	{
		switch(couleur)			// selon le choix de couleur l'ajuste
		{
			case 'r':
			it->ajusterRouge(ajustement);
			break;
			case 'v':
			it->ajusterVert(ajustement);
			break;
			case 'b':
			it->ajusterBleu(ajustement);
			break;
			default:			// gere les erreurs
			cout << " Erreur de prise de couleur, Reesayer : ";
			cin >> couleur;
		}
	}
}

/*
	cr�er un pixel
	Choisir une position
	Si la position est superieur � la taille du vecteur	
		Ajouter � la fin du vecteur
	Autrement
		D�placer un it�rateur � la bonne position
		Ins�rer le pixel (m�thode insert de vector)
*/
void insererPixel(vector<Pixel>& v)
{
	int rouge, vert, bleu, position;
	cout << "*** INSERER UN PIXEL ***" << endl;
	vector<Pixel>::iterator it = v.begin();
	cout << " Rouge (0-255)? ";
	cin >> rouge;
	while(rouge < 0 || rouge > 255)		// gere les erreurs
	{
		cout << "Reesayer : ";
		cin >> rouge;
	}
	cout << " Vert (0-255)? ";
	cin >> vert;
	while(vert < 0 || vert > 255)
	{
		cout << "Reesayer : ";
		cin >> vert;
	}
	cout << " Bleu (0-255)? ";
	cin >> bleu;
	while(bleu < 0 || bleu > 255)
	{
		cout << "Reesayer : ";
		cin >> bleu;
	}
	cout << " Position (0-" << v.size() << ")? ";
	cin >> position;
	while(position < 0)				// gere les erreurs sur position
	{
		cout << "Reesayer : ";
		cin >> position;
	}
	Pixel pixel(rouge, vert, bleu);
	if(position >= v.size())		// insere a la fin du vecteur si position > a la taille du vecteur
	{
		v.push_back(pixel);
	}
	else							// sinon l'insere a la position mise
	{
		it += position;
		v.insert(it, pixel);
	}
	cout << endl;
}
