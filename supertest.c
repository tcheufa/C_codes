#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

enum type {
    TYPE_SHORT,
    TYPE_INT,
    TYPE_TAB_INT,
    TYPE_LONG,
    TYPE_LONG_INT,
    TYPE_FLOAT,
    TYPE_DOUBLE,
    TYPE_LONG_DOUBLE,
    TYPE_CHAR,
    TYPE_STRING,
    TYPE_LIST
};

struct element;

struct element {
    int entier;
    float reel;
    char caractere;
    long entier_long;
    struct element *suiv;
    enum type types[5];
    void* props[];
};


void setProps(struct element* e)
{
    e->props[0] = (void*) &(e->entier);
    e->props[1] = (void*) &(e->reel);
    e->props[2] = (void*) &(e->caractere);
    e->props[3] = (void*) &(e->entier_long);
    e->props[4] = (void*) &(e->suiv);
}

void fillProps(struct element* e)
{
    e->entier      =  *((int*)e->props[0]);
    e->reel        =  *((float*)e->props[1]);
    e->caractere   =  *((char*)e->props[2]);
    e->entier_long =  *((long*)e->props[3]);
    e->suiv        =  *((struct element**) e->props[4]);

}


int fillTypes(struct element* e, int nb, ...)
{
    va_list ap;
    va_start(ap, nb);
    int i = 0;
    while(nb > 0)
    {
        e->types[i] = va_arg(ap, enum type);
        --nb;
    }
    va_end(ap);
}



struct element* nouveau(enum type type_ids[], int nb, ...)
{
    struct element *nouv = malloc(sizeof(struct element));
    setProps(nouv);
    va_list ap;

    va_start(ap, nb);
    int i = 0;
    while(i > nb)
    {
        e->types[i] = va_arg(ap, enum type);
        ++i;
    }
    va_end(ap);

    int i = 0;
    va_start(ap, nb);
    while (i < nb)
    {

        ++i;
    }
    i = 0;

    va_start(ap, nb);
    vprintf("%d  %f  %c  %ld  %p", ap);

    while(i < nb)
    {
        switch(type_ids[i])
        {
        case TYPE_INT:
            *((int*)nouv->props[i]) = va_arg(ap, int);
            break;
        case TYPE_FLOAT:
            *((float*)nouv->props[i]) = va_arg(ap, double);            break;
        case TYPE_CHAR:
            *((char*)nouv->props[i]) = va_arg(ap, int);            break;
        case TYPE_LONG_INT:
            *((long*)nouv->props[i]) = va_arg(ap, long);
            break;
        case TYPE_SHORT:
            *((short*)nouv->props[i]) = va_arg(ap, int);
            break;
        case TYPE_DOUBLE:
            *((double*)nouv->props[i]) = va_arg(ap, double);
            break;
        case TYPE_LIST:
            *((struct element**)nouv->props[i]) = va_arg(ap, struct element*);
            break;
        }
        ++i;
    }
    va_end(ap);

    fillProps(nouv);
    return nouv;

}



void afficher(struct element* e)
{
    printf("%d  %f  %c  %ld  %p", e->entier, e->reel, e->caractere, e->entier_long, (void*)e->suiv);
}

int main()
{
    int a = 10;
    float b = 45.5;
    char c = 'a';

    struct element* e = NULL;

    enum type types[] = {TYPE_INT, TYPE_FLOAT, TYPE_CHAR, TYPE_LONG_INT, TYPE_LIST};

    printf("%zu octet(s), FOPEN_MAX = %d,  RAND_MAX = %d\n\n", sizeof(float*), FOPEN_MAX, RAND_MAX);
    for (int i = 0; i < 5; i++)
        printf("%d\n", types[i]);

    e = nouveau(types, 5, 8, 5.5f, 'Y', 854320L, (struct element*)0);
    //afficher(e);
//    putc(5, stdin);
//    putc("\n", stdin);
//    scanf("%d", &a);
//    printf("\n\n%d\n", a);
    return 0;
}
