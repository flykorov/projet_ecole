int init_window(SDL_Window** window, int l, int h);
void lib_window(SDL_Window* window);
int init_renderer(SDL_Renderer** renderer, SDL_Window* window);
void lib_renderer(SDL_Renderer* renderer);
int init_texture(SDL_Texture** texture, SDL_Renderer* renderer, int l, int h);
void lib_texture(SDL_Texture* texture);
void SDL_affiche_poids_min(SDL_Renderer* renderer, SDL_Texture* texture, struct prems* lacrimatica, int** con_final);
void SDL_aff(struct prems* lacrimatica, int** con_final);
