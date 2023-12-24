#include <stdio.h>

unsigned long long ppcm(unsigned long long a, unsigned long long b) {
    if (a % b == 1)
        return a * b;
    else
    {
        unsigned long long a2 = a, b2 = b, r;
        do
        {
            r = b2;
            b2 = a2 % b2;
            a2 = r;
        }
        while (b2 != 0);
        return (a * b) / a2;
    }
}

void main(void)
{
    unsigned long long n1, n2;
    printf("Entrer le nombre 1: ");
    scanf("%llu", &n1);
    printf("Entrer le nombre 2: ");
    scanf("%llu", &n2);
    printf("Le plus petit multiple commun a %llu et a %llu est : %llu", n1, n2, ppcm(n1,n2)); // erreur lors de l'affichage de ppcm trop grands
}

