#include <stdio.h>
#include"menus.h"

int main (void)
{
	jeuxEssais();
	return 0;
}

void jeuxEssais(void)
{
	printf("pointsBonus"); //pointsBonus

	int pt = 30, pb = pointsBonus(8, &pt);
	printf("point = 30, age = 8, attendu = (pt0, r30), résultat = (pt%d, r%d)\n", pb, pt);
	pt = 50, pb = pointsBonus(17, &pt);
	printf("point = 50, age = 17, attendu = (pt15, r0), résultat = (pt%d, r%d)\n", pb, pt);
	pt = 153, pb = pointsBonus(78, &pt);
	printf("point = 153, age = 78, attendu = (pt45, r3), résultat = (pt%d, r%d)\n", pb, pt);
	pt = 30, pb = pointsBonus(30, &pt);
	printf("point = 30, age = 30, attendu = (pt0, r30), résultat = (pt%d, r%d)\n", pb, pt);
	pt = 50, pb = pointsBonus(50, &pt);
	printf("point = 50, age = 50, attendu = (pt10, r0), résultat = (pt%d, r%d)\n", pb, pt);
	pt = 153, pb = pointsBonus(59, &pt);
	printf("point = 153, age = 59, attendu = (pt30, r3), résultat = (pt%d, r%d)\n", pb, pt);

	printf("----------------------------------------");

	printf("Menus"); // Menus

	printf("menu principal + choix incorrect");

	printf("menu des adhérents + choix  = [1, 2, 3, 4, 5, 6] (lancement des fonctions)");

	printf("menu des adhérents + choix incorrect");

	printf("menu des activités + choix  = [1, 2, 3] (lancement des fonctions)");

	printf("menu des activités + choix incorrect");

	menuPrincipal();
}
