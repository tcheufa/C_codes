#include <stdio.h>
#include <stdlib.h>
#define LEN  10

void printT (int * T, size_t len)
{
    for (size_t i = 0; i < len; i++) {
        printf(" %d ", T[i]);
    }
}

void bubble_sort(int * T, size_t len);

void selection_sort(int * T, size_t len);

void insertion_sort(int * T, size_t len, size_t nb, int value);

void merge(int * T, size_t start, size_t end);

void merge_sort(int * T, size_t start, size_t end);


int main ()
{
    int T [LEN] = { 1, 3, 8, 553, 53, 63, 0, 3, -3, 88 };

    printf("Before :\n");
    printT(T, LEN);

    int value = 0;

    merge_sort(T, 0, LEN-1);

//    int Tab[LEN] = {0};
//    for (size_t i = 0; i < LEN || value != -1; i++) {
//        printf("\nT[%d] = ", i);
//        scanf("%d", &value);
//        insertion_sort(Tab, LEN, i, value);
//    }

    printf("\nAfter :\n");
    printT(T, LEN);

    return 0;
}


void bubble_sort(int * T, size_t len)
{
    size_t i, j;
    int tmp;

    for (i = 0; i < len - 1; i++) {
        for (j = 0; j < len - i - 1; j++) {
            if (T[j] > T[j+1]) {
                tmp = T[j];
                T[j] = T[j+1];
                T[j+1] = tmp;
            }
        }
    }
}

void selection_sort(int * T, size_t len)
{
    size_t j;
    size_t imin;
    int tmp;

    for (size_t i = 0; i < len - 1; i++) {
        imin = i;
        for (j = i + 1; j < len; j++) {
            if (T[imin] > T[j]) {
                imin = j;
            }
        }
        tmp = T[imin];
        T[imin] = T[i];
        T[i] = tmp;
    }
}

void insertion_sort(int * T, size_t len, size_t nb, int value)
{
    if (nb >= len) {
        printf("Le tableau est plein.\n");
        return;
    }

    if (nb == 0) {
        T[0] = value;
        return;
    }

    for (size_t i = 0; i < nb; i++) {
        if (value > T[i]) {
            for (size_t j = nb; j > i; j--) {
                T[j] = T[j-1];
            }
            T[i] = value;
            return;
        }
    }
    T[nb] = value;
}

void merge (int * T, size_t start, size_t end) {
    const int len = end - start + 1;
    int merge[len];
    const size_t mid = (end + start) / 2;
    size_t i1 = start;
    size_t i2 = mid + 1;
    size_t k = 0;

    while (i1 <= mid && i2 <= end) {
        if (T[i1] > T[i2]) {
            merge[k] = T[i1++];
        }
        else {
            merge[k] = T[i2++];
        }
        k++;
    }

    while (i1 <= mid) {merge[k++] = T[i1++];}
    while (i2 <= end) {merge[k++] = T[i2++];}

    for (k = 0; k < len; k++) {
        T[start + k] = merge[k];
    }

}

void merge_sort(int * T, size_t start, size_t end) {
    if (start < end) {
        size_t mid = (end + start) / 2;
        merge_sort(T, start, mid);
        merge_sort(T, mid+1, end);
        merge(T, start, end);
    }
}
