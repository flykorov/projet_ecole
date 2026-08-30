import pygame
import math

class Explosif:
	def __init__(self, x, y, direction, l, h, ecran, c, e):
		self.ecran = ecran
		self.x = x 
		self.y = y
		self.hauteur = h 
		self.largeur = l
		self.couleur = c

		self.taille = 3
		self.dir = direction
		self.vie = 30
		self.vie_mort = 30
		self.vitesse_balle = 15
        
		self.explosion = e

	def updateMissile(self):
		# mouvement
		self.x += self.vitesse_balle * math.cos(self.dir * math.pi / 180)
		self.y += self.vitesse_balle * math.sin(self.dir * math.pi / 180)

		# affichage
		pygame.draw.circle(self.ecran, self.couleur, (int(self.x), int(self.y)), self.taille)

		# bordure
		if self.x > self.largeur:
		    self.x = 0
		elif self.x < 0:
		    self.x = self.largeur
		elif self.y > self.hauteur:
		    self.y = 0
		elif self.y < 0:
		    self.y = self.hauteur
		self.vie -= 1

	def posJoueur(self, x, y):
		pass

	def mortMissile(self):
		pygame.draw.circle(self.ecran, self.couleur, (self.x, self.y), self.explosion)
		self.vie_mort -= 1
		return True