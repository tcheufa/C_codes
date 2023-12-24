#include <stdio.h>
#include <stdlib.h>

///Ma super fonction de formattage : Créé des espace selon le nombre qu'on lui fournit
void makespace(int nb_spaces);

int main(int argc, char *argv[])
{

    ///l'initialisation et les verifications

    int a = 0, b = 0;
    printf("Entrer deux nombres : ");
    do
    {
        if (scanf("%d %d", &a, &b) != 2)
        {
            printf("Erreur lors de la lecture des variables.\n");
            return EXIT_FAILURE;
        }
        else
        {
            if (a < 0 || b < 0)
                printf("Veuillez s'il vous plait entrer un nombre positif");
            else
                break;
        }
    } while (a < 0 || b < 0);


    ///les calculs

    int tmp = 0;
    int c = printf("%d x %d", a, b);
    while (b != 0)
    {
        if (b % 2 == 0)
        {
            a *= 2;
            b /= 2;
        }
        else
        {
            --b;
            tmp += a;
        }
        printf(" = %d x %d + %d\n", a, b, tmp);
        makespace(c);
    }
    printf(" = %d", tmp);
    return EXIT_SUCCESS;
}

void makespace(int nb_spaces)
{
    for (int i = 0; i < nb_spaces; i++)
        printf(" ");
}
