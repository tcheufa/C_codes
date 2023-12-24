#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int myScanf(char[]);

int MyReadLn (char *s, size_t max);
_Bool estPalindrome (char *, size_t len);
_Bool estPalindrome2 (char *, size_t len);
int verifierParentheses (char*);

int main (void)
{
    //declaration de notre chaîne de caractères
    char tab[50];
    int len;
    if ((len = MyReadLn(tab, 50)) == 0)
        printf("Vous avez depasse la capacite maximale de saisie\nLes caracteres depassant la limite ne seront pas recuperes :\n");
//    if (estPalindrome2(tab, len))
//        printf("%s est un palindrome", tab);
//    else
//        printf("%s n'est pas un palindrome", tab);

        len = verifierParentheses(tab);
        len = (len < 0) ? -len : len;
        char plur = (len > 1 || len < -1) ? 's' : '\a';
        printf("Il manque %d parenthese%c %s%c", len, plur, (len < 0) ? "ouvrante" : "fermante", plur);

    return EXIT_SUCCESS;
}


int MyReadLn (char *s, size_t max)
{
    //compteur qui servira à indexer un élément du tableau de caractères

    int i = -1;

    //lecture de la saisie de l'utilisateur tant qu'il n'a pas appuyé sur Entrée

    do
    {
        i++;
        if (scanf("%c", &s[i]) != 1)
            return 0;
    }
    while (s[i] != '\n' && i < max);

    //on remplace le caractère '\n' qui a été enregistré par le caractère nul '\0'
    s[i] = '\0';

    return i;
}

_Bool estPalindrome (char *s, size_t len) {
    for (int i = 0; i < len / 2; ++i) {
        if (s[i] != s[len - i - 1])
            return 0;
    }
    return 1;
}

_Bool estPalindrome2 (char *s, size_t len) {

    char cpy[len];

    int i, k = 0;
    for (i = 0; i < len; ++i) {

        if (isblank(s[i])) {
            k++;
            continue;
        }
        cpy[i - k] = s[i];
    }

    len = i - k;

    cpy[len+1] = '\0';

    printf("%d %s \n", len, cpy);

    for (int j = 0; j < len / 2; ++j) {
        if (cpy[j] != cpy[len - j - 1])
            return 0;

    }
    return 1;
}

int verifierParentheses(char *s) {
    size_t len = 0;
    int parenth = 0;
    while (s[len] != '\0')
        len++;
    for (int i = 0; i < len; ++i) {
        if (s[i] == '(')
            parenth++;
        if (s[i] == ')')
            parenth--;
    }
    return parenth;
}

int myScanf(char T[]) {
    char ptr[25] = {'%', 'X'};
    //scanf("%s", ptr);
    printf(ptr, 167);
}
