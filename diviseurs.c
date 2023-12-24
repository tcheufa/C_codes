#include <stdio.h>
#include <stdlib.h>

/** Ce programme :
--> recupère un entier relatif entré par l'utilisateur,
--> détermine ses diviseurs "supérieurs à 1",
--> les stocke dans un tableau de la taille adéquate et
--> affiche ces diviseurs.
**/

int main(int argc, char *argv[])
{
    int n = 0;
    printf("Entrer un nombre : ");
    if (scanf("%d", &n) != 1)
    {
        printf("Echec de la lecture du nombre.\n");
        return EXIT_FAILURE;
    }
    else
    {
        if (n == 0)
        {
            printf("0 n'a pas d'autres diviseurs que 1");
        }
        else
        {
            int diviseur[n/4]; //selon moi un nombre n a toujours un nombre de diviseurs inferieur ou egal a n/4
            int i = 0;
            for (int m = 2; m <= n / 2; m++)
            {
                if (n % m == 0)
                {
                    diviseur[i] = m;
                    ++i;
                }
            }
            if (i == 0)
            {
                printf("Les diviseurs de %d sont : 1 et %d", n, n);
            }
            else
            {
                printf("les diviseurs de %d sont :\n1 ", n);
                for (int j = 0; j < i; j++)
                    printf("%d ", diviseur[j]);
            }
        }
    }
    return EXIT_SUCCESS;
}
