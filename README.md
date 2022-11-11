[![Build Status](https://codefirst.iut.uca.fr/api/badges/leana.besson/SAE1.01/status.svg)](https://codefirst.iut.uca.fr/leana.besson/SAE1.01)  

# SAE 1.01 : Implémentation d'un besoin client - Léana BESSON Anthony RICHARD

## Installation et Désinstallation :

* Pour installer : ouvrez un terminal dans ce dossier et tapez `make`. Les fichiers executables dans le dossier `src` et la documentation va se générer dans le dossier `doc`.

* Pour désinstaller : ouvrez un terminal dans ce dossier et tapez `make clean`.

### Utilisation :

Pour lancer l'application, ouvrez un terminal dans le dossier `src` et executez le fichier `complexe.exe` avec la commande suivante :  `./complexe.exe`

### Documentation :

Une fois générée, la documentation sera accessible dans le dossier `doc`, en lançant le fichier `index.hmtl`.

### Jeux d'essais :

Les jeux d'essais sont dans le dossier `src`.

* Codes : `testMenus.c`, `testAdherents.c` et `testActivites.c`.
* Executables : `menus.o`, `adherents.o` et `activites.o`.
* Inputs : `inpTestMenus`, `inpTestAdherents`, `inpTestActivites` ; ces inputs permettent de tester les fonctions, il faut donc les passer sur l'entrée standard pour executer convenablement les executables, ce qui donne les commandes suivantes.

#### Commandes :

* Pour les fonctions de gestion des menus (+chargement et sauvegarde du fichier) : `./menus.o < inpTestMenus`
* Pour les fonction de gestion des adhérents : `./adherents.o < inpTestAdherents`
* Pour les fonctions de gestion des activités : `./activites.o < inpTestActivites`
