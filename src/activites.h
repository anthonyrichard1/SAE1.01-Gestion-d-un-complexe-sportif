/**
 * \file activites.h
 * \author Anthony RICHARD Léana BESSON
 * \date 07/11/2022
 * \brief Dans ce fichier sont répertoriées toutes les fonctions qui gèrent les activités du complexe.
 */

/**
 * \brief Cette fonction permet de rechercher la position et la présence d'une activité dans les tableaux. À partir du tableau des activités, la fonction transmet si elle a trouvé ou non l'activité et renvoie sa position dans le tableau (s'elle est trouvé).
 * \param tActivite Tableau d'entiers contenant les numéros des activités.
 * \param nbActivite Entier représentant le nombre d'activité (la taille logique des tableaux).
 * \param val Entier représentant la valeur que l'identifiant que l'on cherche.
 * \param *trouve Pointe vers un entier égal à 1 si l'identifiant est trouvé ou 0 dans le cas contraire.
 * \return Entier représentant la position de l'activité dans le tableau.
 */
int rechercherActivite(int tActivite[], int nbActivite, int val, int *trouve);

/**
 * \brief Cette fonction permet d'afficher la liste des activités disponibles dans le complexe.
 */
void listeActivites(void);

/**
 * \brief Cette fonction permet à un adhérent de réserver des activités. Elle débute par la saisie au clavier de l'identifiant de l'adhérent à ajouter. Ensuite, elle demande le numéro de l'activité à réserver autant de choix que possible (donc 3 fois). À chaque saisie au clavier, l'utilisateur a la possibilité d'annuler l'opération en tapant -1.
 * \param tIdCartes[] Tableau d'entiers contenant les identifiants des adhérents.
 * \param tNbPoints[] Tableau d'entiers contenant les points des adhérents.
 * \param tCartesActives[] Tableau de caractères contenant des 'N' pour les adhérents dont les cartes sont désactivées et 'O' pour ceux qui ont une carte active.
 * \param tFrequentation[] Tableau de caractères contenant des 'O' pour les adhérents qui sont déjà venus au centre aujourd'hui et 'N' dans le cas contraire.
 * \param tPointsDep[] Tableau d'entiers contenant le nombre de points dépensés depuis l'obtention du dernier bonus.
 * \param nbAdherent Entier représentant le nombre d'adhérents (la taille logique des tableaux).
 * \param tActivite[] Tableau d'entiers contenant le numéro de l'activité.
 * \param tCoutPoints[] Tableau d'entiers contenant le nombre de points que coûte une activité.
 * \param tNbEntree[] Tableau d'entiers contenant le nombre d'entrées dans la journée d'une activité.
 * \param nbActivite Entier représentant le nombre d'activité (la taille logique des tableaux).
 */
void reservationActivite(int tIdCartes[], int tNbPoints[], char tCartesActives[], char tFrequentations[], int tPointsDep[], int nbAdherent, int tActivite[], int tCoutPoints[], int tNbEntree[], int nbActivite);

/**
 * \brief Cette fonction permet d'afficher le nombre d'entrées pour chaque activité.
 * \param tActivite[] Tableau d'entiers contenant le numéro de l'activité.
 * \param tNbEntree[] Tableau d'entiers contenant le nombre d'entrées dans la journée d'une activité.
 * \param nbActivite Entier représentant le nombre d'activité (la taille logique des tableaux).
 */
void entreeActivite(int tActivite[], int tNbEntree[], int nbActivite);
