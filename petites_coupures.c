#include <stdio.h>

void coupures(unsigned);

int main(void)
{
	unsigned somme;
	printf("PROGRAMME D'AFFICHAGE DES PETITES COUPURES D'UNE SOMME D'ARGENT\n");
	printf("Donner un montant: ");
	if (scanf("%u", &somme) != 1)
    {
        printf("Erreur lors de la lecture du nombre.\n");
        return 18;
    }
	printf("\n");
	coupures(somme);
	return 0;
}

void coupures(unsigned s)
{
	printf("%u piece(s) de 100F.\n", s / 100);
	s %= 100;
	printf("%u piece(s) de 50F.\n", s / 50);
	s %= 50;
	printf("%u piece(s) de 20F.\n", s / 20);
	s %= 20;
	printf("%u piece(s) de 10F.\n", s / 10);
	s %= 10;
	printf("%u piece(s) de 5F.\n", s / 5);
	s %= 5;
	printf("%u piece(s) de 1F.\n", s);
}
