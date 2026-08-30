import pygame
from dessin import affiche
from bar import player
from bal import balle
from niv1 import tile_size, largeur, longueur

class niveau:
	def __init__(self, terrain, surface):
		super().__init__()
		self.creer_niveau(terrain)
		self.surf = surface
		self.score_j1 = 0
		self.score_j2 = 0
		self.font1 = pygame.font.SysFont("minecraft/Minecraft.ttf", 50)
		self.img1 = self.font1.render(str(self.score_j1), True, 'White')
		self.font2 = pygame.font.SysFont("minecraft/Minecraft.ttf", 50)
		self.img2 = self.font2.render(str(self.score_j2), True, 'White')

	def creer_niveau(self, terrain):
		self.dessin = pygame.sprite.Group()
		self.p1 = pygame.sprite.GroupSingle()
		self.p2 = pygame.sprite.GroupSingle()
		self.ball = pygame.sprite.GroupSingle()
		for ti, i in enumerate(terrain):
			for tj, j in enumerate(i):
				x = tj * tile_size
				y = ti * tile_size + 32
				if j == 'X':
					carre = affiche((x, y), tile_size)
					self.dessin.add(carre)
				if j == 'P':
					j1 = player((x, y))
					self.p1.add(j1)
				if j == 'M':
					j2 = player((x, y))
					self.p2.add(j2)
				if j == 'B':
					ba = balle((x, y))
					self.ball.add(ba)

	def collision(self, touche1, touche2):
		j1 = self.p1.sprite
		j1.dire(touche1)

		j2 = self.p2.sprite
		j2.dire(touche2)

		ba = self.ball.sprite

		if ba.rect.top <= 0:
			ba.direction.y = -ba.direction.y
		if ba.rect.bottom >= longueur:
			ba.direction.y = -ba.direction.y

		if j1.rect.top <= 0:
			j1.rect.top = 0
		if j1.rect.bottom >= longueur:
			j1.rect.bottom = longueur

		if j2.rect.top <= 0:
			j2.rect.top = 0
		if j2.rect.bottom >= longueur:
			j2.rect.bottom = longueur

		if ba.rect.right >= largeur:
			self.score_j1 += 1
			return 2
		if ba.rect.left <= 0:
			self.score_j2 += 1
			return 1

		if ba.rect.colliderect(j1.rect):
			if ba.rect.bottom > j1.rect.top and ba.rect.top < j1.rect.bottom:
			# if abs(ba.rect.left - j1.rect.right) < 10:
				ba.direction.x = -ba.direction.x
				balle.speed += 1
			# else:
				# ba.direction.y = -ba.direction.y
			# elif abs(ba.rect.bottom - j1.rect.top) < 10:
			# 	ba.direction.y = -ba.direction.y
			# elif abs(ba.rect.top - j1.rect.bottom) < 10:
			# 	ba.direction.y = -ba.direction.y

		if ba.rect.colliderect(j2.rect):
			if ba.rect.bottom > j2.rect.top and ba.rect.top < j2.rect.bottom:
			# if abs(ba.rect.right - j2.rect.left) < 10:
				ba.direction.x = -ba.direction.x
				balle.speed += 1
			# else:
				# ba.direction.y = -ba.direction.y
			# elif abs(ba.rect.bottom - j2.rect.top) < 10:
			# 	ba.direction.y = -ba.direction.y
			# elif abs(ba.rect.top - j2.rect.bottom) < 10:
			# 	ba.direction.y = -ba.direction.y

	# def collision_x(self, touche1, touche2, b):
	# 	j1 = self.p1.sprite
	# 	j1.dire(touche1)

	# 	j2 = self.p2.sprite
	# 	j2.dire(touche2)

	# 	ba = self.ball.sprite
	# 	if b == 0:
	# 		if ba.rect.colliderect(j1.rect):
	# 			ba.direction.x = -ba.direction.x
	# 			ba.rect.left = j1.rect.right
	# 			balle.speed += 0.5
	# 		if ba.rect.colliderect(j2.rect):
	# 			ba.direction.x = -ba.direction.x
	# 			ba.rect.right = j2.rect.left
	# 			balle.speed += 0.5

	# 		if ba.rect.left <= 0:
	# 			self.score_j2 += 1
	# 			balle.speed = 3
	# 			# print(1)
	# 			return 1
	# 		if ba.rect.right >= largeur:
	# 			self.score_j1 += 1
	# 			balle.speed = 3
	# 			# print(2)
	# 			return 2
	# 	return 0

	# def collision_y(self, touche1, touche2):
	# 	j1 = self.p1.sprite

	# 	j2 = self.p2.sprite

	# 	ba = self.ball.sprite

	# 	if ba.rect.top <= 0:
	# 		ba.direction.y = -ba.direction.y
	# 	if ba.rect.bottom >= longueur:
	# 		ba.direction.y = -ba.direction.y

	# 	if j1.rect.top <= 0:
	# 		j1.rect.top = 0
	# 	if j1.rect.bottom >= longueur:
	# 		j1.rect.bottom = longueur

	# 	if j2.rect.top <= 0:
	# 		j2.rect.top = 0
	# 	if j2.rect.bottom >= longueur:
	# 		j2.rect.bottom = longueur

	# 	if ba.rect.colliderect(j1):
	# 		ba.direction.y = -ba.direction.y
	# 		# ba.direction.x = -ba.direction.x
	# 		if ba.rect.bottom >= j1.rect.top:
	# 			ba.rect.bottom = j1.rect.top
	# 		else:
	# 			ba.rect.top = j1.rect.bottom
	# 		return 1
	# 	if ba.rect.colliderect(j2):
	# 		ba.direction.y = -ba.direction.y
	# 		# ba.direction.x = -ba.direction.x
	# 		if ba.rect.bottom >= j2.rect.top:
	# 			ba.rect.bottom = j2.rect.top
	# 		else:
	# 			ba.rect.top = j2.rect.bottom
	# 		return 1
	# 	return 0

	def affiche_score(self):
		self.img1 = self.font1.render(str(self.score_j1), True, 'White')
		self.img2 = self.font2.render(str(self.score_j2), True, 'White')
		self.surf.blit(self.img1, (largeur/4, 50))
		self.surf.blit(self.img2, (largeur - largeur/4, 50))

	def run(self, touche1, touche2):
		a = 0
		b = 0
		#print(a)
		self.dessin.draw(self.surf)
		self.ball.sprite.uptade()
		a = self.collision(touche1, touche2)
		# b = self.collision_y(touche1, touche2)
		# a = self.collision_x(touche1, touche2, b)
		#print(a)
		self.p1.draw(self.surf)
		self.p2.draw(self.surf)
		self.ball.draw(self.surf)
		self.affiche_score()
		a = self.ball.sprite.rerun(a)
		if(a != 0):
			balle.speed = 3
		# print(balle.speed)