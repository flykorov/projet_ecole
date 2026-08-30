import pygame

class cote(pygame.sprite.Sprite):
	def __init__(self, pos, taille):
		super().__init__()
		self.image = pygame.Surface((1, taille))
		self.image.fill('Yellow')
		self.rect = self.image.get_rect(topleft = pos)