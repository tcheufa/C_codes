#include <stdio.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#define taille (10)

void quicksort (int * T, size_t start, size_t end);
size_t partition (int*, size_t start, size_t end);
void printTab (char* msg, int *T, size_t size)
{
    printf("%s", msg);
    for(size_t i = 0; i < size; i++) {
        printf("%d ", T[i]);
    }
}

int main (void)
{
    int tableau[taille] = { 3, 5, 7, 8, 2, 1, 0, 18, 9, 4};
    printTab("Tableau non trié :\n", tableau, taille);
    quicksort(tableau, 0, taille-1);
    printTab("\nTableau trié :\n", tableau, taille);
    return 0;
}

size_t partition (int* T, size_t start, size_t end)
{

    int pivot = T[start];
    size_t i_pivot = start;
    int tmp;

    start++;

    while (start <= end) {
        while (T[start] <= pivot) start++;
        while (T[end] > pivot) end--;

        if (start < end) {
            tmp = T[end];
            T[end] = T[start];
            T[start] = tmp;
            start++; end--;
        }
    }

    tmp = T[i_pivot];
    T[i_pivot] = T[end];
    T[end] = tmp;

    return end;
}


void quicksort(int* T, size_t start, size_t end)
{
    if (start < end) {
        size_t i_pivot = partition(T, start, end);
        quicksort(T, start, i_pivot - 1);
        quicksort(T, i_pivot + 1, end);
    }

}
