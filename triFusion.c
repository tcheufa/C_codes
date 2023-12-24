#include <stdio.h>
#include <stdlib.h>

void tri_par_fusion (int[], int);
int **division(int[], int);
void fusion(int[], int[]);


int main()
{
    int **T;
    int tda[5] = {10, 11, 12, 13, 14};
    T = division(tda, 5);
    for (int i = 0; i < 5; i++)
        printf("%d ", *T[i]);
    return 0;
}


void tri_par_fusion (int T[], int taille)
{
    if (taille != 2)
    {
        int moitie = taille / 2;
        int T1[moitie], T2[taille-moitie];
        for (unsigned i = 0; i < moitie; i++)
        {
            T1[i] = T[i];
            T2[i] = T[taille - i - 1];
        }
        tri_par_fusion(T1, moitie);
        tri_par_fusion(T2, taille - moitie);
    }
    else
    {
        ;
    }
}


int **division(int T[], int taille)
{
    static int **Tabs;
    Tabs = (int*) malloc(taille * sizeof(int*));
    for (int i = 0; i < taille; i++)
    {
        Tabs[i] = &T[i];
        *Tabs[i] = T[i];
    }
    return Tabs;
}


void fusion (int T1[], int T2[], int taille1, int taille2, int taillefin)
{
    static int *Tfus;
    *Tfus = (int*) malloc((taille1 + taille2) * sizeof(int));

}

