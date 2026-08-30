#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



int immun_pop(int x, int y, int size[x][y])
{
	int i, j, a;
	for(i=0; i<x; i++)
	{
		for(j=0; j<y; j++)
		{
			scanf("%d", &a);
			size[i][j] = a;
		}
	}
}			

int print_size(int x, int y, int size[x][y], int a, int b, int c)
{
	int i, j;
	printf("Taille = %d x %d\n", x, y);
	for(i=0; i<x; i++)
	{
		for(j=0; j<y; j++)
		{
			printf(" \%2d", size[i][j]);
		}
		printf("\n");
	}
	printf("Foyer = (%d, %d)\n", a, b);
	printf("Virulence = %d\n", c);
	printf("\n");
}

int init_mat_pop(int x,int y, int mat_pop[x][y], int rec_mat[x][y])
{
	int i, j;
	printf("PROPAGATION DU VIRUS :\n");
	for(i=0; i<x; i++)
	{
		for(j=0; j<y; j++)
		{
			mat_pop[i][j] = 0;
			rec_mat[i][j] = 0;
		}
	}
}

int prop_mat_virus(int x, int y, int size[x][y], int mat_pop[x][y], int rec_mat[x][y], int a, int b, int c, int u, int v)
{
	int i, j;
	if(size[a][b] <= c)
	{
		mat_pop[a][b] = -2;
	}else
	{
		return 0;
	}
	if(size[u][v] <= c)
	{
		mat_pop[u][v] = -1;
		rec_mat[u][v] = 1;
	}else
	{
		rec_mat[u][v] = 1;
	}		
	if(u - 1 >= 0 && u - 1 < x && rec_mat[u-1][v] == 0 && mat_pop[u][v] == -1 || mat_pop[u-1][v] == -2)
	{
		prop_mat_virus(x, y, size, mat_pop, rec_mat, a, b, c, u - 1, v);
	}
	if(u + 1 >= 0 && u + 1 < x && rec_mat[u+1][v] == 0 && mat_pop[u][v] == -1 || mat_pop[u+1][v] == -2)				
	{
		prop_mat_virus(x, y, size, mat_pop, rec_mat, a, b, c, u + 1, v);
	}				
	if(v - 1 >= 0 && v - 1 < y && rec_mat[u][v-1] == 0 && mat_pop[u][v] == -1 || mat_pop[u][v-1] == -2)
	{
		prop_mat_virus(x, y, size, mat_pop, rec_mat, a, b, c, u, v - 1);
	}	
	if(v + 1 >= 0 && v + 1 < y && rec_mat[u][v+1] == 0 && mat_pop[u][v] == -1 || mat_pop[u][v+1] == -2)
	{
		prop_mat_virus(x, y, size, mat_pop, rec_mat, a, b, c, u, v + 1);
	}		
	if(u - 1 >= 0 && u - 1 < x && v - 1 >= 0 && v - 1 < y && rec_mat[u-1][v-1] == 0 && mat_pop[u][v] == -1 || mat_pop[u-1][v-1] == -2)
	{
		prop_mat_virus(x, y, size, mat_pop, rec_mat, a, b, c, u - 1, v - 1);
	}				
	if(u + 1 >= 0 && u + 1 < x && v - 1 >= 0 && v - 1 < y && rec_mat[u+1][v-1] == 0 && mat_pop[u][v] == -1 || mat_pop[u+1][v-1] == -2)
	{
		prop_mat_virus(x, y, size, mat_pop, rec_mat, a, b, c, u + 1, v - 1);
	}		
	if(u - 1 >= 0 && u - 1 < x && v + 1 >= 0 && v + 1 < y && rec_mat[u-1][v+1] == 0 && mat_pop[u][v] == -1 || mat_pop[u-1][v+1] == -2)
	{
		prop_mat_virus(x, y, size, mat_pop, rec_mat, a, b, c, u - 1, v + 1);
	}		
	if(u + 1 >= 0 && u + 1 < x && v + 1 >= 0 && v + 1 < y && rec_mat[u+1][v+1] == 0 && mat_pop[u][v] == -1 || mat_pop[u+1][v+1] == -2)
	{
		prop_mat_virus(x, y, size, mat_pop, rec_mat, a, b, c, u + 1, v + 1);
	}
	return 1;	
}

int aff_prop(int x, int y, int mat_pop[x][y], int rec_mat[x][y])
{
	int i, j, k ,l;
	for(k=0; k<y*3+2; k++)
	{
		printf("-");
	}
	printf("\n");
	for(i=0; i<x; i++)
	{
		usleep(100000);
		printf("|");
		for(j=0; j<y; j++)
		{
			if(mat_pop[i][j] == 0)
			{
				printf("   ");
			}else
			{
				printf(" \%2d", mat_pop[i][j]);
			}	
		}
		printf("|");
		printf("\n");
	}
	for(l=0; l<y*3+2; l++)
	{
		printf("-");
	}
	printf("\n");
}

int main()
{
	int x, y, a, b, c, q, l, m, i, j;
	scanf("%d", &x);
	scanf("%d", &y);
	int size[x][y];
	int mat_pop[x][y];
	int rec_mat[x][y];
	immun_pop(x, y, size);
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);
	int u = a;
	int v = b;
	print_size(x, y, size, a, b, c);
	init_mat_pop(x, y, mat_pop, rec_mat);
	prop_mat_virus(x, y, size, mat_pop, rec_mat, a, b, c, u, v);
	aff_prop(x, y, mat_pop, rec_mat);
	return 0;
}	
