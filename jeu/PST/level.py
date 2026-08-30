import pygame
from dessin import affiche
from niv1 import tile_size, largeur, taille
from joueur import player
from change import cote

class niveau:
	def __init__(self, terrain, surface, state):
		super().__init__()
		self.state = state
		self.creer_niveau(terrain)
		self.world_shift = 0
		self.surf = surface
		self.ecran_x = 0
		self.ecran_y = largeur
		self.speed = 8
		self.b = 0
		# self.p1 = player((100, 100))
		# self.p2 = player((200, 200))

	def creer_niveau(self, terrain):
		self.dessin = pygame.sprite.Group()
		self.cote_g = pygame.sprite.Group()
		self.cote_d = pygame.sprite.Group()
		self.p1 = pygame.sprite.GroupSingle()
		self.p2 = pygame.sprite.GroupSingle()
		for ti, i in enumerate(terrain):
			for tj, j in enumerate(i):
				x = tj * tile_size
				y = ti * tile_size 
				if j == 'X':
					carre = affiche((x, y), tile_size)
					self.dessin.add(carre)
				if j == 'P':
					j1 = player((x, y), 'Blue')
					self.p1.add(j1)
				if j == 'M':
					j2 = player((x, y), 'Green')
					self.p2.add(j2)
				if j == 'G':
					cg = cote((x, y), tile_size)
					self.cote_g.add(cg)
				if j == 'D':
					cd = cote((x+tile_size-1, y), tile_size)
					self.cote_d.add(cd)
		self.largeur = x + tile_size
		# print(self.largeur)


	# def intro(self, touche1, touche2):


	# def level_1(self):

	# def level_2(self):

	# def game_management(self):
	# 	if self.state == 0:
	# 		self.level_1()
	# 	if self.state == 1:
	# 		self.level_2()

	def scrolling(self, touche1, touche2):
		j1 = self.p1.sprite
		j1_x = j1.rect.centerx
		direction1_x = j1.direction.x

		j2 = self.p2.sprite
		j2_x = j2.rect.centerx
		direction2_x = j2.direction.x

		# if self.ecran_x > 0:
		if j2_x < largeur / 4 and touche2[3] == True and self.ecran_x > 0:
			self.world_shift = self.speed
			self.ecran_x -= self.speed
			self.ecran_y -= self.speed
			# print(self.ecran_x)
			# print(self.ecran_y)
			j1.rect.x += self.speed
			j2.speed = 0
			a = False
		else:
			a = True
			
		# if self.ecran_y < self.largeur:
		if j1_x > largeur - (largeur / 4) and touche1[4] == True and self.ecran_y < self.largeur:
			self.world_shift = -self.speed
			self.ecran_x += self.speed
			self.ecran_y += self.speed
			# print(self.ecran_x)
			# print(self.ecran_y)
			j1.speed = 0
			j2.rect.x += -self.speed
			b = False
		else:
			b = True

		# print(largeur/4)
		# print(largeur - (largeur / 4))

		if a == True and b == True:
			self.world_shift = 0
			j1.speed = self.speed
			j2.speed = self.speed
		else:
			a = False
			b = False

		# if j2_x < largeur / 4 and direction2_x < 0:
		# 	self.world_shift = 3
		# 	j2.speed = 0
		# 	j1.speed = 0
		# elif j2_x > largeur - (largeur / 4) and direction2_x > 0:
		# 	self.world_shift = -3
		# 	j2.speed = 0
		# 	j1.speed = 0
		# else:
		# 	self.world_shift = 0
		# 	j2.speed = 3
		# 	j1.speed = 3

	# def collision_cote(self, touche1, touche2, niv):
	# 	j1 = self.p1.sprite
	# 	j1.dire(touche1)

	# 	j2 = self.p2.sprite
	# 	j2.dire(touche2)

	# 	for sprite in self.cote_g.sprites():
	# 		if sprite.rect.colliderect(j2.rect):
	# 			niv -= 1

	# 	for sprite in self.cote_d.sprites():
	# 		if sprite.rect.colliderect(j1.rect):
	# 			niv += 1

	def collision_x(self, touche1, touche2):
		j1 = self.p1.sprite
		j1.dire(touche1)

		j2 = self.p2.sprite
		j2.dire(touche2)

		for sprite in self.dessin.sprites():
			if sprite.rect.colliderect(j1.rect):
				if j1.direction.x < 0:
					j1.rect.left = sprite.rect.right
				elif j1.direction.x > 0:
					j1.rect.right = sprite.rect.left
			if sprite.rect.colliderect(j2.rect):
				if j2.direction.x < 0:
					j2.rect.left = sprite.rect.right
				elif j2.direction.x > 0:
					j2.rect.right = sprite.rect.left

		# g = self.cote_g.sprite
		# d = self.cote_d.sprite
		if(self.b < 0):
			for sprite in self.cote_g.sprites():
				if sprite.rect.colliderect(j2.rect):
					self.state += 1
					self.b = 60
			for sprite in self.cote_d.sprites():		
				if sprite.rect.colliderect(j1.rect):
					self.state -= 1
					self.b = 60

		return self.state

	def collision_y(self, touche1, touche2):
		j1 = self.p1.sprite
		j1.jump(touche1)
		j1.gravite()

		j2 = self.p2.sprite
		j2.jump(touche2)
		j2.gravite()

		for sprite in self.dessin.sprites():
			if sprite.rect.colliderect(j1.rect):
				if j1.direction.y > 0:
					j1.rect.bottom = sprite.rect.top
					j1.direction.y = 0
					j1.saut = True
				elif j1.direction.y < 0:
					j1.rect.top = sprite.rect.bottom
			if sprite.rect.colliderect(j2.rect):
				if j2.direction.y > 0:
					j2.rect.bottom = sprite.rect.top
					j2.direction.y = 0
					j2.saut = True
				elif j2.direction.y < 0:
					j2.rect.top = sprite.rect.bottom

	def run(self, touche1, touche2):
		# self.game_management(terrain1, terrain2, touche1, touche2)
		self.dessin.update(self.world_shift)
		self.dessin.draw(self.surf)
		self.cote_g.draw(self.surf)
		self.cote_d.draw(self.surf)
		self.p1.draw(self.surf)
		self.p2.draw(self.surf)	

		a = self.collision_x(touche1, touche2)
		self.collision_y(touche1, touche2)
		
		self.scrolling(touche1, touche2)
		self.b -= 1
		return a