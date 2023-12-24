#include <stdio.h>
#include <stdlib.h>

#define LENGTH 8

unsigned NextGray(_Bool*, size_t);
unsigned Count(_Bool, _Bool*, unsigned);

// TODO : printf("GRAY CODE CONVERTER\n");

int main()
{
    _Bool code[LENGTH] = {0};
    unsigned limit;
    unsigned i;
    printf("Le code Gray\n");
    printf("Afficher la limite de nombres a afficher : ");
    scanf("%u", &limit);

    printf("%5u => ", 0U); for (i = 0; i < LENGTH; i++) printf("0");
    for(i = 1; i <= limit; i++)
    {
        printf("\n%5u => ", i);
        NextGray(code, LENGTH);
    }

    return 0;
}

unsigned NextGray(_Bool* tab, size_t length)
{
    unsigned count = Count(1, tab, length);
    if (0 == count % 2)
        tab[0] -= 1;
    else
    {
        int i;
        for (; i < length; i++)
            if (tab[i] == 1)
                break;
        tab[i+1] -= 1;
    }

    for(int i = length - 1; i >= 0; i--)
        printf("%d", tab[i]);
}

unsigned Count(_Bool needle, _Bool* mixed, unsigned length)
{
    unsigned count = 0;
    for (unsigned i = 0; i < length; i++)
        if (mixed[i] == needle)
            count++;
    return count;
}
