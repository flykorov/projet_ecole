// TP3
// Victor Bouvier d'Acher
// Geoffroy Rodriguez
// Mohamed Arezki Meriane

#ifndef PROGARMMEUR_H
#define PROGARMMEUR_H

#include <string>
using namespace std;

class Programmeur
{
public:
	Programmeur();
	Programmeur(int soc, int age, string n, string p, int an, double s);
	Programmeur(const Programmeur& pro);
	virtual ~Programmeur();

	void setSocial(int soc);
	void setNom(string n);
	void setPrenom(string p);
	void setAge(int a);
	void setSalaire(double s);
	void setAncien(int a);

	// virtual string getType() = 0;

	int getSocial() const;
	string getNom() const;
	string getPrenom() const;
	int getAge() const;
	double getSalaire() const;
	int getAncien() const;

	virtual void affiche() const;
	virtual double calculSalaire();

	Programmeur& operator=(const Programmeur& add);
	bool operator==(const Programmeur& comp);


private:
	int num_ass_social = 0;
	string nom = "Not Define";
	string prenom = "Not Define";
	int age = 0;
	double salaire = 0;
	int ancien = 0;

};

#endif