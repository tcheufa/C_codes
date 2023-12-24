#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Etudiant {
    char matricule[20];
    char nom[20];
    char prenom[20];
    char genre;
    float moyenne;
    struct Etudiant * suiv;
} Etudiant;

typedef struct Etudiant {
    struct Etudiant * debut;
    struct Etudiant * fin;
} Liste;


Liste * creerListe () {
    Liste * nouveau = (Liste *) malloc (sizeof(Liste));
    nouveau->debut = NULL;
    nouveau->fin = NULL;
    return nouveau;
}

void creerEtudiant (Liste * L) {

    Etudiant e;
    printf("Nouvel Étudiant : \n");
    printf("Matricule : ");
    scanf("%S", &e.matricule);
    printf("Nom : ");
    scanf("%S", &e.nom);
    printf("Prénom: ");
    scanf("%S", &e.prenom);
    printf("Genre : ");
    scanf(" %C", &e.genre);
    printf("Moyenne : ");
    scanf("%F", &e.moyenne);


    while (L->suiv != NULL) {
        L = (Liste *) L->suiv;
    }

    L->val = e;
    L->suiv = (struct Liste *) creerListe();
    L = (Liste *) L->suiv;
}


int taille (Liste * L) {
    int taille = 0;
    while (L->suiv != NULL) {
        L = (Liste *) L->suiv;
        taille++;
    }
    return taille;
}

void AfficherEtudiant (Liste * L) {
    while (L->suiv != NULL) {
        printf(" M: %s\n N: %s\n P: %s\n G: %c\n M: %f\n\n", L->val.matricule, L->val.nom, L->val.prenom, L->val.genre, L->val.moyenne);
        L = (Liste *) L->suiv;
    }
}

int main (void) {

    Liste * liste = creerListe();

    char action;

    while (1) {

        printf("\n\n>");
        scanf(" %c", &action);

        switch (action) {
            case 'n':
                creerEtudiant(liste);
                break;
            case 't':
                printf("La taille de la liste est de %d\n", taille(liste));
                break;
            case 'p':
                AfficherEtudiant(liste);
                break;
            case 'q':
                exit(EXIT_SUCCESS);
            default:
                /*Do nothing*/;
        }
    }

    return 0;
}

