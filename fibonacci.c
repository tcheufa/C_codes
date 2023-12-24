#include <stdio.h>
int main(void)
{
    unsigned m, N, a = 2, b = 2;
    printf(" _____________________\n\n"
           " La suite de Fibonacci\n"
           " _____________________\n\n"
           "Entrer un nombre de mois: ");
    if (scanf("%u", &m) != 1)
        printf("Vous avez entrée une valeur incorrecte.\n");

    if (m > 2)
    {
        for (unsigned i = 3; i <= m; i++)
        {
            N = a + b;
            b = a;
            a = N;
        }
    }
    printf("\nAu mois %u il y a %u couples de lapins:\nF(%u) = %u\n", m, N/2, m, N);
    return 0;
}
