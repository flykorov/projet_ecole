# Bouvier d'Acher Victor
# Classe 42
# Projet Cryptographie
# Cryptis

import numpy as np
import random
from constante import *

def agrandir_message(message, clef):
	t = len(clef)
	taille = len(message) / t

	if taille == 1:
		return message

	indice = len(message) % t
	while len(message) % t != 0:			# agrandi le message pour etre egal à un multiple de la clef privée
		message = np.append(message, 0)
	return message

def agrandir_clef_taille_message(message, clef):	# agrandi la clef privée 

	taille = len(clef)
	message = agrandir_message(message, clef)
	taille_nouvelle_clef = np.size(message)

	nouvelle_clef = np.zeros(taille_nouvelle_clef, dtype=np.int64)

	indice_clef = 0 
	for i in range(taille_nouvelle_clef):
		nouvelle_clef[i] = clef[indice_clef]
		indice_clef += 1
		if indice_clef >= taille:
			indice_clef = 0

	return nouvelle_clef, message

def chiffrement(message, clef_public):		# chiffre le message
	taille = len(clef_public)

	clef_message, message = agrandir_clef_taille_message(message, clef_public)		# agrandi le message pour etre egal à un multiple de la taille de la clef

	result = []

	for i in range(int(len(message) / taille)):		# repete pour toute la longueur du message
		mes = message[taille*i:taille*(i+1)]		# divise le message pour qu'elle soit équivalente à la taille de la clef

		retry = True
		i=0
		while(retry):		# repeter jusqu'à avoir un bon chiffrement
			while(i<20):	# chiffre n fois
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

				if np.all((mes >= -1) & (mes <= 1)):			# verifie que le message est chiffré
					retry = True
				else:
					retry = False
			
		result.extend(mes)			# message chiffrer

	return result

# archive
def verifier_message_dechiffrer(message):
	if np.max(message) > 1 or np.max(message) < -1:
		return True
	return False

# archive
def bon_nombre(maxi, mini):
	if abs(maxi) > abs(mini):
		return maxi, True
	else:
		return mini, False

# archive
def plus_ou_moins_un(res, mes, equation, vec):

	tab = [1 for _ in range(taille_clef)]

	for i in range(taille_clef):
		for j in range(taille_clef):
			pass

def babai(message, clef_prive):		# algorithme de déchiffrement avec l'algo de Babaï

	taille = len(clef_prive)

	vec = []
	# clef_message, _ = agrandir_clef_taille_message(message, clef_prive)

	for i in range(len(clef_prive)):		# crée la matrice de toute les clef privée possible
		vec.append(clef_prive)
		clef_prive = np.roll(clef_prive, 1)

	result = []

	for i in range(int(len(message) / taille)):		# déchiffre tout le message
		mes = message[taille*i:taille*(i+1)]		# decoupe le message

		equation = np.array([[i for i in j] for j in vec]) # crée la matrice de toute les clef privée possible

		transpose = equation.T 			# transposer de la matrice
		# print(transpose)
		# print(mes)

		retry = True
		
		# while retry:
		res = 0
		try:
			res = np.linalg.solve(transpose, mes)		# resout le systeme
		except np.linalg.LinAlgError:
			print("error")
			break
		# print(res)
		# print(np.sum((res%1<0.60) & (res%1>0.40)))
		res = np.round(res, 0)							# arrondi le resultat pour retrouvé le message

		# print(res)
		fin = [0 for i in res]						

		for i in range(len(equation)):	 			# met le resultat au format du message
			fin += res[i] * equation[i]


		# print(fin)

		mes = mes - fin					# dechiffre
	

		# print(vec)
		# print(f'res de 1 {mes}')
		if np.all((mes >= -1) & (mes <= 1)):		
			retry = False
			



		result.extend(mes)				# resultat final, message dechiffrer
		# print(mes)

	return result


# archive
def maxi_mini(clef_message, message):
	cle = 0
	ind_cle = 0

	if abs(max(clef_message)) > abs(min(clef_message)):
		cle = max(clef_message)
		ind_cle = np.argmax(clef_message)
	else:
		cle = min(clef_message)
		ind_cle = np.argmin(clef_message)


	mes = 0
	ind_mes = 0

	if abs(max(message)) > abs(min(message)):
		mes = max(message)
		ind_mes = np.where(message == np.max(message))
	else:
		mes = min(message)
		ind_mes = np.where(message == np.min(message))


	return cle, ind_cle, mes, ind_mes

# archive
def dechiffrement(message, clef_prive):

	clef_message = agrandir_clef_taille_message(message, clef_prive)

	continuer = True

	nb_iter = 0
	precedent = 10000000000000

	phase1 = True

	arret=0
	
	while continuer:

		indice = -1
		pos = True
		nb_case = 10000000000000

		if phase1:

			for i in range(len(clef_message)):
				a = np.sum(np.abs(message+clef_message))

				# print(nb_case, a)
				if nb_case > a:
					nb_case = a
					indice = i
				clef_message = np.roll(clef_message, 1)



			for i in range(len(clef_message)):
				a = np.sum(np.abs(message-clef_message))

				# print(nb_case, a)
				if nb_case > a:
					nb_case = a
					indice = i
					pos = False
				clef_message = np.roll(clef_message, 1)

			if nb_case >= precedent:
				phase1 = False
			else:
				clef_message = np.roll(clef_message, indice)

				if pos:
					message += clef_message
				else:
					message -= clef_message
				precedent = nb_case

		else:

			cle, ind_cle, mes, ind_mes = maxi_mini(clef_message, message)

			ind_mes = ind_mes[0]
			# print(ind_mes[0])
			# print(len(ind_mes))
			a = random.randint(0, len(ind_mes)-1)
			# print(f'a = {a}')
			choix = ind_mes[a]

			# print(choix)
			clef_message = np.roll(clef_message, choix-ind_cle)

			if cle < 0 and mes < 0:
				message -= clef_message
				# print("1")

			if cle < 0 and mes > 0:
				message += clef_message
				# print("2")

			if cle > 0 and mes > 0:
				message -= clef_message
				# print("3")

			if cle > 0 and mes < 0:
				message += clef_message
				# print("4")

			arret += 1
			# if arret == 30:
			# 	continuer = False



		if np.all((message >= -1) & (message <= 1)):
			continuer = False

		nb_iter+=1
		# print(message)



	print(nb_iter)




	return message