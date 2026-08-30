#include <iostream>
#include <new>
#include <random>
#include <cstdlib>

using namespace std;

int** allouer_mat()		// allocation dynamique des matrices
{
	int i;
	int** mat = new int*[5];
	for(i=0; i<5; i++)
	{
		mat[i] = new int[5];
	}
	return mat;
}

void affecter_mat_0(int** mat)		// initialise les matrices a 0
{
	int i, j;
	for(i=0; i<5; i++)
		for(j=0; j<5; j++)
			mat[i][j] = 0;	// 0 = inconnu
}

void generer_grille_alea(int** mat)		// genere les grilles aleatoirement
{
	int i, a, b;
	for(i=0; i<3; i++)
	{
		do
		{
			a = rand() % 5;
			b = rand() % 5;
		}while(mat[a][b] == 9); // verifie si la case est deja sur 9
		mat[a][b] = 9;  // 9 = bateau
	}
}

void entrer_grille_joueur(int** mat)	// genere la grille du joueur
{
	int i, x=0, y=0;
	cout << "Entrer les coordonées de vos bateaux\n";
	cout << "Taper un chiffre entre 0 et 4 inclus\n";
	for(i=0; i<3; i++)
	{
		do
		{
			if((x < 0 || 4 < x) || (y < 0 || 4 < y))
				cout << "Erreur lors de la prise des valeurs, Reessayer : \n";
			cout << "Entrer le x : ";
			cin >> x;
			cout << "Entrer le y : ";
			cin >> y;
		}while((x < 0 || 4 < x) || (y < 0 || 4 < y));
		mat[x][y] = 9;		// 9 = bateau
	}
}

void afficher_grille(int** mat1, int** mat2)
{
	int i, j;
	cout << "   ORDI           JOUEUR\n";
	cout << "   0 1 2 3 4      0 1 2 3 4\n\n";
	for(i=0; i<5; i++)		// affichage ligne par ligne
	{
		cout << i << "  ";
		for(j=0; j<5; j++)
		{
			cout << mat1[i][j] << " ";
		}
		cout << "     ";
		for(j=0; j<5; j++)
		{
			cout << mat2[i][j] << " ";
		}
		cout << endl;
	}
}

void init_affiche()		// premier affichage
{
	system("clear");
	cout << "---- INITIALISATION\n";
	cout << "LEGENDE\n";
	cout << "  INCONNU : 0\n";
	cout << "  EAU : 8\n";
	cout << "  BATEAU : 9\n";
	cout << "  COULE : 1\n\n";
}

void tour_joueur(int** mat)
{
	cout << "\n---- TOUR DU JOUEUR\n";

	int x, y;

	cout << "Entrer une coordonee valide pour x : ";
	cin >> x;
	while(x < 0 || x > 4) 	// verifie l'entree
	{
		cout << "Erreur lors de la prise de la valeur de x, Reessayer : ";
		cin >> x;
	}

	cout << "Entrer une coordonee valide pour y : ";
	cin >> y;
	while(y < 0 || y > 4)
	{
		cout << "Erreur lors de la prise de la valeur de y, Reessayer : ";
		cin >> y;
	}

	if(mat[x][y] == 9 || mat[x][y] == 1)	// verifie la cible touchee
	{
		cout << "BATEAU COULE A " << x << "-" << y << endl;
		mat[x][y] = 1;
	}else
	{
		cout << "TIR A L'EAU A " << x << "-" << y << endl;
		mat[x][y] = 8;
	}
}

void tour_ordi(int** mat)	// meme chose que la fonction precedente en automatique
{
	cout << "---- TOUR DE L'ORDINATEUR\n";
	int x, y;
	x = rand() % 5;
	y = rand() % 5;
	if(mat[x][y] == 9 || mat[x][y] == 1)
	{
		cout << "BATEAU COULE A " << x << "-" << y << endl;
		mat[x][y] = 1;
	}else
	{
		cout << "TIR A L'EAU A " << x << "-" << y << endl;
		mat[x][y] = 8;
	}
}

bool verif_fin(int** mat)
{
	int i, j, nb_coule=0;
	bool fin = false;

	for(i=0; i<5; i++)
		for(j=0; j<5; j++)
			if(mat[i][j] == 1)
				nb_coule++;

	if(nb_coule == 3)	// 3 = nombre de bateau sur le plateau
		fin = true;

	return fin;
}

void lib_mat(int** mat)		// libere la memoire
{
	int i;
	for(i=0; i<5; i++)
	{
		delete [] mat[i];
	}
	delete [] mat;
}
