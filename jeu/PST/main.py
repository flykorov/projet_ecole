import pygame
from niv1 import*
from niv2 import*
from level import niveau

class Game:
	def __init__(self):
		pygame.init()
		self.state = 0
		self.ecran = pygame.display.set_mode((largeur, longueur))
		pygame.display.set_caption('test_jeu')
		self.clk = pygame.time.Clock()
		self.niv1 = niveau(niv1, self.ecran, 0)
		self.niv2 = niveau(niv2, self.ecran, 1)
		self.touche_j1 = [False, False, False, False, False, False, False]
		self.touche_j2 = [False, False, False, False, False, False, False]
		self.continuer = True
		self.niv = 0

	def run(self):
		while(self.continuer):
			for event in pygame.event.get():
				if event.type == pygame.KEYDOWN:
					if event.key == pygame.K_ESCAPE:
						self.continuer = False
					if event.key == pygame.K_SPACE:
						#self.espace = True
						self.touche_j1[0] = True
					if event.key == pygame.K_z:
						#self.z = True
						self.touche_j1[1] = True
					if event.key == pygame.K_s:
						#self.s = True
						self.touche_j1[2] = True
					if event.key == pygame.K_q:
						#self.q = True
						self.touche_j1[3] = True
						#player.direction.x = -1
					if event.key == pygame.K_d:
						#self.d = True
						self.touche_j1[4] = True
						#player.direction.x = 1
					if event.key == pygame.K_f:
						#self.attaquer = True
						self.touche_j1[5] = True
					if event.key == pygame.K_n:
						#self.espace = True
						self.touche_j2[0] = True
					if event.key == pygame.K_o:
						#self.z = True
						self.touche_j2[1] = True
					if event.key == pygame.K_l:
						#self.s = True
						self.touche_j2[2] = True
					if event.key == pygame.K_k:
						#self.q = True
						self.touche_j2[3] = True
						#player.direction.x = -1
					if event.key == pygame.K_m:
						#self.d = True
						self.touche_j2[4] = True
						#player.direction.x = 1
					if event.key == pygame.K_j:
						#self.attaquer = True
						self.touche_j2[5] = True
				if event.type == pygame.KEYUP:
					if event.key == pygame.K_SPACE:
						#self.espace = False
						self.touche_j1[0] = False
					if event.key == pygame.K_z:
						#self.z = False
						self.touche_j1[1] = False
					if event.key == pygame.K_s:
						#self.s = False
						self.touche_j1[2] = False
					if event.key == pygame.K_q:
						#self.q = False
						self.touche_j1[3] = False
						#player.direction.x = 0
					if event.key == pygame.K_d:
						#self.d = False
						self.touche_j1[4] = False
						#player.direction.x = 0
					if event.key == pygame.K_f:
						#self.attaquer = False
						self.touche_j1[5] = False
					if event.key == pygame.K_n:
						#self.espace = False
						self.touche_j2[0] = False
					if event.key == pygame.K_o:
						#self.z = False
						self.touche_j2[1] = False
					if event.key == pygame.K_l:
						#self.s = False
						self.touche_j2[2] = False
					if event.key == pygame.K_k:
						#self.q = False
						self.touche_j2[3] = False
						#player.direction.x = -1
					if event.key == pygame.K_m:
						#self.d = False
						self.touche_j2[4] = False
						#player.direction.x = 1
					if event.key == pygame.K_j:
						#self.attaquer = False
						self.touche_j2[5] = False
				if event.type == pygame.QUIT:
					self.continuer = False
			self.ecran.fill('Black')
			if self.state == 0:
				self.state = self.niv1.run(self.touche_j1, self.touche_j2)
			elif self.state == -1:
				self.state = self.niv2.run(self.touche_j1, self.touche_j2)
			elif self.state == 1:
				self.state = self.niv2.run(self.touche_j1, self.touche_j2)
			# print(self.state)
			self.clk.tick(60)
			pygame.display.update()
		pygame.quit()

game = Game()
game.run()

	

