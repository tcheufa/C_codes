#include <stdio.h>

int main (void)
{
    char c = -1;
    do
        {
        ++c;
        printf("c: %u\tc: %u\n", (unsigned int)(unsigned char) c, (unsigned int) c);
        }
    while (c + 1 != 0);
    return 0;
}
