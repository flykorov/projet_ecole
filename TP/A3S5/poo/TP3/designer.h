// TP3
// Victor Bouvier d'Acher
// Geoffroy Rodriguez
// Mohamed Arezki Meriane

#ifndef DESIGNER_H
#define DESIGNER_H

#include <string>
#include "programmeur.h"
using namespace std;

class Designer : public Programmeur
{
public:
	Designer();
	Designer(int soc, int age, string n, string p, int an, double s, string t, bool d);
	Designer(const Designer& des);
	~Designer();

	void setType(string t);
	void setDiplome(int d);

	string getType() const;
	bool getDiplome() const;

	virtual void affiche() const;
	virtual double calculSalaire();

	Designer& operator=(const Designer& add);
	bool operator==(const Designer& comp);

private:
	string type = "Not Define";
	bool diplome = false;
	
};

#endif