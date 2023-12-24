#include <stdio.h>
#include <stdlib.h>

int MyReadLn (char *s, size_t max);
size_t xstrlen (char *s);
char *xstrcpy (char *dst, char *src);
char *xstrcat(char *dst, char *src);
int xstrcmp (char *str1, char *str2);
char *xstrchr (char *str, int val);
char *xstrpbrk (char *str, char *list);
char *xstrstr (char *str1, char *str2);

int main (void)
{
    char chaine1[100] = "Buongiorno ";
    char *st = &chaine1[3];
    chaine1[10] = '\0';
    char chaine2[25];
    xstrcpy(chaine2, chaine1);

    printf("%s\n", chaine2);
    return EXIT_SUCCESS;
}

int MyReadLn (char *s, size_t max)
{
    int i = -1;

    do
    {
        i++;
        if (scanf("%c", &s[i]) != 1)
            return 0;
    }
    while (s[i] != '\n' && i < max);

    s[i] = '\0';

    return i;
}

size_t xstrlen(char *s)
{
    unsigned len = 0;
    while (s[len] != '\0')
        len++;
    return len;
}

char *xstrcpy (char *dst, char *src)
{
    unsigned i;
    for (i = 0; src[i] != '\0'; i++)
        dst[i] = src[i];
    dst[i] = '\0';
    return dst;
}

char *xstrcat(char *dst, char *src)
{
    unsigned i = 0, j = 0;

    while (dst[i] != '\0')
        i++;

    while (src[i] != '\0')
    {
        dst[i]  = src[j];
        i++;
        j++;
    }
    dst [i] = '\0';
    return dst;
}

int xstrcmp(char *str1, char *str2)
{
    while (*str1 == *str2)
    {
        if (*str1 == '\0')
            return 0;
        ++str1;
        ++str2;
    }
    return (*str1 < *str2) ? -1 : 1;
}

char *xstrchr (char *str, int val)
{
    while(*str != '\0')
    {
        if (*str == val)
            return str;
        else
            ++str;
    }
    return NULL;
}

char *xstrpbrk (char *str, char *list)
{
    while (*str != '\0')
    {
        char *p = list;
        while (*p != '\0')
        {
            if (*str == *p)
                return str;
            ++p;
        }
        ++str;
    }
    return NULL;
}

char *xstrstr (char *str1, char *str2)
{
    unsigned i;
    char *c = str1;
    do
    {
        c = xstrchr(c, *str2);
        for (i = 0; str2[i] != '\0'; i++)
            if (c[i] != str2[i])
                c = &c[i];
    }
    while (c != NULL && i != xstrlen(str2));
    return c;
}
