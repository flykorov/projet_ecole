import numpy as np

def modifier_couleur(couleur, dalton=-1):

    if dalton == -1:
        return couleur
    
    red , green, blue = couleur
    r = int(red * dalton[0][0] + green * dalton[0][1] + blue * dalton[0][2])
    g = int(red * dalton[1][0] + green * dalton[1][1] + blue * dalton[1][2])
    b = int(red * dalton[2][0] + green * dalton[2][1] + blue * dalton[2][2])
    c = (r, g, b)

    return c