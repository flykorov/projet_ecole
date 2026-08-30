import pygame
from level import niveau

class check:
	def __init__(self):


	def level_1(self):
		g = self.cg.sprite
		d = self.cd.sprite
		j1 = self.p1.sprite
		j2 = self.p2.sprite
		for sprite in self.g.sprites():
			if sprite.rect.colliderect(j2.rect):
				self.state = 'level_2'
		for sprite in self.d.sprites():		
			if sprite.rect.colliderect(j1.rect):
				self.state = 'level_2'

	def level_2(self):
		self.surf.blit('Blue')

	def game_management(self):
		if self.state == 'level_1':
			level_1
		if self.state == 'level_2':
			level_2
