#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define nb_etud 2
#define nb_notes 2

//TODO: Definition et Remplissage par defaut des notes
/*void Def_matieres(struct Note n[])
{
    char mat[20];
    for (int i = 0; i < nb_notes; i++) {
        printf("Entrer le nom de la matiere pour la note %d", i);
        scanf("%s", &n[i].matiere);
    }
    printf("Remplissage termine\n");
}
*/

//definition de la structure Note

typedef struct Note {
    char matiere[20];
    int coef;
    float valeur;
}Note;

//definition de la structure Etudiant

typedef struct Etudiant {
    char matricule[20];
    char nom[50];
    float moyenne;
    int rang;
    Note notes[nb_notes];
}Etudiant;

//Fonction qui retourne la moyenne des notes

float Moyenne(Note n[])
{
    float moy = 0.0;
    int ttcoef = 0;
    for(int i = 0; i < nb_notes; i++){
        moy += n[i].valeur * n[i].coef;
        ttcoef += n[i].coef;
    }
    return moy / ttcoef;
}

//Fonction qui retourne le rang de l'etudiant
//ALERTE!!! La fonction rang ne reconnait pas les ex aequo
int Rang(Etudiant E[], Etudiant e)
{
    int r = 1;
    for(int j = 0; j < nb_etud; j++){
        if(e.moyenne < E[j].moyenne) {
            r++;
        }
    }
    return r;
}

//Fonction qui enregistre et retourne une note d'un etudiant
Note Retourner_Note()
{
    Note n;
    printf("Entrer le nom de la matiere : ");
    scanf("%s", n.matiere);
    printf("Entrer le coefficient de la matiere : ");
    scanf("%d", &n.coef);
    printf("Entrer la valeur de la note : ");
    scanf("%f", &n.valeur);
    return n;
}

//Ponction qui enregistre et retourne un etudiant
Etudiant Enregistr_Etudiant()
{
    Etudiant e;
    printf("Entrer le nom de l'etudiant : ");
    scanf(" %s", e.nom);
    printf("\nVeuillez entrer les informations relatives aux notes de %s\n", e.nom);
    for(int i = 0; i < nb_etud; i++){
        e.notes[i] = Retourner_Note();
    }
    return e;
}


void bulespace(FILE *b)
{
    fputs("\t", b);
}

void bulligne(FILE *b)
{
    fputs("\n", b);
}

int main()
{
    printf("***AFFICHAGE D'UN BULLETIN DE NOTES***");
    Etudiant etudiants[nb_etud];

    for(int i = 0; i < nb_etud; i++)
    {
        printf("\n\nEntrer les informations relatives %c l'%ctudiant %d :\n", 133, 130, i + 1);
        etudiants[i] = Enregistr_Etudiant();
    }
    char a[3];
    for(int i = 0; i < nb_etud; i++)
    {
        char fichier[50] = "Bulletin";
        strcat(fichier, itoa(i, a, 10)); // le dernier parametre est le systeme de numeration dans lequel il faut convertir le nombre au prealable avant de le transformer en chaine de caracteres.
        strcat(fichier, ".txt");
        FILE *bul = fopen(fichier, "w+");
        fputs("RELEVE DE NOTES", bul);
        fputs("\n\n", bul);
        fputs("Etudiant ", bul);
        fputs(itoa(i+1, a, 4), bul);
        fputs(":  ", bul);
        fputs(etudiants[i].nom, bul);
        fputs("\n", bul);
        for(int j = 0; j < nb_notes; j++)
        {
            fputs(etudiants[i].notes[j].matiere, bul);
            fputs(":  ", bul);
            fprintf(bul, "%f", etudiants[i].notes[j].valeur);
            fputs("\n", bul);
            //bulespace(bul);
        }
        fputs("MOYENNE: ", bul);
        etudiants[i].moyenne = Moyenne(etudiants[i].notes);
        fprintf(bul, "%f", etudiants[i].moyenne);
        fputs("\n", bul);
        fputs("RANG: ", bul);
        etudiants[i].rang = Rang(etudiants, etudiants[i]);
        fprintf(bul, "%d", etudiants[i].rang);
        //bulespace(bul);
        fputs("\n\n", bul);
        fclose(bul);
    }
    return 0;
}
