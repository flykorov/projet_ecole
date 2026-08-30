// TP3
// Victor Bouvier d'Acher
// Geoffroy Rodriguez
// Mohamed Arezki Meriane

#include <iostream>
#include <string>
#include <vector>
#include "gestionnaire.h"
using namespace std;

// int soc, int a, string n, string p, int an, double s
// int pro
// string t, bool d

int main()
{
	Concepteur* con = new Concepteur(2, 35, "Audi", "Ahmad", 10, 20000, 5);
	Concepteur* con4 = new Concepteur(8, 50, "Gaouthi", "Abdalah", 20, 25000, 2);
	Concepteur* con3 = new Concepteur();		// cree un concepteur par parametre
	*con3 = *con;			// copie le concepteur avec l'operateur
	Concepteur* con2 = new Concepteur(*con);	// cree un concepteur par copie
	Designer* des = new Designer(3, 50, "Dridi", "Montacer", 30, 30000, "UX", true);
	Designer* des2 = new Designer(4, 20, "Jaouadi", "Amine", 5, 15000, "UX", false);
	Designer* des4 = new Designer();
	*des4 = *des;
	Designer* des3 = new Designer(*des);
	Gestionnaire* ges = new Gestionnaire();

	// cout << con << endl << con2 << endl << con3 << endl;

	
	ges->ajouterDesigner(des);		// l'ajoute dans la class Gestionnaire
	ges->ajouterConcepteur(con4);
	ges->ajouterDesigner(des3);
	ges->ajouterConcepteur(con);
	ges->ajouterDesigner(des2);
	ges->ajouterConcepteur(con2);
	ges->ajouterDesigner(des4);	
	ges->ajouterConcepteur(con3);

	
	ges->afficherConcepteur(5);		// affiche selon les caracteristique
	ges->afficherDesigner("UX");


	delete ges;					// delete gestionnaire

	return 0;
}