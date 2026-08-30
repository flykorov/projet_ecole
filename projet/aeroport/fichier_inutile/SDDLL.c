#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL/SDL_ttf.h>

//$(sdl2-config --cflags --libs)

int init_window(SDL_Window** window, int x, int y, int l, int h, char titre[20])
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
}

int main(int argc, char *argv[])
{
    SDL_Window *terminal = NULL, *atterrissage = NULL, *decollage = NULL;
    SDL_Renderer *ren_term = NULL, *ren_att = NULL, *ren_dec = NULL;
    SDL_Surface* texte = NULL;
    //FILE* aff;
    SDL_Color blanc = {255, 255, 255};
    //char car;
    if(0 != SDL_Init(SDL_INIT_VIDEO))
    {
        fprintf(stderr, "Erreur SDL_Init : %s", SDL_GetError());
        goto Quit;
    }
    if(TTF_Init() == -1)
    {
    	fprintf(stderr,"Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
    	goto Quit;
    }
    //aff = fopen("projet_c_menu.txt", "r");
    /*if(aff == NULL)
    {
    	printf("Erreur ouverture du fichier\n");
    	goto Quit;
    }*/
    TTF_Font* font = NULL;
    font = TTF_OpenFont("Monospace/Monospace.ttf", 12);
    if(init_window(&terminal, 0, 0, 1280, 1080, "terminal") != 0)
        goto Quit;
    //if(init_window(&decollage, 1280, 0, 640, 540, "decollage") != 0)
        goto Quit;
    //if(init_window(&atterrissage, 1280, 540, 640, 540, "atterrissage") != 0)
        goto Quit;
    if(init_renderer(&ren_term, terminal) != 0)
		goto Quit;
	//if(init_renderer(&ren_dec, decollage) != 0)
		goto Quit;
	//if(init_renderer(&ren_att, atterrissage) != 0)
		goto Quit;	
	SDL_SetRenderDrawColor(ren_term, 0, 255, 0, 0);
	SDL_RenderClear(ren_term);
	//car = fgetc(aff);
	TTF_RenderText_Blended(font, "car", blanc);
	SDL_RenderPresent(ren_term);
	//SDL_SetRenderDrawColor(ren_att, 255, 0, 0, 0);
	//SDL_RenderClear(ren_att);
	//SDL_RenderPresent(ren_att);
	//SDL_SetRenderDrawColor(ren_dec, 0, 0, 255, 0);
	//SDL_RenderClear(ren_dec);
	//SDL_RenderPresent(ren_dec);
    SDL_Delay(5000);

Quit:
	if(texte != NULL)
		SDL_FreeSurface(texte);
	if(ren_term != NULL)
		SDL_DestroyRenderer(ren_term);
	if(ren_dec != NULL)
		SDL_DestroyRenderer(ren_dec);
	if(ren_att != NULL)
		SDL_DestroyRenderer(ren_att);
	if(terminal != NULL)
		SDL_DestroyWindow(terminal);
	if(atterrissage != NULL)
		SDL_DestroyWindow(atterrissage);
	if(decollage != NULL)
		SDL_DestroyWindow(decollage);
	//fclose(aff);
	TTF_CloseFont(font);
	TTF_Quit();
	SDL_Quit();
	return 0;
}