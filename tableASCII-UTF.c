#include <stdio.h>

int main(void)
{
    printf("\n*****TABLEAU DE CORRESPONDANCE******\n\n");
    for (int i = 0; i <= 254; ++i)
        printf("\n %c --> %d ", i, i);
    return 0;
}
