/**
 * \file adherents.h
 * \author Anthony RICHARD Léana BESSON
 * \date 20/10/2022
 * \brief Dans ce fichier sont répertoriées toutes les fonctions qui gère les adhérents de l'application.
 */

/**
 * \brief Cette fonction permet de rechercher la position et la présence d'un adhérent dans les tableaux. A partir du tableau des identifiants, la fonction transmet si elle a trouvée ou non l'adhérent et renvoie sa position dans le tableau (s'il est trouvé) ou la position où il devrait être inséré (s'il n'y est pas). Cela permet de garder un tableau trié par ordre croissant.
 * \param tIdCartes[] Tableau d'entiers contenant les identifiants des adhérents.
 * \param nbAdherent Entier représentant le nombre d'adhérents (la taille logique des tableaux).
 * \param val Entier représentant la valeur que l'identifiant que l'on cherche.
 * \param *trouve Pointe vers un entier égal à 1 si l'identifiant est trouvé ou 0 dans le cas contraire.
 * \return Entier représentant la position de l'adhérent dans le tableau (s'il est trouvé) ou la position à laquelle il devrait être inséré pour garder un tableau trié.
 */
int rechercherAdherent(int tIdCartes[], int nbAdherent, int val, int *trouve);

/**
 * \brief Cette fonction permet d'ajouter un adhérent dans les tableaux. Elle débute par la saisie au clavier de l'identifiant de l'adhérent à ajouter. Ensuite, si l'adhérent n'est pas encore enregistré, on demande également l'âge et le nombre de points de l'adhérent. A chaque saisie au clavier, l'utilisateur a la possibilité d'annuler l'opération en tapant -1. La fonction permet d'ajouter autant d'adhérents que possible, tant que l'utilisateur n'a pas annuler l'opération.
 * \param tIdCartes[] Tableau d'entiers contenant les identifiants des adhérents.
 * \param tAges[] Tableau d'entiers contenant les âges des adhérents.
 * \param tNbPoints[] Tableau d'entiers contenant les points des adhérents.
 * \param tCartesActives[] Tableau de caractères contenant des 'N' pour les adhérents dont les cartes sont désactivées et 'O' pour ceux qui ont une carte active.
 * \param tPointsDep[] Tableau d'entiers contenant le nombre de points dépensés depuis l'obtention du dernier bonus.
 * \param tFrequentation[] Tableau de caractères contenant des 'O' pour les adhérents qui sont déjà venus au centre aujourd'hui et 'N' dans le cas contraire.
 * \param *nbAdherent Pointe vers Entier représentant le nombre d'adhérents (la taille logique des tableaux).
 * \param nbMaxAdherents Entier représentant le nombre maximun d'adhérents (la taille physique des tableaux).
 */
void ajouterAdherent(int tIdCartes[], int tAges[], int tNbPoints[], char tCartesActives[], int tPointsDep[], char tFrequentations[], int *nbAdherent, int nbMaxAdherents);

/**
 * \brief Cette fonction permet d'ajouter des points à la cartes. Elle débute par la saisie au clavier de l'identifiant de l'adhérent qui souhaite ajouter des points. Puis, elle continue avec la saisie au clavier du nombre de points à ajouter. L'utilisateur a la possibilité d'annuler l'opération en tapant -1. La fonction permet d'alimenter autant de cartes que possible, tant que l'utilisateur n'a pas annuler l'opération.
 * \param tIdCartes[] Tableau d'entiers contenant les identifiants des adhérents.
 * \param tNbPoints[] Tableau d'entiers contenant les points des adhérents.
 * \param nbAdherent Entier représentant le nombre d'adhérents (la taille logique des tableaux).
 */
void alimenterCarte(int tIdCartes[], int tNbPoints[], int nbAdherent);

/**
 * \brief Cette fonction permet de changer l'état d'une carte, l'activer ou la désactiver si elle ne l'est pas.
 * \param tIdCartes[] Tableau d'entiers contenant les identifiants des adhérents.
 * \param tCartesActives[] Tableau de caractères contenant des 'N' pour les adhérents dont les cartes sont désactivées et 'O' pour ceux qui ont une carte active.
 * \param nbAdherent Entier représentant le nombre d'adhérents (la taille logique des tableaux).
 */
void changerEtatCarte(int tIdCartes[], char tCartesActives[], int nbAdherent);

/**
 * \brief Cette fonction permet de supprimer toutes les informations concernant un adhérent. Elle débute par la saisie au clavier de l'identifiant de l'adhérent à supprimer. Ensuite, elle demande de confirmer le choix de la suppression de l'adherent. A chaque saisie au clavier, l'utilisateur a la possibilité d'annuler l'opération en tapant -1. La fonction permet de supprimer autant d'adhérents que possible, tant que l'utilisateur n'a pas annuler l'opération.
 * \param tIdCartes[] Tableau d'entiers contenant les identifiants des adhérents.
 * \param tAges[] Tableau d'entiers contenant les âges des adhérents.
 * \param tNbPoints[] Tableau d'entiers contenant les points des adhérents.
 * \param tCartesActives[] Tableau de caractères contenant des 'N' pour les adhérents dont les cartes sont désactivées et 'O' pour ceux qui ont une carte active.
 * \param tPointsDep[] Tableau d'entiers contenant le nombre de points dépensés depuis l'obtention du dernier bonus.
 * \param tFrequentation[] Tableau de caractères contenant des 'O' pour les adhérents qui sont déjà venus au centre aujourd'hui et 'N' dans le cas contraire.
 * \param *nbAdherent Pointe vers Entier représentant le nombre d'adhérents (la taille logique des tableaux).
 */
void supprimerAdherent(int tIdCartes[], int tAges[], int tNbPoints[], char tCartesActives[], int tPointsDep[], char tFrequentations[], int *nbAdherent);

/**
 * \brief Cette fonction permet de changer l'âge d'un adhérent. Elle débute par le saisie au clavier de l'identifiant de la personne. Ensuite, par la saisie au clavier de l'âge souhaité. Enfin, elle modifie la valeur correspondante dans le tableau des âges.
 * \param tIdCartes[] Tableau d'entiers contenant les identifiants des adhérents.
 * \param tAges[] Tableau d'entiers contenant les âges des adhérents.
 * \param nbAdherent Entier représentant le nombre d'adhérents (la taille logique des tableaux).
*/
void changerAgeAdherent(int tIdCartes[], int tAges[], int nbAdherents);
/**
 * \brief Cette fonction permet d'afficher les informations concernants un adhérent spécifique. Elle débute par la saisie au clavier de l'identifiant de l'adhérent dont on souhaite afficher les informations. 
 * \param tIdCartes[] Tableau d'entiers contenant les identifiants des adhérents.
 * \param tAges[] Tableau d'entiers contenant les âges des adhérents.
 * \param tNbPoints[] Tableau d'entiers contenant les points des adhérents.
 * \param tCartesActives[] Tableau de caractères contenant des 'N' pour les adhérents dont les cartes sont désactivées et 'O' pour ceux qui ont une carte active.
 * \param tPointsDep[] Tableau d'entiers contenant le nombre de points dépensés depuis l'obtention du dernier bonus.
 * \param tFrequentation[] Tableau de caractères contenant des 'O' pour les adhérents qui sont déjà venus au centre aujourd'hui et 'N' dans le cas contraire.
 * \param nbAdherent Entier représentant le nombre d'adhérents (la taille logique des tableaux).
 */
void afficheAdherent(int tIdCartes[], int tAges[], int tNbPoints[], char tCartesActives[], int tPointsDep[], char tFrequentations[], int nbAdherent);

/**
 * \brief Cette fonction permet d'afficher les informations de tous les adhérents.
 * \param tIdCartes[] Tableau d'entiers contenant les identifiants des adhérents.
 * \param tAges[] Tableau d'entiers contenant les âges des adhérents.
 * \param tNbPoints[] Tableau d'entiers contenant les points des adhérents.
 * \param tCartesActives[] Tableau de caractères contenant des 'N' pour les adhérents dont les cartes sont désactivées et 'O' pour ceux qui ont une carte active.
 * \param tPointsDep[] Tableau d'entiers contenant le nombre de points dépensés depuis l'obtention du dernier bonus.
 * \param tFrequentation[] Tableau de caractères c
 * \param nbAdherent Entier représentant le nombre d'adhérents (la taille logique des tableaux).
 */
void afficheTAdherent (int tIdCartes[], int tAges[], int tNbPoints[], char tCartesActives[], int tPointsDep[], char tFrequentations[], int nbAdherent);

/**
 * \brief Cette fonction contient les jeux de tests de toutes les fonctions de gestion des adhérents.
*/
void jeuxEssais(void);
