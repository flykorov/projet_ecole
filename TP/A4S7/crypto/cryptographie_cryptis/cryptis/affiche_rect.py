# Bouvier d'Acher Victor
# Classe 42
# Projet Cryptographie
# Cryptis

import pygame
import numpy as np
from constante import *

# nb_rect = 0

def compter_nb_rect(clef, message):			# compte la somme du nombre max(abs) de la clef et du messages
	t = len(clef)
	m = message[0:t]
	v = np.max(np.abs(clef)) + np.max(np.abs(m))
	nb_rect = np.max(v)
	# print(f'nb_rect {nb_rect}')
	return nb_rect

def contour_rect(ecran, clef, pos, div):		# affiche le contour du jeu (en rouge)
	t = len(clef)
	plus = (t+1) * espace_entre_rect_clef + 10 + t * largeur_rect
	v = (int(plus/div)+espace_entre_rect_clef, 800)
	rect = pygame.Rect(pos, v)
	pygame.draw.rect(ecran, rouge, rect, 5)

def calcul_hauteur(clef, message):				# calcul la hauteur des rectangles afficher en fonction de leurs nombres

	divise = 1
	espace = espace_entre_rect_clef
	taille_rect = hauteur_max_rect_clef

	nb_rect = compter_nb_rect(clef, message)
	# print(taille[1]-100)
	# print(espace * nb_rect + taille_rect * nb_rect)

	while(taille_dep[1] - 50 < espace * nb_rect + taille_rect * nb_rect):
		# print(taille[1]-100)
		# print(espace * nb_rect + taille_rect * nb_rect)
		taille_rect -= 1
		if taille_rect == 0:
			nb_rect /= 2					# divise par 2 le nombre de rect afficher, permet de ne pas deborder de l'écran
			taille_rect = 1
			divise += 1

		if taille_rect%4 == 0:
			espace -= 1
			if espace == 0:
				nb_rect /= 2
				espace = 1
				divise += 1

	return taille_rect, espace, divise



def rect_clef(ecran, clef, message, pos, div):		# affiche la clef 

	taille = len(clef)
	t = pos[0]

	rect_clef = []

	
	t += 10

	taille_rect, espace, divise = calcul_hauteur(clef, message)

	for i in range(taille):
		rect_clef.append(t)
		t += int(largeur_rect/div) + int(espace_entre_rect_clef/div)

	
	for i, v in enumerate(clef):
		if v != 0:
			couleur = (0, 0, 0)
			if v < 0:
				couleur = couleur_moins
			else:
				couleur = couleur_plus

			for j in range(int(abs(v)/divise)):
				h = pos[1] + 10 + j * taille_rect + j * espace
				rect = pygame.Rect((rect_clef[i], h), (int(largeur_rect/div), taille_rect))
				pygame.draw.rect(ecran, couleur, rect)


def rect_message(ecran, message, clef, pos, div):		# affiche le message

	taille = len(clef)

	t = pos[0] + 10

	rect_clef = []

	taille_rect, espace, divise = calcul_hauteur(clef, message)


	for i in range(taille):
		rect_clef.append(t)
		t += int(largeur_rect/div) + int(espace_entre_rect_clef/div)

	m = message[0:taille]
	# print(m)

	for i, v in enumerate(m):
		if v != 0:
			couleur = (0, 0, 0)
			if v < 0:
				couleur = couleur_moins
			else:
				couleur = couleur_plus

			for j in range(int(abs(v) / divise)):
				h = taille_dep[1] + pos[1] - 10 - taille_rect - j * taille_rect - j * espace
				rect = pygame.Rect((rect_clef[i], h), (int(largeur_rect/div), taille_rect))
				pygame.draw.rect(ecran, couleur, rect)


