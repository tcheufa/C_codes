#include <stdio.h>
#include <math.h>


double mySqrt (double);
double myPow (double x, int p);

int main (void)
{
    double x = 25.;
    int p = 2;
    printf("%f ^ %d = %f ... %f" , x, p, myPow(x, p), (double)1./126);
    printf("\n\nracine de %f = %f", x, mySqrt(x));
    return 0;
}


double myPow (double x, int p)
{
    double pow = 1;

    for (; p > 0; p--)
        {
            pow *= x;
        }

    return pow;
}

double mySqrt (double x)
{
    if (x == 0. || x == 1.)
        return x;

    int precision;
    if (x < 1)
        {
        for (precision = 0; x >= 1.; precision++)
            x *= 10;
        }

    // if n > 0
    // sqrt(x+1) = Ƹ[((-1)ⁿ(2n)! / (1 - 2n)(n!)²(4ⁿ)) * xⁿ]
    // sign = 1 or -1;
    // a_n = (2n)!;
    // b_n = 1 - 2n;
    // c_n = n!;
    // d_n = (n!)²m
    // e_n = 4ⁿ;
    // f_n = pow(x, n);

    int n = 7; // the degree of limit development. should be a parameter (configurable)
    double pow;
    double sqrt = 0.; // setting sqrt to 1 prevent us from considering the n == 0 case
    double term;
    double tmp; // temp
    double facto;

    x = x - 1; // because sqrt ((x-1) + 1) = sqrt(x);

    int i; // counter

    for ( ; n > 0; n--)
        {
        term = (1 - 2*n);

        // calculate xⁿ, 4ⁿ and (n!)
        tmp = 1;
        facto = 1;
        pow = 1;

        for (i = 1; i <= n; i++)
            {
            pow *= x;
            tmp *= 4;
            facto *= i;
            }

        // calculate (n!)²(4ⁿ)
        tmp = tmp * (facto * facto);

        // transfering the expression (1 - 2n)(n!)²(4ⁿ)
        term *= tmp;

        //calculate (2n)!
        for (i = n+1; i <= 2*n; i++)
            {
            facto *= i;
            }

        // (-1)ⁿ(2n)!
        facto *= (n % 2 == 0) ? 1 : -1;

        // get complete term
        printf("\n\n%f ", term);
        term = (facto / term) * pow;
        printf("%f\n", term);

        sqrt += term;

        }

    if (x < 1)
        {
        for (; precision > 0; precision--)
            sqrt /= 10;
        }


    return sqrt;
}
