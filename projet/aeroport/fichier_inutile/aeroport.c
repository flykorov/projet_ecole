#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define curseur(x,y) printf("\033[%d;%dH", (x), (y))


struct avion
{
    char nom[20];
    int carburant;
    float heure_depart;
    float heure_arriver;
    struct avion* suivant;
};

struct compagnie
{
    char nom[20];
    int nb_avion;
    int liste_noire;
    struct avion* debut;
    struct compagnie* suivant;
};

struct aeroport
{
    struct compagnie* debut;
    int meteo;
    int nb_avion;
    int nb_compagnie;
};

struct avion* ajouter_avion()
{
    //system("clear");
    //system("cat aeroport_aero_avion.txt");
    int car;
    float depart, arriver;
    //char titre[20];
    struct avion* new = malloc(sizeof(struct avion));
    printf("carbubrant\n");
    scanf("%d", &car);
    printf("nom_av\n");
    scanf("%20s", new->nom);
    printf("heure_depart\n");
    scanf("%f", &depart);
    printf("heure_arriver\n");
    scanf("%f", &arriver);
    new->carburant = car;
    //new->nom = titre;
    new->heure_depart = depart;
    new->heure_arriver = arriver;
    return new;
}

struct compagnie* ajouter_compagnie(int* avion)
{
    //system("clear");
    //system("cat aeroport_aero_compagnie.txt");
    int nb_avi, liste;
    //char titre[20];
    struct compagnie* new = malloc(sizeof(struct compagnie));
    struct avion *av;
    new->debut = NULL;
    new->suivant = NULL;
    printf("nb_avion\n");
    scanf("%d", &nb_avi);
    printf("nom_compagnie\n");
    scanf("%20s", new->nom);
    printf("liste\n");
    scanf("%d", &liste);
    avion = nb_avi + avion;
    new->nb_avion = nb_avi;
    //new->nom = titre;
    new->liste_noire = liste;
    while(nb_avi > 0)
    {
        av = ajouter_avion();
        av->suivant = new->debut;
        new->debut = av;
        nb_avi--;
        //printf("a5\n");
    }
    return new;
}

struct aeroport* init_aeroport()
{
    //system("clear");
    //system("cat aeroport_aero_debut.txt");
    int nb_comp, met;
    int nb_avion=0;
    struct aeroport* poport = malloc(sizeof(struct aeroport));
    poport->debut = NULL;
    struct compagnie* comp;
    printf("nb_compagnie\n");
    scanf("%d", &nb_comp);
    printf("météo\n");
    scanf("%d", &met);
    poport->meteo = met;
    poport->nb_compagnie = nb_comp;
    while(nb_comp > 0)
    {
        comp = ajouter_compagnie(&nb_avion);
        comp->suivant = poport->debut;
        poport->debut = comp;
        nb_comp--;
        //printf("a6\n");
    }
    poport->nb_avion = nb_avion;
    return poport;
}

void lib_avion(struct compagnie *comp)
{
	while(comp->debut != NULL)
	{
		struct avion *sup = comp->debut;
        comp->debut = comp->debut->suivant;
        free(sup);
        //printf("a1\n");
    }
}

void lib_compagnie(struct aeroport *poport)
{
    struct compagnie *comp = poport->debut;
    while(comp != NULL)
    {
        lib_avion(comp);
        struct compagnie *sup = comp;
        comp = comp->suivant;
        free(sup);
        //printf("a2\n");
    }
}

void lib_aeorport(struct aeroport *poport)
{
    lib_compagnie(poport);
    free(poport);
}



int main(int argc, char *argv[])
{
    //clear();
    struct aeroport* poport;
    poport = init_aeroport();
    //printf("a3\n");
    lib_aeorport(poport);
    //printf("a4\n");
    return 0;
}
