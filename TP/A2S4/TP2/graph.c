#include "graph.h"
#include <string.h>
#include <limits.h>

void read_file_tx(FILE* file_graphe, char* name_file, graph_t* g)
{
	file_graph = fopen(name_file, "r");
	if(file_graphe == NULL)
	{
		printf("Error : can't open file %s\n", name_file);
		exit(EXIT_FAILURE);
	}
	fscanf(file_graphe, "%d\n", &g->nb_tache);
	g->graph = (tache_t**)malloc(sizeof(tache_t*) * g->nb_tache);
	for(int i=0; i<g->nb_tache; i++)
	{
		char nom;
		int duration;
		int nb_suc;
		fscanf(file_graphe, "%c %d %d ", &nom, &duration, &nb_suc);
		g->graph[i] = (tache_t*)malloc(sizeof(tache_t)*(nb_suc+1));
		g->graph[i][0].nom = nom;
		g->graph[i][0].duration = duration;
		g->graph[i][0].nb_suc = nb_suc;
		for(int j=1; j<=nb_suc; j++)
		{
			fscanf(file_graphe, "%c", &g->graph[i][j].nom);
		}
	}
	fclose(file_graphe);
}

void print_tache_tx(graph_t* g)
{
	printf("tache : %d\n", g->nb_tache);
	for(int i=0; i<g->nb_tache; i++)
	{
		printf("%c %d %d ", g->graph[i][0].nom, g->graph[i][0].duration, g->graph[i][0].nb_suc);
		for(int j=0; j<= g->graph[i]->nb_suc; j++)
		{
			printf("%c ", g->graph[i][j].nom);
		}
		printf("\n");
	}
}

void init_tache_tx(graph_t* g)
{
	for(int i=0; i<g->nb_tache; i++)
	{
		for(int j=0; j<=g->graph[i]->nb_suc; j++)
		{
			g->graph[i][j].tx = INT_MAX;
		}
	}
}

static int find_task_in_others(char c, int j, graph_t* g)
{
	int initial_duration = g->graph[j][0].duration;
	for(int k=j+1; k<g->nb_tache; k++)
	{
		int duration = g->graph[k][0].duration;
		for(int i=1; i<=g->graph[k][0].nb_suc; i++)
		{
			if((c == g->graph[k][i].nom) && (duration >initial_duration))
			{
				initial_duration = duration;
				break;
			}
		}
	}
	return initial_duration;
}

tache_t* compute_tx(graph_t* g)
{
	tache_t* tache_tx = NULL;
	tache_tx = (tache_t*)malloc(sizeof(tache_t) * (g->nb_tache + 1));
	for(int i=0; i<g->nb_tache; i++)
	{
		tache_tx[i].nom = g->graph[i][0].nom;
		tache_tx[i].tx = INT_MAX;
	}
	tache_tx[g->nb_tache].nom = g->graph[g->nb_tache-1][1].nom;
	tache_tx[g->nb_tache].tx = INT_MAX;
	tache_tx[0].tx = 0;
	for(int j=0; j<g->nb_tache; j++)
	{
		char tacje_name = g->graph[j][1].nom;
		int duration = find_task_in_others(tache_name, j, g);
		if(j==0)
		{
			g->graph[j][1].tx = duration;
		}else
		{
			g->graph[j][i].tx = duration + g->graph[j-1][1].tx;
		}
		for(i=2; i<=g->graph[j][0].nb_suc; i++)
		{
			g->graph[j][i].tx = g->graph[j][i].tx;
		}
		for(int k=j+1; k<g->nb_tache; k++)
		{
			for(int s=1; s<=g->graph[k][0].nb_suc; s++)
			{
				if(g->graph[j][1].nom == g->graph[k][s].nom)
				{
					for(int l=1; l<=g->graph[k][0].nb_suc; l++)
					{
						g->graph[k][l].tx = g->graph[j][1].tx;
					}
				}
			}
			if(g->graph[j][1].nom == g->graph[k][1].nom)
			{
				j++;
			}
		}
	}
	for(int l=0; l<=g->nb_tache, l++)
	{
		for(j=0; j<g->nb_tache; j++)
		{
			for(int i=1; i<=g->graph[j][0].nb_suc; i++)
			{
				if((tache_tx[1].tx == INT_MAX) && (tache_tx[1].nom == g->graph[j][i].nom))
				{
					tache_tx[1].tx = g->graph[j][i].tx;
				}
			}
		}
	}
	print
}

void read_file_tx(FILE* file_graphe, char* name_file, graph_t* g)
{
	file_graph = fopen(name_file, "r");
	if(file_graphe == NULL)
	{
		printf("Error : can't open file %s\n", name_file);
		exit(EXIT_FAILURE);
	}
	fscanf(file_graphe, "%d\n", &g->nb_tache);
	g->graph = (tache_t**)malloc(sizeof(tache_t*) * g->nb_tache);
	for(int i=0; i<g->nb_tache; i++)
	{
		char nom;
		int nb_pre;
		fscanf(file_graphe, "%c %d ", &nom, &nb_pre);
		g->graph[i] = (tache_t*)malloc(sizeof(tache_t)*(nb_pre+1));
		g->graph[i][0].nom = nom;
		g->graph[i][0].nb_pre = nb_pre;
		for(int j=1; j<=nb_pre; j++)
		{
			fscanf(file_graphe, "%c", &g->graph[i][j].nom);
		}
	}
	fclose(file_graphe);
}

void print_tache_txx(graph_t* g);
void init_tache_txx(graph_t* g);
void compute_txx(graph_t* g, tache_t* g);
void compute_total_marge(tache_t* t, int nb_tache);
void compute_free_marge(graph_t* g,tache_t* t);
char* compute_critical_path(tache_t* t, int nb_tache);