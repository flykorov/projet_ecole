//TP5
//Victor Bouvier d'Acher
//Arezki Mohamed Meriane

#include <iostream>
#include <iterator>
#include <list>
#include "article.h"
using namespace std;

list<Article> ajouterArticle(list<Article> epicerie, Article article)
{
	if(epicerie.empty() == 1)
	{
		epicerie.push_back(article);
	}
	else
	{
		list<Article>::iterator it;
		for(it = epicerie.begin(); it != epicerie.end(); it++)
		{
			if(it->getMontant() * it->getQuantite() < article.getMontant() * article.getQuantite())
			{
				epicerie.insert(it, article);
				return epicerie;
			}
		}
		epicerie.push_back(article);
	}
	return epicerie;
}

void afficherFacture(list<Article> epicerie)
{
	list<Article>::const_iterator cit;
	int total=0;
	for(cit = epicerie.begin(); cit != epicerie.end(); cit++)
	{
		total += cit->getMontant() * cit->getQuantite();
		cout << *cit << endl;
	}
	cout << "TOTAL---------------------------"<< total << endl;
}

int main()
{
	list<Article> epicerie;
	Article mesArticle[] =
	{
		Article("Banane", 1, 12),
		Article("Patate", 2, 3),
		Article("Pomme ", 3, 12),
		Article("Poulet", 10, 1),
		Article("Oeuf  ", 5, 2),
		Article("Cadeau", 30, 2),
		Article("Patate", 1, 50)
	};
	for(Article article: mesArticle)
	{
		epicerie = ajouterArticle(epicerie, article);
	}
	afficherFacture(epicerie);
	return 0;
}