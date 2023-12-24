#include <stdio.h>

typedef struct {
    char nom[15];
    int notes[2];
} Etudiant;


void Tri_fusion (Etudiant* e, int, int);
void fusion(Etudiant* e, int, int, int);


int main()
{

    Etudiant E[4];

    printf("%s", E[0]); //A titre experimental (assez etrange cela dit)

    int i, j;

    printf("Veuillez remplir les informations suivantes \n\n");
    for (i = 0; i < 4; i++)
    {
        printf("\nEtudiant %d\n", i + 1);
        printf("Entrer le nom de l'Etudiant : ");
        scanf("%s", &E[i].nom);
        for (j = 0; j < 2; j++)
        {
            printf("Entrer la %d%s note : ", j + 1, (j == 0) ? "ere" : "e");
            scanf("%d", &E[i].notes[j]);
        }
        printf("Enregistrement reussi\n");
    }


    //tri selon la plus grande note

    Tri_fusion(E, 0, 3);

    // Affichage des enregistrements effectues

    printf("\nVoici les resultat final : \n\n");
    for (i = 0; i < 4; i++)
    {
        printf("Nom : %s\n", E[i].nom);
        for (j = 0; j < 2; j++)
        {
            printf("note %d : %d\n", j + 1, E[i].notes[j]);
        }
        printf("\n");
    }

    return 0;
}


void Tri_fusion (Etudiant* e, int debut, int fin)
{
    if (debut < fin)
    {
        int milieu = (debut + fin) / 2;
        Tri_fusion(e, debut, milieu);
        Tri_fusion(e, milieu + 1, fin);
        fusion(e, debut, fin, 0);
    }
}

void fusion(Etudiant* e, int debut, int fin, int numNote)
{
    Etudiant tab[fin - debut + 1];
    int milieu = (debut + fin) / 2;
    int i1 = debut, i2 = milieu + 1, i = 0;
    while (i1 <= milieu && i2 <= fin)
    {
        if (e[i1].notes[numNote] > e[i2].notes[numNote])
        {
            tab[i] = e[i1];
            i1++;
        }
        else
        {
            tab[i] = e[i2];
            i2++;
        }
        i++;
    }
    while (i1 <= milieu)
    {
        tab[i] = e[i1];
        i1++;
    }
    while (i2 <= fin)
    {
        tab[i] = e[i2];
        i2++;
    }
    for (i = 0; i < fin - debut; i++)
        e[debut + i] = tab[i];
}
