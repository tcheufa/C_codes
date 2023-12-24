#include <stdio.h>
#include <stdlib.h>

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

typedef struct Note {
    char matiere[20];
    float valeur;
}Note;

typedef struct Etudiant {
    char nom[50];
    Note notes[3];
    float moyenne;
    int rang;
}Etudiant;

float Moyenne(Note n[])
{
    float moy = 0.0;
    for(int i = 0; i < 3; i++){
        moy += n[i].valeur;
    }
    return moy / 3;
}

int Rang(Etudiant E[], Etudiant e)
{
    int r = 1;
    for(int i = 0; i < 3; i++){
        if(e.moyenne < E[i].moyenne) {
            r++;
        }
    }
    return r;
}

Etudiant Enregistr_Notes(Etudiant e)
{
    for(int i = 0; i < 3; i++){
        printf("Entrer le nom de la matiere : ", i);
        scanf("%s", &e.notes[i].matiere);
        printf("Entrer la valeur de la note de %s: ", e.notes[i].matiere);
        scanf("%f", &e.notes[i].valeur);
    }
    return e;
}

Etudiant Enregistr_Etudiant()
{
    Etudiant e;
    printf("Entrer le nom de l'etudiant : ");
    scanf(" %s", &e.nom);
    printf("\nVeuillez entrer les informations relatives aux notes de %s\n", e.nom);
    e = Enregistr_Notes(e);
    return e;
}


//void bulespace(FILE *b){fputs("\t", b);}

//void bulligne(FILE *b){fputs("\n", b);}

int main()
{
    printf("***AFFICHAGE D'UN BULLETIN DE NOTES***");

    Etudiant etudiants[3];

    FILE *bul = fopen("Bulletin.txt", "w+");if(bul==NULL){printf("erreurrrr");}
    fputs("RELEVE DE NOTES", bul);
    fputs("\n\n", bul);

    for(int i = 0; i < 3; i++) {
        printf("\n\nEntrer les informations relatives %c l'%ctudiant %d :\n", 133, 130, i + 1);
        etudiants[i] = Enregistr_Etudiant();
        FILE *f = fopen("releve.txt", "a+");
        fwrite(&etudiants[i], sizeof(Etudiant), 2, f);
        fclose(f);
    }
    //bulespace(bul);
    fputs("\n", bul);
    //bulligne(bul);
    char a[3];
    for(int i = 0; i < 3; i++) {
        fputs("Etudiant ", bul);
        fputs(itoa(i+1, a, 4), bul);
        fputs(":  ", bul);
        fputs(etudiants[i].nom, bul);
        fputs("\n", bul);
        for(int j = 0; j < 3; j++){
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
    }
    fclose(bul);

    return 0;
}
