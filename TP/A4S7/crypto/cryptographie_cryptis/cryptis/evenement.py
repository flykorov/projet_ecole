# Bouvier d'Acher Victor
# Classe 42
# Projet Cryptographie
# Cryptis


import numpy as np

def mis_a_jour_evenement(etat, clef_prive, message):
	continuer = True
	if etat == 1:			# fleche du haut ou espace
		clef_prive = -clef_prive 	# inverse la clef
	if etat == 2:			# fleche du bas
		for i in range(len(clef_prive)):
			message[i] += clef_prive[i]		# ajoute la clef
	if etat == 3:			# fleche de gauche
		clef_prive = np.roll(clef_prive, -1)	# deplace la clef à gauche de 1
	if etat == 4:			# fleche de droite
		clef_prive = np.roll(clef_prive, 1)		# deplace la clef à droite de 1

	return clef_prive, message

def arret(etat):			# pour arreter le programme
	if etat == 5:
		return False
	return True 

