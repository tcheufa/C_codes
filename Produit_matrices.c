#include <stdio.h>
#include <stdlib.h>

void Param_Mat(int li, int col);
void Charger_Tab(int li, int col, int T[li][col]);
void Afficher_Tab(int li, int col,int T[li][col]);
void Init_Tab(int li, int col,int T[li][col]);

int n, n1, p, q ,i , j, k ;

int main(void)
{

        printf("***Multiplication de deux matrices***\nATTENTION !!Si A et B sont des matrices alors A x B n'est pas égal à B x A\n");
        printf("De plus le nombres de colonnes de A doit être egal au nombres de colonnes de B.\n\n");

    //Paramétrage de la matrice A

        printf("*Définition de la première matrice*\n");
        Param_Mat(p, n);

    //Paramétrage de la matrice B

        printf("*Définition de la première matrice*\n");
        Param_Mat(n1, q);

    //verification de l'égslité entre le nombre de colonnes de A et le nombre de colonnes de B

         int A[p][n];
         Charger_Tab(p, n, A);
         int B[n1][q];
         Charger_Tab(n1, q, B);

        //Déclaration et calcul de la matrice produit

        int Produit[p][q];
        Init_Tab(p, q, Produit);

        for( i = 0; i < p-1 ; i++)
            for( j = 0; j < q-1 ; j++)
                for( k = 0; k < n-1 ; k++)
                    Produit[i][j] = Produit[i][j] + A[i][k] * B[i][k];

        Afficher_Tab(p, q, Produit);

        return 0;
}

void Charger_Tab( int li, int col, int T[li][col] ){
    for(i = 0 ; i < li-1 ; i++)
    {
            for(j = 0 ; j < col-1 ; j++)
            {
                    printf("Entrer une valeur :");
                    scanf("%d", &T[i][j]);
            }
    }
}

void Param_Mat(int li, int col)
{
    printf("Entrer le nombre de lignes : ");
    scanf("%d", &li);
    printf("Entrer le nombre de colonnes : ");
    scanf("%d", &col);
}

void Init_Tab(int li, int col,int T[li][col])
{
     for(i = 0 ; i < li-1 ; i++)for(j = 0 ; j < col-1 ; j++) T[i][j] = 0;
}

void Afficher_Tab(int li, int col,int T[li][col])
{
     for(i = 0 ; i < li-1 ; i++){
                  printf("\n");
            for(j = 0 ; j < col-1 ; j++){
                    printf("%d ", T[i][j]);

            }
    }
}
