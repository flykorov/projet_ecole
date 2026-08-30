import pygame

class Power:
	def __init__(self, x, y, e, c):
		self.x = x 
		self.y = y 
		self.ecran = e 
		self.couleur = c 
	
		self.rectangle = pygame.Rect(self.x-self.taille, self.y-self.taille, self.taille*2, self.taille*2)



	def afficherPower(self):

		pygame.draw.circle(self.ecran, self.couleur, (self.x, self.y), 15, 2)


