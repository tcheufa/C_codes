#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
    int tab[10] = {1, 0, 0, 4, 0, 6, 7, 8, 0, 0};
    int *p = tab;
    while (p != (tab + 10))
    {
        if (*p == 0)
            printf("%d ", *p);
        ++p;
    }
}
