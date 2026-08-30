class Gardien(object):
	def __init__(self, nom):
		super(Gardien, self).__init__()
		self.nom = nom
		self.tps_jeu = 0
		self.arret = 0
		self.but_encaisse = 0
		self.tir_cadre_recu = 0
		self.PSxG = 0
		self.degagement = 0
		self.degagement_reussi = 0
		self.nb_match = 0

	def ajout(self, tab):
		self.tps_jeu += int(tab[0])
		self.arret += int(tab[1])
		self.but_encaisse += int(tab[2])
		self.tir_cadre_recu += int(tab[3])
		self.PSxG += float(tab[4])
		self.degagement += int(tab[5])
		self.degagement_reussi += int(tab[6])
		self.nb_match += 1

	def afficher(self):
		print()
		print(self.nom)
		print('GK')
		print(f'temps de jeu :      {self.tps_jeu}')
		print(f'tir cadre recu :    {self.tir_cadre_recu}')
		print(f'arret :             {self.arret}')
		print(f'but encaisse :      {self.but_encaisse}')
		print(f'PSxG :              {self.PSxG}')
		print(f'degagement :        {self.degagement}')
		print(f'degagement reussi : {self.degagement_reussi}')
		print(f'nombre de match :   {self.nb_match}')
		print()