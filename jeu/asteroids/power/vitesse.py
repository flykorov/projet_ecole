import pygame

class Vitesse:
	def __init__(self, x, y, e, c):
		self.x = x 
		self.y = y 
		self.ecran = e 
		self.couleur = c 

		self.taille = 15

		self.rectangle = pygame.Rect(self.x-self.taille, self.y-self.taille, self.taille*2, self.taille*2)



	def afficherPower(self):
		# afficher cercle
		pygame.draw.circle(self.ecran, self.couleur, (self.x, self.y), self.taille, 2)
		


	def action(self, joueur):
		joueur.vitesse_max_joueur += 5