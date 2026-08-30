#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <stdbool.h>
#include "struct.h"

//80 premieres lignes de ce fichier inutiliser tout est dans deux fonctions les deux dernieres

int init_window(SDL_Window** window, int l, int h)
{
	if(0 != SDL_Init(SDL_INIT_VIDEO))
    {
        fprintf(stderr, "Erreur SDL_Init : %s\n", SDL_GetError());
        return -1;
    }
	*window = SDL_CreateWindow("France", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, l, h, SDL_WINDOW_SHOWN);
	if(window == NULL)
	{
		fprintf(stderr, "%s\n", SDL_GetError());
		return -1;
	}
	return 0;
}

void lib_window(SDL_Window* window)
{
	SDL_DestroyWindow(window);
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

void lib_renderer(SDL_Renderer* renderer)
{
	SDL_DestroyRenderer(renderer);
}

int init_texture(SDL_Texture** texture, SDL_Renderer* renderer, int l, int h)
{
	*texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, l, h);
	if(texture == NULL)
	{
		fprintf(stderr, "%s\n", SDL_GetError());
		return -1;
	}
	return 0;
}

void lib_texture(SDL_Texture* texture)
{
	SDL_DestroyTexture(texture);
}

SDL_Texture* load_france(SDL_Renderer* renderer)
{
	SDL_Surface *surface = NULL;
	SDL_Texture *texture = NULL;
    surface = SDL_LoadBMP("France.bmp");
    if(NULL == surface)
    {
        fprintf(stderr, "%s", SDL_GetError());
        return NULL;
    }
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    if(NULL == texture)
    {
        fprintf(stderr, "%s", SDL_GetError());
        return NULL;
    }
    return texture;
}

void SDL_affiche_poids_min(SDL_Renderer* renderer, SDL_Texture* texture, struct prems* lacrimatica, int** con_final)
{
	int i, x1, x2, y1, y2, arret;
	struct cartographie* carto;
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	for(i=0; i<16; i++)
	{
		arret = 0;
		carto = lacrimatica->debut;
		while(carto != NULL && arret != 2)
		{
			if(carto->id == con_final[i][0]+1)
			{
				// printf("a\n");
				x1 = carto->x;
				y1 = carto->y;
				arret++;
			}
			if(carto->id == con_final[i][1]+1)
			{
				// printf("b\n");
				x2 = carto->x;
				y2 = carto->y;
				arret++;
			}
			// printf("%d\n", arret);
			carto = carto->suivant;
		}
		SDL_RenderDrawLine(renderer, y1*26, x1*27, y2*26, x2*27);
		// SDL_Delay(1000);
		SDL_RenderPresent(renderer);
	}
	
}

void SDL_aff(struct prems* lacrimatica, int** con_final)
{
	if(SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        fprintf(stderr, "Erreur SDL_Init : %s\n", SDL_GetError());
        goto lib;
    }
    SDL_Surface *surface = SDL_LoadBMP("France.bmp");
	SDL_Window* window = SDL_CreateWindow("France", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, surface->w, surface->h, SDL_WINDOW_SHOWN);
	if(window == NULL)
	{
		fprintf(stderr, "Erreur SDL_Window : %s\n", SDL_GetError());
		goto lib;
	}
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if(renderer == NULL)
	{
		fprintf(stderr, "Erreur SDL_Renderer : %s\n", SDL_GetError());
		goto lib;
	}
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	if(texture == NULL)
	{
		fprintf(stderr, "Erreur SDL_Texture : %s\n", SDL_GetError());
		goto lib;
	}
	SDL_RenderClear(renderer);
	SDL_SetRenderTarget(renderer, texture);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);
	SDL_affiche_poids_min(renderer, texture, lacrimatica, con_final);
	SDL_Event event;
	SDL_bool continuer = SDL_TRUE;
	// printf("\n%d %d\n", surface->h/24, surface->w/26);
	while(continuer)
	{
		SDL_PollEvent(&event);
		if(event.type == SDL_QUIT)
			continuer = SDL_FALSE;
	}


lib:
	if(surface != NULL)
		SDL_FreeSurface(surface);
	if(texture != NULL)
		SDL_DestroyTexture(texture);
	if(renderer != NULL)
		SDL_DestroyRenderer(renderer);
	if(window != NULL)
		SDL_DestroyWindow(window);
	SDL_Quit();
}