#include <stdio.h>
#include <stdlib.h>

typedef struct element;
typedef struct element* llist;

struct element {
    int val;
    llist nxt;
} element;


llist ajouterEnTete(llist, int);
void afficherListe(llist);

int main(int argc, char **argv)
{
    struct element* ma_liste;
    ma_liste = ajouterEnTete(ma_liste, 12);
    ma_liste = ajouterEnTete(ma_liste, 11);
    ma_liste = ajouterEnTete(ma_liste, 10);
    afficherListe(ma_liste);
    return 0;
}


llist ajouterEnTete(llist l, int val)
{
    if (l == NULL)
        return NULL;
    else
    {
        llist nouv = malloc(sizeof(element));
        nouv->nxt = l;
        nouv->val = val;
        return nouv;
    }
}

void afficherListe(llist l)
{
    llist tmp = l;
    while (tmp != NULL)
    {
        printf("%d ", tmp->val);
        tmp = tmp->nxt;
    }
}
