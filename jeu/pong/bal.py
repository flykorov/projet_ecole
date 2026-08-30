import pygame
import random
import math
from niv1 import largeur, longueur

class balle(pygame.sprite.Sprite):
	speed = 3
	# e = 1
	# b = 1
	# while(e < 0.5 and e > -0.5):
	# 	e = random.randint(0, 90)
	# while(b < 0.5 and b > -0.5):
	# 	b = random.randint(0, 90)
	def __init__(self, pos):
		super().__init__()
		self.image = pygame.Surface((50, 50))
		self.image.fill('White')
		self.rect = self.image.get_rect(center = pos)
		self.direction = pygame.math.Vector2(1, random.choice((-1, 1)))#random.uniform(-2.0, 2.0))
		

	def rerun(self, a):
		#print(a)
		if a != 0:
			# c = 1
			# d = 1
			# while(c < 0.5 and c > -0.5):
			# 	c = random.randint(0, 90)
			# while(d < 0.5 and d > -0.5):
			# 	d = random.randint(0, 90)
			if a == 1:
				pos = (random.randint(largeur/2, largeur - largeur/4), random.randint(100, longueur-100))
				self.rect = self.image.get_rect(center = pos)
				self.direction.x = -1
				self.direction.y = random.choice((1, -1))
				self.speed = 3
			if a == 2:
				pos = (random.randint(largeur/4, largeur/2), random.randint(100, longueur-100))
				self.rect = self.image.get_rect(center = pos)
				self.direction.x = 1
				self.direction.y = random.choice((1, -1))
				self.speed = 3
		return a

	def uptade(self):
		# self.rect.y += math.sin(self.rect.x/10) * 10
		self.rect.x += self.direction.x * self.speed
		self.rect.y += self.direction.y * self.speed