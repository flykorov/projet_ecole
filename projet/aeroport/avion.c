#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
//#include <SDL2/SDL.h>
//#include "SDL2/SDL_ttf.h"
#include <time.h>
//#endif

/*il reste le 2.3 2.4 2.10 faire le déroulement des évenement les conditions et l'affichage avec les curseur*/

#define curseur(x,y) printf("\033[%d;%dH", (x), (y))

struct avion_dec
{
    char nom[20];
    int carburant;
    int heure_depart;
    int minute_depart;
    struct avion_dec* suivant;
};

struct avion_att
{
    char nom[20];
    int carburant;
    int heure_arriver;
    int minute_arriver;
    struct avion_att* suivant;
};

struct compagnie
{
    char nom[20];
    int nb_avion;
    int liste_noire;
    struct avion_dec* depart;
    struct avion_att* debut;
    struct compagnie* suivant;
};

struct aeroport
{
    struct compagnie* debut;
    int meteo;
    int heure;
    int minute;
    int nb_avion_dec;
    int nb_avion_att;
    int nb_avion;
    int nb_compagnie;
};

struct compagnie* creer_avion_dec(struct compagnie* comp)   //creer un avion pour decoller
{
    system("clear");
    system("cat creer_avion_dec.txt");
    struct avion_dec* new = malloc(sizeof(struct avion_dec));
    curseur(13, 9);
    scanf("%20s", new->nom);
    curseur(21, 9);
    scanf("%d", &new->carburant);
    curseur(29, 9);
    scanf("%d", &new->heure_depart);
    new->heure_depart = new->heure_depart % 24;
    curseur(38, 9);
    scanf("%d", &new->minute_depart);
    new->minute_depart = new->minute_depart % 60;
    comp->nb_avion++;
    new->suivant = comp->depart;
    comp->depart = new;
    return comp;
}

struct compagnie* creer_avion_att(struct compagnie* comp)   //creer un avion pour atterir
{
    system("clear");
    system("cat creer_avion_att.txt");
    struct avion_att* new = malloc(sizeof(struct avion_att));
    curseur(13, 9);
    scanf("%20s", new->nom);
    curseur(21, 9);
    scanf("%d", &new->carburant);
    curseur(29, 9);
    scanf("%d", &new->heure_arriver);
    new->heure_arriver = new->heure_arriver % 24;
    curseur(38, 9);
    scanf("%d", &new->minute_arriver);
    new->minute_arriver = new->minute_arriver % 60;
    comp->nb_avion++;
    new->suivant = comp->debut;
    comp->debut = new;
    return comp;
}

struct aeroport* creer_avion(struct aeroport* poport)   //choix de compagnie et de type d'avion
{
    int continuer=0, a, i=1, j=1, q, x=0;
    if(poport->debut != NULL)
    {
        struct compagnie* new = poport->debut;
        system("clear");
        system("cat affichage_comp.txt");
        while(new != NULL)
        {
            curseur(10+x, 3);
            printf("%s (%d)", new->nom, j);
            curseur(10+x, 78);
            printf("%d", new->nb_avion);
            curseur(10+x, 153);
            printf("%d", new->liste_noire);
            j++;
            x = x + 3;
            new = new->suivant;
        }
        do
        {
            curseur(5, 93);
            scanf("%d", &q);
        }while(q < 0 || q > poport->nb_compagnie);
        new = poport->debut;
        while(i < q)
        {
            new = new->suivant;
            i++;
        }
        if(continuer == 0)
        {
            system("clear");
            system("cat ajouter_avion.txt");
            do
            {
                curseur(13, 10);
                scanf("%d", &a);
            }while(a != 1 && a != 2);
            if(a == 1 || a == 2)
            {
                if(a==1)
                {
                    if(new->liste_noire == 0)
                    {
                        new = creer_avion_dec(new);
                        poport->nb_avion_dec++;
                        poport->nb_avion++;
                    }else
                    {
                        system("clear");
                        system("cat comp_liste_noir.txt");
                        int retour;
                        curseur(13, 10);
                        scanf("%d", &retour);
                    }
                }else
                {
                    new = creer_avion_att(new);
                    poport->nb_avion_att++;
                    poport->nb_avion++;
                }
            }
        }
    }else
    {
        system("clear");
        system("cat no_comp");
        int retour;
        curseur(13, 10);
        scanf("%d", &retour);
    }
    return poport;
}

struct aeroport* creer_compagnie(struct aeroport* poport)   //creer compagnie
{
    system("clear");
    system("cat creer_comp.txt");
    struct compagnie* comp = malloc(sizeof(struct compagnie));
    curseur(13, 10);
    scanf("%20s", comp->nom);
    curseur(20, 11);
    scanf("%d", &comp->liste_noire);
    comp->suivant = poport->debut;
    comp->depart = NULL;
    comp->debut = NULL;
    comp->nb_avion = 0;
    poport->nb_compagnie++;
    poport->debut = comp;
    return poport;
}

struct aeroport* creer_aero()   //creer l'aeroport
{
    struct aeroport* poport = malloc(sizeof(struct aeroport));
    poport->debut = NULL;
    poport->heure = 12;
    poport->minute = 0;
    poport->nb_avion = 0;
    poport->nb_avion_att = 0;
    poport->nb_avion_dec = 0;
    poport->meteo = 0;
    return poport;
}

void voir_avion_comp(struct aeroport* poport)   
{
    int i=1, j=1, x=0, y=0;
    struct compagnie* comp = poport->debut;
    system("clear");
    system("cat affichage_comp.txt");
    while(comp != NULL)                 //printf des compagnie
    {
        curseur(10+x, 3);
        printf("%s (%d)", comp->nom, j);
        curseur(10+x, 78);
        printf("%d", comp->nb_avion);
        curseur(10+x, 153);
        printf("%d", comp->liste_noire);
        j++;
        x = x + 3;
        comp = comp->suivant;
    }
    int q;
    do
    {
        curseur(5, 93);
        scanf("%d", &q);
    }while(q < 0 && q > poport->nb_compagnie);          //choix de la compagnie
    comp = poport->debut;
    while(i < q)
    {
        comp = comp->suivant;
        i++;
    }
    struct avion_dec* av = comp->depart;
    struct avion_att* vion = comp->debut;
    system("clear");
    system("cat afficher_avion.txt");
    curseur(2, 88);
    printf("%s", comp->nom);
    while(av != NULL)               //affiche les avions qui decolle
    {
        curseur(10+y, 4);
        printf("%s", av->nom);
        curseur(10+y, 79);
        printf("Depart : %d:%d", av->heure_depart, av->minute_depart);
        curseur(10+y, 155);
        printf("%d", av->carburant); 
        av = av->suivant;
        y = y + 3;
    }
    while(vion != NULL)     //affiche les avions qui atterie
    {
        curseur(10+y, 4);
        printf("%s", vion->nom);
        curseur(10+y, 79);
        printf("Arrivée : %d:%d", vion->heure_arriver, vion->minute_arriver);
        curseur(10+y, 155);
        printf("%d", vion->carburant); 
        vion = vion->suivant;
        y = y + 3;
    }
    int retour;
    curseur(5, 93);
    scanf("%d", &retour);
}

struct compagnie* liste_noire(struct aeroport* poport, int* enl)
{
    int p, j=1, i, x=0;
    struct compagnie* comp = poport->debut;
    system("clear");
    system("cat affichage_comp.txt");
    while(comp != NULL)                     //affichage des compagnies
    {
        curseur(10+x, 3);
        printf("%s (%d)", comp->nom, j);
        curseur(10+x, 78);
        printf("%d", comp->nb_avion);
        curseur(10+x, 153);
        printf("%d", comp->liste_noire);
        j++;
        x = x + 3;
        comp = comp->suivant;
    }
    do
    {
        curseur(5, 93);
        scanf("%d", &p);
    }while(p > poport->nb_compagnie && p < 0);          //choix de la compagnie
    comp = poport->debut;
    for(i=1; i<p; i++)
    {
        comp = comp->suivant;
    }
    if(comp->liste_noire == 0)
        comp->liste_noire = 1;
    else
        comp->liste_noire = 0;
    struct avion_dec *sup;
    while(comp->depart != NULL)         //libere les avions au decollage de la compagnie
    {
        sup = comp->depart;
        comp->depart = comp->depart->suivant;
        free(sup);
        comp->nb_avion--;
        enl++;
        poport->nb_avion--;
        poport->nb_avion_dec--;
        //printf("a1\n");
    }
    comp->depart = NULL;
    return comp;
}

void voir_avion_attente_dec(struct aeroport* poport)
{
    int nb_av = poport->nb_avion_dec, i, j, y=0, t, u, l, ind, x=0;
    int heure = poport->heure;
    int tab[nb_av][3];
    int horaire[nb_av][2];
    char tt[20];
    char nom[nb_av][20];
    char nom_comp[nb_av][20];
    struct avion_dec* av;
    struct compagnie* comp = poport->debut;
    while(comp != NULL)                         //strocke les avions dans un avions
    {
        av = comp->depart;
        while(av != NULL)
        {
            tab[y][0] = av->heure_depart;
            if(tab[y][0] < heure)
                horaire[y][0] = tab[y][0] + 24;
            else
                horaire[y][0] = tab[y][0];
            tab[y][1] = av->minute_depart;
            horaire[y][1] = tab[y][1];
            tab[y][2] = av->carburant;
            strcpy(nom[y], av->nom);
            strcpy(nom_comp[y], comp->nom);
            av = av->suivant;
            y++;
        }
        comp = comp->suivant;
    }
    i=0;
    while(i<y)                          //trie le tableau
    {
        t = horaire[i][0];
        u = horaire[i][1];
        ind = i;
        for(j=i; j<y; j++)
        {
            if(t > horaire[j][0])
            {
                t = horaire[j][0];
                ind = j;
            }else if(t == horaire[j][0])
            {
                if(u > horaire[j][1])
                {
                    u = horaire[j][1];
                    ind = j;
                }
            }
        }
        l = horaire[i][0];
        horaire[i][0] = horaire[ind][0];
        horaire[ind][0] = l;
        l = horaire[i][1];
        horaire[i][1] = horaire[ind][1];
        horaire[ind][1] = l;
        l = tab[i][0];
        tab[i][0] = tab[ind][0];
        tab[ind][0] = l;
        l = tab[i][1];
        tab[i][1] = tab[ind][1];
        tab[ind][1] = l;
        l = tab[i][2];
        tab[i][2] = tab[ind][2];
        tab[ind][2] = l;
        strcpy(tt, nom[i]);
        strcpy(nom[i], nom[ind]);
        strcpy(nom[ind], tt);
        strcpy(tt, nom_comp[i]);
        strcpy(nom_comp[i], nom_comp[ind]);
        strcpy(nom_comp[ind], tt);
        i++;
    }
    if(y > 11)
        y = 11;
    system("clear");
    system("cat voir_ordre_dec.txt");
    for(i=0; i<y; i++)                  //affiche le tableau
    {
        curseur(10+x, 4);
        printf("%s", nom[i]);
        curseur(10+x, 33);
        printf("%d:%d", tab[i][0], tab[i][1]);
        curseur(10+x, 64);
        printf("%d", tab[i][2]);
        curseur(10+x, 99);
        printf("%s", nom_comp[i]);
        curseur(10+x, 132);
        printf("0");
        curseur(10+x, 165);
        printf("%d", poport->meteo);
        x = x + 3;
    }
    int retour;
    curseur(5, 93);
    scanf("%d", &retour);
}

void voir_avion_attente_att(struct aeroport* poport)        //pareil que pour celui du haut
{
    int nb_av = poport->nb_avion_att, i, j, y=0, t, u, l, ind, q, v, car, x=0;
    int heure = poport->heure, bru;
    int horaire[nb_av][2];
    int tab[nb_av][4];
    char nom_comp[nb_av][20];
    char tt[20];
    char nom[nb_av][20];
    struct avion_att* av;
    struct compagnie* comp = poport->debut;
    while(comp != NULL)
    {
        av = comp->debut;
        while(av != NULL)
        {
            tab[y][0] = av->heure_arriver;
            if(tab[y][0] < heure)
                horaire[y][0] = tab[y][0] + 24;
            else
                horaire[y][0] = tab[y][0];
            tab[y][1] = av->minute_arriver;
            horaire[y][1] = tab[y][1];
            tab[y][2] = av->carburant;
            tab[y][3] = comp->liste_noire;
            strcpy(nom[y], av->nom);
            strcpy(nom_comp[y], comp->nom);
            av = av->suivant;
            y++;
        }
        comp = comp->suivant;
    }
    i=0;
    while(i<y)
    {
        t = horaire[i][0];
        u = horaire[i][1];
        ind = i;
        q = tab[i][2];
        v = tab[i][3];
        if(q < 20)
            car = 1;
        else
            car = 0;
        for(j=i; j<y; j++)
        {
            if(q > tab[j][2] && tab[j][2] < 20)
            {
                ind = j;
                q = tab[j][2];
                car = 1;
            }
            if(car == 0)
            {
                if(tab[j][3] == 1)
                {
                    v = 1;
                    ind = j;
                }
                if(v == 0)
                {
                    if(t > horaire[j][0])
                    {
                        t = horaire[j][0];
                        ind = j;
                    }else if(t == horaire[j][0])
                    {
                        if(u > horaire[j][1])
                        {
                            u = horaire[j][1];
                            ind = j;
                        }
                    }
                }
            }
        }
        l = horaire[i][0];
        horaire[i][0] = horaire[ind][0];
        horaire[ind][0] = l;
        l = horaire[i][1];
        horaire[i][1] = horaire[ind][1];
        horaire[ind][1] = l;
        l = tab[i][0];
        tab[i][0] = tab[ind][0];
        tab[ind][0] = l;
        l = tab[i][1];
        tab[i][1] = tab[ind][1];
        tab[ind][1] = l;
        l = tab[i][2];
        tab[i][2] = tab[ind][2];
        tab[ind][2] = l;
        strcpy(tt, nom[i]);
        strcpy(nom[i], nom[ind]);
        strcpy(nom[ind], tt);
        strcpy(tt, nom_comp[i]);
        strcpy(nom_comp[i], nom_comp[ind]);
        strcpy(nom_comp[ind], tt);
        i++;
    }
    if(y > 11)
        y = 11;
    system("clear");
    system("cat voir_ordre_att.txt");
    for(i=0; i<y; i++)
    {
        curseur(10+x, 4);
        printf("%s", nom[i]);
        curseur(10+x, 33);
        printf("%d:%d", tab[i][0], tab[i][1]);
        curseur(10+x, 64);
        printf("%d", tab[i][2]);
        curseur(10+x, 99);
        printf("%s", nom_comp[i]);
        curseur(10+x, 132);
        printf("%d", tab[i][3]);
        curseur(10+x, 165);
        printf("%d", poport->meteo);
        x = x + 3;
    }
    int retour;
    curseur(5, 93);
    scanf("%d", &retour);
}

struct aeroport* deroulement_evenement(struct aeroport* poport, FILE *fichier)
{
    int minute = poport->minute, i, heure = poport->heure, continuer = 0;
    int conti_dec=poport->nb_avion_dec, conti_att=poport->nb_avion_att, conti_aero=poport->nb_avion;
    char nom_dec[poport->nb_avion_dec][20];
    char nom_comp_dec[poport->nb_avion_dec][20];
    int horaire_dec[poport->nb_avion_dec][2];
    int tab_dec[poport->nb_avion_dec][4];
    char nom_att[poport->nb_avion_att][20];
    char nom_comp_att[poport->nb_avion_att][20];
    int horaire_att[poport->nb_avion_att][2];
    int tab_att[poport->nb_avion_att][4];
    char nom_comp[poport->nb_avion][20];
    char nom[poport->nb_avion][20];
    int horaire[poport->nb_avion][2];
    int tab[poport->nb_avion][5];
    int redo, j, y=0, v=0, z, t, u, l, ind, carbu, liste;
    char tt[20];
    struct avion_dec* av_dec;
    struct avion_att* av_att;
    struct compagnie* comp = poport->debut;
    //do         //ne pas activer
    //{
        while(comp != NULL)                         //meme principe que pour en haut
        {
            av_dec = comp->depart;
            while(av_dec != NULL)
            {
                tab_dec[y][0] = av_dec->heure_depart;
                if(tab_dec[y][0] < heure)
                    horaire_dec[y][0] = tab_dec[y][0] + 24;
                else
                    horaire_dec[y][0] = tab_dec[y][0];
                tab_dec[y][1] = av_dec->minute_depart;
                horaire_dec[y][1] = tab_dec[y][1];
                tab_dec[y][2] = av_dec->carburant;
                tab_dec[y][3] = 0;
                strcpy(nom_dec[y], av_dec->nom);
                strcpy(nom_comp_dec[y], comp->nom);
                av_dec = av_dec->suivant;
                y++;
                //printf("a1\n");
            }
            av_att = comp->debut;
            while(av_att != NULL)
            {
                tab_att[v][0] = av_att->heure_arriver;
                if(tab_att[v][0] < heure)
                    horaire_att[v][0] = tab_att[v][0] + 24;
                else
                    horaire_att[v][0] = tab_att[v][0];
                tab_att[v][1] = av_att->minute_arriver;
                horaire_att[v][1] = tab_att[v][1];
                tab_att[v][2] = av_att->carburant;
                tab_att[v][3] = comp->liste_noire;
                strcpy(nom_att[v], av_att->nom);
                strcpy(nom_comp_att[v], comp->nom);
                av_att = av_att->suivant;
                v++;
                //printf("a2\n");
            }
            comp = comp->suivant;
            //printf("a3\n");
        }
        i=0;
        while(i<y)                  // tri des avions au decollages
        {
            t = horaire_dec[i][0];
            u = horaire_dec[i][1];
            ind = i;
            for(j=i; j<y; j++)
            {
                if(t > horaire_dec[j][0])
                {
                    t = horaire_dec[j][0];
                    ind = j;
                }else if(t == horaire_dec[j][0])
                {
                    if(u > horaire_dec[j][1])
                    {
                        u = horaire_dec[j][1];
                        ind = j;
                    }
                }
            }
            l = horaire_dec[i][0];
            horaire_dec[i][0] = horaire_dec[ind][0];
            horaire_dec[ind][0] = l;
            l = horaire_dec[i][1];
            horaire_dec[i][1] = horaire_dec[ind][1];
            horaire_dec[ind][1] = l;
            l = tab_dec[i][0];
            tab_dec[i][0] = tab_dec[ind][0];
            tab_dec[ind][0] = l;
            l = tab_dec[i][1];
            tab_dec[i][1] = tab_dec[ind][1];
            tab_dec[ind][1] = l;
            l = tab_dec[i][2];
            tab_dec[i][2] = tab_dec[ind][2];
            tab_dec[ind][2] = l;
            strcpy(tt, nom_dec[i]);
            strcpy(nom_dec[i], nom_dec[ind]);
            strcpy(nom_dec[ind], tt);
            strcpy(tt, nom_comp_dec[i]);
            strcpy(nom_comp_dec[i], nom_comp_dec[ind]);
            strcpy(nom_comp_dec[ind], tt);
            i++;
            //printf("a4\n");
        }
        i=0;
        int q, car;
        while(i<v)          //tri avions a l'atterrissage
        {
            t = horaire_att[i][0];
            u = horaire_att[i][1];
            ind = i;
            q = tab_att[i][2];
            z = tab_att[i][3];
            if(q < 20)
                car = 1;
            else
                car = 0;
            for(j=i; j<v; j++)
            {
                if(q > tab_att[j][2] && tab_att[j][2] < 20)
                {
                    ind = j;
                    q = tab_att[j][2];
                    car = 1;
                }
                if(car == 0)
                {
                    if(tab_att[j][3] == 1)
                    {
                        z = 1;
                        ind = j;
                    }
                    if(z == 0)
                    {
                        if(t > horaire_att[j][0])
                        {
                            t = horaire_att[j][0];
                            ind = j;
                        }else if(t == horaire_att[j][0])
                        {
                            if(u > horaire_att[j][1])
                            {
                                u = horaire_att[j][1];
                                ind = j;
                            }
                        }
                    }
                }
            }
            l = horaire_att[i][0];
            horaire_att[i][0] = horaire_att[ind][0];
            horaire_att[ind][0] = l;
            l = horaire_att[i][1];
            horaire_att[i][1] = horaire_att[ind][1];
            horaire_att[ind][1] = l;
            l = tab_att[i][0];
            tab_att[i][0] = tab_att[ind][0];
            tab_att[ind][0] = l;
            l = tab_att[i][1];
            tab_att[i][1] = tab_att[ind][1];
            tab_att[ind][1] = l;
            l = tab_att[i][2];
            tab_att[i][2] = tab_att[ind][2];
            tab_att[ind][2] = l;
            l = tab_att[i][3];
            tab_att[i][3] = tab_att[ind][3];
            tab_att[ind][3] = l;
            strcpy(tt, nom_att[i]);
            strcpy(nom_att[i], nom_att[ind]);
            strcpy(nom_att[ind], tt);
            strcpy(tt, nom_comp_att[i]);
            strcpy(nom_comp_att[i], nom_comp_att[ind]);
            strcpy(nom_comp_att[ind], tt);
            i++;
            //printf("a5\n");
        }
        int nb_av = poport->nb_avion, ind_att=0, ind_dec=0, carbu_dec, h_d, h_a, m_d, m_a;
        i=0;
        if(conti_att != 0)
        {
            h_a = tab_att[ind_att][0];
            m_a = tab_att[ind_att][1];
            carbu = tab_att[ind_att][2];
            liste = tab_att[ind_att][3];
        }
        while((carbu < 20 || liste == 1) && conti_att != 0)             //debut de la combinaison des deux tableaux
        {                                                               //ici tri en fonction du carburant et de la liste noir
            tab[i][0] = h_a;
            tab[i][1] = m_a;
            tab[i][2] = carbu;
            tab[i][3] = liste;
            tab[i][4] = 2;
            strcpy(nom[i], nom_att[ind_att]);
            strcpy(nom_comp[i], nom_comp_att[ind_att]);
            ind_att++;
            i++;
            conti_att--;
            if(conti_att != 0)
            {
                h_a = tab_att[ind_att][0];
                m_a = tab_att[ind_att][1];
                carbu = tab_att[ind_att][2];
                liste = tab_att[ind_att][3];
            }
            //printf("a6\n");
        }
        while(i < poport->nb_avion)
        {
            if(conti_dec != 0)                      //verification du nombre d'avion qui decolle
            {
                h_d = horaire_dec[ind_dec][0];
                m_d = horaire_dec[ind_dec][1];
                carbu_dec = tab_dec[ind_dec][2];
            }
            if(conti_att != 0)                  //verification du nombre d'avion qui atterisse
            {
                h_a = horaire_att[ind_att][0];
                m_a = horaire_att[ind_att][1];
                carbu = tab_att[ind_att][2];
            }
            if(conti_att != 0 && conti_dec != 0)            //tri des deux tableau
            {
                if(h_d > h_a)
                {
                    tab[i][0] = tab_att[ind_att][0];
                    tab[i][1] = tab_att[ind_att][1];
                    tab[i][2] = tab_att[ind_att][2];
                    tab[i][3] = tab_att[ind_att][3];
                    tab[i][4] = 2;
                    horaire[i][0] = h_a;
                    horaire[i][1] = m_a;
                    strcpy(nom[i], nom_att[ind_att]);
                    strcpy(nom_comp[i], nom_comp_att[ind_att]);
                    ind_att++;
                    i++;
                    conti_att--;
                }
                if(h_d == h_a)
                {
                    if(m_d > m_a)
                    {
                        tab[i][0] = tab_att[ind_att][0];
                        tab[i][1] = tab_att[ind_att][1];
                        tab[i][2] = tab_att[ind_att][2];
                        tab[i][3] = tab_att[ind_att][3];
                        tab[i][4] = 2;
                        horaire[i][0] = h_a;
                        horaire[i][1] = m_a;
                        strcpy(nom[i], nom_att[ind_att]);
                        strcpy(nom_comp[i], nom_comp_att[ind_att]);
                        ind_att++;
                        i++;
                        conti_att--;
                    }
                    if(m_d == m_a)
                    {
                        tab[i][0] = tab_dec[ind_dec][0];
                        tab[i][1] = tab_dec[ind_dec][1];
                        tab[i][2] = tab_dec[ind_dec][2];
                        tab[i][3] = 0;
                        tab[i][4] = 1;
                        horaire[i][0] = h_d;
                        horaire[i][1] = m_d;
                        strcpy(nom[i], nom_dec[ind_dec]);
                        strcpy(nom_comp[i], nom_comp_dec[ind_dec]);
                        ind_dec++;
                        i++;
                        conti_dec--;
                    }
                    if(m_d < m_a)
                    {
                        tab[i][0] = tab_dec[ind_dec][0];
                        tab[i][1] = tab_dec[ind_dec][1];
                        tab[i][2] = tab_dec[ind_dec][2];
                        tab[i][3] = 0;
                        tab[i][4] = 1;
                        horaire[i][0] = h_d;
                        horaire[i][1] = m_d;
                        strcpy(nom[i], nom_dec[ind_dec]);
                        strcpy(nom_comp[i], nom_comp_dec[ind_dec]);
                        ind_dec++;
                        i++;
                        conti_dec--;
                    }
                }
                if(h_d < h_a)
                {
                    tab[i][0] = tab_dec[ind_dec][0];
                    tab[i][1] = tab_dec[ind_dec][1];
                    tab[i][2] = tab_dec[ind_dec][2];
                    tab[i][3] = 0;
                    tab[i][4] = 1;
                    horaire[i][0] = h_d;
                    horaire[i][1] = m_d;
                    strcpy(nom[i], nom_dec[ind_dec]);
                    strcpy(nom_comp[i], nom_comp_dec[ind_dec]);
                    ind_dec++;
                    i++;
                    conti_dec--;
                }
            }
            if(conti_dec == 0 && conti_att != 0)            // tri des avions qui atterisse
            {
                while(conti_att != 0)
                {
                    tab[i][0] = tab_att[ind_att][0];
                    tab[i][1] = tab_att[ind_att][1];
                    tab[i][2] = tab_att[ind_att][2];
                    tab[i][3] = tab_att[ind_att][3];
                    tab[i][4] = 2;
                    horaire[i][0] = h_a;
                    horaire[i][1] = m_a;
                    strcpy(nom[i], nom_att[ind_att]);
                    strcpy(nom_comp[i], nom_comp_att[ind_att]);
                    ind_att++;
                    conti_att--;
                    i++;
                }
            }   
            if(conti_att == 0 && conti_dec != 0)                //tri des avoins qui decolle
            {
                while(conti_dec != 0)
                {
                    tab[i][0] = tab_dec[ind_dec][0];
                    tab[i][1] = tab_dec[ind_dec][1];
                    tab[i][2] = tab_dec[ind_dec][2];
                    tab[i][3] = 0;
                    tab[i][4] = 1;
                    horaire[i][0] = h_d;
                    horaire[i][1] = m_d;
                    strcpy(nom[i], nom_dec[ind_dec]);
                    strcpy(nom_comp[i], nom_comp_dec[ind_dec]);
                    ind_dec++;
                    conti_dec--;
                    i++;
                }
            }
            //printf("a7\n");
        }
        int f=0, res, heur, minut, wait, cocelico = poport->nb_avion;
        struct avion_dec* sup_dec;
        struct avion_att* sup_att;
        system("clear");
        system("cat evenement.txt");
        heur = poport->heure;
        minut = poport->minute;
        i=0;
        redo = 0;
        while(i < cocelico && continuer == 0 && redo == 0)              //debut du deroulement des evenement
        {
            usleep(10000);          //evite que tout s'affiche d'un coup
            res = 0;
            minut++;    
            if(minut == 60)                             // fait la montre
            {
                minut = 0;
                heur++;
                if(heur == 24)
                    heur = 0;
            }
            curseur(13, 162);
            printf("%d", poport->meteo);
            curseur(19, 162);
            if(minut < 10)
                printf("%d:0%d", heur, minut);
            else
                printf("%d:%d", heur, minut);
            if(tab[i][2] < 20 && tab[i][4] == 2)            //verification pour le carburant
            {
                curseur(10+f, 4);
                printf("%s", nom[i]);
                curseur(10+f, 27);
                printf("%s", nom_comp[i]);
                curseur(10+f, 62);
                printf("%d:%d", heur, minut);
                curseur(10+f, 101);
                printf("%d", tab[i][2]);
                curseur(10+f, 122);
                printf("%d", tab[i][3]);
                fputs(nom[i], fichier);
                fputs(" a atterri\n", fichier);
                comp = poport->debut;
                while(strcmp(nom_comp[i], comp->nom) != 0)
                {
                    comp = comp->suivant;
                }
                av_att = comp->debut;
                while(strcmp(nom[i], comp->debut->nom) != 0)
                {
                    comp->debut = comp->debut->suivant;
                }
                sup_att = comp->debut;
                comp->debut = comp->debut->suivant;
                free(sup_att);
                comp->nb_avion--;
                poport->nb_avion--;
                poport->nb_avion_att--;
                curseur(6, 132);
                scanf("%d", &continuer);
                f = f + 3;
                res = 1;
                i++;
            }
            if(tab[i][3] == 1 && res == 0 && tab[i][4] == 2)            //verification pour la liste_noire
            {
                curseur(10+f, 4);
                printf("%s", nom[i]);
                curseur(10+f, 27);
                printf("%s", nom_comp[i]);
                curseur(10+f, 62);
                printf("%d:%d", heur, minut);
                curseur(10+f, 101);
                printf("%d", tab[i][2]);
                curseur(10+f, 122);
                printf("%d", tab[i][3]);
                fputs(nom[i], fichier);
                fputs(" a atterri\n", fichier);
                comp = poport->debut;
                while(strcmp(nom_comp[i], comp->nom) != 0)              //liberation de l'avion
                {
                    comp = comp->suivant;
                }
                while(strcmp(nom[i], comp->debut->nom) != 0)
                {
                    comp->debut = comp->debut->suivant;
                }
                sup_att = comp->debut;
                comp->debut = comp->debut->suivant;
                free(sup_att);
                comp->nb_avion--;
                poport->nb_avion--;
                poport->nb_avion_att--;
                curseur(6, 132);
                scanf("%d", &continuer);
                f = f + 3;
                res = 1;
                i++;
            }
            if(tab[i][0] == heur && tab[i][1] == minut && res == 0)     //  verification de l'horaire
            {
                curseur(10+f, 4);
                printf("%s", nom[i]);
                curseur(10+f, 27);
                printf("%s", nom_comp[i]);
                curseur(10+f, 62);
                printf("%d:%d", heur, minut);
                //heure_debut = heure;
                //minute_debut = minute;
                curseur(10+f, 101);
                printf("%d", tab[i][2]);
                curseur(10+f, 122);
                printf("%d", tab[i][3]);
                fputs(nom[i], fichier);
                if(tab[i][4] == 2)
                    fputs(" a atterri\n", fichier);
                else
                    fputs(" a décollé\n", fichier);
                comp = poport->debut;
                while(strcmp(nom_comp[i], comp->nom) != 0)                  //liberation de l'avion
                {
                    comp = comp->suivant;
                }
                if(tab[i][4] == 2)
                {
                    //curseur(50, 20);
                    while(strcmp(nom[i], comp->debut->nom) != 0)
                    {
                        comp->debut = comp->debut->suivant;
                        //printf("a2");
                    }
                    sup_att = comp->debut;
                    comp->debut = comp->debut->suivant;
                    free(sup_att);
                    comp->nb_avion--;
                    poport->nb_avion--;
                    poport->nb_avion_att--;
                    curseur(6, 132);
                    scanf("%d", &continuer);
                }
                if(tab[i][4] == 1)
                {
                    comp->depart = comp->depart;
                    //curseur(26, 27);
                    while(strcmp(nom[i], comp->depart->nom) != 0)
                    {
                        comp->depart = comp->depart->suivant;
                        //printf("a1");
                    }
                    sup_dec = comp->depart;
                    comp->depart = comp->depart->suivant;
                    free(sup_dec);
                    comp->nb_avion--;
                    poport->nb_avion--;
                    poport->nb_avion_dec--;
                }
                f = f + 3;
                i++;
            }
            /*for(j=i; j<cocelico; j++)
            {
                if(tab[i][4] == 2)
                {
                    tab[i][2]--;
                    if(tab[i][2] < 20)
                        redo = 1;
                }
            }*/
            poport->heure = heur;
            poport->minute = minute;
            //printf("a8\n");
        }
    //}while(redo == 1);
    curseur(6, 62);
    printf("Fin des évenements                            ");
    int retour;
    curseur(6, 132);
    scanf("%d", &retour);
    return poport;
}

void lib_avion_dec(struct compagnie *comp)
{
    struct avion_dec *sup = comp->depart;
    while(comp->depart != NULL)
    {
        sup = comp->depart;
        comp->depart = comp->depart->suivant;
        free(sup);
        //printf("a1\n");
    }
}

void lib_avion_att(struct compagnie *comp)
{
    struct avion_att *sup = comp->debut;
    while(comp->debut != NULL)
    {
        sup = comp->debut;
        comp->debut = comp->debut->suivant;
        free(sup);
        //printf("a1\n");
    }
}

void lib_compagnie(struct aeroport *poport)
{
    struct compagnie *sup;
    while(poport->debut != NULL)
    {
        lib_avion_dec(poport->debut);
        lib_avion_att(poport->debut);
        sup = poport->debut;
        poport->debut = poport->debut->suivant;
        free(sup);
        //printf("a2\n");
    }
}

void lib_aeorport(struct aeroport *poport)
{
    lib_compagnie(poport);
    free(poport);
}

/*int init_window(SDL_Window** window, int x, int y, int l, int h, char titre[20])
{
    *window = SDL_CreateWindow(titre, x, y, l, h, SDL_WINDOW_BORDERLESS);
    if(window == NULL)
    {
        fprintf(stderr, "%s\n", SDL_GetError());
        return -1;
    }
    return 0;
}

int init_renderer(SDL_Renderer** renderer, SDL_Window* window)
{
    *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == NULL)
    {
        fprintf(stderr, "%s\n", SDL_GetError());
        return -1;
    }
    return 0;
}*/

/*void liste_avion_dec(struct aeroport* poport, char **nom, int **tab)
{
    int i, j, y=0, t, u, l, ind;
    char tt[20];
    struct avion_dec* av;
    struct compagnie* comp = poport->debut;
    while(comp->suivant != NULL)
    {
        av = comp->depart;
        while(av->suivant != NULL)
        {
            tab[y][0] = av->heure_depart;
            tab[y][1] = av->minute_depart;
            tab[y][2] = av->carburant;
            strcpy(nom[y], av->nom);
            av = av->suivant;
            y++;
        }
        comp = comp->suivant;
    }
    i=0;
    while(i<y)
    {
        t = tab[i][0];
        u = tab[i][1];
        ind = i;
        for(j=i; j<y; j++)
        {
            if(t > tab[j][0])
            {
                t = tab[j][0];
                ind = j;
            }else if(t == tab[j][0])
            {
                if(u > tab[j][1])
                {
                    u = tab[j][1];
                    ind = j;
                }
            }
        }
        l = tab[i][0];
        tab[i][0] = tab[ind][0];
        tab[ind][0] = l;
        l = tab[i][1];
        tab[i][1] = tab[ind][1];
        tab[ind][1] = l;
        l = tab[i][2];
        tab[i][2] = tab[ind][2];
        tab[ind][2] = l;
        strcpy(tt, nom[i]);
        strcpy(nom[i], nom[ind]);
        strcpy(nom[ind], tt);
        i++;
    }
}

void liste_avion_att(struct aeroport* poport, char **nom, int **tab)
{
    int i, j, y=0, t, u, l, ind;
    char tt[20];
    struct avion_dec* av;
    struct compagnie* comp = poport->debut;
    while(comp->suivant != NULL)
    {
        av = comp->depart;
        while(av->suivant != NULL)
        {
            tab[y][0] = av->heure_depart;
            tab[y][1] = av->minute_depart;
            tab[y][2] = av->carburant;
            strcpy(nom[y], av->nom);
            av = av->suivant;
            y++;
        }
        comp = comp->suivant;
    }
    i=0;
    while(i<y)
    {
        t = tab[i][0];
        u = tab[i][1];
        ind = i;
        for(j=i; j<y; j++)
        {
            if(t > tab[j][0])
            {
                t = tab[j][0];
                ind = j;
            }else if(t == tab[j][0])
            {
                if(u > tab[j][1])
                {
                    u = tab[j][1];
                    ind = j;
                }
            }
        }
        l = tab[i][0];
        tab[i][0] = tab[ind][0];
        tab[ind][0] = l;
        l = tab[i][1];
        tab[i][1] = tab[ind][1];
        tab[ind][1] = l;
        l = tab[i][2];
        tab[i][2] = tab[ind][2];
        tab[ind][2] = l;
        strcpy(tt, nom[i]);
        strcpy(nom[i], nom[ind]);
        strcpy(nom[ind], tt);
        i++;
    }
}

void fusion_dec_att(struct aeroport* poport, char nom_dec[][], char nom_att[][], char nom[][], int tab_dec[][], int tab_att[][], int tab[][])
{
    int nb_av = poport->nb_avion, i=0, ind_att=0, ind_dec=0, h_d, h_a, m_d, m_a;
    while(i < nb_av)
    {
        h_d = tab_dec[ind_dec][0];
        m_d = tab_dec[ind_dec][1];
        h_a = tab_att[ind_att][0];
        m_a = tab_att[ind_att][1];
        if(h_d > h_a)
        {
            tab[i][0] = h_a;
            tab[i][1] = m_a;
            strcpy(nom[i], nom_att[ind_att]);
            ind_att++;
        }else if(h_d == h_a)
        {
            if(m_d > m_a)
            {
                tab[i][0] = h_a;
                tab[i][1] = m_a;
                strcpy(nom[i], nom_att[ind_att]);
                ind_att++;
            }else if(m_d == m_a)
            {
                tab[i][0] = h_d;
                tab[i][1] = m_d;
                strcpy(nom[i], nom_dec[ind_dec]);
                ind_dec++;
            }else
            {
                tab[i][0] = h_d;
                tab[i][1] = m_d;
                strcpy(nom[i], nom_dec[ind_dec]);
                ind_dec++;
            }
        }else
        {
            tab[i][0] = h_d;
            tab[i][1] = m_d;
            strcpy(nom[i], nom_dec[ind_dec]);
            ind_dec++;
        }
        i++;
    }
}*/

