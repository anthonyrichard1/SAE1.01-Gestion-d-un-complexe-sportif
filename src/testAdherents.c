#include <stdio.h>
#include"adherents.h"

int main (void)
{
	int nbAdherent = 5;
	int tab[5] = {5, 10, 15, 20, 25}, trouve, pos;
	pos = rechercherAdherent(tab, nbAdherent, 23, &trouve);
	
	printf("pos : %d\n", pos);
	printf("trouvé : %d\n", trouve);
}
