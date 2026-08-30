#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct graph
{
	int nb_vertices;
	int arcs;
	int** mat;
};


void read_file(FILE* fic, char* nom, struct graph* g)
{
	int i, j;
	fic = fopen(nom, "r");
	if(fic == NULL)
	{
		printf("bou\n");
		exit(EXIT_FAILURE);
	}
	fscanf(fic, "%d\n", &g->nb_vertices);
	printf("nb_vertices %d\n", g->nb_vertices);

	g->mat = malloc(sizeof(int*) * g->nb_vertices);
	for(i=0; i<g->nb_vertices; i++)
		g->mat[i] = malloc(sizeof(int) * g->nb_vertices);

	for(i=0; i<g->nb_vertices; i++)
		for(j=0; j<g->nb_vertices; j++)
			g->mat[i][j] = 0;

	while(!feof(fic))
	{
		while(feof(fic) == 0)
		{
			int a, b=0;
			fscanf(fic, "%d %d\n", &a, &b);
			g->mat[a][b] = 1;
			g->arcs = g->arcs = 1;
			printf("%d %d\n", a, b);
		}
	}
	fclose(fic);
}

void aff_mat_ajd(struct *g)
{
	int i, j;
	printf("boubou\n");
	for(i=0; i<g->nb_vertices; i++)
		for(j=0; j<g->nb_vertices;j++)
			printf("%d\n", g->mat[i][j]);
}

int** mat_pro(int ** matrix, int n)
{
	int** matric_prod = NULL;
	matric_prod = malloc(n * sizeof(int*));
	
}