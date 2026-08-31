# Bouvier d'Acher Victor
# Classe 42
# Projet Cryptographie
# Cryptis

import random
import numpy as np
from evenement import *
from key import * 
from creer_clef import *
from creer_alphabet import *
from chiffrage import *
from convertion import *
from affiche_rect import *
from affiche_bouton import *
from bouton import *
from fin_auto import *

t_clef = taille_clef

# tableau des caractère invisible ASCII
ascii_invisible = ["NUL", "SOH", "STX", "ETX", "EOT", "ENQ", "ACK", "BEL", "BS", "HT", "LF", "VT", "FF", "CR", "SO", "SI", "001", "DLE", "DC1", "DC2", "DC3", "DC4", "NAK", "SYN", "ETB", "CAN", "EM", "SUB", "ESC", "FS", "GS", "RS", "US"]

dico = creer_alphabet()

afficher_ascii_invisible = {}
for i in range(32):
	afficher_ascii_invisible[chr(i)] = ascii_invisible[i] 

afficher_ascii_invisible[chr(127)] = "DEL"


# phrase au hasard
phrase = "je suis une patate"

# archive
nb_rate = 0
bonne_clef = []
mauvaise_clef = []
pour_mauv = []
pour_bon = []

tab_res = []

refaire = True

# etat de la page afficher
page = "menu"

# initialisation des variables
clef_prive = None
clef_public = None
message = None
message_bot = None
clef = None
clef_bot = None

# etat pour le jeu en arcade (1 bouton de gauche 2 de droite)
type_etat = [1, 2, 1]

ordi_vitesse = vitesse_ordi

ecran, clk = init_pygame()

# tout les boutons afficher
cryptis = rect_affichage(ecran, pos_cryptis, taille_cryptis, "CRYPTIS", change=False, police=80)
tutoriel = rect_affichage(ecran, pos_tuto, taille_tuto, "TUTORIEL")
arcade = rect_affichage(ecran, pos_arcade, taille_arcade, "ARCADE")
documentation = rect_affichage(ecran, pos_docu, taille_docu, "DOCUMENTATION")
dictionaire = rect_affichage(ecran, pos_dico, taille_dico, "DICTIONNAIRE")
quitter = rect_affichage(ecran, pos_quit, taille_quit, "QUITTER")
croix = rect_affichage(ecran, pos_croix, taille_croix, "x", gris)

fleche_gauche = rect_affichage(ecran, pos_gauche, taille_gauche, "<")
fleche_droit = rect_affichage(ecran, pos_droit, taille_droit, ">")
choix_clef = [rect_affichage(ecran, pos_prive, taille_prive, "clef privée"), rect_affichage(ecran, pos_public, taille_public, "clef publique")]
choix_clef_bot = [rect_affichage(ecran, pos_prive_bot, taille_prive_bot, "clef privée"), rect_affichage(ecran, pos_public_bot, taille_public_bot, "clef publique")]
mode = [rect_affichage(ecran, pos_mode_solo, taille_mode_solo, "SOLO"), rect_affichage(ecran, pos_mode_versus, taille_mode_versus, "VERSUS")]
vitesse = rect_affichage(ecran, pos_nombre_vit, taille_nombre_vit, str(ordi_vitesse), change=False)
fleche_gauche_vit = rect_affichage(ecran, pos_gauche_vit, taille_gauche_vit, "<")
fleche_droit_vit = rect_affichage(ecran, pos_droit_vit, taille_droit_vit, ">")
nombre = rect_affichage(ecran, pos_nombre, taille_nombre, str(taille_clef), change=False)
jouer = rect_affichage(ecran, pos_jouer, taille_jouer, "JOUER")

nom_joueur = rect_affichage(ecran, pos_nom_joueur, taille_nom_joueur, "JOUEUR", change=False)
nom_ordi = rect_affichage(ecran, pos_nom_ordi, taille_nom_ordi, "ORDINATEUR", change=False)


continuer = True

ordi = 0
fin = 0
# # print(dico)

while(continuer):

	ecran.fill('Black')

	etat, bou = evenement_pygame() 	# evenement de touche
	continuer = arret(etat)			# arreter tout

	# met a jour lorsque l'on clique sur les boutons
	page, t_clef, type_etat, ordi_vitesse = bouton(bou, page, t_clef, type_etat, ordi_vitesse)


	# affichage du menu
	if page == "menu":
		cryptis.afficher_rect()
		# tutoriel.afficher_rect()
		arcade.afficher_rect()
		# documentation.afficher_rect()
		dictionaire.afficher_rect()
		quitter.afficher_rect()


	# affichage du dico 
	if page == "dico":
		croix.afficher_rect()

		x = 50
		y = 200

		x2 = 80
		x1 = 140

		for k, v in dico.items():
			if k in afficher_ascii_invisible.keys():
				k = afficher_ascii_invisible[k]

			m = ""
			for i in v:
				m += str(i)


			afficher(ecran, k, blanc, x, y, 20)
			afficher(ecran, ":", blanc, x2, y, 20)
			afficher(ecran, m, blanc, x1, y, 20)
			y += 30
			if y > 950:
				y = 200
				x += 200
				x1 += 200
				x2 += 200


	# pas fait
	if page == "docu":
		croix.afficher_rect()

	# sorti du jeu
	if page == "quit":
		continuer = False

	# cliquer sur ARCADE choix du jeu
	if page == "choix":

		# afficher les textes
		afficher(ecran, "Taille de la clef", orange, 500, 100, 40)
		afficher(ecran, "Choix de la clef du joueur", orange, 500, 250, 40)
		afficher(ecran, "Choix de la clef de l'ordinateur", orange, 500, 400, 40)
		afficher(ecran, "Choix du mode de jeu", orange, 500, 550, 40)
		afficher(ecran, "Vitesse de l'ordinateur", orange, 500, 700, 40)

		# changer le texte
		nombre.mot = str(t_clef)
		vitesse.mot = str(ordi_vitesse)

		# afficher les rectangles
		fleche_droit.afficher_rect()
		fleche_gauche.afficher_rect()
		nombre.afficher_rect()
		fleche_droit_vit.afficher_rect()
		fleche_gauche_vit.afficher_rect()
		vitesse.afficher_rect()


		# modifier les couleurs et l'etat des boutons
		if type_etat[0] == 1:
			choix_clef[0].couleur = orange
			choix_clef[0].change = False
			choix_clef[1].change = True
			choix_clef[1].couleur = vert
		else:
			choix_clef[0].couleur = vert
			choix_clef[0].change = True
			choix_clef[1].change = False
			choix_clef[1].couleur = orange

		if type_etat[1] == 1:
			choix_clef_bot[0].couleur = orange
			choix_clef_bot[0].change = False
			choix_clef_bot[1].change = True
			choix_clef_bot[1].couleur = vert
		else:
			choix_clef_bot[0].couleur = vert
			choix_clef_bot[0].change = True
			choix_clef_bot[1].change = False
			choix_clef_bot[1].couleur = orange

		if type_etat[2] == 1:
			mode[0].couleur = orange
			mode[0].change = False
			mode[1].change = True
			mode[1].couleur = vert
		else:
			mode[0].couleur = vert
			mode[0].change = True
			mode[1].change = False
			mode[1].couleur = orange


		# d'autre bouton
		choix_clef[0].afficher_rect()
		choix_clef[1].afficher_rect()
		choix_clef_bot[0].afficher_rect()
		choix_clef_bot[1].afficher_rect()
		mode[0].afficher_rect()
		mode[1].afficher_rect()
		jouer.afficher_rect()
		croix.afficher_rect()

		

	# initialise les variables pour le jeu
	if page == "init":
		clef_prive = creer_clef_privee(t_clef)

		clef_public = creer_clef_public(clef_prive)

		message = "je suis une patate"

		message = convertir_texte_into_tab(message, dico)

		message = chiffrement(message, clef_public)

		# affectation de la clef au joueur et au bot
		if type_etat[0] == 1:
			clef = clef_prive
		else:
			clef = clef_public

		if type_etat[1] == 1:
			clef_bot = clef_prive
		else:
			clef_bot = clef_public

		refaire = True

		message_bot = message.copy()


		# clef = np.array([-10, 1, 21, 5, 8, 7, 5, 7, -20, -13, 19, 38, 3, 38, -12, -43])
		# message = np.array([-84, 112, 12, -1, 33, -36, 11, -26, -90, -10, 47, 134, 18, 46, -37, -74])

		# type de partie
		if type_etat[2] == 1:
			page = "jeu"
		else:
			page = "versus"

	# affiche la fin pendant une seconde, s'arrete que lorsque le joueur à fini
	if page == "pause":

		croix.afficher_rect()

		if type_etat[2] == 1:
			rect_auto(ecran, page)

			contour_rect(ecran, clef, pos_dep, 1)
			rect_clef(ecran, clef, message, pos_dep, 1)
			rect_message(ecran, message, clef, pos_dep, 1)
		else:

			contour_rect(ecran, clef, pos_dep, 2)
			rect_clef(ecran, clef, message, pos_dep, 2)
			rect_message(ecran, message, clef, pos_dep, 2)

			contour_rect(ecran, clef_bot, pos_dep_bot, 2)
			rect_clef(ecran, clef_bot, message_bot, pos_dep_bot, 2)
			rect_message(ecran, message_bot, clef_bot, pos_dep_bot, 2)


		if fin == 30:
			page = "menu"
			fin = 0
		else:
			fin += 1




	# duel entre le joueur et le bot
	if page == "versus":

		clef, message = mis_a_jour_evenement(etat, clef, message)


		if refaire:
			tab_res = finir_auto(message_bot, clef_bot)
			refaire = False


		if ordi == 0:
			clef_bot, message_bot, tab_res = finir_a_jour(clef_bot, message_bot, tab_res)
		ordi += 1
		ordi %= ordi_vitesse

		croix.afficher_rect()

		nom_joueur.afficher_rect()
		nom_ordi.afficher_rect()

		contour_rect(ecran, clef, pos_dep, 2)
		rect_clef(ecran, clef, message, pos_dep, 2)
		rect_message(ecran, message, clef, pos_dep, 2)

		contour_rect(ecran, clef_bot, pos_dep_bot, 2)
		rect_clef(ecran, clef_bot, message_bot, pos_dep_bot, 2)
		rect_message(ecran, message_bot, clef_bot, pos_dep_bot, 2)
		

		# verifie si le message est dechiffrer
		m = message[0:t_clef]
		ar = 0
		for i in m:
			if i <= 1 and i >= -1:
				ar += 1
		if ar == len(m):
			page = "pause"
			refaire = True


	# pour les parties solo
	if page == "jeu" or page == "auto":

		# lorsque le joueur joue
		if page == "jeu":
			nom_joueur.mot = "JOUEUR"
			clef, message = mis_a_jour_evenement(etat, clef, message)
			refaire = True

		# initialise le tableau de resolution de chiffrement
		if page == "auto" and refaire:
			tab_res = finir_auto(message, clef)
			refaire = False

		# lorsque le bot joue
		if page == "auto":

			nom_joueur.mot = "ORDINATEUR"
			if ordi == 0:
				clef, message, tab_res = finir_a_jour(clef, message, tab_res)
			ordi += 1
			ordi %= ordi_vitesse


		nom_joueur.afficher_rect()

		
		rect_auto(ecran, page)
		croix.afficher_rect()

		contour_rect(ecran, clef, pos_dep, 1)
		rect_clef(ecran, clef, message, pos_dep, 1)
		rect_message(ecran, message, clef, pos_dep, 1)
		

		m = message[0:t_clef]
		ar = 0
		for i in m:
			if i <= 1 and i >= -1:
				ar += 1
		if ar == len(m):
			page = "pause"

	pygame.display.update()

	clk.tick(tick)

		

pygame.quit()


	# message = dechiffrement(message, clef_prive)

# dechiffre le reste du message 
if message != None:
	message = babai(message, clef_prive)

		# print(f'message dechiffrer : {message}')

	message = convertir_tab_into_texte(message, dico)
	# print(f'message recu : {message}')




# archive
# comptait le nombre de bonne et de mauvaise clef

# 	if message != phrase:
# 		nb_rate += 1
# 		mauvaise_clef.append(clef_prive)
# 		print(message)
# 		print("raté")
# 	else:
# 		bonne_clef.append(clef_prive)

# # print(nb_rate)

# for i in bonne_clef:
# 	print(i)
# 	if abs(min(i)) > abs(max(i)):
# 		print(min(i))
# 	else: 
# 		print(max(i))
# print("mauvaise")
# for i in mauvaise_clef:
# 	print(i)
# 	if abs(min(i)) > abs(max(i)):
# 		print(min(i))
# 	else: 
# 		print(max(i))
# print(mauvaise_clef)