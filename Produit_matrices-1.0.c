#include <stdio.h>
#include <stdlib.h>

//void Param_Mat(int li, int col);
//void Charger_Tab(int li, int col, int T[li][col]);
//void Afficher_Tab(int li, int col,int T[li][col]);
//void Init_Tab(int li, int col,int T[li][col]);



int main(){
        int n, n1, p, q ,i , j, k ;
        printf("***Multiplication de deux matrices***\nATTENTION !!Si A et B sont des matrices alors A x B n'est pas égal à B x A\n");
        printf("De plus le nombres de colonnes de A doit être egal au nombres de colonnes de B.\n\n");
                //Paramétrage de la matrice A
        printf("*Définition de la première matrice*\n");
                    //Param_Mat(p, n);
        printf("Entrer le nombre de lignes : ");
        scanf("%d", &p);
        printf("Entrer le nombre de colonnes : ");
        scanf("%d", &n);
        int A[p][n];
         //Charger_Tab(p, n, A);
        for(i = 0 ; i < p ; i++){
            for(j = 0 ; j < n; j++){
                    printf("Entrer une valeur :");
                    scanf("%d", &A[i][j]);
            }
    }

        //Paramétrage de la matrice B
        printf("*Définition de la première matrice*\n");
                    //Param_Mat(n1, q);
        printf("Entrer le nombre de lignes : ");
        scanf("%d", &n1);
        printf("Entrer le nombre de colonnes : ");
        scanf("%d", &q);



         int B[n1][q];
         //Charger_Tab(n1, q, B);
          for(i = 0 ; i < n1; i++){
            for(j = 0 ; j < q ; j++){
                    printf("Entrer une valeur :");
                    scanf("%d", &B[i][j]);
            }
    }

        //Déclaration et calcul de la matrice produit
        int Produit[p][q];
       // Init_Tab(p, q, Produit);
       for(i = 0 ; i < p ; i++)for(j = 0 ; j < q ; j++) Produit[i][j] = 0;

        for( i = 0; i < p ; i++)for( j = 0; j < q ; j++)for( k = 0; k < n ; k++){
            Produit[i][j] = Produit[i][j] + A[i][k] * B[k][j];
        }
         for(i = 0 ; i < p ; i++){
                  printf("\n");
            for(j = 0 ; j < q ; j++){
                    printf("%d ", Produit[i][j]);

            }
    }

        return 0;
}



