#include <stdio.h>
#include <stdlib.h>

void triangle(unsigned);

int main(void)
{
	unsigned c;
	printf("PROGRAMME D'AFFICHAGE D'UN TRIANGLE\n");
	printf("Donner la longueur du cote: ");
	if (scanf("%u", &c) != 1)
    {
        printf("Erreur lors de la lecture du nombre.\n");
        return EXIT_FAILURE;
    }
	printf("\n");
	triangle(c);
	return 0;
}

void triangle(unsigned a)
{
	unsigned j;
	for (unsigned i = 0; i < a; ++i)
	{
        for (j = 0; j <= i; ++j)
            printf("*");
        printf("\n");
	}
}
