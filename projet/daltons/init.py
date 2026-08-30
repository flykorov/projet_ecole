import pygame
from constante import *

def init_pygame():		# initialise l'afficheur graphique
	pygame.init()
	ecran = pygame.display.set_mode((largeur, longueur))
	pygame.display.set_caption('Tableau')
	clk = pygame.time.Clock()
	return ecran, clk

def evenement_pygame():			# recupere les evenement de touche
	# touche {'up':False, 'down':False, 'left':False, 'right':False}
	bouton = False
	quit = False
	for event in pygame.event.get():
		if event.type == pygame.KEYDOWN:
			if event.key == pygame.K_ESCAPE:
				quit = True
		if event.type == pygame.MOUSEBUTTONDOWN:
			bouton = True
		if event.type == pygame.QUIT:
			quit = True
	return bouton, quit, pygame.mouse.get_pos()