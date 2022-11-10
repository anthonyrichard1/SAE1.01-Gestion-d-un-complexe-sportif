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
	int idCarte = 0, age, nbPoints, pos, i;
	int trouve;

	while (idCarte != -1)
	{
		i = *nbAdherents-1;

		if (*nbAdherents == nbMaxAdherents)
		{
			fprintf(stderr, "\e[1;91mErreur : le nombre d'adhérent maximal a été atteint\e[0m\n");
			printf("Fin de l'opération...\n");
			return;
		}

		printf("Entrez l'identifiant de l'adhérent à ajouter (-1 pour annuler l'opération) : ");
		scanf("%d", &idCarte);

		if (idCarte >= nbMaxAdherents || idCarte < 0)
		{
			if (idCarte != -1)
			{
				fprintf(stderr, "\e[1;91mErreur : %04d n'est pas un identifiant valide, recommencez\e[0m\n", idCarte);
			}
		}
		else
		{
			pos = rechercherAdherent(tIdCartes, *nbAdherents, idCarte, &trouve);

			if (trouve)
			{
				fprintf(stderr, "\e[1;91mErreur : l'identifiant %04d existe déjà\e[0m\n", idCarte);
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

					fprintf(stderr, "\e[1;91mErreur : %d n'est pas un age valide (nombre négatif ou nul), recommencez\e[0m\n", idCarte);
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

					fprintf(stderr, "\e[1;91mErreur : il faut obligatoirement ajouter des points à un nouvel utilisateur, recommencez\e[0m\n");
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

				printf("\e[1;92mAdhérent %04d ajouté !\e[0m\n", idCarte);
				++*nbAdherents;
			}
		}		
	}

	printf("Fin de l'opération...\n");
	return;
}

void alimenterCarte(int tIdCartes[], int tNbPoints[], int nbAdherents) {
	int points, identifiant, trouve, pos;

	while (identifiant != -1) {
		printf("Entrez votre identifiant (-1 pour annuler l'opération) : ");
		scanf("%d", &identifiant);

		pos = rechercherAdherent(tIdCartes, nbAdherents, identifiant, &trouve);

		if (trouve ==  0) {
			if (identifiant != -1)
			{
				fprintf(stderr, "\e[1;91mErreur : identifiant introuvable\e[0m\n");
			}
		}
		else
		{
			printf("Vous avez %d points. 1 point vaut 0.5€.", tNbPoints[pos]);
			printf("\nNombre de points souhaité (-1 pour annuler l'opération) : ");
			scanf("%d", &points);

			while (points <= 0)
			{
				if (points == -1) {
					printf("Fin de l'opération...\n");
					return;
				}
				else
				{
					fprintf(stderr, "\e[1;91mErreur : le nombre de points doit être supérieur à 0\e[0m\n");
				}

				printf("Vous avez %d points. 1 point vaut 0.5€.", tNbPoints[pos]);
				printf("\nNombre de points souhaité (-1 pour annuler l'opération) : ");
				scanf("%d", &points);
			}

			printf("Cela coûte %.2f€.", points*0.5);
			tNbPoints[pos] += points;
			printf("\n\e[1;92mVous avez %d points.\e[0m\n", tNbPoints[pos]);
		}
	}
	
	printf("Fin de l'opération...\n");
	return;
}

void changerEtatCarte(int tIdCartes[], char tCartesActives[], int nbAdherents)
{
	int idCarte, pos, trouve;
	char choix;

	while (idCarte != -1)
	{
		printf("Entrez l'identifiant de la carte (-1 pour annuler l'opération) : ");
		scanf("%d", &idCarte);

		pos = rechercherAdherent(tIdCartes, nbAdherents, idCarte, &trouve);

		if (!trouve)
		{
			if (idCarte != -1)
			{
				fprintf(stderr, "\e[1;91mErreur : l'identifiant est inconnu, recommencez\e[0m\n");
			}
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
					printf("\e[1;92mCarte désactivée !\e[0m\n");
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
					printf("\e[1;92mCarte activée !\e[0m\n");
				}
				else
				{
					printf("Abandon de l'opération...\n");
				}

				choix = 'a';
			}
		}
	}

	printf("Fin de l'opération...\n");
	return;
}

void supprimerAdherent(int tIdCartes[], int tAges[], int tNbPoints[], char tCartesActives[], int tPointsDep[], char tFrequentations[], int *nbAdherents) {
	int identifiant, pos, i, trouve;
	char verif;

	while (identifiant != -1) {

		if (*nbAdherents == 0)
		{
			fprintf(stderr, "\e[1;91mErreur : aucun adhérent enregistré\e[0m\n");
			printf("Fin de l'opération...\n");
			return;
		}

		printf("Entrez votre identifiant (-1 pour annuler l'opération) : ");
		scanf("%d", &identifiant);

		pos = rechercherAdherent(tIdCartes, *nbAdherents, identifiant, &trouve);

		if (trouve == 0)
		{
			if (identifiant != -1)
			{
				fprintf(stderr, "\e[1;91mErreur : identifiant introuvable\e[0m\n");
			}
		}
		else
		{
			printf("Voulez-vous vraiment supprimer l'adherent %04d ? (O/N)  : ", identifiant);
			scanf("%*c%c", &verif);

			while (verif != 'O' && verif != 'o' && verif != 'N' && verif != 'n') {
				fprintf(stderr, "\e[1;91mErreur : saisie incorrecte\e[0m");
				printf("Voulez-vous vraiment supprimer l'adherent %04d ? (O/N)  : ", identifiant);
				scanf("%*c%c%*c", &verif);
			}

			if (verif == 'O' || verif == 'o') {
				for(i = pos; i < *nbAdherents; ++i) {
					tIdCartes[i] =  tIdCartes[i+1];
					tAges[i] = tAges[i+1];
					tNbPoints[i] = tNbPoints[i+1];
					tCartesActives[i] = tCartesActives[i+1];
					tPointsDep[i] = tPointsDep[i+1];
					tFrequentations[i] = tFrequentations[i+1];
				}
				printf("\e[1;92mAdherent %04d supprimé !\e[0m\n", identifiant);
				*nbAdherents -= 1;
			}
			else
			{
				printf("Abandon de l'opération...");
			}
		}
	}

	printf("Fin de l'opération...\n");
	return;
}

void afficheAdherent(int tIdCartes[], int tAges[], int tNbPoints[], char tCartesActives[], int tPointsDep[], char tFrequentations[], int nbAdherents) {
	int identifiant, pos, trouve;

	while (identifiant != -1)
	{
		printf("Entrez votre identifiant (-1 pour annuler l'opération) : ");
		scanf("%d", &identifiant);

		pos = rechercherAdherent(tIdCartes, nbAdherents, identifiant, &trouve);

		if (trouve == 0) {
			if (identifiant != -1)
			{
				fprintf(stderr, "\e[1;91mErreur : identitifiant introuvable.\e[0m\n");
			}
		}
		else
		{
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

	printf("Fin de l'opération...\n");
	return;
}

void afficheTAdherent (int tIdCartes[], int tAges[], int tNbPoints[], char tCartesActives[], int tPointsDep[], char tFrequentations[], int nbAdherents) {
	int i;

	printf("Id carte| Age \t| Nb points \t| Carte active \t| Points dépensés \t| Fréquentation\n");
	for(i = 0; i < nbAdherents; ++i) {
		printf("%04d \t| %d \t| %d \t\t| %c \t\t| %d \t\t\t| %c\n", tIdCartes[i], tAges[i], tNbPoints[i], tCartesActives[i], tPointsDep[i], tFrequentations[i]);
	}
}

