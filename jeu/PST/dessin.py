import pygame

class affiche(pygame.sprite.Sprite):
	def __init__(self, pos, taille):
		super().__init__()
		self.image = pygame.Surface((taille, taille))
		self.image.fill('Red')
		self.rect = self.image.get_rect(topleft = pos)
		
	def update(self, scrol):
		self.rect.x += scrol