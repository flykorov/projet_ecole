#include <iostream>
#include <iterator>
#include <vector>
#include "dataset.h"
using namespace std;

Dataset::Dataset()
{

}

Dataset::~Dataset()
{
	int i;
	for(i=0; i<vecData.size(); i++)
	{
		Rectangle* temp = dynamic_cast<Rectangle*>(vecData[i]);		// verifie si le data est de type rectangle
		if(temp != nullptr)
		{
			delete temp;
		}else
		{
			Cercle* tmp = dynamic_cast<Cercle*>(vecData[i]);		// verifie si le data est de type cercle
			if(tmp != nullptr)
			{
				delete tmp;
			}
		}
	}
}

void Dataset::ajouterData(Data* d)
{
	vecData.push_back(d);			// push_back le vecteur
}

void Dataset::printData()
{
	int i;
	for(auto it=vecData.begin(); it!=vecData.end(); it++)
	{
		Rectangle* temp = dynamic_cast<Rectangle*>(*it);	// verifie si data est de type rectangle
		if(temp != nullptr)
			temp->affiche();	// appelle la fonction affiche de rectangle
		Cercle* tmp = dynamic_cast<Cercle*>(*it);		// verifie si data est de type cercle
		if(tmp != nullptr)
			tmp->affiche();		// appelle la fonction affiche de cercle
	}
}