import pygame
from niv1 import*
from level import niveau

class Game:
	def __init__(self):
		pygame.init()
		pygame.joystick.init()
		self.state = 0
		self.ecran = pygame.display.set_mode((largeur, longueur))
		pygame.display.set_caption('test_jeu')
		self.clk = pygame.time.Clock()
		self.niv = niveau(niv1, self.ecran)
		self.touche_j1 = [False, False]
		self.touche_j2 = [False, False]
		self.continuer = True

	def run(self):
		# self.continuer = False
		while(self.continuer):
			for event in pygame.event.get():
				if event.type == pygame.KEYDOWN:
					if event.key == pygame.K_ESCAPE:
						self.continuer = False
					if event.key == pygame.K_z:
						self.touche_j1[0] = True
					if event.key == pygame.K_s:
						self.touche_j1[1] = True
					if event.key == pygame.K_o:
						self.touche_j2[0] = True
					if event.key == pygame.K_l:
						self.touche_j2[1] = True
				if event.type == pygame.KEYUP:
					if event.key == pygame.K_z:
						self.touche_j1[0] = False
					if event.key == pygame.K_s:
						self.touche_j1[1] = False
					if event.key == pygame.K_o:
						self.touche_j2[0] = False
					if event.key == pygame.K_l:
						self.touche_j2[1] = False
				if event.type == pygame.QUIT:
					self.continuer = False
			self.ecran.fill('Black')
			a = self.niv.run(self.touche_j1, self.touche_j2)
			self.clk.tick(60)
			pygame.display.update()
		print('bou')
		pygame.time.delay(2000)
		print('merang')
		pygame.joystick.quit()
		pygame.quit()

game = Game()
game.run()