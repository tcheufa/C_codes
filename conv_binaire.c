#include <stdio.h>

//Fonction qui retourne la conversion en base 2 d'un nombre decimal
int conv_bin(int N);


///TODO : Gestion des nombres des décimaux et des nombres négatif en complément de 2

int main(void)
{
    int dec;
    printf("Entrer un nombre entier: ");
    scanf("%d", &dec);
    printf("%d s'ecrit en base 2 comme suit: \n%d", dec, ((dec < 0) ? -1 : 1) * conv_bin(dec));
}

int conv_bin(int N)
{
    int tab[100];
    int i = 0, res = 0;
    if (N < 2 && N >= 0)
        return N;
    else
    {
        //Divisions successives de N

        while(N != 0)
        {
            tab[i] = (N % 2 == 0) ? 0 : 1;
            N = N / 2;
            i++;
        }

        //L'on genere le resultat sous forme entiere

        for(int j = i - 1; j >= 0; j--)
            res = (tab[j] + res) * 10;
        return res / 10;
    }
}
