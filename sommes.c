#include <stdio.h>

void vider_stdin(void) {
    int c;

    do {
        c = fgetc(stdin);
    }
    while (c != '\n' && c != EOF);

    if (ferror(stdin)) {
        perror("Echec lors du vidage de tampon:");
    }
}

char buf[255];

void exo1 (void);
void exo2 (void);
void exo3 (void);

int main (void) {
    exo1();
    exo2();
    exo3();
    exo4();

    return 0;
}


void exo1 (void) {
    int n;
    unsigned s;
    printf("Ecrire une programme qui affiche la somme des n premiers entiers naturels. La valeur de n est saisie au clavier lors de l’exécution.\n>");
    while ( 1 != scanf("%d", &n) || n <= 0 ) {
        printf("Veuillez entrer un nombre entier naturel non nul \n>");
        vider_stdin();
    }

    s = 0;
    for (int i = 1; i < n; i++)
        s = s + i;

    printf("La somme des %d premiers nombres entiers naturels est %u\n\n", n, s);
}


void exo2 (void) {
    int d, f;
    unsigned s;

    printf("Ecrire un programme qui affiche la somme des entiers compris entre les entiers d et f . Les valeurs de d et f sont saisies au clavier lors de l’exécution.\n>");

    while (1) {
        while ( 1 != scanf("%d", &d) || d < 0 ) {
            printf("Veuillez entrer un nombre entier naturel\n>");
            vider_stdin();
        }

        printf(">");
        while ( 1 != scanf("%d", &f) || f < 0 ) {
            printf("Veuillez entrer un nombre entier naturel\n>");
            vider_stdin();
        }

        if (d < f)
            break;

        printf("%d ne doit pas être supérieur ou égal à %d\n>", d, f);
    }

    printf("La somme des nombres entiers naturels compris entre %d et %d est ", d, f);

    for (s = d; d < f; d++)
        s = s + d + 1;

    printf("%u\n\n", s);
}



void exo3 (void) {
    int d, f;
    unsigned s;

    printf("Ecrire une programme qui affiche la somme des valeurs absolues des entiers compris entre les entiers relatifs d et f . Les valeurs de d et f sont saisies au clavier lors de l’exécution.\n>");


    while (1) {
        while ( 1 != scanf("%d", &d) ) {
            printf("Veuillez entrer un nombre entier relatif\n>");
            vider_stdin();
        }

        printf(">");
        while ( 1 != scanf("%d", &f) ) {
            printf("Veuillez entrer un nombre entier relatif\n>");
            vider_stdin();
        }

        if (d < f)
            break;

        printf("%u ne doit pas être supérieur ou égal à %u\n>", d, f);
    }

    printf("La somme des nombres entiers compris entre %d et %d est ", d, f);

    for (s = d; d < f; d++)
        s = s + (d < 0 ? -d : d) + 1;

    printf("%u\n\n", s);
}


void exo4 (void) {
    int d, f;
    unsigned s;

    printf("Ecrire une programme qui affiche la somme des valeurs absolues des entiers pairs compris entre les entiers relatifs d et f . Les valeurs de d et f sont saisies au clavier lors de l’exécution.\n>");

    while (1) {
        while ( 1 != scanf("%d", &d) ) {
            printf("Veuillez entrer un nombre entier relatif\n>");
            vider_stdin();
        }

        printf(">");
        while ( 1 != scanf("%d", &f) ) {
            printf("Veuillez entrer un nombre entier relatif\n>");
            vider_stdin();
        }

        if (d < f)
            break;

        printf("%u ne doit pas être supérieur ou égal à %u\n>", d, f);
    }

    printf("La somme des nombres entiers pairs compris entre %d et %d est ", d, f);

    for (s = 0; d <= f; d++)
        if (d % 2 == 0)
            s = s + (d < 0 ? -d : d);

    printf("%u\n\n", s);
}
