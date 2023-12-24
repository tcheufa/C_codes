#include <stdio.h>

float divide (int , int);

int main (void)
{
    int a = 500, b = 4;
    printf("%d / %d = %f", a, b, divide(a, b));
    return 0;
}


float divide (int dividend, int divisor)
{
    float number = 0;
    float decimal_part = 0;
    int precision = 1;

    while (dividend > divisor)
        {
        dividend -= divisor;
        number++;
        }

    while (dividend != 0 && precision != 1000)
        {
        dividend *= 10;

        while (dividend > divisor)
            {
            dividend -= divisor;
            decimal_part++;
            }

            precision *= 10;
            decimal_part /= precision;
            number += decimal_part;
        }

    return number;
}
