#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nom[50], code[50], nomMagasin[50];
    unsigned int prix;
} Produit;

struct Liste;
typedef struct {
    Produit * produit;
    struct Liste * suivant;
} Liste;

void ajouterListe (Liste *L, Produit nouv);
Liste * creerListe (Produit * nouv);
void afficherProduit(Produit * p);

int main (void)
{

    Liste * L = creerListe(&(Produit){"Banane", "ABJDE74R", "SUNU Babana", 500});
    afficherProduit(L->produit);
    return 0;
}


void ajouterListe (Liste * L, Produit nouv)
{
    Produit* n = (Produit *) malloc(sizeof(Produit));
    *n = nouv;

    while (L->suivant != NULL) {
        L = (Liste *) L->suivant;
    }
}

Liste * creerListe (Produit * nouv)
{
    Liste * L =  (Liste *) malloc(sizeof(Liste));
    L->produit = nouv;
    return L;
}


void afficherProduit(Produit * p)
{
    printf("Nom: %s\tCode: %s\tNomMagasin: %s", p->nom, p->code, p->nomMagasin);
}
