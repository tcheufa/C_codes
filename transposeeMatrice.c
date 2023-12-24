#include <stdio.h>
#include <stdlib.h>

enum taille{
 nb_lignes = 3,
 nb_colonnes = 3
} taille;

int Transposee(int (*M)[nb_colonnes])
{
    for(int j = 0; j < nb_colonnes; j++)
    {
        if(j == 0)
            printf("/");
        else
        {
            if (j == nb_colonnes - 1)
                printf("\\");
            else
                printf("|");
        }
        for(int i = 0; i < nb_lignes; i++)
            printf(" %2d  ", M[i][j]);
        if (j == nb_colonnes -1)
            printf("/\n");
        else
        {
             if (j == 0)
                printf("\\\n");
            else
                printf("|\n");
        }
    }
}



void main() {
    int matrice[nb_lignes][nb_colonnes];
    for(int i = 0; i < nb_lignes; i++) {
        for(int j = 0; j < nb_colonnes; j++) {
            scanf("%d", &matrice[i][j]);
        }
    }
    printf("\nLa transposée de la matrice donne : \n");
    Transposee(matrice);
}
