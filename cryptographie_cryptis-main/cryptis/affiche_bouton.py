# Bouvier d'Acher Victor
# Classe 42
# Projet Cryptographie
# Cryptis

import pygame
import numpy as np
from constante import *
from text import *
from bouton import *

def rect_auto(ecran, page):				# bouton auto lorsque l'on joue en solo en arcade
	souris = pygame.mouse.get_pos()

	rect = pygame.Rect(pos_auto, taille_auto)

	mot = "AUTO"

	if page == "auto":
		mot = "ARRET"


	if souris_sur_rect(souris, pos_auto, taille_auto):
		pygame.draw.rect(ecran, blanc, rect, 5)
		afficher(ecran, mot, blanc, pos_auto[0]+taille_auto[0]/2, pos_auto[1]+taille_auto[1]/2, 30)

	else:
		pygame.draw.rect(ecran, vert, rect, 5)
		afficher(ecran, mot, vert, pos_auto[0]+taille_auto[0]/2, pos_auto[1]+taille_auto[1]/2, 30)



class rect_affichage:

	def __init__(self, ecran, pos, taille, mot, couleur=vert, change=True, police=30):
		self.police = police
		self.ecran = ecran
		self.pos = pos
		self.taille = taille
		self.couleur = couleur
		self.rect = pygame.Rect(pos, taille)
		self.mot = mot
		self.change = change

	def afficher_rect(self):		# affiche le rect et change la couleur du rect si le curseur de la souris pointe sur le bouton

		souris = pygame.mouse.get_pos()

		if souris_sur_rect(souris, self.pos, self.taille) and self.change:
			pygame.draw.rect(self.ecran, blanc, self.rect, 5)
			afficher(self.ecran, self.mot, blanc, self.pos[0]+self.taille[0]/2, self.pos[1]+self.taille[1]/2, self.police)

		else:
			pygame.draw.rect(self.ecran, gris, self.rect, 5)
			afficher(self.ecran, self.mot, self.couleur, self.pos[0]+self.taille[0]/2, self.pos[1]+self.taille[1]/2, self.police)

