#include<stdio.h>

int main()
{
    int exp = 0; //Contiendra le nombre de division effectuees pour obtenir un quotient nul ce qui equivaut au nombre de chiffres qu'aura le resultat de la conversion
    int dec; // contiendra le nombre de l'utilisateur qui sera au systme decimal
    int dec2; // contiendra la valeur de dec pour travailler avec afin que le contenu de ce dernier ne disparaisse pas
    int dec3; // contiendra la valeur de dec pour travailler avec.
    int base;   // contiendra la base dans laquelle l'utilisateur veut convertir son nombre

    printf("Entrer un nombre : ");
    scanf("%d", &dec);

    // passage de valeurs
    dec2 = dec;
    dec3 = dec2;

    printf("Veuillez entrer le nombre correspondant a la base ou vous souhaitez afficher votre nombre : ");
    scanf("%d", &base);

    // On effectue une boucle qui va permettre grace a la variable exp de savoir le nombre de fois que l'on effectuera la division
    do
    {
        dec2 = dec2 / base;
        exp++;
    }
    while(dec2 > 0); //On ne s'arrete que lorsque le quotient vaut 0

    // declaration d'un tableau de exp entiers
    int conv[exp];

    // On charge le tableau des unites du nombre resultant dans la base $base
    // L'on procede au chargement dans l'ordre decroissant parce que les chiffres se lisent dans l'ordre inverse de l'apparition des restes de la division de dec
    for(int i = exp - 1; i >= 0; i--)
    {
        conv[i] = dec3 % base;
        dec3 = dec3 / base;
    }

    // Affichage de la conversion
    printf("\n%d dans la base %d est egal a : ", dec, base);
    for(int i = 0; i < exp; i++)
    {
        if(conv[i] < 10)
            printf("%d", conv[i]);
        else //si le chiffre est superieur ou egal a 10 on lui attribue un caractere qui va de A(code 65) jusqu'aaa...
            printf("%c", 65 + (conv[i] - 10));
    }

    // On exploite la valeur de exp pour determiner le nombre de chiffres du nombre resultant de la conversion
    printf("\n\n%d a %d chiffre(s) dans la base %d.\n", dec, exp, base);

    return 0;
}

