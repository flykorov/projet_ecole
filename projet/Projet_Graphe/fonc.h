#include "struct.h"
struct prems* ouvre_carte(int** carte, struct prems* lacrimatica, struct donne* donner);
struct prems* distance_ville(struct prems* lacrimatica);
void arbre_couvrant_poids_min(struct prems* lacrimatica, struct init_poids_min* ouaient, float** poids);
void init_poids(float** poids);
void matrice_de_poids(struct prems* lacrimatica, float** poids, struct donne* donner);
void tri_poids(float** poids, int** pdf, float* marchepas, struct donne* donner);
void sup_case(int** pdf, float* con_depart, struct donne* donner);
int cont_neg(int** pdf, struct donne* donner);
void chang_tab(int** pdf, float* con_depart, int** con_mil, float* dis_mil, struct donne* donner);
void poids_min(int** con_mil, float* dis_mil, float* dis_fin, int** con_final, struct donne* donner);
float poids_aretes(float* dis_fin);