import pygame
from init import *
from piece import *
from events_traitement import *
from random_tout import tout as Hasard
from modif_couleur import *




daltonisme = -1
ecran, clk = init_pygame()
List_Ob = []
coffre = []
hasard = Hasard()
ordre = hasard.get_ordre()
mdp = hasard.get_mdp()
vase_ordre = hasard.get_vaseordre()
def jeu():
	hasard = Hasard()
	ordre = hasard.get_ordre()
	mdp = hasard.get_mdp()
	vase_ordre = hasard.get_vaseordre()
	liste_vase = [rouge,orange,jaune]
	List_Ob = []

	List_Ob.append(objet(ecran, modifier_couleur(liste_vase[ordre[0]]), mdp[ordre[0]], 0.3, 200, 'vase', pos=(vase_ordre[0], 300)))
	List_Ob.append(objet(ecran, modifier_couleur(liste_vase[ordre[1]]), mdp[ordre[1]], 0.3, 200, 'vase', pos=(vase_ordre[1], 300)))
	List_Ob.append(objet(ecran, modifier_couleur(liste_vase[ordre[2]]), mdp[ordre[2]], 0.3, 200, 'vase', pos=(vase_ordre[2], 300)))
	List_Ob.append(objet(ecran, modifier_couleur(gris), "", 0.3, 200, 'coffre', pos=(350, 650)))
	List_Ob.append(objet(ecran, modifier_couleur(gris_clair), "", 0.3, 200, 'le carre', pos=(350, 650)))
	List_Ob.append(objet(ecran, modifier_couleur(vert), "", 0.3, 50, 'ecran_chiffre', pos = (480, 750)))

	List_Ob.append(objet(ecran, modifier_couleur(marron), "", 0.3, 200, 'protanopia', pos=(100, 900)))
	List_Ob.append(objet(ecran, modifier_couleur(vert_fonce), "", 0.3, 200, 'deuteranopia', pos=(150, 900)))
	List_Ob.append(objet(ecran, modifier_couleur(bleu_marine), "", 0.3, 200, 'tritanopia', pos=(50, 900)))
	List_Ob.append(objet(ecran, modifier_couleur((255, 255, 255)), "", 0.3, 200, 'normal', pos=(200, 900)))

	
	List_Ob.append(objet(ecran, modifier_couleur((255, 255, 255)), 'normal', 1, 100, 'type_dalto'))

	List_Ob.append(objet(ecran, modifier_couleur(gris), "", 1, 100, 'type_dalto', largeur=5))

	coffre = []
	coffre.append(objet(ecran, modifier_couleur(gris), "", 1, 0,'coffre'))

	c = 1
	for i in range(400,700,100):
		for j in range(400,700,100):
			coffre.append(objet(ecran, modifier_couleur(gris_clair), c, 1, 50, 'pad', pos = (j, i)))
			c+=1
	coffre.append(objet(ecran, modifier_couleur(gris_clair), 0, 1, 50, 'pad', pos = (400, 700)))
	coffre.append(objet(ecran, modifier_couleur(vert), "", 1, 50, 'ecran_chiffre', pos = (400, 250)))
	coffre.append(objet(ecran, modifier_couleur(gris_clair), "", 1, 50, 'le carre', 10))
	coffre.append(objet(ecran, modifier_couleur(liste_vase[ordre[0]]), "", 1, 50, 'couleur', pos=(400, 150)))
	coffre.append(objet(ecran, modifier_couleur(liste_vase[ordre[1]]), "", 1, 50, 'couleur', pos=(500, 150)))
	coffre.append(objet(ecran, modifier_couleur(liste_vase[ordre[2]]), "", 1, 50, 'couleur', pos=(600, 150)))
	coffre.append(objet(ecran, modifier_couleur(gris), "X", 1, 50, 'croix', pos=(920, 50)))
	etat = "piece"
	return coffre,List_Ob,mdp,ordre,etat

add = 0

etat = "piece"

coffre,List_Ob,mdp,ordre,etat = jeu()
etat_dalto = 'normal'
arret = False
while(not arret):
	ecran.fill('Black')
	bouton, arret, mouse_pos = evenement_pygame()
	
	if bouton:
		if etat == "coffre":
			for i in coffre:
				if point_dans_polygone(mouse_pos,i.get_forme()):
					if i.get_name() == 'pad':
						add = i.get_chiffre()
					if i.get_name() == 'croix':
						etat = 'piece'
					if i.get_name() == 'reset':
						coffre,List_Ob,mdp,ordre,etat = jeu()
		if etat == "piece":
			for i in List_Ob:
				if point_dans_polygone(mouse_pos,i.get_forme()):
					if i.get_name() == 'coffre':
						etat = 'coffre'
					if i.get_name() == 'protanopia':
						etat_dalto = 'protanopia'
						daltonisme = protanopia
					if i.get_name() == 'deuteranopia':
						etat_dalto = 'deuteranopia'
						daltonisme = deuteranopia
					if i.get_name() == 'tritanopia':
						etat_dalto = 'tritanopia'
						daltonisme = tritanopia
					if i.get_name() == 'normal':
						etat_dalto = 'normal'
						daltonisme = -1

		
	
	if etat == "coffre":
		for i in coffre:
			if i.get_name() == 'ecran_chiffre' and add != 0:
				i.add_chiffre(add)
				add=0
				if i.get_chiffre() == mdp[ordre[0]]+mdp[ordre[1]]+mdp[ordre[2]]:
					coffre.append(objet(ecran, modifier_couleur(rouge), "Gagné !!", 1, 100, 'gagne'))
					coffre.append(objet(ecran, modifier_couleur(rouge), "reset", 1, 50, 'reset'))
				
			i.afficher(daltonisme)
	else:
		for i in List_Ob:
			if i.get_name() == 'type_dalto':
				i.modif_name(etat_dalto)
			i.afficher(daltonisme)
	pygame.display.update()


pygame.quit()