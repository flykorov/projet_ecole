# Bouvier d'Acher Victor
# Classe 42
# Projet Cryptographie
# Cryptis

import pygame
import numpy as np
from constante import *

def souris_sur_rect(souris, pos, taille):		# verifie si la souris est sur le rectangle
	if souris[0] >= pos[0] and souris[0] <= pos[0]+taille[0] and souris[1] >= pos[1] and souris[1] <= pos[1]+taille[1]:
		return True

def bouton(bou, page, t_clef, type_etat, vitesse):		# verifie qu'elle bouton est cliquer

	typ = type_etat

	souris = pygame.mouse.get_pos()
	if bou == 1:
		if souris_sur_rect(souris, pos_auto, taille_auto) and page == "jeu":
			page = "auto"
		elif souris_sur_rect(souris, pos_auto, taille_auto) and page == "auto":
			page = "jeu"

		if souris_sur_rect(souris, pos_droit, taille_droit) and page == "choix":
			if t_clef < 16:
				t_clef += 1

		if souris_sur_rect(souris, pos_gauche, taille_gauche) and page == "choix":
			if t_clef > 8:
				t_clef -= 1 

		if souris_sur_rect(souris, pos_droit_vit, taille_droit_vit) and page == "choix":
			if vitesse < 30:
				vitesse += 1

		if souris_sur_rect(souris, pos_gauche_vit, taille_gauche_vit) and page == "choix":
			if vitesse > 1:
				vitesse -= 1 

		if souris_sur_rect(souris, pos_jouer, taille_jouer) and page == "choix":
			page = "init"

		if souris_sur_rect(souris, pos_prive, taille_prive) and page == "choix":
			typ[0] = 1

		if souris_sur_rect(souris, pos_public, taille_public) and page == "choix":
			typ[0] = 2

		if souris_sur_rect(souris, pos_prive_bot, taille_prive_bot) and page == "choix":
			typ[1] = 1

		if souris_sur_rect(souris, pos_public_bot, taille_public_bot) and page == "choix":
			typ[1] = 2

		if souris_sur_rect(souris, pos_mode_solo, taille_mode_solo) and page == "choix":
			typ[2] = 1

		if souris_sur_rect(souris, pos_mode_versus, taille_mode_versus) and page == "choix":
			typ[2] = 2

		if souris_sur_rect(souris, pos_arcade, taille_arcade) and page == "menu":
			page = "choix"

		if souris_sur_rect(souris, pos_dico, taille_dico) and page == "menu":
			page = "dico"

		# if souris_sur_rect(souris, pos_docu, taille_docu) and page == "menu":
		# 	page = "docu"

		if souris_sur_rect(souris, pos_croix, taille_croix) and page != "menu":
			page = "menu"

		

		if souris_sur_rect(souris, pos_quit, taille_quit) and page == "menu":
			page = "quit"


	return page, t_clef, typ, vitesse

