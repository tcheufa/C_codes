//Bon Projet très important:
//TODO: Réaliser un programme qui permet de passer de la Majuscule à la Minuscule et inversement.
//TODO: Le programme doit aussi pouvoir faire la capitalisation.

///TODO???
///UN PROGRAMME DE FORMATTAGE DE TEXTE DANS UN LANGAGE DE PROGRAMMATION COMME LE C.
/// LE PROGRAMME DOIT ALLÉGER LA TAILLE DU CODE SOURCE EN ENLEVANT TOUT RETOUR À LA LIGNE, ESPACE ET ALINÉAS SUPERFLUS.
/// DANS L'ESPOIR QUE CELA OPTIMISERA LE PROCESSUS DE COMPILATION.

#include <stdio.h>
#include <stdlib.h>

void Capitalize(char *s);
void Minimize(char *s);
void toUpper(char *s);
void toLower(char *s);

int main(void)
{
    char chaine[] = "henry avec un H majuscule j'ai dit!";
    toUpper(chaine);
    printf("%s", chaine);
    return EXIT_SUCCESS;
}

void Capitalize(char *s)
{
    if ('z' - *s < 26 && 'z' - *s >= 0)
        *s -= ('a' - 'A');
}

void Minimize(char *s)
{
    if ('Z' - *s < 26 && 'Z' - *s >= 0)
        *s += ('a' - 'A');
}

void toUpper(char *s)
{
    for (char *u = s; *u != '\0'; ++u)
        Capitalize(u);
}

void toLower(char *s)
{
    for (char *u = s; *u != '\0'; ++u)
        Minimize(u);
}
