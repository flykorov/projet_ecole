import pygame

class player(pygame.sprite.Sprite):
	def __init__(self, pos, couleur):
		super().__init__()
		self.image = pygame.Surface((20, 40))
		self.image.fill(couleur)
		self.rect = self.image.get_rect(topleft = pos)
		self.direction = pygame.math.Vector2(0, 0)
		self.speed = 8
		self.gravity = 0.8
		self.jump_speed = -16
		self.saut = True

	def dire(self, touche):
		if touche[3] == True:
			self.direction.x = -1
			self.rect.x += self.direction.x * self.speed
		if touche[4] == True:
			self.direction.x = 1
			self.rect.x += self.direction.x * self.speed

	def gravite(self):
		self.direction.y += self.gravity
		self.rect.y += self.direction.y

	def jump(self, touche):
		if touche[0]:
			if self.saut:
				self.direction.y = self.jump_speed
				self.saut = False


	def update(self, touche):
		# self.dire(touche)
		# self.jump(touche)
		# self.gravite()
		# self.collision_x(touche)
		# self.collision_x()
		# self.collision_y()
		pass
