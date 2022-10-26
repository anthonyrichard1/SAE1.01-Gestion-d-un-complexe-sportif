#include <stdio.h>
#include <stdlib.h>
#include"menus.h"
#include"adherents.h"

void menuPrincipal(void)
{
	int choix, nbMaxAdherent = 10000, nbAdherent;
	//Informations des adhérents
	int tAges[nbMaxAdherent], tIdCartes[nbMaxAdherent], tNbPoints[nbMaxAdherent];
	int tFrequentations[nbMaxAdherent];
	
	nbAdherent = chargerFichier(tIdCartes, tAges, tNbPoints, tFrequentations);
	
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
				menuAdherents(tIdCartes, tAges, tNbPoints, &nbMaxAdherent, &nbAdherent);
				break;
				
			case 2 :
				menuActivites(tIdCartes, tAges, tNbPoints, &nbMaxAdherent, &nbAdherent);
				break;
			
			case 9 :
				sauvegarderFichier(tIdCartes, tAges, tNbPoints, nbAdherent);
				exit(0);
			
			default :
				printf("\nChoix incorrect, recommencez\n");
				break;
		}		
	}	
}

void menuAdherents(int tIdCartes[], int tAges[], int tNbPoints[], int *nbMaxAdherents, int *nbAdherents)
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
				ajouterAdherent(tIdCartes, tAges, tNbPoints, nbAdherents, nbMaxAdherents);
				break;

			case 9 :
				return;
			
			default :
				printf("\nChoix incorrect, recommencez\n");
				break;
		}		
	}	
}

void menuActivites(int tIdCartes[], int tAges[], int tNbPoints[], int *nbMaxAdherents, int *nbAdherents)
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

int chargerFichier(int tIdCartes[], int tAges[], int tNbPoints[], int tFrequentations[])
{
	FILE *f;
	int choix = -1, idCarte, age, nbPoints, nbAdherents = 0;
	
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
	
	fscanf(f, "%d\t%d\t%d", &idCarte, &age, &nbPoints);
	
	while (!feof(f))
	{
		tIdCartes[nbAdherents] = idCarte;
		tAges[nbAdherents] = age;
		tNbPoints[nbAdherents] = nbPoints;
		tFrequentations[nbAdherents] = 0;
		nbAdherents++;
		fscanf(f, "%d\t%d\t%d", &idCarte, &age, &nbPoints);
	}
	
	fclose(f);
	return nbAdherents;
}

void sauvegarderFichier(int tIdCartes[], int tAges[], int tNbPoints[], int nbAdherents)
{
	FILE *f;
	int i = 0;
	
	f = fopen("listeAdherents.don", "w");
	
	while (i < nbAdherents)
	{
		fprintf(f, "%05d\t%d\t%d\n", tIdCartes[i], tAges[i], tNbPoints[i]);
		i++;
	}
	
	fclose(f);
}
