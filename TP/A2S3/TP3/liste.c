#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//flemme de typedef

struct liste
{
	float chiffre;
	struct liste *suivant;
};

struct prems
{
	struct liste *premier;
};

struct prems* init_liste()
{
	struct liste* l1 = malloc(sizeof(struct liste));
	struct prems* pre = malloc(sizeof(struct prems));
	l1->chiffre = 0;
	l1->suivant = NULL;
	pre->premier = l1;
	return pre;
}

void aff_liste(struct liste *a)
{
	if(a != NULL)
	{
		printf("%f ", a->chiffre);
		if(a->suivant != NULL)
		{
			a = a->suivant;
			aff_liste(a);
		}
	}
	printf("\n");
}

void aff_mir_liste(struct liste *a)
{
	if(a != NULL)
	{
		float b;
		b = a->chiffre;
		a = a->suivant;
		if(a->suivant != NULL)
		{
			aff_mir_liste(a);
		}else
		{
			printf("%f ", a->chiffre);
		}
		printf("%f ", b);
	}
}

struct prems* ins_num_debut(struct prems *p)
{
	printf("insertion d'un chiffre au début de la liste\n");
	float nbIns;
	scanf("%f", &nbIns);
	struct liste *new = malloc(sizeof(struct liste));
	new->chiffre = nbIns;
	new->suivant = p->premier;
	p->premier = new;
	return p;
}

struct liste* sup_num_deb(struct prems *p)
{
	printf("suppression d'un chiffre au début de la liste\n");
	struct liste *aSup = p->premier;
	p->premier = p->premier->suivant;
	free(aSup);
	return p->premier;
}

struct liste* ins_num_fin(struct prems* p)
{
	printf("insertion d'un chiffre à la fin de la liste\n");
	float nbIns;
	scanf("%f", &nbIns);
	struct liste *a = p->premier;
	struct liste *new = malloc(sizeof(struct liste));
	while(a->suivant != NULL)
	{
		a = a->suivant;
	}
	new->chiffre = nbIns;

	new->suivant = NULL;
	a->suivant = new;
	return a->suivant;
}

struct liste* sup_num_fin(struct prems *pre)
{
	printf("suppression d'un chiffre à la fin de la liste\n");
	struct liste* a = pre->premier;
	struct liste *aSup = a->suivant;
	while(a->suivant->suivant != NULL)
	{
		a = a->suivant;
		aSup = aSup->suivant;
	}
	free(aSup);
	a->suivant = NULL;
	return a->suivant;
}

struct prems* sup_occ(struct prems *p)
{
	printf("suppression des occurence dans la liste\n");
	float nbSup;
	scanf("%f", &nbSup);
	struct liste* a;
	struct liste* a_av;
	struct liste* aSup;
	while(p->premier->chiffre == nbSup)
	{
		aSup = p->premier;
		p->premier = p->premier->suivant;
		free(aSup);
		if(p->premier == NULL)
			goto alaide;
	}
alaide:
	if(p->premier != NULL)
	{
		a = p->premier;
		if(a->suivant != NULL)
		{
			while(a->suivant->suivant != NULL)
			{
				if(a->suivant->chiffre == nbSup)
				{
					aSup = a->suivant;
					a->suivant = a->suivant->suivant;
					free(aSup);
				}else
				{
					a = a->suivant;
				}
			}
			if(a->suivant->chiffre == nbSup)
			{
				aSup = a->suivant;
				a->suivant = NULL;
				free(aSup);
			}
		}
	}
	return p;
}

struct liste* ins_num_mil(struct prems* p)
{
	printf("insertion d'un chiffre au milieu de la liste\n");
	int n=0, y=0, i=0;
	float nbIns;
	scanf("%f", &nbIns);
	struct liste *a = p->premier;
	struct liste *new;
	while(a->suivant != NULL)
	{
		n++;
		a = a->suivant;
		y=1;
	}
	n = n / 2;
	a = p->premier;
	while(i<n)
	{
		i++;
		a = a->suivant;
	}
	new = malloc(sizeof(struct liste));
	new->chiffre = nbIns;
	new->suivant = a->suivant;
	a->suivant = new;
	return a;
}

void copi_tab(struct prems* p)
{
	if(p->premier != NULL)
	{
		int i, n=0;
		struct liste *a = p->premier;
		if(a->suivant == NULL)
		{
			float tab = a->chiffre;
			printf("%f\n", tab);
		}else
		{
			while(a->suivant != NULL)
			{
				n++;
				a = a->suivant;
			}
			n++;
			float tab[n];
			a = p->premier;
			for(i=0; i<n; i++)
			{
				tab[i] = a->chiffre;
				a = a->suivant;
			}
			for(i=0; i<n; i++)
				printf("%f ", tab[i]);
			printf("\n");
		}		
	}
}

void lib_tab(float *tab)
{
	free(tab);
}

void lib(struct prems *p)
{
	while(p->premier != NULL)
	{
		struct liste *sup = p->premier;
		p->premier = p->premier->suivant;
		free(sup);
	}
	free(p);
}

int main()
{
	float *tab;
	float nbSup;
	struct prems *pre;
	struct liste *l2;
	pre = init_liste();
	pre = ins_num_debut(pre);
	pre = ins_num_debut(pre);
	pre = ins_num_debut(pre);
	l2 = pre->premier;
	//ins_num_fin(l2);
	aff_liste(l2);
	pre->premier = sup_num_deb(pre);
	l2 = pre->premier;
	aff_liste(l2);
	pre = ins_num_debut(pre);
	l2 = pre->premier;
	//sup_num_fin(l2);
	l2 = ins_num_fin(pre);
	l2 = pre->premier;
	aff_liste(l2);
	l2 = sup_num_fin(pre);
	l2 = pre->premier;
	aff_liste(l2);
	l2 = ins_num_mil(pre);
	l2 = pre->premier;
	aff_mir_liste(l2);
	printf("\n");
	pre = sup_occ(pre);
	l2 = pre->premier;
	aff_liste(l2);
	copi_tab(pre);
	lib(pre);
}