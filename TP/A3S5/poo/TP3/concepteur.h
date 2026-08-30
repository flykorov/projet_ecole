// TP3
// Victor Bouvier d'Acher
// Geoffroy Rodriguez
// Mohamed Arezki Meriane

#ifndef CONCEPTEUR_H
#define CONCEPTEUR_H

#include <string>
#include "programmeur.h"
using namespace std;

class Concepteur : public Programmeur
{
public:
	Concepteur();
	Concepteur(int soc, int age, string n, string p, int an, double s, int pro);
	Concepteur(const Concepteur& con);
	~Concepteur();

	void setProjet(int p);

	int getProjet() const;

	virtual void affiche() const;
	virtual double calculSalaire();

	Concepteur& operator=(const Concepteur& add);
	bool operator==(const Concepteur& comp);
	
private:
	int nbProjet = 0;

};

#endif