#include<stdio.h>

int main(void)
{
    int i,j;
    int tab[5]; = {1,2,3,4,5}

    for (i = 0; i < 5; i++)
    {
        printf("Entrer le nombre %d : ", i+1);
        if(scanf("%d", &tab[i]) != 1)
            return 1;
    }

    for (i = 0; i < 5; i++)
    {
        printf("\nTable de multiplication de %d\n", tab[i]);
        for (j = 0; j <= 10; j++)
            printf("%3d x %3d = %4d\n", tab[i], j, tab[i]*j);
    }
}
