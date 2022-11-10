#include <stdio.h>
#include <stdlib.h>
#include"menus.h"
#include"adherents.h"
#include"activites.h"

void menuPrincipal(void)
{
	int choix, nbMaxAdherent = 10000, nbAdherent;
	int nbActivite=14;

	//Informations des adhérents
	int tAges[nbMaxAdherent], tIdCartes[nbMaxAdherent], tNbPoints[nbMaxAdherent], tPointsDep[nbMaxAdherent];
	char tCartesActives[nbMaxAdherent], tFrequentations[nbMaxAdherent];

	//Informations des activités
	int tActivite[14]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14}, tCoutPoints[14]={10, 15, 20, 10, 10, 10, 10, 20, 10, 15, 10, 10, 10, 15}, tNbEntree[14];

	nbAdherent = chargerFichier(tIdCartes, tAges, tNbPoints, tCartesActives, tFrequentations, tPointsDep);

	while (1)
	{
		printf("\n----------------------------------------\n");

		printf(
		"\nMenu principal\n\n"
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
				menuActivites(tIdCartes, tNbPoints, tCartesActives, tFrequentations, tPointsDep, tActivite, tCoutPoints, tNbEntree, nbActivite, &nbAdherent);
				break;

			case 9 :
				sauvegarderFichier(tIdCartes, tAges, tNbPoints, tCartesActives, tPointsDep, nbAdherent);
				exit(0);

			default :
				printf("\n\e[1;91mChoix incorrect, recommencez\e[0m\n");
				break;
		}
	}
}

void menuAdherents(int tIdCartes[], int tAges[], int tNbPoints[], char tCartesActives[], char tFrequentations[], int tPointsDep[], int nbMaxAdherents, int *nbAdherent)
{
	int choix;

	while (1)
	{
		printf("\n----------------------------------------\n");

		printf(
		"\nMenu des adhérents\n\n"
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
				ajouterAdherent(tIdCartes, tAges, tNbPoints, tCartesActives, tPointsDep, tFrequentations, nbAdherent, nbMaxAdherents);
				break;

			case 2 :
				alimenterCarte(tIdCartes, tNbPoints, *nbAdherent);
				break;

			case 3 :
				changerEtatCarte(tIdCartes, tCartesActives, *nbAdherent);
				break;

			case 4 :
				supprimerAdherent(tIdCartes, tAges, tNbPoints, tCartesActives, tPointsDep, tFrequentations, nbAdherent);
				break;

			case 5 :
				afficheAdherent(tIdCartes, tAges, tNbPoints, tCartesActives, tPointsDep, tFrequentations, *nbAdherent);
				break;

			case 6 :
				afficheTAdherent(tIdCartes, tAges, tNbPoints, tCartesActives, tPointsDep, tFrequentations, *nbAdherent);
				break;

			case 9 :
				return;

			default :
				printf("\n\e[1;91mChoix incorrect, recommencez\e[0m\n");
				break;
		}
	}
}

void menuActivites(int tIdCartes[], int tNbPoints[], char tCartesActives[], char tFrequentations[], int tPointsDep[], int tActivite[], int tCoutPoints[], int tNbEntree[], int nbActivite, int *nbAdherent)
{
	int choix;

	while (1)
	{
		printf("\n----------------------------------------\n");

		printf(
		"\nMenu des activités\n\n"
		"1 - Voir la liste des activités disponibles\n"
		"2 - Réserver une activité\n"
		"3 - Afficher le nombre d'entrées par activités\n"
		"9 - Menu principal\n"
		"Votre choix : ");

		scanf("%d", &choix);

		switch (choix)
		{
			case 1 :
				listeActivites();
				break;

			case 2 :
				reservationActivite(tIdCartes, tNbPoints, tCartesActives, tFrequentations, tPointsDep, nbAdherent, tActivite, tCoutPoints, tNbEntree, nbActivite);
				break;

			case 3 :
				entreeActivite(tActivite, tNbEntree, nbActivite);
				break;

			case 9 :
				return;

			default :
				printf("\n\e[1;91mChoix incorrect, recommencez\e[0m\n");
				break;
			}
	}
}

int chargerFichier(int tIdCartes[], int tAges[], int tNbPoints[], char tCartesActives[], char tFrequentations[], int tPointsDep[])
{
	FILE *f;
	int choix = -1, idCarte, age, nbPoints, pointsDep, nbAdherent = 0;
	char active;

	while ((f=fopen("listeAdherents.don", "r")) == NULL)
	{
		fprintf(stderr, "\e[1;91mErreur : le fichier est introuvable, veuillez insérer le fichier listeAdherents dans le dossier src puis tapez 1 pour réessayer ou 9 pour quitter le programme\e[0m\n");
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
		tIdCartes[nbAdherent] = idCarte;
		tAges[nbAdherent] = age;
		tNbPoints[nbAdherent] = nbPoints + pointsBonus(age, &pointsDep);
		tCartesActives[nbAdherent] = active;
		tFrequentations[nbAdherent] = 'N';
		tPointsDep[nbAdherent] = pointsDep;
		nbAdherent++;
		fscanf(f, "%d\t%d\t%d\t%c\t%d", &idCarte, &age, &nbPoints, &active, &pointsDep);
	}

	fclose(f);
	return nbAdherent;
}

void sauvegarderFichier(int tIdCartes[], int tAges[], int tNbPoints[], char tCartesActives[], int tPointsDep[], int nbAdherent)
{
	FILE *f;
	int i = 0;

	f = fopen("listeAdherents.don", "w");

	while (i < nbAdherent)
	{
		fprintf(f, "%04d\t%d\t%d\t%c\t%d\n", tIdCartes[i], tAges[i], tNbPoints[i], tCartesActives[i], tPointsDep[i]);
		i++;
	}

	fclose(f);
}

int pointsBonus(int age, int *pointsDep)
{
	int pb = 0;

	if (*pointsDep >= 50)
	{
		pb += 10;

		if (age < 18 || age >= 60)
		{
			pb += 5;
		}
	}

	pb *= *pointsDep/50;

	*pointsDep = *pointsDep%50;

	return pb;
}
