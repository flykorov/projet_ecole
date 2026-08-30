#include <stdio.h>
#include <stdlib.h>

struct matrice
{
	int nbl;
	int nbc;
	double** matrix;
};

struct matrice* creat_mat(int n, int m)
{
	int i, j;
	struct matrice* init_mat;
	init_mat = malloc(sizeof(struct matrice));
	(*init_mat).nbl = n;
	(*init_mat).nbc = m;
	(*init_mat).matrix = malloc(n * sizeof(double*));
	for(i=0; i<n; i++)
	{
		(*init_mat).matrix[i] = malloc(m * sizeof(double));	
	}
	for(i=0; i<n; i++)
		for(j=0; j<m; j++)
			(*init_mat).matrix[i][j] = 0;
	return init_mat;
}

void lib_mat(struct matrice* mat)
{
	int i;
	for(i=0; i<(*mat).nbl; i++)
	{
			free((*mat).matrix[i]);
			(*mat).matrix[i] = NULL;
	}
	free((*mat).matrix);
	(*mat).matrix = NULL;
	free(mat);
	mat = NULL;
}

void assigner_chiffre(struct matrice* mat, int n, int m, double x)
{
	(*mat).matrix[n][m] = x;
}

void afficher_tab(struct matrice* mat)
{
	int i, j;
	for(i=0; i<(*mat).nbl; i++)
	{
		for(j=0; j<(*mat).nbc; j++)
		{
			printf("%lf ", (*mat).matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void GenererMatrice(struct matrice* mat, struct matrice* mat2)
{
	int i, j;
	for(i=0; i<(*mat).nbl; i++)
	{
		for(j=0; j<(*mat).nbc; j++)
		{	
			(*mat).matrix[i][j] = rand() % 100;
			(*mat2).matrix[i][j] = rand() % 100;
		}
	}
}

void ProduitMatrice(struct matrice* mat, struct matrice* mat2, struct matrice* matpro)
{
	int i, j=0, k=0, r=0, y=0;
	while(r != (*mat).nbl * (*mat).nbc)
	{
		for(i=0; i<(*mat).nbl; i++)
		{
			y = y + (*mat).matrix[j][i] * (*mat2).matrix[i][k];
		}
		(*matpro).matrix[j][k] = y;
		k++;
		k = k%(*mat).nbl;
		if(k == 0)
		{
			j++;
		}
		y = 0;
		r++;
	}			
}


int main()
{
	int i, j, n, m, l;
	double x;
	struct matrice* mat;
	struct matrice* mat2;
	struct matrice* matpro;
	printf("entrez la taille de votre matrice(ligne puis colonne)\n");
	scanf("%d %d", &i, &j);
	mat = creat_mat(i, j);
	mat2 = creat_mat(i, j);
	matpro = creat_mat(i, j);
	/*afficher_tab(mat);
	printf("voulez vous integrer une var dans la matrice? (1 = oui, 0 = non)\n");
	scanf("%d", &l);
	while(l == 1)
	{
		printf("entrez le chiffre que vous voulez integrer\n");
		scanf("%lf", &x);
		do
		{
			printf("en quelle position?(ligne puis colonne)\n");
			scanf("%d %d", &n, &m);
		}while(n>=i || m>=j);
		assigner_chiffre(mat, n, m, x);
		printf("voulez vous integrer un autre chiffre?\n");
		scanf("%d", &l);
	}*/
	GenererMatrice(mat, mat2);
	if((*mat).nbl == (*mat).nbc)
		ProduitMatrice(mat, mat2, matpro);
	afficher_tab(mat);
	afficher_tab(mat2);
	afficher_tab(matpro);
	lib_mat(mat);
	lib_mat(mat2);
	lib_mat(matpro);
}