#include <stdio.h>
#include <stdlib.h>

void tri_fusion(int tab[], int debut, int fin);
void fusion(int tab[], int debut, int fin);

int main()
{
    int Tab[8] = {8, 3, 1, 4, 5, 6, 10, 2};
    printf("\nTableau non trie:\n");
    for (int i = 0; i < 8; i++) printf("%d ", Tab[i]);
    printf("\nLe tableau trie donne:\n");
    tri_fusion(Tab, 0, 7);
    for (int i = 0; i < 8; i++) printf("%d ", Tab[i]);
}


void tri_fusion(int tab[], int debut, int fin)
{
    if(debut < fin)
    {
        int milieu = (debut + fin) / 2;
        tri_fusion(tab, debut, milieu);
        tri_fusion(tab, milieu+1, fin);
        fusion(tab, debut, fin);
    }
}


void fusion(int tab[], int debut, int fin)
{
    int tabsup[fin-debut+1];
    int milieu = (debut + fin) / 2;
    int i1 = debut;
    int i2 = milieu + 1;
    int k = 0;

    while(i1 <= milieu && i2 <= fin)
    {
        if (tab[i1] < tab[i2])
        {
            tabsup[k] = tab[i1];
            i1++;
        }
        else
        {
            tabsup[k] = tab[i2];
            i2++;
        }
        k++;
    }
    while(i1 <= milieu)
    {
        tabsup[k] = tab[i1];
        i1++;
        k++;
    }
    while(i2 <= fin)
    {
        tabsup[k] = tab[i2];
        i2++;
        k++;
    }

    for(k = 0; k <= fin - debut; k++)
    {
        tab[debut + k] = tabsup[k];
    }
}
