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
void menuAdherents(int tIdCartes[], int tAges[], int tNbPoints[], int *nbMaxAdherent, int *nbAdherent);

/**
 * \brief XXXXXXXXXXX
 */
void menuActivites(int tIdCartes[], int tAges[], int tNbPoints[], int *nbMaxAdherent, int *nbAdherent);

/**
 * \brief XXXXXXXXXXX
 */
int chargerFichier(int tIdCartes[], int tAges[], int tNbPoints[], int tFrequentation[]);

/**
 * \brief XXXXXXXXXXX
 */
void sauvegarderFichier(int tIdCartes[], int tAges[], int tNbPoints[], int nbAdherent);
