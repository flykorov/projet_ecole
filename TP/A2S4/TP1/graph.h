struct graph
{
	int nb_vertices;
	int arcs;
	int** mat;
};

void read_file(FILE* file_graphe, char* name_file, struct graph* g);