struct cartographie
{
	int id;
	char* nom;
	int x;
	int y;
	int nb_con;
	int* connexion;
	float* distance;
	bool marque;
	struct cartographie* suivant;
};

struct prems
{
	struct cartographie* debut;
};

struct poids_min
{
	int marque;
	int id;
	int nb_con;
	int* connexion;
	float* distance;
	struct poids_min* suivant;
};

struct init_poids_min
{
	struct poids_min* debut;
};

struct lettre
{
	int num;
};

struct arbre
{
	struct lettre* lewo;
	struct lettre* prawo;
	struct arbre* gauche;
	struct arbre* droit;
};

struct compression
{
	int occ;
	struct lettre* ouais;
	struct arbre* debut;
	struct compression* suivant;
};

struct init_comp
{
	struct compression* debut;
};

struct donne
{
	int ligne_carte;
	int colonne_carte;
	int taille_carte;
	int nb_ville;
	int nb_connexion;
	int nb_con;
	int con_fin;
};

// struct arbre_codage
// {
// 	int i;
// 	int* poete;
// 	struct arbre_codage* suivant;
// };

// struct init_cod
// {
// 	struct arbre_codage* debut;
// };


