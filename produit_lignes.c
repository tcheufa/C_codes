#include <stdio.h>

int sommeTab_1dim (unsigned, int *);
int produit_lignes (unsigned N, unsigned M, int (*)[]);

int main (void)
{
    int tableau[4][3] = {
                            {1, 2, 3},
                            {4, 5, 6},
                            {7, 8, 9},
                            {10, 11, 12}
                        };
    printf ("produit = %d", produit_lignes(4, 3, tableau));
}


int produit_lignes(unsigned N, unsigned M, int (*tab)[M])
{
    int produit = 1;
    for (size_t i = 0; i < N; i++)
        produit *= sommeTab_1dim (M, tab[i]);
    return produit;
}


int sommeTab_1dim (unsigned N, int *tab)
{
    int somme = 0;
    for (size_t i = 0; i < N; i++)
    {
        printf(" %d ", tab[i]);
        somme += tab[i];
    }
    printf("\n");
    return somme;
}
