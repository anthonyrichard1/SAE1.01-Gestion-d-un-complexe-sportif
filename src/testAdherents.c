#include <stdio.h>
#include"adherents.h"

int main (void)
{
	jeuxEssais();
	return 0;
}

void jeuxEssais(void)
{
	int ids[10] = {1, 2, 3, 6, 7, 8}, ages[10] = {5, 10, 15, 20, 25, 30}, points[10] = {5, 10, 15, 20, 25, 30}, trouve, pos, nbAdherents = 6, nbMaxAdherents = 10, dep[10] = {5, 10, 15, 20, 25, 30};
	char actives[10] = {'N', 'O', 'N', 'O', 'N', 'O'}, freq[10] = {'N', 'O', 'N', 'O', 'N', 'O'};

	printf("Soit la liste des adhérents suivantes :\n");

	afficheTAdherent(ids, ages, points, actives, dep, freq, nbAdherents);

	printf("-> rechercherAdherents :\n"); //rechercherAdherents

	printf("val = 1 (premier élément de la liste)\n");
	pos = rechercherAdherent(ids, nbAdherents, 1, &trouve);
	printf("trouve = %d pos = %d\n", trouve, pos);

	printf("val = 0 (premier élément pas dans la liste)\n");
	pos = rechercherAdherent(ids, nbAdherents, 0, &trouve);
	printf("trouve = %d pos = %d\n", trouve, pos);

	printf("--------------------\n\n");

	printf("val = 8 (dernier élément de la liste)\n");
	pos = rechercherAdherent(ids, nbAdherents, 8, &trouve);
	printf("trouve = %d pos = %d\n", trouve, pos);

	printf("--------------------\n\n");

	printf("val = 5 (une valeur au milieu mais pas dans la liste)\n");
	pos = rechercherAdherent(ids, nbAdherents, 5, &trouve);
	printf("trouve = %d pos = %d\n", trouve, pos);

	printf("--------------------\n\n");

	printf("val = 6 (une valeur au milieu mais déjà dans la liste)\n");
	pos = rechercherAdherent(ids, nbAdherents, 6, &trouve);
	printf("trouve = %d pos = %d\n", trouve, pos);

	printf("--------------------\n\n");

	printf("val = 9 (fin du tableau mais pas dans la liste)\n");
	pos = rechercherAdherent(ids, nbAdherents, 9, &trouve);
	printf("trouve = %d pos = %d\n", trouve, pos);

	printf("--------------------\n\n");

	printf("-> ajouterAdherents :\n"); //ajouterAdherents

	afficheTAdherent(ids, ages, points, actives, dep, freq, nbAdherents);
	printf("id = 1 (déjà dans la liste)\n");
	ajouterAdherent(ids, ages, points, actives, dep, freq, &nbAdherents, nbMaxAdherents);
	afficheTAdherent(ids, ages, points, actives, dep, freq, nbAdherents);
	printf("nbAdherent = %d", nbAdherents);

	printf("--------------------\n\n");

	printf("id = 10 (premier id hors du tableau) et id = -42 (id négatif)\n");
	ajouterAdherent(ids, ages, points, actives, dep, freq, &nbAdherents, nbMaxAdherents);
	afficheTAdherent(ids, ages, points, actives, dep, freq, nbAdherents);
	printf("nbAdherent = %d", nbAdherents);

	printf("--------------------\n\n");

	printf("id = 5 age = -7 (invalide) points = 10\n");
	ajouterAdherent(ids, ages, points, actives, dep, freq, &nbAdherents, nbMaxAdherents);
	afficheTAdherent(ids, ages, points, actives, dep, freq, nbAdherents);
	printf("nbAdherent = %d", nbAdherents);

	printf("--------------------\n\n");

	printf("id = 5 age = 10 points = 0 (invalide)\n");
	ajouterAdherent(ids, ages, points, actives, dep, freq, &nbAdherents, nbMaxAdherents);
	afficheTAdherent(ids, ages, points, actives, dep, freq, nbAdherents);
	printf("nbAdherent = %d", nbAdherents);

	printf("--------------------\n\n");

	printf("id = 5 (milieu de la liste) age = 10 points = 10\n");
	ajouterAdherent(ids, ages, points, actives, dep, freq, &nbAdherents, nbMaxAdherents);
	afficheTAdherent(ids, ages, points, actives, dep, freq, nbAdherents);
	printf("nbAdherent = %d", nbAdherents);

	printf("--------------------\n\n");

	printf("insertions multiples : id = 0 (premier élément), id = 4 (au milieu) et id = 9 (dernier élément) pour remplir complètement le tableau\n");
	ajouterAdherent(ids, ages, points, actives, dep, freq, &nbAdherents, nbMaxAdherents);
	afficheTAdherent(ids, ages, points, actives, dep, freq, nbAdherents);
	printf("nbAdherent = %d", nbAdherents);

	printf("--------------------\n\n");

	printf("débordement du tableau\n");
	ajouterAdherent(ids, ages, points, actives, dep, freq, &nbAdherents, nbMaxAdherents);
	afficheTAdherent(ids, ages, points, actives, dep, freq, nbAdherents);
	printf("nbAdherent = %d", nbAdherents);

	printf("--------------------\n\n");

	printf("-> changerEtatCarte :\n"); //changerEtatCarte

	printf("id = 10 (pas dans le tableau)\n");
	changerEtatCarte(ids, actives, nbAdherents);

	printf("--------------------\n\n");

	printf("id = 0 (carte activée) et confirmation\n");
	changerEtatCarte(ids, actives, nbAdherents);
	afficheAdherent(ids, ages, points, actives, dep, freq, nbAdherents);

	printf("--------------------\n\n");

	printf("id = 3 (carte désactivée) et confirmation\n");
	changerEtatCarte(ids, actives, nbAdherents);
	afficheAdherent(ids, ages, points, actives, dep, freq, nbAdherents);

	printf("--------------------\n\n");

	printf("id = 9 (carte activée) et annulation de l'opération\n");
	changerEtatCarte(ids, actives, nbAdherents);
	afficheAdherent(ids, ages, points, actives, dep, freq, nbAdherents);

	printf("--------------------\n\n");

	printf("id = 7 (carte désactivée) et annulation de l'opération\n");
	changerEtatCarte(ids, actives, nbAdherents);
	afficheAdherent(ids, ages, points, actives, dep, freq, nbAdherents);

	printf("--------------------\n\n");

	printf("-> supprimerAdherent\n"); // supprimerAdherent

	printf("nbAdherent = 0 (pas d'adhérents dans les tableaux)\n");
	nbAdherents = 0;
	supprimerAdherent(ids, ages, points, actives, dep, freq, &nbAdherents);
	nbAdherents = 10;

	printf("--------------------\n\n");

	printf("id = 0105 (pas dans la liste)\n");
	supprimerAdherent(ids, ages, points, actives, dep, freq, &nbAdherents);
	afficheTAdherent(ids, ages, points, actives, dep, freq, nbAdherents);
	printf("nbAdherent = %d\n", nbAdherents);

	printf("--------------------\n\n");

	printf("suppressions multiples : id = 0 (premier élément), id = 9 (dernier élément) et id = 4 (dans le milieu)\n");
	supprimerAdherent(ids, ages, points, actives, dep, freq, &nbAdherents);
	afficheTAdherent(ids, ages, points, actives, dep, freq, nbAdherents);
	printf("nbAdherent = %d\n", nbAdherents);

	printf("--------------------\n\n");

	printf("refus de supprimer l'id = 5\n");
	supprimerAdherent(ids, ages, points, actives, dep, freq, &nbAdherents);
	afficheTAdherent(ids, ages, points, actives, dep, freq, nbAdherents);
	printf("nbAdherent = %d\n", nbAdherents);

	printf("--------------------\n\n");

	printf("alimenterCarte\n"); //alimenterCarte

	printf("id = 0004 (pas dans la liste)\n");
	alimenterCarte(ids, points, nbAdherents);

	printf("--------------------\n\n");

	printf("id = 0005 + points = -5 (invalide)\n");
	alimenterCarte(ids, points, nbAdherents);
	afficheAdherent(ids, ages, points, actives, dep, freq, nbAdherents);

	printf("--------------------\n\n");

	printf("id = 0005 + points = 0 (invalide)\n");
	alimenterCarte(ids, points, nbAdherents);
	afficheAdherent(ids, ages, points, actives, dep, freq, nbAdherents);

	printf("--------------------\n\n");

	printf("id = 0005 + points = 10 (valide)\n");
	alimenterCarte(ids, points, nbAdherents);
	afficheAdherent(ids, ages, points, actives, dep, freq, nbAdherents);

	printf("--------------------\n\n");

	printf("ajout multiples de points : id = 0001 + points = 50 et id = 0002 + points = 50\n");
	alimenterCarte(ids, points, nbAdherents);
	afficheTAdherent(ids, ages, points, actives, dep, freq, nbAdherents);

	printf("--------------------\n\n");
}

