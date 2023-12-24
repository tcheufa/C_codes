#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char matricule[20];
    char nom[20];
    char prenom[20];
    char genre;
    float moyenne;
} Etudiant;


typedef struct {
    Etudiant etudiant;
    struct Liste * suiv;
} Liste;


Liste * creerListe () {
    Liste * nouveau = (Liste *) malloc (sizeof(Liste));
    nouveau->suiv = NULL;
    return nouveau;
}

void creerEtudiant (Liste * L) {

    /// Enregistrement du nouvel étudiant

    Etudiant e;
    printf("Nouvel Étudiant : \n");
    printf("Matricule : ");
    scanf("%s", e.matricule);
    printf("Nom : ");
    scanf("%s", e.nom);
    printf("Prénom: ");
    scanf("%s", e.prenom);
    printf("Genre : ");
    scanf(" %c", &e.genre);
    printf("Moyenne : ");
    scanf("%f", &e.moyenne);


    /// Déplacement du pointeur jusqu'au dernier élément de la liste

    while (L->suiv != NULL) {
        L = L->suiv;
    }

    /// Affectation de la valeur

    L->etudiant = e;

    /// Création d'un nouvel élément vide pour une prochaine insertion

    L->suiv = creerListe();
    L = L->suiv;
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
        printf(" M: %s\n N: %s\n P: %s\n G: %c\n M: %f\n\n", L->etudiant.matricule, L->etudiant.nom, L->etudiant.prenom, L->etudiant.genre, L->etudiant.moyenne);
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
