class Joueur(object):
	def __init__(self, nom):
		super(Joueur, self).__init__()
		self.nom = nom
		self.poste = []
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
		self.nb_match = 0
		self.note = 0
		

	def ajout(self, tab):
		verif = True
		j=0
		self.tps_jeu += int(tab[0])
		self.but += int(tab[1])
		self.tir += int(tab[2])
		self.tir_cadre += int(tab[3])
		self.pressing += int(tab[4])
		self.tacle += int(tab[5])
		self.xG += float(tab[6])
		self.xA += float(tab[7])
		self.passe += int(tab[8])
		self.passe_reussi += int(tab[9])
		for i in range(len(self.poste)):
			if self.poste[i] != tab[10]:
				j += 1
		if j == len(self.poste):
			self.poste.append(tab[10])
		self.nb_match += 1

	def afficher(self):
		print()
		print(self.nom)
		print(self.poste)
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

	def recup_donner(self):
		tab = []
		tab.append(self.tps_jeu)
		tab.append(self.tir)
		tab.append(self.tir_cadre)
		tab.append(self.but)
		tab.append(self.pressing)
		tab.append(self.tacle)
		tab.append(self.xG)
		tab.append(self.xA)
		tab.append(self.passe)
		tab.append(self.passe_reussi)
		return tab

	def moyenne(self, stat):
		moy_tps_jeu = self.tps_jeu / stat[0]
		moy_tir = (self.tir/self.tps_jeu)
		moy_tir_cadre = (self.tir_cadre/self.tps_jeu)
		moy_but = (self.but/self.tps_jeu)
		moy_pressing = (self.pressing/self.tps_jeu)
		moy_tacle = (self.tacle/self.tps_jeu)
		moy_xG = (self.xG/self.tps_jeu)
		moy_xA = (self.xA/self.tps_jeu)
		moy_passe = (self.passe/self.tps_jeu)
		moy_passe_reussi = (self.passe_reussi/self.tps_jeu)

		# print(moy_tir)
		# print(moy_tir_cadre)
		# print(moy_but)
		# print(moy_xG)
		# print(moy_xA)
		# print(moy_passe)
		# print(moy_passe_reussi)

		tab1 = []
		tab1.append(moy_tir)
		tab1.append(moy_tir_cadre)
		tab1.append(moy_but)
		tab1.append(moy_pressing)
		tab1.append(moy_tacle)
		tab1.append(moy_xG)
		tab1.append(moy_xA)
		tab1.append(moy_passe)
		tab1.append(moy_passe_reussi)
		
		tab2 = []
		tab2.append(stat[1]/stat[0])
		tab2.append(stat[2]/stat[0])
		tab2.append(stat[3]/stat[0])
		tab2.append(stat[4]/stat[0])
		tab2.append(stat[5]/stat[0])
		tab2.append(stat[6]/stat[0])
		tab2.append(stat[7]/stat[0])
		tab2.append(stat[8]/stat[0])
		tab2.append(stat[9]/stat[0])

		pourcentage = [0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1]

		niv = 0

		for i in range(len(tab1)):
			print(tab1[i]/tab2[i])
			niv += (tab1[i] / tab2[i]) * pourcentage[i]

		print()
		print(niv)

		niv /= 10

		print(niv)

		self.afficher()

