/**
 * \file menus.h
 * \author Anthony RICHARD Léana BESSON
 * \date 20/10/2022
 */
 
/**
 * \brief XXXXXXXXXXX
 */
void menuPrincipal(void);

/**
 * \brief XXXXXXXXXXX
 */
void menuAdherents(int tIdCartes[], int tAges[], int tNbPoints[], int tCartesActives[], int *nbMaxAdherents, int *nbAdherents);

/**
 * \brief XXXXXXXXXXX
 */
void menuActivites(int tIdCartes[], int tAges[], int tNbPoints[], int tCartesActives[], int *nbMaxAdherents, int *nbAdherents);

/**
 * \brief XXXXXXXXXXX
 */
int chargerFichier(int tIdCartes[], int tAges[], int tNbPoints[], int tCartesActives[], int tFrequentations[]);

/**
 * \brief XXXXXXXXXXX
 */
void sauvegarderFichier(int tIdCartes[], int tAges[], int tNbPoints[], int tCartesActives[], int nbAdherents);
