#include <stdio.h>

int main(void)
{
    printf("Miles\tKm\n");
    for (int miles = 0; miles <= 30; miles += 5)
        printf("%5d %4d\n", miles, miles * 8 / 5);
    return 0;
}
