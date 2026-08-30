import pygame
import math

class Chercheuse:
	def __init__(self, x, y, direction, l, h, ecran, c, ds):
		self.ecran = ecran
		self.x = x 
		self.y = y
		self.hauteur = h 
		self.largeur = l
		self.couleur = c

		self.jx = 0
		self.jy = 0

		self.taille = 3
		self.dir = direction
		self.vie = 30
		self.vie_mort = 30
		self.vitesse_balle = 15

		self.distance_suivi = ds
		self.rectangle = pygame.Rect(self.x-self.distance_suivi/2, self.y-self.distance_suivi/2, self.distance_suivi, self.distance_suivi)
		self.rect_joueur = pygame.Rect(self.jx, self.jy, 1, 1)
	
	def nouvelleAngle(self):
		dx = self.jx - self.x
		dy = self.jy - self.y
		angle_radians = math.atan2(dy, dx)
		angle_degrees = math.degrees(angle_radians)
		return angle_degrees

	def updateMissile(self):

		if self.rectangle.colliderect(self.rect_joueur):
			self.dir = self.nouvelleAngle()

		# mouvement
		self.x += self.vitesse_balle * math.cos(self.dir * math.pi / 180)
		self.y += self.vitesse_balle * math.sin(self.dir * math.pi / 180)

		self.rectangle = pygame.Rect(self.x-self.distance_suivi/2, self.y-self.distance_suivi/2, self.distance_suivi, self.distance_suivi)
		self.rect_joueur = pygame.Rect(self.jx, self.jy, 1, 1)

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
		self.jx = x 
		self.jy = y 

	def mortMissile(self):
		return False