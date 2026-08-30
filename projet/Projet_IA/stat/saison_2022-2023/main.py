# import csv
from statistique import*
# from equipe import*
# from joueur import*



# FW attaquant
# LM Millieu de terrain
# LW = AT, MT
nom_ficher = []
nom_ficher_gardien = []
nom_equipe = ['auxerre', 'ajaccio', 'angers', 'monaco']
auxerre = ['Auxerre/match1/resume.csv', 'Auxerre/match2/resume.csv', 'Auxerre/match3/resume.csv', 'Auxerre/match4/resume.csv', 'Auxerre/match5/resume.csv', 'Auxerre/match6/resume.csv', 'Auxerre/match7/resume.csv', 'Auxerre/match8/resume.csv']
ajaccio = ['Ajaccio/match1/resume.csv', 'Ajaccio/match2/resume.csv', 'Ajaccio/match3/resume.csv', 'Ajaccio/match4/resume.csv', 'Ajaccio/match5/resume.csv', 'Ajaccio/match6/resume.csv', 'Ajaccio/match7/resume.csv', 'Ajaccio/match8/resume.csv']
angers = ['Angers/match1/resume.csv', 'Angers/match2/resume.csv', 'Angers/match3/resume.csv', 'Angers/match4/resume.csv', 'Angers/match5/resume.csv', 'Angers/match6/resume.csv', 'Angers/match7/resume.csv', 'Angers/match8/resume.csv']
monaco = ['Monaco/match1/resume.csv', 'Monaco/match2/resume.csv', 'Monaco/match3/resume.csv', 'Monaco/match4/resume.csv', 'Monaco/match5/resume.csv', 'Monaco/match6/resume.csv', 'Monaco/match7/resume.csv', 'Monaco/match8/resume.csv']

auxerre_g = ['Auxerre/match1/gardien.csv', 'Auxerre/match2/gardien.csv', 'Auxerre/match3/gardien.csv', 'Auxerre/match4/gardien.csv', 'Auxerre/match5/gardien.csv', 'Auxerre/match6/gardien.csv', 'Auxerre/match7/gardien.csv', 'Auxerre/match8/gardien.csv']
ajaccio_g = ['Ajaccio/match1/gardien.csv', 'Ajaccio/match2/gardien.csv', 'Ajaccio/match3/gardien.csv', 'Ajaccio/match4/gardien.csv', 'Ajaccio/match5/gardien.csv', 'Ajaccio/match6/gardien.csv', 'Ajaccio/match7/gardien.csv', 'Ajaccio/match8/gardien.csv']
angers_g = ['Angers/match1/gardien.csv', 'Angers/match2/gardien.csv', 'Angers/match3/gardien.csv', 'Angers/match4/gardien.csv', 'Angers/match5/gardien.csv', 'Angers/match6/gardien.csv', 'Angers/match7/gardien.csv', 'Angers/match8/gardien.csv']
monaco_g = ['Monaco/match1/gardien.csv', 'Monaco/match2/gardien.csv', 'Monaco/match3/gardien.csv', 'Monaco/match4/gardien.csv', 'Monaco/match5/gardien.csv', 'Monaco/match6/gardien.csv', 'Monaco/match7/gardien.csv', 'Monaco/match8/gardien.csv']


nom_ficher.append(auxerre)
nom_ficher.append(ajaccio)
nom_ficher.append(angers)
nom_ficher.append(monaco)

nom_ficher_gardien.append(auxerre_g)
nom_ficher_gardien.append(ajaccio_g)
nom_ficher_gardien.append(angers_g)
nom_ficher_gardien.append(monaco_g)

stat = Statistique(nom_ficher, nom_equipe, nom_ficher_gardien)
stat.ouverture()
# stat.affichage_joueur()
stat.stat_glob()
# stat.aff_stat_glob()
# stat.moye()
stat.affichage_gardien()

