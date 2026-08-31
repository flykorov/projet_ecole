# Bouvier d'Acher Victor
# Classe 42
# Projet Cryptographie
# Cryptis

import numpy as np
import random
from constante import *


def melanger_tab(clef_prive):			# melange la clef privée 
	taille = len(clef_prive)
	for i in range(taille*2):
		a = random.randint(0, taille-1)
		b = random.randint(0, taille-1)

		clef_prive[a], clef_prive[b] = clef_prive[b], clef_prive[a]

	return clef_prive

def creer_clef_privee(taille):			# creer la clef privée


	clef_prive = np.ones(taille, dtype=np.int64)
	
	for i in range(taille-1):			# creer les petits chiffres de la clef privée
		# b = random.randint(-int(i/4), int(i/4))
		clef_prive[i] = int(i/4) + random.randint(-int(i/8), int(i/8))
		a = random.randint(0, 1)
		if a == 0:
			clef_prive[i] = -clef_prive[i]

	clef_prive[taille-1] = random.randint(taille - int(taille/8), taille + int(taille/8))	# creer la grosse bar de la clef privée
	a = random.randint(0, 1)
	if a == 0:
		clef_prive[taille-1] = -clef_prive[taille-1]

	clef_prive = melanger_tab(clef_prive)

	return clef_prive


def creer_clef_public(clef_prive):		# creer la clef publique
	taille = len(clef_prive)
	clef_public = np.zeros(taille, dtype=np.int64)
	excelent = False
	signe = 1
	tab = np.zeros(taille, dtype=np.int64)
	while not excelent:					# pour creer une bonne clef publique
		a = random.randint(0, 3)
		if a == 0:						# deplace la clef à droite
			clef_prive = np.roll(clef_prive, 1)
			tab = np.roll(tab, 1)
		if a == 1:						# deplace la clef à gauche
			clef_prive = np.roll(clef_prive, -1)
			tab = np.roll(tab, -1)
		if a == 2:						# inverse la clef
			clef_prive = -clef_prive
			signe = -signe
		if a == 3:						# ajoute la clef
			clef_public += clef_prive
			tab[0] += signe

		nombre_0 = np.count_nonzero(tab == 0)
		# print(nombre_0)
		if np.count_nonzero(tab == 0) < 5:			# la majorité des chiffres du tableau doivent avoir été incrémenté au moins une fois par la grosse bar
			excelent = True

		# if nb > taille * 6 and nb_bon >= taille/2:
		# 	excelent = True


	return clef_public


# archive
def compter_case(clef_public):
	taille = len(clef_public)
	nb = 0
	nb_bon = 0
	for i in range(taille):
		if clef_public[i] < 0:
			nb -= clef_public[i]
		else:
			nb += clef_public[i]
		if clef_public[i] >= taille:
			nb_bon += 1
	return nb, nb_bon


