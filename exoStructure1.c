#include <stdio.h>
#define nb_notes 2
#define nb_etudiants 2

//declaration de la structure note
struct note {
    char matiere[20];
    float valeur;
};

// declaration de la structure etudiant
struct etudiant {
    char matricule[10];
    char nom[50];
    int age;
    char classe[10];
    struct note notes[nb_notes];
};

//Fonction d'enregistrement d'une note
struct note Retourner_Note() {
    struct note n;
    printf("\tEntrer le nom de la matiere : ");
    scanf(" %s", &n.matiere);
    printf("\tEntrer la valeur : ");
    scanf(" %f", &n.valeur);
    return n;
}

//Fonction d'enregistrement des etudiants
struct etudiant Enregistr_Etud()
{
    struct etudiant e;
    printf("\tEntrer le matricule de l'etudiant: ");
    scanf(" %s", &e.matricule);
    printf("\tEntrer le nom de l'etudiant : ");
    scanf(" %s", &e.nom);
    printf("\tEntrer l'age de l'etudiant : ");
    scanf("%d", &e.age);
    printf("\tEntrer la classe de l'etudiant : ");
    scanf(" %s", &e.classe);
    printf("\n\tVeuillez entrer les informations relatives aux notes\n");

    for(int i = 0; i < nb_notes; i++)
    {
        printf("++Note %d++\n", i+1);
        e.notes[i] = Retourner_Note();
    }
    return e;
}

//Fonction qui retourne le plus jeune des etudiants
struct etudiant PlusJeune(struct etudiant e[]) {
    int agemin = e[0].age;
    int idx_pp;
    for(int i = 1; i < nb_etudiants; i++)
    {
        if (agemin > e[i].age)
        {
            agemin = e[i].age;
            idx_pp = i;
        }
    }
    return e[idx_pp];
}

//Fonction qui retourne la moyenne
float Moyenne(struct note n[])
{
    float moy = 0.0;
    for(int i = 0; i < nb_notes; i++)
        moy = (moy + n[i].valeur);
    return moy / nb_notes;
}

int main()
{

//declaration d'un tableau de 5 etudiants
    struct etudiant etudiants[nb_etudiants];

    printf("\n*****PROGRAMME DE GESTION DES ETUDIANTS ET DE LEURS NOTES*****\n\n");

    printf("Entrer les informations relatives aux etudiants :\n");
    for (int i = 0; i < nb_etudiants; i++)
    {
        printf("\n-Etudiant %d-\n", i+1);
        etudiants[i] = Enregistr_Etud();
    }
    printf("\n---AffichaJge des resultats---\n");

    for(int i = 0; i < nb_etudiants; i++)
        printf("\nLa moyenne de l'etudiant %s est : %f", etudiants[i].nom, Moyenne(etudiants[i].notes));

    struct etudiant plusJeune = PlusJeune(etudiants);
    printf("\n\nL'Etudiant le plus jeune possede les caracteristiques suivantes :\n\n");
    printf("\tMATRICULE : %s", PlusJeune(etudiants).matricule);
    printf("\n\tNOM : %s", plusJeune.nom);
    printf("\n\tAGE : %d", plusJeune.age);
    printf("\n\tCLASSE : %s\n", plusJeune.classe);


    return 0;
}


