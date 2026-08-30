# Bouvier d'Acher Victor
# Classe 42
# Projet Cryptographie
# Cryptis

"""
Ceci est un fichier de test

il permet de realiser les differentes étapes 
de la cryptographie par réseaux euclidien 
sans l'interface graphique

libre à vous de tester differentes clefs et messages
et de modifier les algorithmes de création de clef,
de chiffrement ou déchiffrement comme bon vous semble
"""

import random
import numpy as np
from constante import *
from creer_alphabet import *
from convertion import *
from test_fonction import *


# debut du main

taille = 10

dico = creer_alphabet()


clef_prive = creer_clef_privee_libre(taille)

# clef_prive = np.array([1, 7, -1])

clef_public = creer_clef_public_libre(clef_prive)

# clef_prive = np.array([1, 0, 0, 1, 4, 3, -2, 0, 6, 4])
# clef_public = np.array([-13, -58, -49, -23,  -3, 3, -27, -58, -23, 13])


# clef_public = np.array([16, -4, -12])

print(clef_prive)
print(clef_public)

message = "Victoire"

message = convertir_texte_into_tab(message, dico)

message = chiffrement_libre(message, clef_public)

# message = np.array([-9, 29, -20, 44, -23, -20])
print(message)


# clef_public = np.array([-98, -123, -323, -7, 3522, 2122, 3404, 3765, -7114, -5266, -8973, 5414, 56, 1424, -402, -52, 164, 503, 119, -193, -361, -43, 211, 187, 275, -13, 16, -345, -134, -247, 44, 170, 256, 363, 122, -71, -423, -305, -71, 70, 37, -107, 99, -119, 206, -283, 146, -97, 476, 322, -80, -88, -649, -45, -203, 492, 175, 358, 76, -67, -59, -212, 231, -231, 256, -277, -6, -217, 239, -29, 171, -56, 397, -122, 40, -296, 344, 66, 238, -79])
# message = np.array([-11518, 7044, 8487, 25474, -10437, -2497, -20277, -10884, -7404, -7804, 14094, 45910, 65013, -31358, -47990, -63975, -30405, 51456, 64080, 48068, -26426, -7010, -12248, -44747, -34096, 46573, 16775, 23547, -12730, -8217, -24815, -6148, 12357, 3520, -17388, -12271, 1265, 2834, 18721, 46926, 34214, 38733, -55066, -23258, -34755, 29096, 7494, 5751, -17072, -12473, -11226, 11175, 15892, 20671, -5763, -18832, -4443, 15282, 737, -7280, -4800, -3989, 11910, -6408, 7583, -25413, -2249, -13749, 333, 16704, 17056, 40624, -9081, 16491, -45122, 3125, -11099, 1401, -5433, -13862])
print(len(clef_public))
print(len(message))

# print(clef_public)
message = babai_libre(message, clef_public)

print(message)
# print(f'message dechiffrer : {message}')

message = convertir_tab_into_texte(message, dico)
# print(f'message recu : {message}')

print(message)

