import pygame

class player(pygame.sprite.Sprite):
	def __init__(self, pos):
		super().__init__()
		self.image = pygame.Surface((50, 200))
		self.image.fill('White')
		self.rect = self.image.get_rect(topleft = pos)
		self.direction = pygame.math.Vector2(0, 0)
		self.speed = 10

	def dire(self, touche):
		if touche[0] == True:
			self.direction.y = -1
			self.rect.y += self.direction.y * self.speed
		if touche[1] == True:
			self.direction.y = 1
			self.rect.y += self.direction.y * self.speed
