# Bouvier d'Acher Victor
# Classe 42
# Projet Cryptographie
# Cryptis

from constante import *

def changer_etat(etat, binaire):		# calculer le caractere en trits 
	for i in range(taille_char):
		etat[i] += 1
		etat[i] %= pow(3,i)
		if etat[i] == 0:
			if binaire[i] == 0:
				binaire[i] = 1
			elif binaire[i] == 1:
				binaire[i] = -1
			else:
				binaire[i] = 0

def creer_alphabet():					# renvoie un dictionaire avec le nom du caractère et son equivalent en trits 
	dico = {}
	binaire = [0 for i in range(taille_char)]
	etat = [0 for i in range(taille_char)]
	puissance = [pow(3, i) for i in range(taille_char)]

	for i in range(128):				# les 128 premiers caractere ASCII
		dico[chr(i)] = list(binaire)
		changer_etat(etat, binaire)

	return dico
