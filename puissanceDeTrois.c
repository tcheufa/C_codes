#include <stdio.h>

int main(void)
{
    long int N;
    unsigned exp = 0;
    printf("Entrer un nombre: ");
    scanf("%ld", &N);
    printf("%ld ", N);
    while(N != 1 && N % 3 == 0)
    {
            N /= 3;
            ++exp;
    }
    if (N == 1)
        printf("= 3^%u donc c'est une puissance de 3 ! L'exposant associé est %u", exp, exp);
    else
        printf("n'est pas une puissance de 3");
    return 0;
}
