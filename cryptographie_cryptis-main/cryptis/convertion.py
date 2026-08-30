# Bouvier d'Acher Victor
# Classe 42
# Projet Cryptographie
# Cryptis

import numpy as np
from constante import *

def convertir_texte_into_tab(message, dico):
	taille = len(message)
	tab = np.zeros(taille*5, dtype=np.int64)
	indice=0
	for i in message:
		a = dico[i]
		for j in a:
			tab[indice] = j
			indice += 1

	return tab

def cree_message(message):
	tab = []
	temp = []
	indice = 0
	for i in message:
		temp.append(i)
		indice += 1
		if indice == taille_char:
			indice = 0
			tab.append(temp)
			temp = []
	return tab


def convertir_tab_into_texte(message, dico):
	taille = len(message)
	tab = cree_message(message)
	mot = ""
	for l in tab:
		for k, i in dico.items():
			if i == l:
				mot += k

	return mot