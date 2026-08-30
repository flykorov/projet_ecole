# Classe 33 
## Groupe

Victor Bouvier d'Acher
Matthis Mejean--Noyal
Damien Jouvanceau
Arezki Meriane

## Description

-
Ceci est la V4 du jeu Memory Game.
-
-
C'est la version V3 adapter a vue.js.
Il y a deux version de celle-ci:
	La premiere est la version sans aucune modification de la V3, seulement une reorganisation des fichiers.
	Les fichiers de la V3 adaptee a vue.js sont GameConfig.vue et GamePlayLegacy.vue, avec le code js dans le fichier index.html.
	La deuxieme est la version plus adaptee a vue.js avec l'utilisation de boucle v-for et sans utiliser le code dans index.html. ces fichier s'appellent GamePlay.vue et GameCard.vue.
Un bouton permet de changer de version a tout moment.
Pour pouvoir lancer la page web, entrer dans le dossier v4, et lancer la commande yarn serve, utiliser l'URL local et taper le nom de l'URL local sur un navigateur (http://localhost:8080).
Les images sont dans le dossier public puis image.
-

Avec le jeu est fourni cypress, l'interface de test.

Pour voir le fichier de test, allez dans le dossier cypress puis e2e et ouvrer le fichier spec.cy.js.

Pour lancer les tests, ecriver yarn cypress open dans un terminal, cliquer sur E2E Testing et utiliser le navigateur de votre choix. Une fois le navigateur ouvert ouvrer le fichier spec.cy.js

Il faut avoir installer yarn, npm et node pour utiliser cypress.

-
Les phases de test sont normalement toute concluante mais il peut avoir des tests manquer a cause de la rng du jeu.
Les cases sont choisi aleatoirement, il se peut qu'il y ai une petite probabilitee qu'un test echoue a cause de malchance.
-