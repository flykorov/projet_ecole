typedef struct
{
	int start;
	int end;
	int poids;
}edge;

typedef struct
{
	int nb_sommet;
	int nb_edge;
	edge* e;
}graphe;

int min(int a, int b);
graphe* allocate_graphe(int nb_sommet, int nb_edge);
graphe* load_graphe(char* file_chemin);
void display_graphe(graphe* g);
void free_graphe(graphe* g);
void printMSTpoids(graohe* g);
