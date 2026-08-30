import pygame
import math
import random
from info import*

class Asteroid:
    def __init__(self, x, y, t, e):
        self.x = x
        self.y = y

        self.largeur = largeur
        self.hauteur = hauteur

        self.ecran = e
        self.couleur = blanc

        if t == "Large":
            self.taille = 30
        elif t == "Normal":
            self.taille = 20
        else:
            self.taille = 10
        self.t = t

        # random vitesse et acceleration
        self.vitesse = random.uniform(1, (40 - self.taille) * 4 / 15)
        self.dir = random.randrange(0, 360) * math.pi / 180

        # random sprite
        full_circle = random.uniform(18, 36)
        dist = random.uniform(self.taille / 2, self.taille)
        self.vertices = []
        while full_circle < 360:
            self.vertices.append([dist, full_circle])
            dist = random.uniform(self.taille / 2, self.taille)
            full_circle += random.uniform(18, 36)

    def updateAsteroid(self):
        # bouger asteroid
        self.x += self.vitesse * math.cos(self.dir)
        self.y += self.vitesse * math.sin(self.dir)

        # bordure
        if self.x > self.largeur:
            self.x = 0
        elif self.x < 0:
            self.x = self.largeur
        elif self.y > self.hauteur:
            self.y = 0
        elif self.y < 0:
            self.y = self.hauteur

        # affiche asteroid
        for v in range(len(self.vertices)):
            if v == len(self.vertices) - 1:
                next_v = self.vertices[0]
            else:
                next_v = self.vertices[v + 1]
            this_v = self.vertices[v]
            pygame.draw.line(self.ecran, self.couleur, (self.x + this_v[0] * math.cos(this_v[1] * math.pi / 180),
                                                  self.y + this_v[0] * math.sin(this_v[1] * math.pi / 180)),
                             (self.x + next_v[0] * math.cos(next_v[1] * math.pi / 180),
                              self.y + next_v[0] * math.sin(next_v[1] * math.pi / 180)))
