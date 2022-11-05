/**
 * \file adherents.h
 * \author Anthony RICHARD Léana BESSON
 * \date 20/10/2022
 */

/**
 * \brief Cette fonction permet de rechercher la position et la présence d'un adhérent dans les tableaux. A partir du tableau des identifiants, la fonction transmet si elle a trouvée ou non l'adhérent et renvoie sa position dans le tableau (s'il est trouvé) ou la position où il devrait être insérer (s'il n'y est pas). Cela permet de garder un tableau trié par ordre croissant.
 * \param tIdCartes[] Tableau d'entiers contenant les identifiants des adhérents.
 * \param nbAdherents Un entier représentant le nombre d'adhérents (la taille logique des tableaux).
 * \param val Un entier représentant la valeur que l'identifiant que l'on cherche.
 * \param *trouve Pointe vers un entier égal à 1 si l'identifiant est trouvé ou 0 dans le cas contraire.
 * \return int Un entier représentant la position de l'adhérent dans le tableau (s'il est trouvé) ou la position à laquelle il devrait être insérer pour garder un tableau trié.
 */ 
int rechercherAdherent(int tIdCartes[], int nbAdherents, int val, int *trouve);

/**
 * \brief Cette fonction permet d'ajouter un adhérent dans les tableaux. Elle débute par la saisie au clavier de l'identifiant de l'adhérent à ajouter. Ensuite, si l'adhérent n'est pas encore enregistré, on demande également l'age et le nombre de points de l'adhérent. A chaque saisie au clavier, l'utilisateur a la possibilité d'annuler l'opération en tapant -1. La fonction permet d'ajouter autant d'adhérent que possible, tant que l'utilisateur n'a pas annuler l'opération.
 * \param tIdCartes[] Tableau d'entiers contenant les identifiants des adhérents.
 * \param tAges[] Tableau d'entiers contenant les ages des adhérents.
 * \param tNbPoints[] Tableau d'entiers contenant les points des adhérents.
 * \param tCartesActives[] Tableau de caractères contenant des 'N' pour les adhérents dont les cartes sont désactivées et 'O' pour ceux qui ont une carte active.
 * \param tPointsDep[] Tableau d'entiers contenant le nombre de points dépensés depuis le l'obtention du dernier bonus.
 * \param tFrequentation[] Tableau de caractères contenant des 'O' pour les adhérents qui sont déjà venus au centre aujourd'hui et 'N' dans le cas contraire.
 * \param nbMaxAdherents Un entier représentant le nombre maximun d'adhérents (la taille physique des tableaux).
 * \param *nbAdherents Pointe vers un entier représentant le nombre d'adhérents (la taille logique des tableaux).
 */ 
void ajouterAdherent(int tIdCartes[], int tAges[], int tNbPoints[], char tCartesActives[], int tPointsDep[], char tFrequentations[], int *nbAdherents, int nbMaxAdherents);

/**
 * \brief XXXXXXXXXXX
 */ 
void alimenterCarte(int tIdCartes[], int tNbPoints[], int nbAdherents);

/**
 * \brief Cette fonction permet de changer l'état d'une carte, l'activer ou la désactiver si elle ne l'est pas.
 * \param tIdCartes[] Tableau d'entiers contenant les identifiants des adhérents.
 * \param tCartesActives[] Tableau de caractères contenant des 'N' pour les adhérents dont les cartes sont désactivées et 'O' pour ceux qui ont une carte active.
 * \param nbAdherents Un entier représentant le nombre d'adhérents (la taille logique des tableaux).
 */ 
void changerEtatCarte(int tIdCartes[], char tCartesActives[], int nbAdherents);

/**
 * \brief XXXXXXXXXXX
 */ 
void supprimerAdherent(int tIdCartes[], int tAges[], int tNbPoints[], char tCartesActives[], int tPointsDep[], char tFrequentations[], int *nbAdherents);

/**
 * \brief XXXXXXXXXXX
 */ 
void afficheAdherent(int tIdCartes[], int tAges[], int tNbPoints[], char tCartesActives[], int tPointsDep[], char tFrequentations[], int nbAdherents);

/**
 * \brief XXXXXXXXXXX
 */ 
void afficheTAdherent (int tIdCartes[], int tAges[], int tNbPoints[], char tCartesActives[], int tPointsDep[], char tFrequentations[], int nbAdherents);
