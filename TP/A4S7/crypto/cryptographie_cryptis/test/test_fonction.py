# Bouvier d'Acher Victor
# Classe 42
# Projet Cryptographie
# Cryptis

"""
Ceci sont les fonctions utilisé uniquement dans le fichier nommé test.py
pour effectué des tests séparement du code pricipale

a utiliser comme vous le voulez
"""

import numpy as np
import random

def babai_libre(message, clef_prive):		

	taille = len(clef_prive)

	vec = []
	# clef_message, _ = agrandir_clef_taille_message(message, clef_prive)

	for i in range(len(clef_prive)):	
		vec.append(clef_prive)
		clef_prive = np.roll(clef_prive, 1)

	result = []

	for i in range(int(len(message) / taille)):	
		mes = message[taille*i:taille*(i+1)]	

		equation = np.array([[i for i in j] for j in vec])

		transpose = equation.T 		
		# print(transpose)
		# print(mes)

		retry = True
		
		# while retry:
		res = 0
		try:
			res = np.linalg.solve(transpose, mes)	
		except np.linalg.LinAlgError:
			print("error")
			break
		# print(res)
		# print(np.sum((res%1<0.60) & (res%1>0.40)))
		res = np.round(res, 0)

		# print(res)
		fin = [0 for i in res]						

		for i in range(len(equation)):	 
			fin += res[i] * equation[i]


		print(fin)

		mes = mes - fin	
	

		# print(vec)
		# print(f'res de 1 {mes}')
		if np.all((mes >= -1) & (mes <= 1)):		
			retry = False
			



		result.extend(mes)
		# print(mes)

	return result


def creer_clef_public_libre_v2(clef_prive):
	vec = []
	# clef_message, _ = agrandir_clef_taille_message(message, clef_prive)

	for i in range(len(clef_prive)):	
		vec.append(clef_prive)
		clef_prive = np.roll(clef_prive, 1)

	coef = []

	for i in range(len(clef_prive)):
		coef.append(random.randint(0, len(clef_prive)))
		a = random.randint(0, 1)
		if a:
			coef[i] *= -1
		coef[i] = 5

	# print(f'coef = {coef}')


	clef_public = [0 for i in range(len(clef_prive))]
	for i in range(len(clef_prive)):
		# print(f'coef {coef[i]} * {vec[i]}')
		clef_public += coef[i] * vec[i]
		# print(clef_public)

	return clef_public

def creer_clef_public_libre(clef_prive):	
	taille = len(clef_prive)
	clef_public = np.zeros(taille, dtype=np.int64)
	excelent = False
	signe = 1
	tab = np.zeros(taille, dtype=np.int64)
	while not excelent:
		a = random.randint(0, 3)
		if a == 0:
			clef_prive = np.roll(clef_prive, 1)
			tab = np.roll(tab, 1)
		if a == 1:
			clef_prive = np.roll(clef_prive, -1)
			tab = np.roll(tab, -1)
		if a == 2:
			clef_prive = -clef_prive
			signe = -signe
		if a == 3:
			clef_public += clef_prive
			tab[0] += signe

		nombre_0 = np.count_nonzero(tab == 0)
		# print(nombre_0)
		if np.count_nonzero(tab == 0) < 5: 
			excelent = True

		# if nb > taille * 6 and nb_bon >= taille/2:
		# 	excelent = True


	return clef_public

def agrandir_message_libre(message, clef):
	t = len(clef)
	taille = len(message) / t

	if taille == 1:
		return message

	indice = len(message) % t
	while len(message) % t != 0:
		message = np.append(message, 0)
	return message


def chiffrement_libre(message, clef_public):	
	taille = len(clef_public)

	message = agrandir_message_libre(message, clef_public)		
	result = []

	for i in range(int(len(message) / taille)):	
		mes = message[taille*i:taille*(i+1)]		
		retry = True
		i=0
		while(retry):	
			while(i<20):
				a = random.randint(0, 3)
				if a == 0:
					clef_public = np.roll(clef_public, 1)
				if a == 1:
					clef_public = np.roll(clef_public, -1)
				if a == 2:
					clef_public = -clef_public
				if a == 3:
					mes += clef_public
					i+=1

				if np.all((mes >= -1) & (mes <= 1)):	
					retry = True
				else:
					retry = False
			
		result.extend(mes)		

	return result

def melanger_tab(clef_prive):			# melange la clef privée 
	taille = len(clef_prive)
	for i in range(taille*2):
		a = random.randint(0, taille-1)
		b = random.randint(0, taille-1)

		clef_prive[a], clef_prive[b] = clef_prive[b], clef_prive[a]

	return clef_prive

def creer_clef_privee_libre(taille):


	clef_prive = np.ones(taille, dtype=np.int64)
	
	for i in range(taille-1):
		# b = random.randint(-int(i/4), int(i/4))
		clef_prive[i] = int(i/4) + random.randint(-int(i/8), int(i/8))
		a = random.randint(0, 1)
		if a == 0:
			clef_prive[i] = -clef_prive[i]

	clef_prive[taille-1] = random.randint(taille - int(taille/8), taille + int(taille/8))
	a = random.randint(0, 1)
	if a == 0:
		clef_prive[taille-1] = -clef_prive[taille-1]

	clef_prive = melanger_tab(clef_prive)

	return clef_prive



