#include <stdio.h>

//Tres performant
int pgdc (int a, int b)
{
    int r = a % b;
    if(r == 0)
        return b;
    else
        return pgdc(b, r);
}

int main(void)
{
    int n1, n2;
    scanf("%d %d", &n1, &n2);
    printf("PGDC(%d;%d) = %d", n1, n2, pgdc(n1, n2));
    return 0;
}
