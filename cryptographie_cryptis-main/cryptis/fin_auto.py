# Bouvier d'Acher Victor
# Classe 42
# Projet Cryptographie
# Cryptis

import numpy as np
from constante import *

def finir_auto(message, clef_prive):
	vec = []
	t = len(clef_prive)
	for i in range(t):
		vec.append(clef_prive)
		clef_prive = np.roll(clef_prive, 1)

	result = []

	mes = message[0:t]

	equation = np.array([[i for i in j] for j in vec])

	transpose = equation.T

	res = 0
	try:
		res = np.linalg.solve(transpose, mes)
	except np.linalg.LinAlgError:
		print("error")

	res = np.round(res, 0)

	return res

def finir_a_jour(clef_prive, message, tab):

	t = len(clef_prive)
	while(True):
		# break
		if tab[0]==0:
			clef_prive = np.roll(clef_prive, 1)
			tab = np.roll(tab, -1)
			break
	
		if tab[0]<0:
				# if np.abs(np.min(clef_prive)) > np.abs(np.max(clef_prive)):
			for i in range(t):
				message[i] += clef_prive[i]
			tab[0] += 1
			break
		else:
			clef_prive = - clef_prive
			tab = - tab

		break

	return clef_prive, message, tab

