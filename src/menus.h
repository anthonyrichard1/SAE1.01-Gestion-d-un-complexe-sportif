/**
 * \file menus.h
 * \author Anthony RICHARD Léana BESSON
 * \date 20/10/2022
 * \brief Dans ce fichier sont répertoriées toutes les fonctions qui gère les menus de l'application.
 */

/**
 * \brief Cette fonction affiche le menu principal, un menu permettant de choisir entre les deux sous menus adhérents et activités. Elle ne possède aucun paramètre car l'option choisie est récupéré par une saisie au clavier.
 */
void menuPrincipal(void);

/**
 * \brief Cette fonction affiche le menu des adhérents, et permet de sélectionner l'opération que l'on souhaite effectuer sur les adhérents (ajout, suppression par exemple). Le choix de l'utilisateur est récupéré par une saisie au clavier.
 * \param tIdCartes[] Tableau d'entiers contenant les identifiants des adhérents.
 * \param tAges[] Tableau d'entiers contenant les âges des adhérents.
 * \param tNbPoints[] Tableau d'entiers contenant les points des adhérents.
 * \param tCartesActives[] Tableau de caractères contenant des 'N' pour les adhérents dont les cartes sont désactivées et 'O' pour ceux qui ont une carte active.
 * \param tFrequentation[] Tableau de caractères contenant des 'O' pour les adhérents qui sont déjà venus au centre aujourd'hui et 'N' dans le cas contraire.
 * \param tPointsDep[] Tableau d'entiers contenant le nombre de points dépensés depuis l'obtention du dernier bonus.
 * \param nbMaxAdherents Entier représentant le nombre maximun d'adhérents (la taille physique des tableaux).
 * \param *nbAdherent Pointe vers Entier représentant le nombre d'adhérents (la taille logique des tableaux).
 */
void menuAdherents(int tIdCartes[], int tAges[], int tNbPoints[], char tCartesActives[], char tFrequentations[], int tPointsDep[], int nbMaxAdherents, int *nbAdherent);

/**
 * \brief Cette fonction affiche le menu des activités, et permet de sélectionner l'opération que l'on souhaite effectuer sur les activités (liste des disponibilités, réservations par exemple). Le choix de l'utilisateur est récupéré par une saisie au clavier.
 * \param tIdCartes[] Tableau d'entiers contenant les identifiants des adhérents.
 * \param tNbPoints[] Tableau d'entiers contenant les points des adhérents.
 * \param tCartesActives[] Tableau de caractères contenant des 'N' pour les adhérents dont les cartes sont désactivées et 'O' pour ceux qui ont une carte active.
 * \param tFrequentation[] Tableau de caractères contenant des 'O' pour les adhérents qui sont déjà venus au centre aujourd'hui et 'N' dans le cas contraire.
 * \param tPointsDep[] Tableau d'entiers contenant le nombre de points dépensés depuis l'obtention du dernier bonus.
 * \param tActivite[] Tableau d'entiers contenant le numéro de l'activité.
 * \param tCoutPoints[] Tableau d'entiers contenant le nombre de points que coûte une activité.
 * \param tNbEntree[] Tableau d'entiers contenant le nombre d'entrée dans la journée d'une activité.
 * \param nbActivite Entier représentant le nombre d'activité (la taille logique des tableaux).
 * \param *nbAdherent Pointe vers Entier représentant le nombre d'adhérents (la taille logique des tableaux).
 */
void menuActivites(int tIdCartes[], int tNbPoints[], char tCartesActives[], char tFrequentations[], int tPointsDep[], int tActivite[], int tCoutPoints[], int tNbEntree[], int nbActivite, int *nbAdherent);

/**
 * \brief Cette fonction permet de récupérer les données contenues dans le fichier listeAdherents.don pour les stocker dans des tableaux. Elle est utilisée au lancement de l'application.
 * \param tIdCartes[] Tableau d'entiers contenant les identifiants des adhérents.
 * \param tAges[] Tableau d'entiers contenant les âges des adhérents.
 * \param tNbPoints[] Tableau d'entiers contenant les points des adhérents.
 * \param tCartesActives[] Tableau de caractères contenant des 'N' pour les adhérents dont les cartes sont désactivées et 'O' pour ceux qui ont une carte active.
 * \param tFrequentation[] Tableau de caractères contenant des 'O' pour les adhérents qui sont déjà venus au centre aujourd'hui et 'N' dans le cas contraire.
 * \param tPointsDep[] Tableau d'entiers contenant le nombre de points dépensés depuis l'obtention du dernier bonus.
 * \return Entier représentant le nombre d'adhérents dans le fichier (la taille logique des tableaux).
 */
int chargerFichier(int tIdCartes[], int tAges[], int tNbPoints[], char tCartesActives[], char tFrequentations[], int tPointsDep[]);

/**
 * \brief Cette fonction permet de récupérer les données contenues dans les tableaux pour les stocker dans le fichier listeAdherents.don. Elle est utilisée à la fermeture de l'application.
 * \param tIdCartes[] Tableau d'entiers contenant les identifiants des adhérents.
 * \param tAges[] Tableau d'entiers contenant les âges des adhérents.
 * \param tNbPoints[] Tableau d'entiers contenant les points des adhérents.
 * \param tCartesActives[] Tableau d'entiers représentant des 0 pour les adhérents dont les cartes sont désactivées et 1 pour ceux qui ont une carte active.
 * \param tPointsDep[] Tableau d'entiers contenant le nombre de points dépensés depuis l'obtention du dernier bonus.
 * \param nbAdherent Entier représentant le nombre d'adhérents (la taille logique des tableaux).
 */
void sauvegarderFichier(int tIdCartes[], int tAges[], int tNbPoints[], char tCartesActives[], int tPointsDep[], int nbAdherent);

/**
 * \brief Cette fonction calcule et renvoie le nombre de points bonus qui doivent être donnés à l'adhérent. Tous les 50 points, l'adhérent obtient 15 points bonus s'il est mineur ou retraité, 10 dans le cas contraire.
 * \param age Entier représentant l'âge de l'adhérent.
 * \param *pointsDep Pointe vers Entier représentant le nombre de points dépensés par l'adhérent.
 * \return Entier représentant le nombre de points bonus qui doivent être donnés à l'adhérent.
 */
int pointsBonus(int age, int *pointsDep);

/**
 * \brief Cette fonction contient les jeux de tests de tous les menus, et de la fonction des points bonus.
 */
void jeuxEssais(void);


