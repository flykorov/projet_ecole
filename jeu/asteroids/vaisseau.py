import pygame
import math
import random
from info import*

# destruction du vaisseau
class VaisseauDetruit:
    def __init__(self, x, y, l, e, c):
        self.angle = random.randrange(0, 360) * math.pi / 180
        self.dir = random.randrange(0, 360) * math.pi / 180
        self.rotation = random.uniform(-0.25, 0.25)
        self.x = x
        self.y = y
        self.longueur = l
        self.speed = random.randint(2, 8)
        self.ecran = e
        self.couleur = c

    def updateJoueurMort(self):
        pygame.draw.line(self.ecran, self.couleur,
                         (self.x + self.longueur * math.cos(self.angle) / 2,
                          self.y + self.longueur * math.sin(self.angle) / 2),
                         (self.x - self.longueur * math.cos(self.angle) / 2,
                          self.y - self.longueur * math.sin(self.angle) / 2))
        self.angle += self.rotation
        self.x += self.speed * math.cos(self.dir)
        self.y += self.speed * math.sin(self.dir)

# vaisseau du joueur

class Vaisseau:
    def __init__(self, x, y, couleur, e):
        self.x = x
        self.y = y

        self.re_x = x 
        self.re_y = y

        self.largeur = largeur
        self.hauteur = hauteur
        self.xvitesse = 0
        self.yvitesse = 0
        self.dir = -90
        self.rotation = 0

        self.delai_mort = 0
        self.invincibilite = 0
        self.clignotement = 0

        self.hyperspace = 0

        self.balle = []
        self.balle_mort = []
        self.nb_balle = 4

        self.avancer = False
        self.vivant = True

        self.friction_acc = 0.5
        self.friction_dec = 0.1
        self.vitesse_max_joueur = 20
        self.taille_joueur = 15
        self.ecran = e
        self.couleur = couleur

        self.explosion = 30
        self.distance_suivi = 100

        self.type_missile = 0
        self.vie = 2


        self.rectangle = pygame.Rect(self.x-self.taille_joueur, self.y-self.taille_joueur, self.taille_joueur*2, self.taille_joueur*2)

    def updateJoueur(self):
        # bouger joueur
        speed = math.sqrt(self.xvitesse**2 + self.yvitesse**2)
        if self.avancer:
            if speed + self.friction_acc < self.vitesse_max_joueur:
                self.xvitesse += self.friction_acc * math.cos(self.dir * math.pi / 180)
                self.yvitesse += self.friction_acc * math.sin(self.dir * math.pi / 180)
            else:
                self.xvitesse = self.vitesse_max_joueur * math.cos(self.dir * math.pi / 180)
                self.yvitesse = self.vitesse_max_joueur * math.sin(self.dir * math.pi / 180)
        else:
            if speed - self.friction_dec > 0:
                nouvelle_x = (self.friction_dec * math.cos(self.yvitesse / self.xvitesse))
                nouvelle_y = (self.friction_dec * math.sin(self.yvitesse / self.xvitesse))
                if self.xvitesse != 0:
                    if nouvelle_x / abs(nouvelle_x) == self.xvitesse / abs(self.xvitesse):
                        self.xvitesse -= nouvelle_x
                    else:
                        self.xvitesse += nouvelle_x
                if self.yvitesse != 0:
                    if nouvelle_y / abs(nouvelle_y) == self.yvitesse / abs(self.yvitesse):
                        self.yvitesse -= nouvelle_y
                    else:
                        self.yvitesse += nouvelle_y
            else:
                self.xvitesse = 0
                self.yvitesse = 0
        self.x += self.xvitesse
        self.y += self.yvitesse

        # bordure
        if self.x > self.largeur:
            self.x = 0
        elif self.x < 0:
            self.x = self.largeur
        elif self.y > self.hauteur:
            self.y = 0
        elif self.y < 0:
            self.y = self.hauteur

        self.rectangle = pygame.Rect(self.x-self.taille_joueur, self.y-self.taille_joueur, self.taille_joueur*2, self.taille_joueur*2)


        # rotation
        self.dir += self.rotation

    def afficherJoueur(self):
        a = math.radians(self.dir)
        x = self.x
        y = self.y
        s = self.taille_joueur
        t = self.avancer

        # pygame.draw.rect(self.ecran, (155, 0, 0), self.rectangle, 1)
        
        # affichage
        pygame.draw.line(self.ecran, self.couleur,
                         (x - (s * math.sqrt(130) / 12) * math.cos(math.atan(7 / 9) + a),
                          y - (s * math.sqrt(130) / 12) * math.sin(math.atan(7 / 9) + a)),
                         (x + s * math.cos(a), y + s * math.sin(a)))

        pygame.draw.line(self.ecran, self.couleur,
                         (x - (s * math.sqrt(130) / 12) * math.cos(math.atan(7 / 9) - a),
                          y + (s * math.sqrt(130) / 12) * math.sin(math.atan(7 / 9) - a)),
                         (x + s * math.cos(a), y + s * math.sin(a)))

        pygame.draw.line(self.ecran, self.couleur,
                         (x - (s * math.sqrt(2) / 2) * math.cos(a + math.pi / 4),
                          y - (s * math.sqrt(2) / 2) * math.sin(a + math.pi / 4)),
                         (x - (s * math.sqrt(2) / 2) * math.cos(-a + math.pi / 4),
                          y + (s * math.sqrt(2) / 2) * math.sin(-a + math.pi / 4)))
        if t:
            pygame.draw.line(self.ecran, self.couleur,
                             (x - s * math.cos(a),
                              y - s * math.sin(a)),
                             (x - (s * math.sqrt(5) / 4) * math.cos(a + math.pi / 6),
                              y - (s * math.sqrt(5) / 4) * math.sin(a + math.pi / 6)))
            pygame.draw.line(self.ecran, self.couleur,
                             (x - s * math.cos(-a),
                              y + s * math.sin(-a)),
                             (x - (s * math.sqrt(5) / 4) * math.cos(-a + math.pi / 6),
                              y + (s * math.sqrt(5) / 4) * math.sin(-a + math.pi / 6)))

        

    def affichage(self):
        if not self.vivant:
            if self.hyperspace == 0:
                if self.delai_mort == 0:
                    if self.clignotement < 5:
                        if self.clignotement == 0:
                            self.clignotement = 10
                        else:
                            self.afficherJoueur()
                    self.clignotement -= 1
                else:
                    self.delai_mort -= 1
        else:
            self.afficherJoueur()



    def tuerJoueur(self):
        # reset
        self.x = self.re_x
        self.y = self.re_y 
        self.avancer = False
        self.dir = -90
        self.xvitesse = 0
        self.yvitesse = 0
