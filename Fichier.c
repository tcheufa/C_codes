#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    typedef struct Personne{
       char nom[50];
       char age[3];
    } Personne;
    FILE *f = fopen("test.txt", "a+");
    /*Ecriture sur un fichier
    char a[100];
    gets(a);
    fputs(a, f);
    fputc('\n', f);
    gets(a);
    fputs(a, f);
    fputc('\n', f);
    */
    /*Affichage caractere par caractere
    char c;
    while((c = getc(f)) != EOF) {
        printf("%c", c);
    }
    */
    Personne A = {.nom = "DiZ", .age = "30"};
    fwrite(&A, sizeof(Personne), 2, f);
    fclose(f);
    FILE *t = fopen("test.txt", "a+");
    while (fread(&A, sizeof(Personne),2, f))
        printf("\n%s %s", A.nom, A.age);
    fclose(t);
    return 0;
}
