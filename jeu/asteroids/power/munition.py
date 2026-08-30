import pygame

class Munition:
	def __init__(self, x, y, e, c):
		self.x = x 
		self.y = y 
		self.ecran = e 
		self.couleur = c 

		self.taille = 15
		self.pos = self.taille/3
		self.hauteur = self.taille/1.5
		self.largeur = 4
		self.rect1 = pygame.Rect(self.x-self.pos-self.largeur, self.y-self.hauteur/2, self.largeur, self.hauteur)
		self.rect2 = pygame.Rect(self.x-self.hauteur-self.largeur/2, self.y-self.largeur/2, self.hauteur, self.largeur)

		
		self.taille_petit_cercle = self.taille/5

		self.rectangle = pygame.Rect(self.x-self.taille, self.y-self.taille, self.taille*2, self.taille*2)



	def afficherPower(self):
		# afficher cercle
		pygame.draw.circle(self.ecran, self.couleur, (self.x, self.y), self.taille, 2)
		
		# afficher +
		pygame.draw.rect(self.ecran, self.couleur, self.rect1)
		pygame.draw.rect(self.ecran, self.couleur, self.rect2)

		# afficher munition
		pygame.draw.circle(self.ecran, self.couleur, (self.x+self.pos, self.y), self.taille_petit_cercle)

	def action(self, joueur):
		joueur.nb_balle += 1