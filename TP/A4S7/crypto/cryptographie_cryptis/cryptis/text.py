# Bouvier d'Acher Victor
# Classe 42
# Projet Cryptographie
# Cryptis

import pygame
from constante import *

def afficher(ecran, message, couleur, x, y, s, center=True):        # pour afficher le texte sur la console
    ecran_text = pygame.font.SysFont("Calibri", s).render(message, True, couleur)
    if center:
        rect = ecran_text.get_rect()
        rect.center = (x, y)
    else:
        rect = (x, y)
    ecran.blit(ecran_text, rect)