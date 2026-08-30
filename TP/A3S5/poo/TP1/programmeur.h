#ifndef PROGRAMMEUR_H
#define PROGRAMMEUR_H
using namespace std;

class Programmeur
{
public:
	Programmeur();
	Programmeur(string p, string n, bool c) : characteristique(c), prenom(p), nom(n) {}
	~Programmeur();

	string getPrenom();
	string getNom();
	bool getChar();
	
	void setName(string p, string n);
	void setChar(bool c);

	Programmeur* ajout(Programmeur* programmeur, int compteurProg);

private:
	bool characteristique=0;
	string prenom = "not define";
	string nom = "not define";
};

#endif