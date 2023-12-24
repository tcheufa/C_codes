#include <stdio.h>
#include <string.h>

int existe (char *str, char val)
{
    for (size_t t = 0; str[t] != '\0'; t++)
        if (str[t] == val)
            return 1;
    return 0;
}


int nbVoyelles (char* str) {

    _Bool estVoyelle(char c)
    {
        switch(c) {
            case 'A':
            case 'a':
            case 'E':
            case 'e':
            case 'I':
            case 'i':
            case 'O':
            case 'o':
            case 'U':
            case 'u':
                return 1;
                break;
            default:
                /*do nothing*/;
                break;
        }
        return 0;
    };

//    _Bool (*estVoyelle)(char) = f;

    int nb = 0;
    for(size_t t = 0; str[t] != '\0'; t++) {
        if (str[t] == 'y' || str[t] == 'Y') {
            if (t > 0 && !estVoyelle(str[t-1])) {
                nb++;
            }
        }
        else if (estVoyelle(str[t])) {
            nb++;
        }
    }
    return nb;
}


int nbChiffres (int n)
{
    int nb = 0;
    while(n > 0) {
        n /= 10;
        nb++;
    }
    return nb;
}

int input(char *msg, int* p) {
    printf("%s", msg);
    return scanf("%d", p);
}

int main (void)
{
//    char *chaine = "Banjoury";
//    printf("\n%d\n", existe(chaine, 'i'));
//    char chaine2[45] = " fdsffef ef f";
//    printf("\n%d\n", sizeof chaine2);
//    printf("Nombre de voyelles dans `%s` = %d", chaine, nbVoyelles(chaine));
//
//    int nb = 0;
//    int n;
//    int n2;
//
//    input("Entrer un nombre positif : ", &n);
//
//    n2 = n;
//    while(n2 > 0) {
//        n2 /= 10;
//        nb++;
//    }
//    printf("Le nombre chiffres de %d = %d", n, nbChiffres(n));

    unsigned int h1, h2, min1, min2;
    unsigned int h, min;

    while (1) {
        printf("\nOpération (h:min +/- h:min): ");

        scanf("%d : %d + %d : %d", &h1, &min1, &h2, &min2);

        if (min1 > 59 || min2 > 59 || h1 > 23 || h2 > 23) {
            printf("Heure non valide.\n");
            continue;
        }

        min = min1 + min2;

        h = h1 + h2;

        if (min > 59) {
            min -= 60;
            h++;
        }

        if (h > 23) {
            h -= 24;
        }

        printf("Il est désormais %d:%c%d.", h, (min < 10) ? '0' : '\0', min);
    }
    return 0;
}
