class Gardien(object):
	def __init__(self, nom):
		super(Gardien, self).__init__()
		self.nom = nom
		self.tps_jeu = 0
		self.tir = 0
		self.tir_cadre = 0
		self.but = 0
		self.xG = 0
		self.xA = 0
		self.passe = 0
		self.passe_reussi = 0
		self.nb_match = 0

	def ajout(self, tab):
		self.tps_jeu += int(tab[0])
		self.but += int(tab[1])
		self.tir += int(tab[2])
		self.tir_cadre += int(tab[3])
		self.xG += float(tab[4])
		self.xA += float(tab[5])
		self.passe += int(tab[6])
		self.passe_reussi += int(tab[7])

	def afficher(self):
		print(self.nom)
		print(self.tps_jeu)
		print(self.tir)
		print(self.tir_cadre)
		print(self.but)
		print(self.xG)
		print(self.xA)
		print(self.passe)
		print(self.passe_reussi)
		