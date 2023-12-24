#include <stdio.h>
#include <limits.h>

/// Reorders the array in order to pack non duplicates on a side (at the beginning)
/// Order of elements is preserved here
/// Returns the length of the array without the duplicates
/// Returns the len parameter if no duplicate were found or the length of array is 1
size_t rmv_dupl_ord (int* array, size_t len);

/// Same as rmv_dupl_ord except that order is not preserved
size_t rmv_dupl_unord (int* array, size_t len);

int main (void) {
    int array[20] = { 0,  1,  2,  3,  4,  4,  5,  3,  7, 10,  8,  0, 10, 11, 12,  4, 14,  2, 11,  6 };
                    //                    ^       ^               ^   ^           ^       ^   ^   ^
//                  { 1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 }
    void t(size_t len) {
        for (int i = 0; i < len; i++) {
            printf("%d, ", array[i]);
        }

        printf("\n\n");
    };

    void (*pf)(size_t) = &t;

    printf("With duplicates: \n");

    pf(20);

    size_t len = rmv_dupl_unord(array, 20);

    printf("Without duplicates: \n");

    pf(20);

    return 0;
}



size_t rmv_dupl_ord (int* array, size_t len) {
    if (len < 1)
        return len;

    int duplicate = array[0];
    size_t i = 0;
    size_t j;
    _Bool dupl_found = 0;

    /// if a duplicate is found it is replaced by the value INT_MAX
    for (; i < len-1; i++) {
        duplicate = array[i];

        for (j = i+1; j < len; j++) {
            if (array[j] == duplicate) {
                array[j] = INT_MAX;
                dupl_found = 1;
            }
        }
    }

    int uniques[len];

    for (i = 0, j = 0; i < len; i++) {
        if (array[i] != INT_MAX) {
            uniques[j++] = array[i];
        }
    }

    for (i = 0; i < j; i++)
        array[i] = uniques[i];

    for (i = j; i < len; i++)
        array[i] = INT_MAX;

    return  j;
}




size_t rmv_dupl_unord (int* array, size_t len) {
    if (len < 1)
        return len;

    int duplicate = array[0];
    size_t i = 0;
    size_t j;

    _Bool dupl_found = 0;

    /// if a duplicate is found it is replaced by the value INT_MAX
    for (; i < len-1; i++) {
        duplicate = array[i];

        for (j = i+1; j < len; j++) {
            if (array[j] == duplicate) {
                array[j] = INT_MAX;

                dupl_found = 1;
            }
        }
    }

    // If no duplicate was found there is no need for this function to continue
    // So it returns 0 indicating
    if (!dupl_found) {
        return len;
    }

    int tmp;

    j = len - 1;

    for (i = 1; i < j; i++) {
        if (array[i] == INT_MAX && j > i) {
            while(array[j] == INT_MAX)
                j--;

            tmp = array[j];

            array[j] = array[i];

            array[i] = tmp;

            j--;
        }
    }

    return i;
}
