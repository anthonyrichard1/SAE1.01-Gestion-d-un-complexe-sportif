#include <stdio.h>
#include"adherents.h"

int main (void)
{
	int ids[10000] = {1, 1234, 5678, 6234, 6789, 9998},
	ages[1000] = {5, 10, 15, 20, 25, 30},
	points[10000] = {5, 10, 15, 20, 25, 30},
	actives[10000] = {0, 1, 0, 1, 0, 1}, trouve, pos, nbAdherents = 6, nbMaxAdherents = 10000;
	FILE *f;

	printf("Soit la liste des adhérents suivantes :\n");

	afficheTAdherent(ids, ages, points, nbAdherents);

	printf("--------------------\n\n");

	printf("rechercherAdherents :\n");

	printf("val = 1 (premier élément de la liste)\n");
	pos = rechercherAdherent(ids, nbAdherents, 1, &trouve);
	printf("trouve = %d pos = %d\n", trouve, pos);

	printf("val = 0 (premier élément pas dans la liste)\n");
	pos = rechercherAdherent(ids, nbAdherents, 0, &trouve);
	printf("trouve = %d pos = %d\n", trouve, pos);

	printf("--------------------\n\n");

	printf("val = 9998 (dernier élément de la liste)\n");
	pos = rechercherAdherent(ids, nbAdherents, 9998, &trouve);
	printf("trouve = %d pos = %d\n", trouve, pos);

	printf("--------------------\n\n");

	printf("val = 3333 (une valeur au milieu)\n");
	pos = rechercherAdherent(ids, nbAdherents, 3333, &trouve);
	printf("trouve = %d pos = %d\n", trouve, pos);

	printf("--------------------\n\n");

	printf("val = 5678 (une valeur au milieu mais déjà dans la liste)\n");
	pos = rechercherAdherent(ids, nbAdherents, 5678, &trouve);
	printf("trouve = %d pos = %d\n", trouve, pos);

	printf("--------------------\n\n");

	printf("val = 9999 (fin du tableau mais pas dans la liste)\n");
	pos = rechercherAdherent(ids, nbAdherents, 9999, &trouve);
	printf("trouve = %d pos = %d\n", trouve, pos);

	printf("--------------------\n\n");

	printf("ajouterAdherents :\n");
	afficheTAdherent(ids, ages, points, nbAdherents);
	printf("id = 00001 (déjà dans la liste)\n");
	ajouterAdherent(ids, ages, points, actives, &nbAdherents, nbMaxAdherents);
	afficheTAdherent(ids, ages, points, nbAdherents);

	printf("--------------------\n\n");

	printf("id = 10000 (premier id hors du tableau)\n");
	ajouterAdherent(ids, ages, points, actives, &nbAdherents, nbMaxAdherents);
	afficheTAdherent(ids, ages, points, nbAdherents);

	printf("--------------------\n\n");

	printf("id = 5555 age = -7 (invalide) points = 10\n");
	ajouterAdherent(ids, ages, points, actives, &nbAdherents, nbMaxAdherents);
	afficheTAdherent(ids, ages, points, nbAdherents);

	printf("--------------------\n\n");

	printf("id = 5555 age = 10 points = 0 (invalide)\n");
	ajouterAdherent(ids, ages, points, actives, &nbAdherents, nbMaxAdherents);
	afficheTAdherent(ids, ages, points, nbAdherents);

	printf("--------------------\n\n");

	printf("id = 5555 (milieu de la liste) age = 10 points = 10\n");
	ajouterAdherent(ids, ages, points, actives, &nbAdherents, nbMaxAdherents);
	afficheTAdherent(ids, ages, points, nbAdherents);

	printf("--------------------\n\n");

	printf("insertions multiples : id = 0 (premier élément) et id = 9999 (dernier élément)\n");
	ajouterAdherent(ids, ages, points, actives, &nbAdherents, nbMaxAdherents);
	afficheTAdherent(ids, ages, points, nbAdherents);

	printf("--------------------\n\n");
}
