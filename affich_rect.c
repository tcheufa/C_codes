#include <stdio.h>

void rectangle(unsigned, unsigned);

int main(void)
{
	unsigned longueur, largeur;
	printf("PROGRAMME D'AFFICHAGE D'UN RECTANGLE\n");
	printf("Donner la longueur: ");
	scanf("%u", &longueur);
	printf("Donner la largeur: ");
	scanf("%u", &largeur);
	printf("\n");
	rectangle(largeur, longueur);
	return 0;
}

void rectangle(unsigned a, unsigned b)
{
	unsigned j = 1;
	for (unsigned i = 1; i <= b; ++i)
    {
		for (; j <= a; ++j)
            printf("*");
        printf("\n");
	}
}
