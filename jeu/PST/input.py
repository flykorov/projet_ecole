import pygame
#from player import personnage

class evenement:
	def __init__(self):
		self.continuer = True
		self.saut = False
		self.z = False
		self.s = False
		self.q = False
		self.d = False
		self.espace = False
		self.attaquer = False

	def touche(self):
		for event in pygame.event.get():
			if event.type == pygame.KEYDOWN:
				if event.key == pygame.K_ESCAPE:
					self.continuer = False
				if event.key == pygame.K_SPACE:
					self.espace = True
				if event.key == pygame.K_z:
					self.z = True
				if event.key == pygame.K_s:
					self.s = True
				if event.key == pygame.K_q:
					self.q = True
					#player.direction.x = -1
				if event.key == pygame.K_d:
					self.d = True
					#player.direction.x = 1
				if event.key == pygame.K_k:
					self.attaquer = True
			if event.type == pygame.KEYUP:
				if event.key == pygame.K_SPACE:
					self.espace = False
				if event.key == pygame.K_z:
					self.z = False
				if event.key == pygame.K_s:
					self.s = False
				if event.key == pygame.K_q:
					self.q = False
					#player.direction.x = 0
				if event.key == pygame.K_d:
					self.d = False
					#player.direction.x = 0
			if event.type == pygame.QUIT:
				self.continuer = False