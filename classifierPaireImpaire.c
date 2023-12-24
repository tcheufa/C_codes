#include <stdio.h>
#include <stdlib.h>

int** classifier(int T[], size_t taille);

void printT(int** T, size_t taille)
{
    printf("\n\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < taille; j++) {
            printf(" %3d ", T[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    int entiers[] = { 1, 2, 13, 4, 35, 6, 7, 10};
    size_t taille = sizeof entiers / sizeof entiers[0];
    printf("La taille du tableau : %zu\n", taille);
    for (int i = 0; i < taille; i++) printf(" %d ", entiers[i]);
    int** entiers_classes;

    entiers_classes = classifier(entiers, taille);

    free(entiers_classes[0]);
    free(entiers_classes[1]);
    free(entiers_classes);
    printf("Fin");
    return 0;
}


int** classifier(int T[], size_t len)
{
    size_t i;
    size_t j;
    size_t imin;
    size_t i_pair = 0;
    size_t i_impair = 0;
    int tmp;

    // A two dimensional array pointer ( array of two pointer to array of len integers
    // The first row refers to the evens and the second to the odd ones
    int **result = (int**) malloc(sizeof(int*[2]));
    if (result == NULL) {
        perror("Erreur d'allocation");
    }

    result[0] = (int*) malloc(len * sizeof(int));
    if (result[0] == NULL) {
        perror("Erreur d'allocation");
    }

    result[1] = (int*) malloc(len * sizeof(int));
    if (result[1] == NULL) {
        perror("Erreur d'allocation");
    }

    // Selection Sort
    for (i = 0; i <= len - 2; i++) {
        imin = i;
        for (j = len - 1; j > i; j--) {
            if (T[imin] > T[j]) {
                imin = j;
            }
        }
        // Swapping T[imin] with T[i]
        tmp = T[imin];
        T[imin] = T[i];
        T[i] = tmp;

        // Passing the number to the result array
        if (T[i] % 2 == 0) {
            result[0][i_pair] = T[i];
            i_pair++;
        }
        else {
            result[1][i_impair] = T[i];
            i_impair++;
        }
    }

    if (T[i] % 2 == 0) result[0][i_pair] = T[i];
    else result[1][i_impair] = T[i];

    printT(result, len);

    return result;
}
