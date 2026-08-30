#include <stdint.h>
#include <stdlib.h>

typedef struct{
	char nom;
	int nb_suc;
	int nb_pre;
	int tx;
	int txx;
	int total_marge;
	int free_marge;
	int duration;
}tache_t;

typedef struct{
	int nb_tache;
	tache_t** graph;
}graph_t;

void read_file_tx(FILE* file_graphe, char* name_file, graph_t* g);
void print_tache_tx(graph_t* g);
void init_tache_tx(graph_t* g);
task_t* compute_tx(graph_t* g);
void read_file_txx(FILE* file_graphe, char* name_file, graph_t* g);
void print_tache_txx(graph_t* g);
void init_tache_txx(graph_t* g);
void compute_txx(graph_t* g, tache_t* g);
void compute_total_marge(tache_t* t, int nb_tache);
void compute_free_marge(graph_t* g,tache_t* t);
char* compute_critical_path(tache_t* t, int nb_tache);