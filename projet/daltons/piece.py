import pygame
import numpy as np
from constante import *
from Object_forme import *
from milieu import *

class Object():
	def __init__(self,name, ecran, couleur, taille, taille_lettre, forme, largeur=0, chiffre = "", pos=(0,0)):
		self.name=name
		self.ecran = ecran
		self.couleur = couleur
		self.taille = taille
		self.chiffre = str(chiffre)
		self.forme = [(i[0]*taille + pos[0], i[1]*taille + pos[1]) for i in forme]
		self.pos_chiffre = milieu(self.forme)
		self.taille_lettre = taille_lettre * self.taille
		self.pos = pos
		self.largeur = largeur

		
		
	def afficher(self, dalto):
		pygame.draw.polygon(self.ecran, self.modifier_couleur(self.couleur, dalto), self.forme, self.largeur)
		text = pygame.font.SysFont("Calibri", int(self.taille_lettre)).render(self.chiffre, True, (0, 0, 0))
		self.ecran.blit(text, (self.pos_chiffre[0] - text.get_width() / 2, self.pos_chiffre[1] - text.get_height() / 2))

	def get_forme(self):
		return self.forme
	
	def get_name(self):
		return self.name

	def get_chiffre(self):
		return self.chiffre

	def add_chiffre(self,chiffre):
		if len(self.chiffre) >= 3:
			self.chiffre = chiffre
		else:
			self.chiffre += chiffre

	
	def modifier_couleur(self,couleur, dalton=-1):

		if dalton == -1:
			return couleur
		
		red , green, blue = couleur
		r = int(red * dalton[0][0] + green * dalton[0][1] + blue * dalton[0][2])
		g = int(red * dalton[1][0] + green * dalton[1][1] + blue * dalton[1][2])
		b = int(red * dalton[2][0] + green * dalton[2][1] + blue * dalton[2][2])
		c = (r, g, b)

		return c

	def modif_name(self,chiffre)-> None:
		self.chiffre = chiffre

def objet(ecran, couleur, chiffre, taille, taille_lettre, name, largeur=0, pos=(0,0)) -> Object:
	return Object(name,ecran, couleur, taille, taille_lettre, Object_forme[name], largeur, chiffre, pos)


