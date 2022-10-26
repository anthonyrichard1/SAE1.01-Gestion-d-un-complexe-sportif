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

int alimenterCarte(int tIdCartes[], int nbAdherents, int tNbPoints[]) {
	int points, identifiant, trouve, pos;
	
	printf("Entrez votre identifiant : ");
	scanf("%d", &identifiant);
	if (identifiant == -1) {
			printf("Fin de l'opération...\n");
			return;
		}
	pos = rechercherAdherent(tIdCartes, nbAdherents, identifiant, &trouve);
	
	while (trouve ==  0) {
		printf("Nous ne trouvons pas votre identifiant. ");
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
		printf("Le nombre de poitns doit être supérieur à 0.");
		printf("\nNombre de points souhaité : ");
		scanf("%d", &points);
	}
	
	printf("Cela coûte %.2f€.", points*0.5);
	tNbPoints[pos] += points;
	printf("\nVous avez %d points.\n", tNbPoints[pos]);
	return 0;
}

int supprimerAdherent(int tIdCartes[], int tAges[], int tNbPoints[], int *nbAdherents) {
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
				printf("Nous ne trouvons pas votre identifiant. ");
				printf("Entrez votre identifiant : ");
				scanf("%d", &identifiant);
				pos = rechercherAdherent(tIdCartes, *nbAdherents, identifiant, &trouve);
			}
			
			printf("Voulez-vous vraiment supprimé l'adherent %d ? (O/N)  : ", identifiant);
			scanf("%*c%c", &verif);
			
			while (verif != 'O' && verif != 'N') {
				printf("Erreur de saisie ! ");
				printf("Voulez-vous vraiment supprimé l'adherent %d ? (O/N)  : ", identifiant);
				scanf("%*c%c%*c", &verif);
			}
			
			if (verif == 'O') {
				for(i = pos; i < *nbAdherents; ++i) {
					tIdCartes[i] =  tIdCartes[i+1];
					tAges[i] = tAges[i+1];
					tNbPoints[i] = tNbPoints[i+1];
					*nbAdherents -= 1;
				}
				printf("Adherent %d supprimé.\n", identifiant);
			}
			verif == 'N';
		}
	}
}

void afficheAdherent(int tIdCartes[], int tAges[], int tNbPoints[], int *nbAdherents) {
	int identifiant, pos, trouve;
	
	printf("Entrez votre identifiant (-1 pour annuler l'opération) : ");
	scanf("%d", &identifiant);
	pos = rechercherAdherent(tIdCartes, *nbAdherents, identifiant, &trouve);
		
	if (identifiant == -1) {
		printf("Fin de l'opération...\n");
		return;
	}
		
	while (trouve ==  0) {
		printf("Nous ne trouvons pas votre identifiant. ");
		printf("Entrez votre identifiant : ");
		scanf("%d", &identifiant);
		pos = rechercherAdherent(tIdCartes, *nbAdherents, identifiant, &trouve);
	}
	
	printf("L'adherent %d a %d ans et a %d points. ", identifiant, tAges[pos], tNbPoints[pos]);
}

void afficheTAdherent (int tIdCartes[], int tAges[], int tNbPoints[], int *nbAdherents) {
	int i;
	
	printf("Id carte | Age | nb points\n");
	for(i = 0; i < *nbAdherents; ++i) {
		printf("%d\t | %d  | %d\n", tIdCartes[i], tAges[i], tNbPoints[i]);
	}
}
