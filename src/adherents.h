/**
 * \file adherents.h
 * \author Anthony RICHARD Léana BESSON
 * \date 20/10/2022
 */

/**
 * \brief XXXXXXXXXXX
 */ 
int rechercherAdherent(int tIdCartes[], int nbAdherents, int val, int *trouve);

/**
 * \brief XXXXXXXXXXX
 */ 
void ajouterAdherent(int tIdCartes[], int tAges[], int tNbPoints[], int tCartesActives[], int *nbAdherents, int *nbMaxAdherents);

/**
 * \brief XXXXXXXXXXX
 */ 
void alimenterCarte(int tIdCartes[], int tNbPoints[], int *nbAdherents);

/**
 * \brief XXXXXXXXXXX
 */ 
void changerEtatCarte(int tIdCartes[], int tCartesActives[], int nbAdherents);

/**
 * \brief XXXXXXXXXXX
 */ 
void supprimerAdherent(int tIdCartes[], int tAges[], int tNbPoints[], int *nbAdherents);

/**
 * \brief XXXXXXXXXXX
 */ 
void afficheAdherent(int tIdCartes[], int tAges[], int tNbPoints[], int *nbAdherents);

/**
 * \brief XXXXXXXXXXX
 */ 
void afficheTAdherent (int tIdCartes[], int tAges[], int tNbPoints[], int *nbAdherents);
