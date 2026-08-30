import pygame
import math
import random

# import RPi.GPIO as GPIO
# GPIO.setmode(GPIO.BOARD)

from info import*
from vaisseau import*
from asteroid import*

from missile.basique import*
from missile.explosif import*
from missile.chercheuse import*

from power.vie import*
from power.munition import*
from power.taille import*
from power.vitesse import*
from power.balle import*
from power.po_explo import*
from power.po_cherch import*

pygame.init()

# ecran
ecran = pygame.display.set_mode((largeur, hauteur))
pygame.display.set_caption("Asteroids Versus")
clock = pygame.time.Clock()

snd_fire = pygame.mixer.Sound("sound/fire.wav")
snd_bangL = pygame.mixer.Sound("sound/bangLarge.wav")
snd_bangM = pygame.mixer.Sound("sound/bangMedium.wav")
snd_bangS = pygame.mixer.Sound("sound/bangSmall.wav")

# GPIO.setup(31, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)
# GPIO.setup(33, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)
# GPIO.setup(35, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)
# GPIO.setup(37, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)
# GPIO.setup(32, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)
# GPIO.setup(36, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)
# GPIO.setup(38, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)
# GPIO.setup(40, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)
# GPIO.setup(5, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)
# GPIO.setup(7, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)


# ecrire du texte
def afficher(message, couleur, x, y, s, center=True):
    ecran_text = pygame.font.SysFont("Calibri", s).render(message, True, couleur)
    if center:
        rect = ecran_text.get_rect()
        rect.center = (x, y)
    else:
        rect = (x, y)
    ecran.blit(ecran_text, rect)


# gerer les collisions
def collision(x, y, x2, y2, taille):
    if x > x2 - taille and x < x2 + taille and y > y2 - taille and y < y2 + taille:
        return True
    return False

def collisionRect(obj1, obj2):
    if obj1.rectangle.colliderect(obj2.rectangle):
        return True
    return False

def collisionCircle():
    pass

def randomPower(powerup, a, ecran):

    r = random.randrange(0, 8)

    if r == 0:
        b = random.randrange(0, 2)
        if b == 0:
            powerup.append(Po_Explo(a.x, a.y, ecran, rouge))
        else:
            powerup.append(Po_Cherch(a.x, a.y, ecran, violet))
    elif(r<4):
        b = random.randrange(0, 5)
        if b == 0:
            powerup.append(Vie(a.x, a.y, ecran, rouge))
        if b == 1:
            powerup.append(Munition(a.x, a.y, ecran, marron))
        if b == 2:
            powerup.append(Taille(a.x, a.y, ecran, vert))
        if b == 3:
            powerup.append(Balle(a.x, a.y, ecran, bleu_sombre))
        if b == 4:
            powerup.append(Vitesse(a.x, a.y, ecran, jaune))

def detruireVaisseau(p, j):
    p.append(VaisseauDetruit(j.x, j.y, 5 * j.taille_joueur / (2 * math.cos(math.atan(1 / 3))), ecran, j.couleur))
    p.append(VaisseauDetruit(j.x, j.y, 5 * j.taille_joueur / (2 * math.cos(math.atan(1 / 3))), ecran, j.couleur))
    p.append(VaisseauDetruit(j.x, j.y, j.taille_joueur, ecran, j.couleur))

    # tuer joueur
    j.vivant = False
    j.delai_mort = 30
    j.invincibilite = 120
    j.tuerJoueur()



def run(etatInitial):
    etatActuel = etatInitial
    # joueur_vivant = True
    # clignotement = [0, 0]
    attente = 0
    pieces_joueur1 = []
    pieces_joueur2 = []
    asteroid = []
    powerup = []
    # delay_mort = [0, 0]
    # duree_invincibilite = [0, 0]
    # hyperspace = [0, 0]
    # nb_balle = 4
    # balle = []
    stage = 3
    score = 0
    # live = 2
    oneUp_multiplier = 1
    playOneUpSFX = 0
    intensity = 0

    joueur1 = Vaisseau(largeur/4, hauteur/2, bleu, ecran)
    joueur2 = Vaisseau(largeur - largeur/4, hauteur/2, orange, ecran)


    # vie_sup = Vie(200, 100, ecran, rouge)
    # munition_sup = Munition(200, 200, ecran, bleu_sombre)
    # powerup.append(vie_sup)
    # powerup.append(munition_sup)

    while etatActuel != "Exit":
        # menu
        while etatActuel == "Menu":
            ecran.fill(noir)
            afficher("ASTEROIDS", blanc, largeur / 2, hauteur / 2, 100)
            afficher("cliquez", blanc, largeur / 2, hauteur / 2 + 100, 50)
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    etatActuel = "Exit"

                if event.type == pygame.KEYDOWN:
                    if event.key == pygame.K_ESCAPE:
                        etatActuel = "Exit"
                    else:
                        etatActuel = "Playing"
            pygame.display.update()
            clock.tick(30)

        # input raspberry
        # joystick
        # if GPIO.input(37) == GPIO.HIGH:
        #     joueur1.avancer = True
        # if GPIO.input(37) == GPIO.LOW:
        #     joueur1.avancer = False

        # if GPIO.input(33) == GPIO.HIGH:
        #     joueur1.rotation = vitesse_rotation_max
        # if GPIO.input(33) == GPIO.LOW:
        #     joueur1.rotation = 0

        # if GPIO.input(31) == GPIO.HIGH:
        #     joueur1.rotation = -vitesse_rotation_max
        # if GPIO.input(31) == GPIO.LOW:
            joueur1.rotation = 0

        # if GPIO.input(35) == GPIO.HIGH:

        # if GPIO.input(35) == GPIO.LOW:

        # if GPIO.input(40) == GPIO.HIGH:
        #     joueur2.avancer = True
        # if GPIO.input(40) == GPIO.LOW:
        #     joueur2.avancer = False

        # if GPIO.input(32) == GPIO.HIGH:
        #     joueur1.rotation = vitesse_rotation_max
        # if GPIO.input(32) == GPIO.LOW:
        #     joueur1.rotation = 0

        # if GPIO.input(38) == GPIO.HIGH:
        #     joueur1.rotation = -vitesse_rotation_max
        # if GPIO.input(38) == GPIO.LOW:
        #     joueur1.rotation = 0

        # if GPIO.input(36) == GPIO.HIGH:

        # if GPIO.input(36) == GPIO.LOW:

        # bouton
        # if GPIO.input(5) == GPIO.HIGH and joueur1.delai_mort == 0 and len(joueur1.balle) < joueur1.nb_balle:
        #     if joueur1.type_missile == 0:
        #         joueur1.balle.append(Basique(joueur1.x, joueur1.y, joueur1.dir, largeur, hauteur, ecran, blanc))
        #     if joueur1.type_missile == 1:
        #         joueur1.balle.append(Explosif(joueur1.x, joueur1.y, joueur1.dir, largeur, hauteur, ecran, orange, joueur1.explosion))
        #     if joueur1.type_missile == 2:
        #         joueur1.balle.append(Chercheuse(joueur1.x, joueur1.y, joueur1.dir, largeur, hauteur, ecran, blanc, joueur1.distance_suivi))
        # if GPIO.input(7) == GPIO.HIGH and joueur2.delai_mort == 0 and len(joueur2.balle) < joueur2.nb_balle:
        #     if joueur2.type_missile == 0:
        #         joueur2.balle.append(Basique(joueur2.x, joueur2.y, joueur2.dir, largeur, hauteur, ecran, blanc))
        #     if joueur2.type_missile == 1:
        #         joueur2.balle.append(Explosif(joueur2.x, joueur2.y, joueur2.dir, largeur, hauteur, ecran, orange, joueur2.explosion))
        #     if joueur2.type_missile == 2:
        #         joueur2.balle.append(Chercheuse(joueur2.x, joueur2.y, joueur2.dir, largeur, hauteur, ecran, blanc, joueur2.distance_suivi))
        # # input
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                etatActuel = "Exit"
            if event.type == pygame.KEYDOWN:

                if event.key == pygame.K_ESCAPE:
                    etatActuel = "Exit"

                if event.key == pygame.K_z:
                    joueur2.avancer = True
                if event.key == pygame.K_d:
                    joueur2.rotation = vitesse_rotation_max
                if event.key == pygame.K_q:
                    joueur2.rotation = -vitesse_rotation_max
                if event.key == pygame.K_SPACE and joueur2.delai_mort == 0 and len(joueur2.balle) < joueur2.nb_balle:
                    if joueur2.type_missile == 0:
                        joueur2.balle.append(Basique(joueur2.x, joueur2.y, joueur2.dir, largeur, hauteur, ecran, blanc))
                    if joueur2.type_missile == 1:
                        joueur2.balle.append(Explosif(joueur2.x, joueur2.y, joueur2.dir, largeur, hauteur, ecran, orange, joueur2.explosion))
                    if joueur2.type_missile == 2:
                        joueur2.balle.append(Chercheuse(joueur2.x, joueur2.y, joueur2.dir, largeur, hauteur, ecran, blanc, joueur2.distance_suivi))

                    # Play SFX
                    pygame.mixer.Sound.play(snd_fire)


                if event.key == pygame.K_UP:
                    joueur1.avancer = True
                if event.key == pygame.K_LEFT:
                    joueur1.rotation = -vitesse_rotation_max
                if event.key == pygame.K_RIGHT:
                    joueur1.rotation = vitesse_rotation_max
                if event.key == pygame.K_m and joueur1.delai_mort == 0 and len(joueur1.balle) < joueur1.nb_balle:
                    if joueur1.type_missile == 0:
                        joueur1.balle.append(Basique(joueur1.x, joueur1.y, joueur1.dir, largeur, hauteur, ecran, blanc))
                    if joueur1.type_missile == 1:
                        joueur1.balle.append(Explosif(joueur1.x, joueur1.y, joueur1.dir, largeur, hauteur, ecran, orange, joueur1.explosion))
                    if joueur1.type_missile == 2:
                        joueur1.balle.append(Chercheuse(joueur1.x, joueur1.y, joueur1.dir, largeur, hauteur, ecran, bleu_sombre, joueur1.distance_suivi))


                    # Play SFX
                    pygame.mixer.Sound.play(snd_fire)


                if etatActuel == "Game Over":
                    if event.key == pygame.K_r:
                        etatActuel = "Exit"
                        run("Menu")

                # if event.key == pygame.K_LSHIFT:
                #     hyperspace = 30

            if event.type == pygame.KEYUP:
                if event.key == pygame.K_z:
                    joueur2.avancer = False
                if event.key == pygame.K_q or event.key == pygame.K_d:
                    joueur2.rotation = 0

                if event.key == pygame.K_UP:
                    joueur1.avancer = False
                if event.key == pygame.K_LEFT or event.key == pygame.K_RIGHT:
                    joueur1.rotation = 0

        # if joueur1.vivant:
        joueur1.updateJoueur()
        # if joueur2.vivant:
        joueur2.updateJoueur()

        # duree d invincibilite du joueur
        
        if joueur1.invincibilite != 0:
            joueur1.invincibilite -= 1
        else:
            joueur1.vivant = True

        # elif hyperspace[0] == 0:
        #     joueur_vivant = True

        if joueur2.invincibilite != 0:
            joueur2.invincibilite -= 1
        else:
            joueur2.vivant = True

        # elif hyperspace[1] == 0:
        #     joueur_vivant = True

        ecran.fill(noir)

        # Hyperspace

        # if hyperspace != 0:
        #     joueur_vivant = False
        #     hyperspace -= 1
        #     if hyperspace == 1:
        #         joueur1.x = random.randrange(0, largeur)
        #         joueur1.y = random.randrange(0, hauteur)

        # afficher fragment vaisseau
        for f in pieces_joueur1:
            f.updateJoueurMort()
            if f.x > largeur or f.x < 0 or f.y > hauteur or f.y < 0:
                pieces_joueur1.remove(f)

        for f in pieces_joueur2:
            f.updateJoueurMort()
            if f.x > largeur or f.x < 0 or f.y > hauteur or f.y < 0:
                pieces_joueur2.remove(f)

        if joueur1.vivant and joueur2.vivant:
            if collision(joueur1.x, joueur1.y, joueur2.x, joueur2.y, joueur2.taille_joueur):
                detruireVaisseau(pieces_joueur1, joueur1)

                if joueur1.vie != 0:
                    joueur1.vie -= 1
                else:
                    etatActuel = "Game Over"

                detruireVaisseau(pieces_joueur2, joueur2)

                if joueur2.vie != 0:
                    joueur2.vie -= 1
                else:
                    etatActuel = "Game Over"

        for p in powerup:
            p.afficherPower()
            sup=False
            if joueur1.vivant:
                if collisionRect(joueur1, p):
                    p.action(joueur1)
                    sup=True


            if joueur2.vivant:
                if collisionRect(joueur2, p):
                    p.action(joueur2)
                    sup=True

            if sup:
                powerup.remove(p)

        # collision avec asteroid
        for a in asteroid:
            a.updateAsteroid()
            if joueur1.vivant:
                if collision(joueur1.x, joueur1.y, a.x, a.y, a.taille):
                    # fragment vaisseau
                    detruireVaisseau(pieces_joueur1, joueur1)

                    randomPower(powerup, a, ecran)

                    if joueur1.vie != 0:
                        joueur1.vie -= 1
                    else:
                        etatActuel = "Game Over"

                    # Split asteroid
                    if a.t == "Large":
                        asteroid.append(Asteroid(a.x, a.y, "Normal", ecran))
                        asteroid.append(Asteroid(a.x, a.y, "Normal", ecran))
                        # Play SFX
                        pygame.mixer.Sound.play(snd_bangL)
                    elif a.t == "Normal":
                        asteroid.append(Asteroid(a.x, a.y, "Small", ecran))
                        asteroid.append(Asteroid(a.x, a.y, "Small", ecran))
                        # Play SFX
                        pygame.mixer.Sound.play(snd_bangM)
                    else:
                        pass
                        # Play SFX
                        pygame.mixer.Sound.play(snd_bangS)
                    asteroid.remove(a)

            if joueur2.vivant:
                if collision(joueur2.x, joueur2.y, a.x, a.y, a.taille):
                    # fragment vaisseau
                    detruireVaisseau(pieces_joueur2, joueur2)

                    randomPower(powerup, a, ecran)

                    if joueur2.vie != 0:
                        joueur2.vie -= 1
                    else:
                        etatActuel = "Game Over"

                    # Split asteroid
                    if a.t == "Large":
                        asteroid.append(Asteroid(a.x, a.y, "Normal", ecran))
                        asteroid.append(Asteroid(a.x, a.y, "Normal", ecran))
                        # Play SFX
                        pygame.mixer.Sound.play(snd_bangL)
                    elif a.t == "Normal":
                        asteroid.append(Asteroid(a.x, a.y, "Small", ecran))
                        asteroid.append(Asteroid(a.x, a.y, "Small", ecran))
                        # Play SFX
                        pygame.mixer.Sound.play(snd_bangM)
                    else:
                        pass
                        # Play SFX
                        pygame.mixer.Sound.play(snd_bangS)
                    asteroid.remove(a)


        # balle
        for b in joueur2.balle:
            b.updateMissile()
            b.posJoueur(joueur1.x, joueur1.y)

            if joueur1.vivant:
                if collision(b.x, b.y, joueur1.x, joueur1.y, joueur1.taille_joueur):
                    detruireVaisseau(pieces_joueur1, joueur1)

                    if joueur1.vie != 0:
                        joueur1.vie -= 1
                    else:
                        etatActuel = "Game Over"

                    joueur2.balle.remove(b)

            for a in asteroid:
                if collision(b.x, b.y, a.x, a.y, a.taille):

                    randomPower(powerup, a, ecran)

                    # Split asteroid
                    if a.t == "Large":
                        asteroid.append(Asteroid(a.x, a.y, "Normal", ecran))
                        asteroid.append(Asteroid(a.x, a.y, "Normal", ecran))
                        # Play SFX
                        pygame.mixer.Sound.play(snd_bangL)
                    elif a.t == "Normal":
                        asteroid.append(Asteroid(a.x, a.y, "Small", ecran))
                        asteroid.append(Asteroid(a.x, a.y, "Small", ecran))
                        # Play SFX
                        pygame.mixer.Sound.play(snd_bangM)
                    else:
                        pass
                        # Play SFX
                        pygame.mixer.Sound.play(snd_bangS)
                    asteroid.remove(a)
                    try:
                        joueur2.balle.remove(b)
                        joueur2.balle_mort.append(b)
                    except ValueError:
                        continue
                    break

            # detruire balle
            if b.vie <= 0:
                try:
                    joueur2.balle.remove(b)
                    joueur2.balle_mort.append(b)
                except ValueError:
                    continue

        for b in joueur1.balle:
            b.updateMissile()
            b.posJoueur(joueur2.x, joueur2.y)

            if joueur2.vivant:
                if collision(b.x, b.y, joueur2.x, joueur2.y, joueur2.taille_joueur):
                    detruireVaisseau(pieces_joueur2, joueur2)

                    if joueur2.vie != 0:
                        joueur2.vie -= 1
                    else:
                        etatActuel = "Game Over"

                    joueur1.balle.remove(b)

            for a in asteroid:
                if collision(b.x, b.y, a.x, a.y, a.taille):

                    randomPower(powerup, a, ecran)
                    
                    # Split asteroid
                    if a.t == "Large":
                        asteroid.append(Asteroid(a.x, a.y, "Normal", ecran))
                        asteroid.append(Asteroid(a.x, a.y, "Normal", ecran))
                        # Play SFX
                        pygame.mixer.Sound.play(snd_bangL)
                    elif a.t == "Normal":
                        asteroid.append(Asteroid(a.x, a.y, "Small", ecran))
                        asteroid.append(Asteroid(a.x, a.y, "Small", ecran))
                        # Play SFX
                        pygame.mixer.Sound.play(snd_bangM)
                    else:
                        pass
                        # Play SFX
                        pygame.mixer.Sound.play(snd_bangS)
                    asteroid.remove(a)
                    try:
                        joueur1.balle.remove(b)
                        joueur1.balle_mort.append(b)
                    except ValueError:
                        continue
                    break

            # detruire balle
            if b.vie <= 0:
                try:
                    joueur1.balle.remove(b)
                    joueur1.balle_mort.append(b)
                except ValueError:
                    continue

        for b in joueur1.balle_mort:
            verif = b.mortMissile()

            if joueur2.vivant and verif:
                if collision(joueur2.x, joueur2.y, b.x, b.y, b.explosion):
                    detruireVaisseau(pieces_joueur2, joueur2)

                    if joueur2.vie != 0:
                        joueur2.vie -= 1
                    else:
                        etatActuel = "Game Over"

                    joueur1.balle_mort.remove(b)

            # detruire balle morte
            if b.vie_mort <= 0:
                try:
                    joueur1.balle_mort.remove(b)
                except ValueError:
                    continue

        for b in joueur2.balle_mort:
            verif = b.mortMissile()

            if joueur1.vivant and verif:
                if collision(joueur1.x, joueur1.y, b.x, b.y, b.explosion):
                    detruireVaisseau(pieces_joueur1, joueur1)

                    if joueur1.vie != 0:
                        joueur1.vie -= 1
                    else:
                        etatActuel = "Game Over"

                    joueur2.balle_mort.remove(b)

            # detruire balle morte
            if b.vie_mort <= 0:
                try:
                    joueur2.balle_mort.remove(b)
                except ValueError:
                    continue


        # ajouter des asteroids
        if len(asteroid) < 15:
            if attente < 150:
                attente += 1
            else:
                x = largeur / 2
                y = hauteur / 2
                while x - largeur / 2 < largeur / 4 and y - hauteur / 2 < hauteur / 4:
                    x = random.randrange(0, largeur)
                    y = random.randrange(0, hauteur)
                asteroid.append(Asteroid(x, y, "Large", ecran))
                attente = 0


        # afficher joueur
        if etatActuel != "Game Over":
            joueur1.affichage()
            joueur2.affichage()
        else:
            if joueur1.vie == 0:
                afficher("Joueur 2 GAGNE", blanc, largeur / 2, hauteur / 2, 100)
                afficher("Appuyer sur \"R\" pour recommencer!", blanc, largeur / 2, hauteur / 2 + 100, 50)
                joueur1.vie = -1
            else:
                afficher("Joueur 1 GAGNE", blanc, largeur / 2, hauteur / 2, 100)
                afficher("Appuyer sur \"R\" pour recommencer!", blanc, largeur / 2, hauteur / 2 + 100, 50)
                joueur2.vie = -1



        # affiche les vies
        for l in range(joueur1.vie + 1):
            Vaisseau(75 + l * 25, 75, bleu, ecran).afficherJoueur()

        for l in range(joueur2.vie + 1):
            Vaisseau(largeur - 75 - l * 25, 75, orange, ecran).afficherJoueur()


        pygame.display.update()

        clock.tick(30)

run("Menu")

pygame.quit()