#include <stdio.h>
#include"activites.h"
#include"adherents.h"

int rechercherActivite(int tActivite[], int nbActivite, int val, int *trouve)
{
	int i = 0;

	while (i < nbActivite)
	{
		if (val == tActivite[i])
		{
			*trouve = 1;
			return i;
		}

		i++;
	}

	*trouve = 0;
	return i;
}

void listeActivites(void) 
{
	printf("\nNuméro de l'activité | Nom de l'activité | Coût de l'activité\n"
	"1\t\t     | Musculation\t | 10 points\n"
	"2\t\t     | Aquagym\t\t | 15 points\n"
	"3\t\t     | SPA\t\t | 20 points\n"
	"4\t\t     | Danse\t\t | 10 points\n"
	"5\t\t     | Loisirs créatifs\t | 10 points\n"
	"6\t\t     | Basket\t\t | 10 points\n"
	"7\t\t     | Football\t\t | 10 points\n"
	"8\t\t     | Escape game\t | 20 points\n"
	"9\t\t     | Athlétisme\t | 10 points\n"
	"10\t\t     | Massage\t\t | 15 points\n"
	"11\t\t     | Boxe française\t | 10 points\n"
	"12\t\t     | Escrime\t\t | 10 points\n"
	"13\t\t     | Gymnastique\t | 10 points\n"
	"14\t\t     | Equitation\t | 15 points\n\n");

}

void reservationActivite(int tIdCartes[], int tNbPoints[], char tCartesActives[], char tFrequentations[], int tPointsDep[], int *nbAdherent, int tActivite[], int tCoutPoints[], int tNbEntree[], int nbActivite)
{
	int nbResa = 0, pos, trouve, identifiant, activite;
	int posAct, trouveAct;

	printf("Entrez votre identifiant (-1 pour annuler l'opération) : ");
	scanf("%d", &identifiant);
	pos = rechercherAdherent(tIdCartes, *nbAdherent, identifiant, &trouve);

	if (identifiant == -1) {
		printf("Fin de l'opération...\n");
		return;
	}

	while (trouve ==  0) {
		fprintf(stderr, "Nous ne trouvons pas votre identifiant. ");
		printf("Entrez votre identifiant : ");
		scanf("%d", &identifiant);
		pos = rechercherAdherent(tIdCartes, *nbAdherent, identifiant, &trouve);
	}

	if(tCartesActives[pos] == 'N') {
		fprintf(stderr, "Votre carte est désactivé, vous ne pouvez pas réserver d'activité.\n");
		return;
	}

	if(tFrequentations[pos] == 'O') {
		fprintf(stderr, "Vous avez déjà fréquenté le centre aujourd'hui.\n");
		return;
	}

	while(nbResa < 3) {
		listeActivites();

		printf("Entrez le numéro de l'activité souhaité (-1 pour annuler l'opération) : ");
		scanf("%d", &activite);
		posAct = rechercherActivite(tActivite, nbActivite, activite, &trouveAct);

		if (activite == -1) {
			printf("Fin de l'opération...\n");
			return;
		}

		while (trouveAct == 0) {
			fprintf(stderr, "Ce numéro d'activité est incorrecte. ");
			printf("Entrez le numéro de l'activité souhaité : ");
			scanf("%d", &activite);
			posAct = rechercherActivite(tActivite, nbActivite, activite, &trouveAct);
		}

		if(tNbPoints[pos] < tCoutPoints[posAct]) {
			fprintf(stderr, "Vous n'avez pas assez de points pour faire cette activité.\n");
		}
		else if(tNbEntree[posAct] == 50) {
			fprintf(stderr, "Il n'y a plus de place disponible pour cette activité.\n");
		}
		else {
			tNbPoints[pos] -= tCoutPoints[posAct];
			tPointsDep[pos] += tCoutPoints[posAct];
			tFrequentations[pos] = 'O';
			tNbEntree[posAct] += 1;

			++nbResa;
		}
	}
}

void entreeActivite(int tActivite[], int tNbEntree[], int nbActivite) 
{
	int i;

	printf("Numéro de l'activité | Nombre d'entrée\n");

	for(i=0; i < nbActivite; ++i) {
		printf("%d\t\t     | %d\n", tActivite[i], tNbEntree[i]);
	}
}
