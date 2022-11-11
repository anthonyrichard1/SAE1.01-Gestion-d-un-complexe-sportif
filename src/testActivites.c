#include <stdio.h>
#include <stdlib.h>
#include"activites.h"
#include"adherents.h"

int main (void)
{
	jeuxEssais();
	return 0;
}

void jeuxEssais(void) {
	int ids[10] = {1, 2, 3, 6, 7, 8}, ages[10] = {5, 10, 15, 20, 25, 30}, points[10] = {5, 5, 15, 20, 25, 30}, nbAdherents = 6, dep[10] = {5, 10, 15, 20, 25, 30};
	int activite[14]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14}, cout[14]={10, 15, 20, 10, 10, 10, 10, 20, 10, 15, 10, 10, 10, 15}, entree[14]={30, 29, 36, 7, 31, 0, 10, 27, 20, 21, 6, 37, 50, 17}, nbActivite=14;
	
	char actives[10] = {'N', 'O', 'O', 'O', 'O', 'O'}, freq[10] = {'N', 'N', 'N', 'O', 'N', 'N'};
	
	printf("Soit la liste des adhérents suivantes :\n");
	afficheTAdherent(ids, ages, points, actives, dep, freq, nbAdherents);

	printf("\n----------------------------------------\n\n");
	
	printf("\nSoit la liste des activités suivantes :\n");
	entreeActivite(activite, entree, nbActivite);

	printf("\n----------------------------------------\n\n");
	
	printf("-> reservationActivite :\n");
	
	printf("Annulé l'opération\n");
	reservationActivite(ids, points, actives, freq, dep, nbAdherents, activite, cout, entree, nbActivite);

	printf("\n----------------------------------------\n\n");
	
	printf("id = 1555 (invalide)\n");
	reservationActivite(ids, points, actives, freq, dep, nbAdherents, activite, cout, entree, nbActivite);

	printf("\n----------------------------------------\n\n");
	
	printf("actives = 'N'\n");
	reservationActivite(ids, points, actives, freq, dep, nbAdherents, activite, cout, entree, nbActivite);

	printf("\n----------------------------------------\n\n");
	
	printf("freq = 'O'\n");
	reservationActivite(ids, points, actives, freq, dep, nbAdherents, activite, cout, entree, nbActivite);

	printf("\n----------------------------------------\n\n");
	
	printf("activite = 15 (invalide)\n");
	reservationActivite(ids, points, actives, freq, dep, nbAdherents, activite, cout, entree, nbActivite);

	printf("\n----------------------------------------\n\n");
	
	printf("activite = 1 + points = 5\n");
	reservationActivite(ids, points, actives, freq, dep, nbAdherents, activite, cout, entree, nbActivite);

	printf("\n----------------------------------------\n\n");
	
	printf("entree = 50\n");
	reservationActivite(ids, points, actives, freq, dep, nbAdherents, activite, cout, entree, nbActivite);

	printf("\n----------------------------------------\n\n");
	
	printf("1 réservations\n");
	reservationActivite(ids, points, actives, freq, dep, nbAdherents, activite, cout, entree, nbActivite);
	afficheTAdherent(ids, ages, points, actives, dep, freq, nbAdherents);
	entreeActivite(activite, entree, nbActivite);

	printf("\n----------------------------------------\n\n");
	
	printf("2 réservations\n");
	reservationActivite(ids, points, actives, freq, dep, nbAdherents, activite, cout, entree, nbActivite);
	afficheTAdherent(ids, ages, points, actives, dep, freq, nbAdherents);
	entreeActivite(activite, entree, nbActivite);

	printf("\n----------------------------------------\n\n");
	
	printf("3 réservations\n");
	reservationActivite(ids, points, actives, freq, dep, nbAdherents, activite, cout, entree, nbActivite);
	afficheTAdherent(ids, ages, points, actives, dep, freq, nbAdherents);
	entreeActivite(activite, entree, nbActivite);

	printf("\n----------------------------------------\n\n");
}
