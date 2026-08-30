from equipe import*

class Statistique(object):
	def __init__(self, nom_fichier, nom_equipe, nom_gardien):
		super(Statistique, self).__init__()
		self.nom_fichier = nom_fichier
		self.nom_equipe = nom_equipe
		self.nom_gardien = nom_gardien
		self.equipe = []
		self.tps_jeu = 0
		self.tir = 0
		self.tir_cadre = 0
		self.but = 0
		self.pressing = 0
		self.tacle = 0
		self.xG = 0
		self.xA = 0
		self.passe = 0
		self.passe_reussi = 0
		self.stat = []
		self.nb_match = 0

	def ouverture(self):
		for i in range(4):
			eq = Equipe(self.nom_equipe[i], self.nom_fichier[i], self.nom_gardien[i])
			eq.ouvrir()
			eq.ouvrir_gardien()
			self.equipe.append(eq)


	def affichage_joueur(self):
		print('Equipe que vous voulez regardez')
		for i in range(len(self.equipe)):
			print(f'{self.equipe[i].nom} ({i})')
		print(f'Toutes les equipes {len(self.equipe)}')
		choix = int(input())
		print(choix)
		if choix >= 0 and choix <= len(self.equipe)-1:
			self.equipe[choix].affiche(choix)
		elif choix == len(self.equipe):
			for j in range(choix):
				self.equipe[j].affiche(choix)
		else:
			print('erreur')
		print()

	def affichage_gardien(self):
		for i in range(len(self.equipe)):
			self.equipe[i].affiche_gardien()


	def stat_glob(self):
		for i in range(4):
			tab = self.equipe[i].donner()
			self.tps_jeu += tab[0]
			self.tir += tab[1]
			self.tir_cadre += tab[2]
			self.but += tab[3]
			self.pressing += tab[4]
			self.tacle += tab[5]
			self.xG += tab[6]
			self.xA += tab[7]
			self.passe += tab[8]
			self.passe_reussi += tab[9]

		self.stat.append(self.tps_jeu)
		self.stat.append(self.tir)
		self.stat.append(self.tir_cadre)
		self.stat.append(self.but)
		self.stat.append(self.pressing)
		self.stat.append(self.tacle)
		self.stat.append(self.xG)
		self.stat.append(self.xA)
		self.stat.append(self.passe)
		self.stat.append(self.passe_reussi)


	def aff_stat_glob(self):
		print(f'temps de jeu :    {self.tps_jeu}')
		print(f'tir :             {self.tir}')
		print(f'tir cadre :       {self.tir_cadre}')
		print(f'but :             {self.but}')
		print(f'pressing :        {self.pressing}')
		print(f'tacle :           {self.tacle}')
		print(f'xG :              {self.xG}')
		print(f'xA :              {self.xA}')
		print(f'passe :           {self.passe}')
		print(f'passe reussi :    {self.passe_reussi}')
		print(f'nombre de match : {self.nb_match}')
		print()

	def moye(self):
		self.equipe[0].moy(self.stat)

