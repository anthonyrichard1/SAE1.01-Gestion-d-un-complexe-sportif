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

void ajouterAdherent(int tIdCartes[], int tAges[], int tNbPoints[], int *nbAdherents, int *nbMaxAdherents)
{
	unsigned idCarte, age, nbPoints, pos, i = *nbAdherents-1;
	int trouve;

	while (1)
	{

		if (*nbAdherents == *nbMaxAdherents)
		{
			fprintf(stderr, "Erreur : le nombre d'adhérent maximal a été atteint\n");
			printf("Fin de l'opération...\n");
			return;
		}

		printf("Entrez l'identifiant de l'adhérent à ajouter (-1 pour annuler l'opération) : ");
		scanf("%d", &idCarte);

		while (idCarte >= *nbMaxAdherents || idCarte < 0)
		{
			if (idCarte == -1)
			{
				printf("Fin de l'opération...\n");
				return;
			}

			fprintf(stderr, "Erreur : l'identifiant entré n'est pas valide, recommencez\n");
			printf("Entrez l'identifiant de l'adhérent à ajouter (-1 pour annuler l'opération) : ");
			scanf("%d", &idCarte);
		}

		pos = rechercherAdherent(tIdCartes, *nbAdherents, idCarte, &trouve);

		if (trouve)
		{
			fprintf(stderr, "Erreur : cet identifiant existe déjà\n");
		}
		else
		{
			printf("Entrez l'age de l'adhérent à ajouter (-1 pour annuler l'opération) : ");
			scanf("%d", &age);

			while (age < 0)
			{
				if (age == -1)
				{
					printf("Fin de l'opération...\n");
					return;
				}

				fprintf(stderr, "Erreur : l'age entré est invalide (nombre négatif), recommencez\n");
				printf("Entrez l'age de l'adhérent à ajouter (-1 pour annuler l'opération) : ");
				scanf("%d", &age);
			}

			printf("Entrez le nombre de points à ajouter à l'adhérent (-1 pour annuler l'opération) : ");
			scanf("%d", &nbPoints);

			while (nbPoints <= 0)
			{
				if (nbPoints == -1)
				{
					printf("Fin de l'opération...");
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
				i++;
			}

			tIdCartes[pos] = idCarte;
			tAges[pos] = age;
			tNbPoints[pos] = nbPoints;

			idCarte = -1;
			age = -1;
			nbPoints = -1;
			++*nbAdherents;
		}
	}
}
