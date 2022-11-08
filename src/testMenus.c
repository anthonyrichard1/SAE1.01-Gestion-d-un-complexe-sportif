#include <stdio.h>
#include"menus.h"

int main (void)
{
	jeuxEssais();
	return 0;
}

void jeuxEssais(void)
{

	printf("menu principal + choix incorrect\n");

	printf("--------------------\n\n");

	printf("menu des adhérents + choix  = [1, 2, 3, 4, 5, 6] (lancement des fonctions)\n");

	printf("--------------------\n\n");

	printf("menu des adhérents + choix incorrect\n");

	printf("--------------------\n\n");

	menuPrincipal();

}
