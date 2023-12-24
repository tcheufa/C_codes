#include <stdio.h>
#include <stdlib.h>

struct Etudiant;

typedef struct {
    char nom[15];
    int notes[2];
    struct Etudiant* next;

} Etudiant;

Etudiant* NouvelEtudiant();                             /// Retourne l'adresse vers un nouvel Etudiant
int TailleChaine(Etudiant*);                            /// Retourne le nombre de structures de la liste chaînée
void AfficherEtudiants();                               /// Afficher les informations de tous les Etudiants
Etudiant* tri_selection_chainee_par_note(Etudiant*);    /// Effectue le tri croissant des Etudiants selon leur note et retourne l'adresse vers le premier élément\
                                                        la nouvelle liste
void trierParSelection2p0(Etudiant*);

int main()
{

    Etudiant *E = (Etudiant*) malloc(sizeof(Etudiant));
    Etudiant *tmp = NULL;

    int i, j, n;

/// Détermination du nombre de boucles d'enregistrements

    printf("Combien d'etudiants ? \n");
    scanf("%d", &n);
/// Enregistrement

    printf("Veuillez remplir les informations suivantes \n\n");
    E = NouvelEtudiant();
    tmp = E;

    for (i = 0; i < n-1; i++)
    {
       tmp->next = NouvelEtudiant();
       tmp = tmp->next;
    }
    tmp->next = NULL;


///TEST !!!

//    snprintf(E->nom, 15, "%s", "E1");
//    E->notes[0] = 1;
//    E->notes[1] = 4;
//    E->next = (Etudiant*) malloc(sizeof(Etudiant));
//
//    tmp = E->next;
//
//    snprintf(tmp->nom, 15, "%s", "E2");
//    tmp->notes[0] = 4;
//    tmp->notes[1] = 4;
//    tmp->next = (Etudiant*) malloc(sizeof(Etudiant));
//
//    tmp = tmp->next;
//
//    snprintf(tmp->nom, 15, "%s", "E3");
//    tmp->notes[0] = 14;
//    tmp->notes[1] = 4;
//    tmp->next = NULL;

///  FIN TEST !!

    printf("\nCa fait %d enregistrements en tout\n", TailleChaine(E));

    ///tri selon la plus grande note

    trierParSelection2p0(E);
    tmp = E;
    /// Affichage des enregistrements effectues

    printf("\nVoici les resultat finaux : \n\n");
    AfficherEtudiants(tmp);
    tmp = tmp->next;

    return 0;
}



Etudiant* NouvelEtudiant()
{
    static unsigned compt = 0;
    int j;
    compt++;
    printf("\nEtudiant %u\n", compt);
    Etudiant* nouvE = (Etudiant*) malloc(sizeof(Etudiant));
    printf("Entrer le nom de l'Etudiant : ");
    scanf("%s", nouvE->nom);
    for (j = 0; j < 2; j++)
    {
        printf("Entrer la %d%s note : ", j + 1, (j == 0) ? "ere" : "e");
        scanf("%d", &nouvE->notes[j]);
    }
    if (nouvE != NULL)
        printf("Enregistrement reussi\n");
    else
        printf("Echec de l'enregistrement");

    return nouvE;
 }


int TailleChaine(Etudiant* deb)
{
    int compt = 0;
    Etudiant* p = deb;
    while(p != NULL)
    {
        compt++;
        p = p->next;
    }
    return compt;
}



void AfficherEtudiants (Etudiant* d)
{
    int j;
    while (d != NULL)
    {
        printf("Nom : %s\n", d->nom);
        for (j = 0; j < 2; j++)
        {
            printf("note %d : %d\n", j + 1, d->notes[j]);
        }
        printf("\n");
        d = d->next;
    }
}


Etudiant* tri_selection_chainee_par_note(Etudiant* deb)
{
    Etudiant* debutfinal = deb;     /// Conservera l'état du premier élément de la nouvelle chaîne triée
    Etudiant* min = NULL;           /// Contient le pointeur de l'élément qui a la plus petite note à partir d'un certain niveau de la chaîne
    Etudiant* prev_min = NULL;      /// Contient le pointeur de l'élément situé avant l'élément pointé par min
    Etudiant* tmp = NULL;           /// Permet de se déplacer dans la liste et servira aussi de variable intermédiaire pour les permutations
    Etudiant* prev = NULL;          /// Contient le pointeur de l'élément situé avant l'élément pointé par tmp
    Etudiant* prev_deb = NULL;      /// Contient le pointeur de l'élément situé avant l'élément pointé par deb

    /// Variable pour les vérification liées au pointeur debutfinal

    int i = 0;

    /// Parcours de la chaîne

    while (deb->next != NULL)
    {

    /// Initialisation

        prev_min = NULL;
        prev = deb;
        tmp = deb->next;
        min = deb;

        //printf("\n\ndeb = %s\n", deb->nom);

    /// Parcours pour comparaison avec le deb actuel

        while(tmp != NULL)
        {
            if (tmp->notes[0] < min->notes[0])
            {
                min = tmp;
                if(prev != NULL)
                    prev_min = prev;
            }

//            printf("prev_deb=%s  tmp=%s  prev=%s  prev_min=%s  min=%s\n",
//                (prev_deb == NULL) ? "(null)" : prev_deb->nom,
//                tmp->nom,
//                (prev == NULL) ? "(null)" : prev->nom,
//                (prev_min == NULL) ? "(null)" : prev_min->nom,
//                min->nom
//            );

    /// Mise à jour des variables en vue de la prochaine boucle

            prev = tmp;
            tmp = tmp->next;
        }

    /// debutfinal se voit assigner sa valeur qu'une seule fois

        if (i == 0)
        {
            debutfinal = min;
            i++;
        }

    /// Rien ne se passe si min pointe vers le même etudiant que deb \
            Dans le contraire on effectue les permutations nécessaires

        if (min != deb)
        {
            tmp = deb->next;
            deb->next = min->next;


            if (min == tmp)
                min->next = deb;
            else
                min->next = tmp;

            if (prev_min != NULL)
                if (prev_min != deb)
                    prev_min->next = deb;

        }

    /// Mise à jour des variables en vue de la prochaine boucle

        if (i == 1 && debutfinal->next == deb)
        {
//            printf("\n\nyelllellelle\n\n");
            debutfinal->next = min;
            i++;
        }

    /// Actualisation pour la prochaine boucle

        prev_deb = min;
        deb = min->next;

//        printf("xsuiv = %s\n", tmp->nom);
//        AfficherEtudiants(debutfinal);
    }

    return debutfinal;
}


void trierParSelection2p0(Etudiant* debut)
{
    Etudiant *L = NULL, *T = NULL, *T2 = NULL, *T3 = NULL, *min = NULL, *tmp = NULL, *x = NULL;
    T2 = debut;
    x = L;
    while (T2->next != NULL)
    {
        T = T2;
        T2 = T2->next;
        if (T2->notes[0] < min->notes[0])
        {
            min = T2;
            T3 = T;
        }
        tmp = T3;
        tmp = tmp->next;
        T3->next = tmp->next;
        min->next = L->next;
        L->next = T3->next;
        T3->next = L;
    }

    while (x->next != NULL)
    {
        printf("%s %d", x->nom, x->notes[0]);
    }

}
