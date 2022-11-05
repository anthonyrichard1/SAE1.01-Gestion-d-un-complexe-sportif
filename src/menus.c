#include <stdio.h>
#include <stdlib.h>
#include"menus.h"
#include"adherents.h"

void menuPrincipal(void)
{
	int choix, nbMaxAdherent = 10000, nbAdherent;

	//Informations des adhérents
	int tAges[nbMaxAdherent], tIdCartes[nbMaxAdherent], tNbPoints[nbMaxAdherent], tPointsDep[nbMaxAdherent];
	char tCartesActives[nbMaxAdherent], tFrequentations[nbMaxAdherent];
	
	nbAdherent = chargerFichier(tIdCartes, tAges, tNbPoints, tCartesActives, tFrequentations, tPointsDep);
	
	while (1)
	{
		printf(
		"\nMenu principal\n"
		"1 - Menu des adhérents\n"
		"2 - Menu des activités\n"
		"9 - Quitter\n"
		"Votre choix : ");
		
		scanf("%d", &choix);
		
		switch (choix)
		{
			case 1 :
				menuAdherents(tIdCartes, tAges, tNbPoints, tCartesActives, tFrequentations, tPointsDep, nbMaxAdherent, &nbAdherent);
				break;
				
			case 2 :
				menuActivites(tIdCartes, tAges, tNbPoints, tCartesActives, tFrequentations, tPointsDep, nbMaxAdherent, nbAdherent);
				break;
			
			case 9 :
				sauvegarderFichier(tIdCartes, tAges, tNbPoints, tCartesActives, tPointsDep, nbAdherent);
				exit(0);
			
			default :
				printf("\nChoix incorrect, recommencez\n");
				break;
		}		
	}	
}

void menuAdherents(int tIdCartes[], int tAges[], int tNbPoints[], char tCartesActives[], char tFrequentations[], int tPointsDep[], int nbMaxAdherents, int *nbAdherents)
{
	int choix;
	
	while (1)
	{
		printf(
		"\nMenu des adhérents\n"
		"1 - Ajouter un adhérent\n"
		"2 - Alimenter une carte\n"
		"3 - Activer/Désactiver une carte\n"
		"4 - Supprimer un adhérent\n"
		"5 - Afficher les informations d'un adhérent\n"
		"6 - Afficher les informations de tous les adhérents\n"
		"9 - Menu principal\n"
		"Votre choix : ");
		
		scanf("%d", &choix);
		
		switch (choix)
		{		
			case 1 :
				ajouterAdherent(tIdCartes, tAges, tNbPoints, tCartesActives, tPointsDep, tFrequentations, nbAdherents, nbMaxAdherents);
				break;

			case 2 :
				alimenterCarte(tIdCartes, tNbPoints, *nbAdherents);
				break;

			case 3 :
				changerEtatCarte(tIdCartes, tCartesActives, *nbAdherents);
				break;
				
			case 4 :
				supprimerAdherent(tIdCartes, tAges, tNbPoints, tCartesActives, tPointsDep, tFrequentations, nbAdherents);
				break;
				
			case 5 :
				afficheAdherent(tIdCartes, tAges, tNbPoints, tCartesActives, tPointsDep, tFrequentations, *nbAdherents);
				break;
				
			case 6 : 
				afficheTAdherent(tIdCartes, tAges, tNbPoints, tCartesActives, tPointsDep, tFrequentations, *nbAdherents);
				break;
				
			case 9 :
				return;
			
			default :
				printf("\nChoix incorrect, recommencez\n");
				break;
		}		
	}	
}

void menuActivites(int tIdCartes[], int tAges[], int tNbPoints[], char tCartesActives[], char tFrequentations[], int tPointsDep[], int nbMaxAdherents, int nbAdherents)
{
	int choix;
	
	while (1)
	{
		printf(
		"\nMenu des activités\n"
		"1 - Voir la liste des activités disponibles\n"
		"2 - Réserver une activité\n"
		"5 - Afficher le nombre d'entrées par activités\n"
		"9 - Menu principal\n"
		"Votre choix : ");
		
		scanf("%d", &choix);
		
		switch (choix)
		{			
			case 9 :
				return;
			
			default :
				printf("\nChoix incorrect, recommencez\n");
		}		break;
	}		
}

int chargerFichier(int tIdCartes[], int tAges[], int tNbPoints[], char tCartesActives[], char tFrequentations[], int tPointsDep[])
{
	FILE *f;
	int choix = -1, idCarte, age, nbPoints, pointsDep, nbAdherents = 0;
	char active;
	
	while ((f=fopen("listeAdherents.don", "r")) == NULL)
	{
		fprintf(stderr, "Erreur : le fichier est introuvable, veuillez insérer le fichier listeAdherents dans le dossier src puis tapez 1 pour réessayer ou 9 pour quitter le programme\n");
		scanf("%d", &choix);
		
		switch (choix)
		{
			default : break;
			case 9 : exit(1);
		}
	}
	
	fscanf(f, "%d\t%d\t%d\t%c\t%d", &idCarte, &age, &nbPoints, &active, &pointsDep);
	
	while (!feof(f))
	{
		tIdCartes[nbAdherents] = idCarte;
		tAges[nbAdherents] = age;
		tNbPoints[nbAdherents] = nbPoints;
		tCartesActives[nbAdherents] = active;
		tFrequentations[nbAdherents] = 'N';
		tPointsDep[nbAdherents] = pointsDep;
		nbAdherents++;
		fscanf(f, "%d\t%d\t%d\t%c\t%d", &idCarte, &age, &nbPoints, &active, &pointsDep);
	}
	
	fclose(f);
	return nbAdherents;
}

void sauvegarderFichier(int tIdCartes[], int tAges[], int tNbPoints[], char tCartesActives[], int tPointsDep[], int nbAdherents)
{
	FILE *f;
	int i = 0;
	
	f = fopen("listeAdherents.don", "w");
	
	while (i < nbAdherents)
	{
		fprintf(f, "%04d\t%d\t%d\t%c\t%d\n", tIdCartes[i], tAges[i], tNbPoints[i], tCartesActives[i], tPointsDep[i]);
		i++;
	}
	
	fclose(f);
}