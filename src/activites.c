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
	int pos, trouve, identifiant, activite;
	int posAct, trouveAct;

	while(1) {
		int nbResa = 0;
		
		printf("Entrez votre identifiant (-1 pour annuler l'opération) : ");
		scanf("%d", &identifiant);
		pos = rechercherAdherent(tIdCartes, *nbAdherent, identifiant, &trouve);

		if (identifiant == -1) {
			printf("Fin de l'opération...\n");
			return;
		}

		if (trouve ==  0)
			fprintf(stderr, "\e[1;91mNous ne trouvons pas votre identifiant.\e[0m\n");
		else {
			if(tCartesActives[pos] == 'N') 
				fprintf(stderr, "\e[1;91mVotre carte est désactivée, vous ne pouvez pas réserver d'activité.\e[0m\n");
			else {
				if(tFrequentations[pos] == 'O') 
					fprintf(stderr, "\e[1;91mVous avez déjà fréquenter le centre aujourd'hui.\e[0m\n");
				else {
					while(nbResa < 3) {
						listeActivites();

						printf("Entrez le numéro de l'activité souhaité (-1 pour annuler l'opération) : ");
						scanf("%d", &activite);
						posAct = rechercherActivite(tActivite, nbActivite, activite, &trouveAct);

						if (activite == -1) {
							printf("Fin de l'opération...\n");
							return;
						}

						if (trouveAct == 0) 
							fprintf(stderr, "\e[1;91mCe numéro d'activité est incorrect.\e[0m\n");
						else {
							if(tNbPoints[pos] < tCoutPoints[posAct]) {
								fprintf(stderr, "\e[1;91mVous n'avez pas assez de points pour faire cette activité.\e[0m\n");
							}
							else if(tNbEntree[posAct] == 50) {
								fprintf(stderr, "\e[1;91mIl n'y a plus de place disponible pour cette activité.\e[0m\n");
							}
							else {
								printf("\e[1;92mActivité %d réservé !\e[0m\n", activite);
								tNbPoints[pos] -= tCoutPoints[posAct];
								tPointsDep[pos] += tCoutPoints[posAct];
								tFrequentations[pos] = 'O';
								tNbEntree[posAct] += 1;

								++nbResa;
							}
						}
					}
				}
			}
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
