#include <stdio.h>
#include"adherents.h"

int rechercherAdherent(int tIdCartes[], int nbAdherents, int val, int *trouve)
{
	int i = 0;
	
	while (i < nbAdherents)
	{
		if (val == tIdCartes[i])
		{
			*trouve = 1;
			return i;
		}
		else if (val < tIdCartes[i])
		{
			*trouve = 0;
			return i;
		}
		
		i++;
	}

	*trouve = 0;
	return i;
}

void ajouterAdherent(int tIdCartes[], int tAges[], int tNbPoints[], char tCartesActives[], int tPointsDep[], char tFrequentations[], int *nbAdherents, int nbMaxAdherents)
{
	int idCarte, age, nbPoints, pos, i;
	int trouve;

	while (1)
	{
		i = *nbAdherents-1;

		if (*nbAdherents == nbMaxAdherents)
		{
			fprintf(stderr, "Erreur : le nombre d'adhérent maximal a été atteint\n");
			printf("Fin de l'opération...\n");
			return;
		}

		printf("Entrez l'identifiant de l'adhérent à ajouter (-1 pour annuler l'opération) : ");
		scanf("%d", &idCarte);

		while (idCarte >= nbMaxAdherents || idCarte < 0)
		{
			if (idCarte == -1)
			{
				printf("Fin de l'opération...\n");
				return;
			}

			fprintf(stderr, "Erreur : %04d n'est pas un identifiant valide, recommencez\n", idCarte);
			printf("Entrez l'identifiant de l'adhérent à ajouter (-1 pour annuler l'opération) : ");
			scanf("%d", &idCarte);
		}

		pos = rechercherAdherent(tIdCartes, *nbAdherents, idCarte, &trouve);

		if (trouve)
		{
			fprintf(stderr, "Erreur : l'identifiant %04d existe déjà\n", idCarte);
		}
		else
		{
			printf("Entrez l'age de l'adhérent à ajouter (-1 pour annuler l'opération) : ");
			scanf("%d", &age);

			while (age <= 0)
			{
				if (age == -1)
				{
					printf("Fin de l'opération...\n");
					return;
				}

				fprintf(stderr, "Erreur : %d n'est pas un age valide (nombre négatif ou nul), recommencez\n", idCarte);
				printf("Entrez l'age de l'adhérent à ajouter (-1 pour annuler l'opération) : ");
				scanf("%d", &age);
			}

			printf("Entrez le nombre de points à ajouter à l'adhérent (-1 pour annuler l'opération) : ");
			scanf("%d", &nbPoints);

			while (nbPoints <= 0)
			{
				if (nbPoints == -1)
				{
					printf("Fin de l'opération...\n");
					return;
				}

				fprintf(stderr, "Erreur : il faut obligatoirement ajouter des points à un nouvel utilisateur, recommencez\n");
				printf("Entrez le nombre de points à ajouter à l'adhérent (-1 pour annuler l'opération) : ");
				scanf("%d", &nbPoints);
			}

			while (i >= pos)
			{
				tIdCartes[i+1] = tIdCartes[i];
				tAges[i+1] = tAges[i];
				tNbPoints[i+1] = tNbPoints[i];
				tCartesActives[i+1] = tCartesActives[i];
				tPointsDep[i+1] = tPointsDep[i];
				tFrequentations[i+1] = tFrequentations[i];
				i--;
			}

			tIdCartes[pos] = idCarte;
			tAges[pos] = age;
			tNbPoints[pos] = nbPoints;
			tCartesActives[pos] = 'O';
			tPointsDep[pos] = 0;
			tFrequentations[pos] = 'N';

			idCarte = -1;
			++*nbAdherents;
			printf("Adhérent ajouté !\n");
		}
	}
}

void alimenterCarte(int tIdCartes[], int tNbPoints[], int nbAdherents) {
	int points, identifiant, trouve, pos;
	
	while(1) {
		printf("Entrez votre identifiant (-1 pour annuler l'opération) : ");
		scanf("%d", &identifiant);
		pos = rechercherAdherent(tIdCartes, nbAdherents, identifiant, &trouve);
			
		if (identifiant == -1) {
			printf("Fin de l'opération...\n");
			return;
		}
			
		while (trouve ==  0) {
			fprintf(stderr, "Nous ne trouvons pas votre identifiant. ");
			printf("Entrez votre identifiant : ");
			scanf("%d", &identifiant);
			pos = rechercherAdherent(tIdCartes, nbAdherents, identifiant, &trouve);
		}
		
		printf("Vous avez %d points. 1 point vaut 0.5€.", tNbPoints[pos]);
		printf("\nNombre de points souhaité (-1 pour annuler l'opération) : ");
		scanf("%d", &points);
		
		if (points == -1) {
			printf("Fin de l'opération...\n");
			return;
		}
					
		while (points <= 0) {
			printf("Le nombre de points doit être supérieur à 0.");
			printf("\nNombre de points souhaité : ");
			scanf("%d", &points);
		}
		
		printf("Cela coûte %.2f€.", points*0.5);
		tNbPoints[pos] += points;
		printf("\nVous avez %d points.\n", tNbPoints[pos]);
	}
}

void changerEtatCarte(int tIdCartes[], char tCartesActives[], int nbAdherents)
{
	int idCarte, pos, trouve;
	char choix;

	while (1)
	{
		printf("Entrez l'identifiant de la carte (-1 pour annuler l'opération) : ");
		scanf("%d", &idCarte);

		if (idCarte == -1)
		{
			printf("Fin de l'opération...\n");
			return;
		}
		
		pos = rechercherAdherent(tIdCartes, nbAdherents, idCarte, &trouve);

		if (!trouve)
		{
			fprintf(stderr, "Erreur : l'identifiant est inconnu, recommencez\n");
		}
		else
		{
			if (tCartesActives[pos] == 'O')
			{
				while (choix != 'o' && choix != 'O' && choix != 'n' && choix != 'N')
				{
					printf("La carte %04d est actuellement activée, voulez-vous la désactiver (O/N) : ", idCarte);
					scanf("%*c%c%*c", &choix);
				}

				if (choix == 'o' || choix == 'O')
				{
					tCartesActives[pos] = 'N';
					printf("Carte désactivée !\n");
				}
				else
				{
					printf("Abandon de l'opération...\n");
				}

				choix = 'a';
			}
			else
			{

				while (choix != 'o' && choix != 'O' && choix != 'n' && choix != 'N')
				{
					printf("La carte %04d est actuellement désactivée, voulez-vous l'activer (O/N) :", idCarte);
					scanf("%*c%c%*c", &choix);
				}
				
				if (choix == 'o' || choix == 'O')
				{
					tCartesActives[pos] = 'O';
					printf("Carte activée !\n");
				}
				else
				{
					printf("Abandon de l'opération...\n");
				}

				choix = 'a';
			}
		}
	}
}

void supprimerAdherent(int tIdCartes[], int tAges[], int tNbPoints[], char tCartesActives[], int tPointsDep[], char tFrequentations[], int *nbAdherents) {
	int identifiant, pos, i, trouve;
	char verif = 'N';
	
	while (1) {
		while (verif == 'N') {
			printf("Entrez votre identifiant (-1 pour annuler l'opération) : ");
			scanf("%d", &identifiant);
			pos = rechercherAdherent(tIdCartes, *nbAdherents, identifiant, &trouve);
			
			if (identifiant == -1) {
				printf("Fin de l'opération...\n");
				return;
			}
			
			while (trouve ==  0) {
				fprintf(stderr, "Nous ne trouvons pas votre identifiant. ");
				printf("Entrez votre identifiant : ");
				scanf("%d", &identifiant);
				pos = rechercherAdherent(tIdCartes, *nbAdherents, identifiant, &trouve);
			}
			
			printf("Voulez-vous vraiment supprimé l'adherent %d ? (O/N)  : ", identifiant);
			scanf("%*c%c", &verif);
			
			while (verif != 'O' && verif != 'N') {
				fprintf(stderr, "Erreur de saisie ! ");
				printf("Voulez-vous vraiment supprimé l'adherent %d ? (O/N)  : ", identifiant);
				scanf("%*c%c%*c", &verif);
			}
			
			if (verif == 'O') {
				for(i = pos; i < *nbAdherents; ++i) {
					tIdCartes[i] =  tIdCartes[i+1];
					tAges[i] = tAges[i+1];
					tNbPoints[i] = tNbPoints[i+1];
					tCartesActives[i] = tCartesActives[i+1];
					tPointsDep[i] = tPointsDep[i+1];
					tFrequentations[i] = tFrequentations[i+1];
					*nbAdherents -= 1;
				}
				printf("Adherent %d supprimé.\n", identifiant);
			}
			verif = 'N';
		}
	}
}

void afficheAdherent(int tIdCartes[], int tAges[], int tNbPoints[], char tCartesActives[], int tPointsDep[], char tFrequentations[], int nbAdherents) {
	int identifiant, pos, trouve;

	while (1)
	{
		printf("Entrez votre identifiant (-1 pour annuler l'opération) : ");
		scanf("%d", &identifiant);
		pos = rechercherAdherent(tIdCartes, nbAdherents, identifiant, &trouve);
			
		if (identifiant == -1) {
			printf("Fin de l'opération...\n");
			return;
		}
			
		while (trouve ==  0) {
			fprintf(stderr, "Nous ne trouvons pas votre identifiant. ");
			printf("Entrez votre identifiant : ");
			scanf("%d", &identifiant);
			pos = rechercherAdherent(tIdCartes, nbAdherents, identifiant, &trouve);
		}
		
		printf("L'adherent %04d a %d ans et a %d points et a dépensé %d points depuis le dernier bonus. ", identifiant, tAges[pos], tNbPoints[pos], tPointsDep[pos]);
		
		if (tCartesActives[pos] == 'O')
		{
			printf("Sa carte est activée et ");
		}
		else
		{
			printf("Sa carte est désactivée et ");
		}
		if (tFrequentations[pos] == 'O')
		{
			printf("il est déjà venu au centre aujourd'hui.\n");
		}
		else
		{
			printf("il n'est pas venu au centre aujourd'hui.\n");
		}
	}
}

void afficheTAdherent (int tIdCartes[], int tAges[], int tNbPoints[], char tCartesActives[], int tPointsDep[], char tFrequentations[], int nbAdherents) {
	int i;
	
	printf("Id carte| Age \t| Nb points \t| Carte active \t| Points dépensés \t| Fréquentation\n");
	for(i = 0; i < nbAdherents; ++i) {
		printf("%04d \t| %d \t| %d \t\t| %c \t\t| %d \t\t\t| %c\n", tIdCartes[i], tAges[i], tNbPoints[i], tCartesActives[i], tPointsDep[i], tFrequentations[i]);
	}
}
