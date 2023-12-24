#include <stdio.h>

void TrianglePascal (unsigned short);

int main (void)
{
    unsigned short taille;
    printf ("Quelle taille pour votre triangle de Pascal ?\n");
    scanf ("%hu", &taille);
    TrianglePascal(taille);
}

void TrianglePascal (unsigned short taille)
{

    unsigned int T[taille][taille];
    unsigned i, j;

    for (i = 0; i < taille; i++)
        for (j = 0; j < taille; j++)
            T[i][j] = 0;

    T[0][0] = 1;
    printf(" %5d\n", T[0][0]);

    for (i = 1; i < taille; i++)
    {
        T[i][0] = 1;
        printf(" %5d", T[i][0]);

        for (j = 1; j <= i; j++)
        {
            T[i][j] = T[i-1][j-1] + T[i-1][j];
            printf (" %5d", T[i][j]);
        }
        printf("\n");
    }
}
