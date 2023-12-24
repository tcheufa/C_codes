#include <stdio.h>

struct structure {
    float ass[3];
    float assse[7];
};
int main(int argc, char *argv[]) {
    struct structure structure = {1.};
    int n = 1;
    long l = 1;
    float  f = 1.;
    double d = 1.;
    unsigned char *pn = (unsigned char*) &n;
    unsigned char *pl = (unsigned char*) &l;
    unsigned char *pf = (unsigned char*) &f;
    unsigned char *pd = (unsigned char*) &d;
    unsigned char *ps = (unsigned char*) &structure.ass;

    for (size_t i = 0; i < sizeof n; i++)
        printf(" %x", pn[i]);
    printf("\n");

    for (size_t i = 0; i < sizeof l; i++)
        printf(" %x", pl[i]);

    printf("\n");

    for (size_t i = 0; i < sizeof f; i++)
        printf(" %x", pf[i]);

    printf("\n");

    for (size_t i = 0; i < sizeof d; i++)
        printf(" %x", pd[i]);

    printf("\nStructure: \n");

    for (size_t i = 0; i < sizeof structure.ass; i++)
        printf(" %x", ps[i]);
}
