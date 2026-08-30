import pygame

class affiche(pygame.sprite.Sprite):
	def __init__(self, pos, taille):
		super().__init__()
		self.image = pygame.Surface((10, 20))
		self.image.fill('White')
		self.rect = self.image.get_rect(center = pos)

	