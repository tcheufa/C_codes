#include <stdio.h>
#include <math.h>

float* ResolveSecDegEquation (float a, float b, float c)
{

    static float results[2] = {0.};
    float delta = 0.;
    if (a == 0)
    {
        results[0] = - c / b;
        results[1] = results[0];
    }
    else if (c == 0)
    {
        results[0] = 0;
        results[1] = - b / a;
    }
    else
    {
        delta = b * b - 4 * a * c;
        delta = sqrt(delta);

        if (delta < 0)
        {
            results[0] = 1 / 0;
            results[1] = 1 / 0;
        }
        else if (delta == 0)
        {
            results[0] = - b / (2 * a);
            results[1] = results[0];
        }
        else
        {
            results[0] = (- b - delta) / (2 * a);
            results[1] = (- b + delta) / (2 * a);
        }
    }
    return results;
}


int main ()
{
    float res[2];
    float *r = res;
    //test de l'équation
    r =  ResolveSecDegEquation(-4, -3, 2);
    printf ("%f ,  %f", r[0], r[1]);
    return 0;
}
