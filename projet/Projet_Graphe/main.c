#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <SDL2/SDL.h>
#include "fonc.h"
#include "lib.h"
#include "allouer.h"
#include "affiche.h"
#include "SDL.h"
#include "donne.h"
#include "huffman.h"
#include "compression.h"

int main()
{
	struct prems* lacrimatica;		//struct pointant vers les donnees des villes
	struct init_comp* pourquoi;		//struct utiliser pour la compression huffman
	struct donne* donner;		//differente donnee intrinsect a carte.txt
	// struct compression* alors;
	donner = allouer_donne();
	donner->colonne_carte = taille_colonnes();
	donner->ligne_carte = taille_lignes();
	donner->taille_carte = donner->ligne_carte * donner->colonne_carte;
	donner->nb_ville = nb_ville();
	donner->con_fin = donner->nb_ville-1;
	donner->nb_con = (donner->nb_ville)*2 + 1;
	donner->nb_connexion = donner->nb_con * 2;
	lacrimatica = creer_prems(donner);
	float** poids = allouer_mat_float(donner->nb_ville, donner->nb_ville);
	float* con_depart = malloc(donner->nb_connexion * sizeof(float));
	int** pdf = allouer_mat(donner->nb_connexion, 2);
	int** carte = alloue_mat(donner);
	int nb_char =  nb_char_dico("carte.txt"); 
	int** dico = allouer_mat(nb_char, 2);
	int** dico_tri = allouer_mat(nb_char, 2);
	int** bin = allouer_mat(nb_char, 9);
	mat_neg1(bin, nb_char, 9);
	int** con_final = allouer_mat(donner->con_fin, 2);
	float* dis_fin = malloc(donner->con_fin * sizeof(float));
	struct init_poids_min* str_poids_min =  creer_init_poids_min(donner);
	
	lacrimatica = ouvre_carte(carte, lacrimatica, donner);		//sol des 5 premiers exo
	distance_ville(lacrimatica);
	matrice_de_poids(lacrimatica, poids, donner);
	tri_poids(poids, pdf, con_depart, donner);

	reint_fic_cod("arbre_codage.txt");		//15 prochaines lignes compression carte
	reint_fic("sequence_codee.txt");
	creation_dico(dico, nb_char, "carte.txt");
	creation_dico(dico_tri, nb_char, "carte.txt");
	tri_dico(dico, nb_char);
	fake_tri_dico(dico_tri, nb_char);
	pourquoi = creer_init_comp();
	alloue_comp(pourquoi, dico_tri, nb_char);
	creer_arbre(pourquoi);
	arbre_de_codage(pourquoi, "arbre_codage.txt");
	sequence_codee(pourquoi, "sequence_codee.txt");
	reception_codee(bin, nb_char, "sequence_codee.txt");
	compression_bin(bin, nb_char, "carte.txt", "bin_carte.txt");
	fichier_compresser(pourquoi, "compression_carte.txt", "bin_carte.txt", "arbre_codage.txt");


	affiche_carte(carte, donner);
	affiche_coor(lacrimatica);
	affiche_distance(lacrimatica);
	affiche_dico(dico, nb_char);
	affiche_dico(dico_tri, nb_char);
	affiche_arbre(pourquoi);
	affiche_poids(poids, donner->nb_ville, donner->nb_ville);
	affiche_sequence_codee(bin, nb_char);
	// affiche_tri_poids(pdf, con_depart);
	sup_case(pdf, con_depart, donner);
	// affiche_tri_poids(pdf, con_depart);
	int con = cont_neg(pdf, donner);
	int** con_mil = allouer_mat(con, 2);
	float* dis_mil = malloc(con * sizeof(float));
	chang_tab(pdf, con_depart, con_mil, dis_mil, donner);
	// affiche_new_tri_poids(con_mil, dis_mil);
	poids_min(con_mil, dis_mil, dis_fin, con_final, donner);
	// affiche_rep_poids_min(dis_fin, con_final);
	poids_aretes(dis_fin);
	// affiche_poids_min(str_poids_min);
	int** mat = allouer_mat(13, 8);
	int** tab = allouer_mat(13, 2);
	dechiffre_sequence(mat, tab, "compression_carte.txt", "decom_carte.txt", 13, 8);


	cree_fic(lacrimatica, con_final, donner);

	int nb_cara = nb_char_dico("solution.txt");			//20 prochaine ligne compresse la solution optimal
	int** dico_sol = allouer_mat(nb_cara, 2);
	int** bin2 = allouer_mat(nb_cara, 9);
	mat_neg1(bin2, nb_cara, 9);

	reint_fic_cod("arbre_sol.txt");
	reint_fic("sequence_sol.txt");
	creation_dico(dico_sol, nb_cara, "solution.txt");
	fake_tri_dico(dico_sol, nb_cara);
	struct init_comp* alors = creer_init_comp();
	alloue_comp(alors, dico_sol, nb_cara);
	creer_arbre(alors);
	arbre_de_codage(alors, "arbre_sol.txt");
	sequence_codee(alors, "sequence_sol.txt");
	reception_codee(bin2, nb_cara, "sequence_sol.txt");
	compression_bin(bin2, nb_cara, "solution.txt", "bin_solution.txt");
	fichier_compresser(alors, "compression_solution.txt", "bin_solution.txt", "arbre_sol.txt");
	int** mat2 = allouer_mat(nb_cara, 8);
	int** tab2 = allouer_mat(nb_cara, 2);
	dechiffre_sequence(mat2, tab2, "compression_solution.txt", "decom_solution.txt", nb_cara, 8);

	SDL_aff(lacrimatica, con_final);

	liber_mat(bin2, nb_cara);
	liber_mat(dico_sol, nb_cara);
	liber_mat(mat, 13);
	liber_mat(tab, 13);
	liber_mat(mat2, nb_cara);
	liber_mat(tab2, nb_cara);
	// affiche_mec(alors->debut);

	lib_struct(lacrimatica);
	liber_mat(dico, nb_char);
	liber_mat(dico_tri, nb_char);
	liber_mat_float(poids, donner->nb_ville);
	lib_mat(carte, donner);
	// lib_tab(con_mil);
	// lib_tab(dis_mil);
	lib_pourquoi(pourquoi);
	lib_pourquoi(alors);
	// lib_mec(alors->debut);
	// free(alors);
	lib_poids_min(str_poids_min);
	liber_mat(bin, nb_char);
	liber_mat(pdf, donner->nb_connexion);
	liber_mat(con_mil, donner->nb_con);
	liber_mat(con_final, donner->con_fin);
	free(donner);
	free(dis_fin);
	free(con_depart);
	free(dis_mil);
	// printf("%d\n", nb_cara);
	return 0;
}