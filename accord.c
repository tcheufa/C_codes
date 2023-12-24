#include <stdio.h>
#include <stdlib.h>




int main()
{
    typedef struct {
        char* nom;
        int notes[2];
    } Etudiant;
    
    Etudiant E[4];
    int i, j;
    for (i = 0; i < 4; i++)
    {
        printf("Entrer le nom de l'Etudiant : ");
        scanf("%s", &E[i].nom);
        for (j = 0; j < 2; j++)
        {
            printf("Entrer la %d%s note : ", i + 1, (i == 0) ? "iere" : "e");
            scanf("%d", &E[i].notes[j]);
        }
        E
    }
}