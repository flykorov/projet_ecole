# Classe 42
## GROUPE

Victor Bouvier d'Acher  

# Projet Cryptis
## Description

-
Voici le Projet de Cryptologie
-
-
Le Jeu se décompose en plusieurs parties.  
Le menu qui se compose de 3 boutons, ARCADE, DICTIONNAIRE, QUITTER.  
Le bouton ARCADE permet de lancer une préface permettant de choisir les caractéristiques du jeu :  
	- la taille de la clef  
	- le choix de la clef privée ou publique pour le joueur et l'ordinateur  
	- le choix de jouer seul ou en versus  
	- lancer le jeu  
Une fois le jeu lancer vous pouvez utiliser les touches :  
	- ← pour roll la clef à gauche  
	- → pour roll la clef à droite  
	- ↓ pour additionner la clef au message  
	- ↑ ou space pour inverser la clef  
Le bouton DICTIONNAIRE affiche le dictionnaire utilisé pour convertir les messages.  
Le bouton QUIT quitte le jeu.
-

## Lancement du projet

-
Ajouter le projet git dans un répertoire.
Entrer dans le dossier cryptis 
- 
-
Pour que le projet soit fonctionel, veuillez installer :  

	- pygame  
	$ pip install pygame  
  
	- installer numpy  
	$ pip install numpy  
-
-
Si vous voulez tester les différents algorithmes du programme, il faut aller dans le fichier test.  
Vous avez un fichier test.py qui lance l'algorithme:
	- création des clefs
	- chiffrement
	- déchiffrement
	- création du dictionnaire
	- convertion des messages
Toutes les fonctions utilisées sont dans le fichier test_fonction.py  
Ces fichiers sont indépendants du projet donc modifiable à souhait.  
-