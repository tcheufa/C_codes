#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char c;
    short compt = 0;
    printf("Entrer une phrase (si plusieurs phrases sont saisies seule la premiere sera prise en compte):\n");

    do
    {
        if(scanf("%c", &c) != 1)
        {
            printf("Erreur lors de la lecture du nombre.\n");
            return EXIT_FAILURE;
        }
        if (c == 'e' || c == 'E')
            ++compt;
    }
    while (c != '.' && c != '?' && c != '!');

    if (compt == 0)
        printf("Aucune lettre 'e' n'a ete detectee");
    else
        printf("Au moins une lettre 'e' a ete detectee (precisement %i)", compt);

    return EXIT_SUCCESS;
}
