import pygame

class Vie:
	def __init__(self, x, y, e, c):
		self.x = x 
		self.y = y 
		self.ecran = e 
		self.couleur = c 
		self.taille = 15

		self.rectangle = pygame.Rect(self.x-self.taille, self.y-self.taille, self.taille*2, self.taille*2)

		self.hauteur = self.taille/4
		self.taille_demi_cercle = self.taille/4

		self.position = [(self.x-self.taille_demi_cercle*2, self.y-self.hauteur), (self.x+self.taille_demi_cercle*2, self.y-self.hauteur), (self.x, self.y+self.hauteur*2)]


	def afficherPower(self):
		# afficher le cercle
		pygame.draw.circle(self.ecran, self.couleur, (self.x, self.y), self.taille, 2)
		
		# afficher le coeur
		pygame.draw.circle(self.ecran, self.couleur, 
			(self.x-self.taille_demi_cercle, self.y-self.hauteur), 
			self.taille_demi_cercle,
			0, True, True, False, False)

		pygame.draw.circle(self.ecran, self.couleur, 
			(self.x+self.taille_demi_cercle, self.y-self.hauteur), 
			self.taille_demi_cercle, 
			0, True, True, False, False)

		pygame.draw.polygon(self.ecran, self.couleur, 
			self.position)

		# pygame.draw.rect(self.ecran, self.couleur, self.rectangle)

	def action(self, joueur):
		joueur.vie += 1