# Bouvier d'Acher Victor
# Classe 42
# Projet Cryptographie
# Cryptis

import pygame

largeur = 1000
longueur = 1000

def init_pygame():		# initialise l'afficheur graphique
	pygame.init()
	ecran = pygame.display.set_mode((largeur, longueur))
	pygame.display.set_caption('Cryptris New Version')
	clk = pygame.time.Clock()

	return ecran, clk

def evenement_pygame():			# recupere les evenement de touche
	# touche {'up':False, 'down':False, 'left':False, 'right':False}
	etat = 0
	bou = 0
	for event in pygame.event.get():
		if event.type == pygame.KEYDOWN:
			if event.key == pygame.K_UP:
				etat = 1
			if event.key == pygame.K_DOWN:
				etat = 2
			if event.key == pygame.K_LEFT:
				etat = 3
			if event.key == pygame.K_RIGHT:
				etat = 4
			if event.key == pygame.K_SPACE:
				etat = 1
			if event.key == pygame.K_ESCAPE:
				etat = 5
		if event.type == pygame.MOUSEBUTTONDOWN:
			bou = 1
		if event.type == pygame.QUIT:
			etat = 5
	return etat, bou


		



