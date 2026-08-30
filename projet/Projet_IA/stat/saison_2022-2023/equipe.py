import csv
# from attaquant import*
from gardien import*
# from defenseur import*
# from milieu import*
from joueur import*

class Equipe(object):
	def __init__(self, nom, fic, fic_gardien):
		super(Equipe, self).__init__()
		self.nom = nom
		self.fic = fic
		self.fic_gardien = fic_gardien
		self.joueur = []
		self.gardien = []

	def ouvrir(self):
		for fic in self.fic:
			with open(fic, newline = '') as match:
				verif = True
				name = ['Min', 'Buts', 'Tirs', 'TC', 'Press', 'Tcl', 'xG', 'xA', 'Cmp', 'Att', 'Pos']
				next(match)
				read = csv.DictReader(match)
				for nom in read:
					if nom['Joueur'][0] != '1':
					# print(nom['Joueur'])
					# if nom['Pos'] == 'FW' or nom['Pos'] == 'RW' or nom['Pos'] == 'LW':
						a = len(self.joueur)
						if a != 0:
							for i in range(a):
								j = nom['Joueur']
								# print(f'{self.joueur[i].nom}, {j}')
								if self.joueur[i].nom == nom['Joueur']:
									# print('bou')
									verif = False
									tab = []
									for stat in name:
										tab.append(nom[stat])
									self.joueur[i].ajout(tab)
							if verif:
								jou = Joueur(nom['Joueur'])
								tab = []
								i=0
								for stat in name:
									tab.append(nom[stat])
								jou.ajout(tab)
								self.joueur.append(jou)
							verif = True
						else:
							jou = Joueur(nom['Joueur'])
							tab = []
							i=0
							for stat in name:
								tab.append(nom[stat])
							jou.ajout(tab)
							self.joueur.append(jou)

	def ouvrir_gardien(self):
		for fic in self.fic_gardien:
			with open(fic, newline = '') as match:
				verif = True
				name = ['Min', 'TCC', 'BE', 'Arrêts', 'PSxG', 'Cmp', 'Att']
				next(match)
				read = csv.DictReader(match)
				for nom in read:
					if nom['Joueur'][0] != '1':
					# print(nom['Joueur'])
					# if nom['Pos'] == 'FW' or nom['Pos'] == 'RW' or nom['Pos'] == 'LW':
						a = len(self.gardien)
						if a != 0:
							for i in range(a):
								j = nom['Joueur']
								# print(f'{self.joueur[i].nom}, {j}')
								if self.gardien[i].nom == nom['Joueur']:
									# print('bou')
									verif = False
									tab = []
									for stat in name:
										tab.append(nom[stat])
									self.gardien[i].ajout(tab)
							if verif:
								gar = Gardien(nom['Joueur'])
								tab = []
								i=0
								for stat in name:
									tab.append(nom[stat])
								gar.ajout(tab)
								self.gardien.append(gar)
							verif = True
						else:
							gar = Gardien(nom['Joueur'])
							tab = []
							i=0
							for stat in name:
								tab.append(nom[stat])
							gar.ajout(tab)
							self.gardien.append(gar)
				
	def affiche(self, choix):
		if choix == 4:
			for j in range(choix):
				self.joueur[j].afficher()
		else:
			print('Joueur que vous voulez regardez')
			for i in range(len(self.joueur)):
				print(f'{self.joueur[i].nom} ({i})')
			print(f'Tout les joueurs {len(self.joueur)}')
			choix = 0
			choix = int(input())
			if choix >= 0 and choix <= len(self.joueur)-1:
				self.joueur[choix].afficher()
			elif choix == len(self.joueur):
				for j in range(choix):
					self.joueur[j].afficher()
			else:
				print('erreur')
		print()


	def affiche_gardien(self):
		for i in range(len(self.gardien)):
			self.gardien[i].afficher()

	def donner(self):
		tableau = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
		for i in range(len(self.joueur)):
			tab = self.joueur[i].recup_donner()
			for j in range(len(tableau)):
				tableau[j] += tab[j]
		return tableau

	def moy(self, stat):
		self.joueur[9].moyenne(stat)