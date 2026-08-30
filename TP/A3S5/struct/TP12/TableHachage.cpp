// TP12
// Victor Bouvier d'Acher
// Geoffroy Rodriguez
// Mohamed Arezki Meriane


#include <iterator>
#include "TableHachage.h"

TableHachage::TableHachage(int m)
{
	this->m = m;					// La taille du tableau
	T = new list<Couple>[m];		// Le tableau de Couple (taille m)
}

TableHachage::~TableHachage()
{
	delete[] T;						// On efface le tableau lors de la destruction de la table de hachage 
									// pour éviter une fuite de mémoire  
									// (Rappel : Si on utilise un pointeur  (new) alors il faut un delete)
}

// Ajout trié dans la liste
void TableHachage::ajouter(int cle, int valeur)
{
	int temp = hachage(cle);
	int i;
	list<Couple>::iterator it;
	Couple c(cle, valeur);
	for(i=0; i<m; i++)
	{
		if(i==temp && T[i].empty()==1)
		{
			T[i].push_back(c);
			return;
		}
		for (it=T[i].begin(); it!=T[i].end(); it++)
		{
			if(i==temp)
			{
				if(*it == c)
					return;
				if(*it > c)
				{
					T[i].insert(it, c);
					return;
				}
				else
				{
					T[i].push_back(c);
					return;
				}
			}
		}
	}

	// Trouver la bonne position (ou alvéole) dans le tableau  *** Par hachage évidemment ***
	// Rechercher dans la liste chainée si CLE existe
	//   Si la CLE verifiée est == CLE
	//     Ne rien faire  (return); 
	//   Si la CLÉ vérifiée est > CLE
	//     Insérer un nouveau Couple à la position courante (celle de l'itérateur)
	//	   Return;
	// Insérer le nouveau couple à la fin de la liste (push_back)  -->  la valeur est la plus grande de cette liste!	
}

bool TableHachage::supprimer(int cle)
{
	int temp = hachage(cle);
	int i;
	for(i=0; i<m; i++)
	{
		if(i==temp)
		{
			list<Couple>::iterator it;
			for(it=T[i].begin(); it!=T[i].end(); it++)
			{
				Couple c(cle, 0);
				if(*it == c)
				{
					T[i].erase(it);
					return true;
				}
			}
		}
	}

	// Trouver la bonne position (ou alvéole) dans le tableau
	// Rechercher dans la liste chainée si CLE existe
	//   Si c'est le cas
	//     Supprimer la CLE
	//     Retourner TRUE
	// Retourner FALSE   (La CLE n'est pas dans la liste chainée)
	return false;
}

int TableHachage::rechercher(int cle)
{
	int temp = hachage(cle);

	for(int i=0; i<m; i++)
	{
		if(i==temp)
		{
			list<Couple>::iterator it;
			for(it=T[i].begin(); it!=T[i].end(); it++)
			{
				Couple c(cle, 0);
				if(*it == c)
				{
					return it->getValeur();
				}
			}	
		}
	}
	// Trouver la bonne position (ou alvéole) dans le tableau
	// Rechercher dans la liste chainée si CLE existe
	//   Si c'est le cas
	//     Retourner la valeur
	// RETOURNER -1  (PAS TROUVÉ)
	return -1;
}

int TableHachage::hachage(int cle)
{
	return cle % m;
	// La fonction de hachage est la suivante --> CLE MOD M

}

ostream &operator<< (ostream& out, const TableHachage& tableHachage)
{
	list<Couple>::iterator itCouple;

	out << "----------------------" << endl;
	out << "T[], \t(CLE, \tVALEUR)" << endl;
	for (int x = 0; x < tableHachage.m; x++)
		for (itCouple=tableHachage.T[x].begin(); itCouple != tableHachage.T[x].end(); itCouple++)
		{
			out << x << "\t" << (*itCouple);
			out << endl;
		}
	out << "----------------------" << endl;

	return out;
}