#include <stdio.h>
#include <stdlib.h>

int main()
{
    int exp = 0;
    int dec, dec2, dec3;
    int base;

    printf("Entrer un nombre : ");

    if (scanf("%d", &dec) != 1)
    {
        printf("Une erreur s'est produite lors de la lecture du nombre.\n");
        return EXIT_FAILURE;
    }

    dec3 = dec2 = dec;
    printf("Dans quelle base souhaitez-vous afficher ce nombre : ");

    if (scanf("%s", &base) != 1)
    {
        printf("Une erreur s'est produite lors de la lecture du nombre.\n");
        return EXIT_FAILURE;
    }

    ///Ici on détermine la taille de notre nombre (le nombres de chiffres qu'elle contiendra)

    do
    {
        dec2 = dec2 / base;
        exp++;
    }
    while(dec2 > 0);

    ///Nous créons un tableau pour accueillir le nombre exact de chiffres du nombre dans la base de destination

    int conv[exp];

    ///On effectue la conversion en envoyant chaque chiffre un à un dans notre tableau

    for(int i = exp - 1; i >= 0; i--)
    {
        conv[i] = dec3 % base;
        dec3 = dec3 / base;
    }

    ///On affiche le résultat

    printf("%d dans la base %d est egal a : ", dec, base);

    for(int i = 0; i < exp; i++)
    {
        if(conv[i] < 10)
            printf("%d", conv[i]);
        else
            printf("%c", 65 + (conv[i] - 10));
    }

    printf("\n\n%d a %d chiffre(s) dans la base %d.\n", dec, exp, base);

    return 0;
}
