#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    unsigned n, i = 2;
    printf("Entrer un nombre entier: ");
    if (scanf("%u", &n) != 1)
    {
        printf("Erreur lors de la lecture du nombre.\n");
        return EXIT_FAILURE;
    }
    while ((i < n / 2) && (n % i != 0))
        i++;
    if (i == n / 2)
        printf("%u est un nombre premier !", n);
    else
        printf("%u n'est pas un nombre premier.", n);
    return EXIT_SUCCESS;
}
