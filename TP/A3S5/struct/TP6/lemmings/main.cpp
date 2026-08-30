// TP4
// Victor Bouvier d'Acher
// Geoffroy Rodriguez
// Mohamed Arezki Meriane

#include <iostream>
#include <list>
#include <iterator>
#include <queue>
#include <stack>
#include <ctime>
#include "lemming.h"
using namespace std;

void defAttroupement(list<Lemming> &lemAttroupement, int nb)
{
	int i;
	for(i=0; i<nb; i++)
	{
		Lemming lem;
		lemAttroupement.push_back(lem);
	}
}

void avancerPassage(list<Lemming> &lemAttroupement, queue<Lemming> &lemPasSombre)
{
	list<Lemming>::const_iterator cit;
	for(cit = lemAttroupement.begin(); cit != lemAttroupement.end(); cit++)
		lemPasSombre.push(*cit);
}

void avancerPente(queue<Lemming> &lemPasSombre, queue<Lemming> &lemPente)
{
	int a;
	while(lemPasSombre.empty() == 0)
	{
		a = rand()%20;
		if(a == 0)
		{
			cout << "Le lemming " << lemPasSombre.front() << " glisse et meurt!\n";
			lemPasSombre.pop(); 
		}else
		{
			lemPente.push(lemPasSombre.front());
			lemPasSombre.pop();
		}
	}
}

void creerEchelle(queue<Lemming> &lemPente, list<Lemming> &lemEchelle)
{
	int i;
	stack<Lemming> temp;
	for(i=0; i<10; i++)
	{
		temp.push(lemPente.front());
		lemPente.pop();
	}
	while(lemPente.empty() == 0)
	{
		lemEchelle.push_back(lemPente.front());
		lemPente.pop();
	}
	while(temp.empty() == 0)
	{
		lemEchelle.push_back(temp.top());
		temp.pop();
	}
}

void avancerSprint(list<Lemming> &lemEchelle, queue<Lemming> &lemSprint)
{
	int a, i=0, taille = lemEchelle.size();
	int tab[taille] = {0};
	while(i<5)						// on affecte 5 position pour le test des lemmings au sprint
	{
		a = rand() % taille;
		if(tab[a] == 0)
		{
			i++;
			tab[a] = 1;
		}
	}
	i=0;
	while(lemEchelle.empty() == 0)
	{
		if(tab[i] == 1)			// on verifie si le lemming est eligible au test
		{
			a = rand() % 2;
			if(a == 0)
			{
				cout << "Le lemming " << lemEchelle.front() << " est victime du piege!\n";
				lemEchelle.pop_front();
			}else
			{
				lemSprint.push(lemEchelle.front());
				lemEchelle.pop_front();
			}
		}else
		{
			lemSprint.push(lemEchelle.front());
			lemEchelle.pop_front();
		}
		i++;
	}
}

void sauterLiane(queue<Lemming> &lemSprint, queue<Lemming> &lemLibre, list<Lemming> &lemDisparu)
{
	int a;
	while(lemSprint.empty() == 0)
	{
		a = rand() % 5;
		if(a == 0)
		{
			cout << "Le lemming " << lemSprint.front() << " echappe la liane et tombe dans la fosse sans fond!\n";
			lemDisparu.push_back(lemSprint.front());
			lemSprint.pop();
		}else
		{
			lemLibre.push(lemSprint.front());
			lemSprint.pop();
		}
	}
}

void afficherLemming(list<Lemming> &lemming)
{
	list<Lemming>::const_iterator cit;
	cout << "LISTE (" << lemming.size() << ") : " ;
	for(cit = lemming.begin(); cit != lemming.end(); cit++)
		cout << *cit << " <- ";
	cout << endl;
}

void afficherLemming(queue<Lemming> &lemming)
{
	cout << "FILE (" << lemming.size() << ") : " ;
	cout << lemming.front() << " <-- " << lemming.back();
	cout << endl;
}


int main()
{
	srand(time(NULL));

	// Etape #1 : L'attroupement
	list<Lemming> lemAttroupement;
	cout << "Etape #1 : L'attroupement\n";
	defAttroupement(lemAttroupement, 20);
	afficherLemming(lemAttroupement);
	cout << endl;

	// Etape #2 : Le passage sombre
	queue<Lemming> lemPasSombre;
	cout << "Etape #2 : Le passage sombre\n";
	avancerPassage(lemAttroupement, lemPasSombre);
	afficherLemming(lemPasSombre);
	cout << endl;

	// Etape #3 : La pente
	queue<Lemming> lemPente;
	cout << "Etape #3 : La pente\n";
	avancerPente(lemPasSombre, lemPente);
	afficherLemming(lemPente);
	cout << endl;

	// Etape #4 : L'echelle
	list<Lemming> lemEchelle;
	cout << "Etape #4 : L'echelle\n";
	creerEchelle(lemPente, lemEchelle);
	afficherLemming(lemEchelle);
	cout << endl;

	// Etape #5 : Le sprint
	queue<Lemming> lemSprint;
	cout << "Etape #5 : Le sprint\n";
	avancerSprint(lemEchelle, lemSprint);
	afficherLemming(lemSprint);
	cout << endl;

	// Etape #6 : Liberte!
	queue<Lemming> lemLibre;
	list<Lemming> lemDisparu;
	cout << "Etape #6 : Liberte!\n";
	sauterLiane(lemSprint, lemLibre, lemDisparu);
	afficherLemming(lemLibre);
	cout << endl;
	afficherLemming(lemDisparu);
	cout << endl;

	return 0;
}