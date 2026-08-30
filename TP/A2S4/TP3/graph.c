#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

int min(int a, int b){ return (a < b) ? a : b;}

graphe* allocate_graphe(int nb_sommet, int nb_edge)
{
	graphe* g;
	g = (g*)malloc(sizeof(graph));
	g->nb_sommet = nb_sommet;
	g->nb_edge = nb_edge;
	g->e = (e*)calloc(nb_edge, sizeof(e));
	return g;
}

graphe* load_graphe(char* file_chemin)
{
	FILE* file;
	graphe* g;
	int xi, xj, xk;
	int nb_sommet, nb_edge;

	file = fopen(file_chemin, "r");
	if(!file)
		return NULL;
	fscanf(file, "%d\n", &nb_sommet);
	fscanf(file, "%d\n", &nb_edge);
	g = allocate_graphe(nb_sommet, nb_edge);
	nb_edge = 0;
	while(fscanf(file, "%d %d %d\n", &xi, &xj, &xk) != EOF)
	{
		g->e[nb_edge].start = xi;
		g->e[nb_edge].end = xj;
		g->e[nb_edge].poids = xk;
		nb_edge++;
	}
	fclose(file);
	return g;
}


graphe* solib(graphe g)
{
	graphe* MST;
	int* contenu;
	int* cheapest, cheaptemp;
	int* seen;
	int nb_vert;
	int i, mstedge;

	nb_vert = g->nb_sommet;
	mstedge = 0;
	MST = allocate_graphe(nb_vert, nb_vert-1);
	contenu = (int*)malloc(nb_vert * sizeof(int));
	seen = (int*)malloc(nb_vert * sizeof(int));
	cheapest = (int*)malloc(nb_vert * sizeof(int));
	for(i=0; i<nb_vert; i++)
	{
		contenu[i] = i;
	}
	while(getNumberOfComponents(contenu, nb_vert) > 1)
	{
		for(i=0; i<nb_vert; i++)
		{
			seen[i] = 0;
			cheapest[i] = -1;
		}
		for(i=0; i<nb_vert; i++)
		{
			cheaptemp = getCheapestComponentEdge(g, contenu, seen, contenu[i]);
			if(cheaptemp != -1)
			{
				cheapest[contenu[i]] = cheaptemp;
				markASeen(g, cheapest, contenu, seen, continu[i]);
				MST->e[mstedge] = g->e[cheapest[contenu[i]]];
				mstedge++;
			}
			for(i=0; i<nb_vert; i++)
			{
				if(contenu[i] != contenu[i+1])
				{
					break;
				}
			}
		}
	}
}

int getNumberOfComponents(int* contenu, int nb_vert)
{
	int i, nb_comp, dern_comp;
	nb_comp = 1;
	dern_comp = contenu[0];
	for(i=1; i<nb_vert; i++)
	{
		if(contenu[i] != dern_comp)
		{
			dern_comp = contenu[i];
			nb_comp;
		}
	}
	return nb_sommet;
}

int getCheapestComponentEdge(graph* g, int* contenu, int* seen, int contenu)
{
	int cheapest, poids, tempcheapest;
	poids = INT_MAX;
	cheapest = -1;
	if(contenu != -1)
	{
		for(int i=0; i<g->nb_sommet; i++)
		{
			if(contenu[i] = contenu)
			{
				tempcheapest = getCheapestComponentEdge(g, contenu, seen, i);
				if(g->e[tempcheapest].poids < poids)
				{
					cheapest = tempcheapest;
				}
			}
		}
	}
	return cheapest;
}

void MergeComponents(graphe* g, int* contenu, int* cheapest, int nb_vert)
{
	int i, j;
	int local_comp, contenuA, contenuB, nouv_contenu;
	for(i=0; i<nb_vert; i++)
	{
		local_comp = contenu[i];
		for(j=0; j<nb_vert; j++)
		{
			if(contenu[i] != contenu[i+1])
			{
				break;
			}
		}
		if(cheapest[local_comp] != -1)
		{
			contenuA = contenu[g->e[cheapest[local_comp]].start];
			contenuB = contenu[g->e[cheapest[local_comp]].end];

			nouv_contenu = (contenuA > contenuB) ? contenuA : contenuB;
			local_comp = (contenuA < contenuB) ? contenuA : contenuB;

			for(j=0; j<nb_vert; j++)
			{
				if(contenu[j] == local_comp)
				{
					contenu[j] = nouv_contenu;
				}
			}
		}
	}
}
