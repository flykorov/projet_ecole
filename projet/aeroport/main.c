#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
//#include <SDL/SDL.h>
//#include "SDL/SDL_ttf.h"
#include "avion.h"

#define curseur(x,y) printf("\033[%d;%dH", (x), (y))

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

int main()
{
    int utilisateur, continuer = 1;
    int enl = 0;
    FILE *fichier = NULL;
    fichier = fopen("aeroport_log.txt", "w");
    struct aeroport* poport;
    struct compagnie* comp;
    poport = creer_aero();
    while(continuer == 1)
    {
        system("clear");
        system("cat aero_debut.txt");
        curseur(34, 87);
        scanf("%d", &utilisateur);
        switch(utilisateur)
        {
            case 0:
            continuer = 0;
            break;
            case 1:
            poport = creer_compagnie(poport);
            break;
            case 2:
            poport = creer_avion(poport);
            break;
            case 3:
            voir_avion_comp(poport);
            break;
            case 4:
            comp = liste_noire(poport, &enl);
            break;
            case 5:
            voir_avion_attente_dec(poport);
            break;
            case 6:
            voir_avion_attente_att(poport);
            break;
            case 7:
            poport = deroulement_evenement(poport, fichier);
            //printf("nbavion%d", poport->nb_avion);
            default:
            continuer = 1;
        }
    }
    lib_aeorport(poport);
    fclose(fichier);
    system("clear");
    return 0;
}
/*SDL_Window *terminal = NULL;
    SDL_Renderer *ren_term = NULL;
    SDL_Surface* image = NULL;
    SDL_Event event;
    if(0 != SDL_Init(SDL_INIT_VIDEO))
    {
        fprintf(stderr, "Erreur SDL_Init : %s", SDL_GetError());
        goto Quit;
    }
    if(init_window(&terminal, 0, 0, 1280, 1080, "terminal") != 0)
        goto Quit;
    if(init_renderer(&ren_term, terminal) != 0)
        goto Quit;

    SDL_SetRenderDrawColor(ren_term, 0, 255, 0, 0);
    SDL_RenderClear(ren_term);
    SDL_RenderPresent(ren_term);
    SDL_Delay(5000);*/
/*SDL_bool quit = SDL_FALSE;
    while(!quit)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
                quit = SDL_TRUE;
        }
        SDL_Delay(60);
    }*/
//printf("a4\n");
    /*Quit:
    if(ren_term != NULL)
        SDL_DestroyRenderer(ren_term);
    if(terminal != NULL)
        SDL_DestroyWindow(terminal);
    SDL_Quit();*/