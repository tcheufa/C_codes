#include <stdio.h>
#include <stdlib.h>

struct Etudiant;
struct Note;

typedef struct {
    char matiere[50];
    float note;
    struct Note * suiv;
} Note;

typedef struct {
    char nom[50];
    char matricule[50];
    Note * listeNotes;
    struct Etudiant * suiv;
} Etudiant;

typedef struct {
    Etudiant * premier;
} ListeEtud;

void ajouterEtud (ListeEtud * L, unsigned int position, Etudiant n)
{
    Etudiant * p = L->premier;
    Etudiant * nouv = (Etudiant*) malloc(sizeof(Etudiant));
    *nouv = n;
    for (; position > 0 && p->suiv != NULL; position--, p = p->suiv);

    nouv->suiv = p->suiv;
    p->suiv = nouv;
}

void enleverEtud (ListeEtud * L, unsigned int position)
{
    Etudiant * p = L->premier;
    Etudiant * prec = NULL;

    if (position == 0) {
        L->premier = p->suiv;
        free(p);
        return;
    }

    for (unsigned int i = 0; i < position && p->suiv != NULL; i++, prec = p, p = p->suiv);

    prec->suiv = p->suiv;
    free(p);
}

void viderListe (ListeEtud * L)
{
    if (L->premier == NULL) return;

    for(Etudiant * p = L->premier, * suivant = NULL; p != NULL; suivant = p->suiv, free(p), p = suivant);

    L->premier = NULL;
}

void afficherListe (ListeEtud * L)
{
    if (L->premier == NULL) return;

    for (Etudiant * p = L->premier; p != NULL; p = p->suiv) {
        printf("Nom : %s\nMatricule: %s\n\n", p->nom, p->matricule);
    }
}

int main (void)
{
    ListeEtud L;
    Etudiant * prems = malloc(sizeof(Etudiant));
    *prems = (Etudiant){"Yohan", "IUC21E0070543", NULL, NULL};
    Etudiant sec = {"Habib", "IUC45E9553", NULL, NULL};
    L.premier = prems;
    ajouterEtud(&L, 10, sec);
    ajouterEtud(&L, 1, (Etudiant){"Magni", "IUC21E007998", NULL, NULL});
    viderListe(&L);
//    L.premier = malloc(sizeof(Etudiant));
    afficherListe(&L);
    return 0;
}
