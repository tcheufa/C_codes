#include <stdio.h>

union U {
    int entier;
    float flottant;
};

typedef struct Date{
    unsigned char jour;
    unsigned char mois;
    unsigned char annee;
};

static void modifier_jour (unsigned char *, unsigned short);
static void modifier_mois (unsigned char *, unsigned short);
static void modifier_annee (unsigned char *, unsigned short);

static unsigned short calcule_jour (unsigned char * date);
static unsigned short calcule_mois (unsigned char * date);
static unsigned short calcule_annee (unsigned char * date);


int main (void)
{
    unsigned short n;
    n = 5;
//    printf("%hu & %hu = %hu\n", n, 0x7Fu, n & 0x7FU);
    unsigned char date[3];
    unsigned short jour, mois, annee;
    printf("\nEntrer la date du jour (jj/mm/aaaa) : ");
    while(scanf("%hu / %hu / %hu", &jour, &mois, &annee) != 3)
    {
        printf("Erreur de saisie: \n> ");
    }
    modifier_jour(date, jour);
//    modifier_mois(date, mois);
//    modifier_annee(date, annee);
    printf("Nous sommes le : %hu / %hu / %hu\n\n", calcule_jour(date), calcule_mois(date), calcule_annee(date));

    union U u = {2};
    printf("%d\t", u.entier);
    u.flottant = 9.;
    printf("%f", u.flottant);
    return 0;
}


static void modifier_jour (unsigned char * date, unsigned short jour)
{
    date[0] |= jour;
}


static void modifier_mois (unsigned char * date, unsigned short mois)
{
    date[0] |= (mois & 0x07) << 5;
    date[1] |= (mois & 0x01U);
}


static void modifier_annee (unsigned char * date, unsigned short annee)
{
    date[1] |= (annee >> 7);
    date[2] |= (annee & 0x1FU);
}


static unsigned short calcule_jour (unsigned char * date)
{
    return (date[0] >> 3);
}


static unsigned short calcule_mois (unsigned char * date)
{
    return (date[0] & 0x07U << 1) | (date[1] & 0x1);
}


static unsigned short calcule_annee (unsigned char * date)
{
    return (date[1] << 7) | (date[1] >> 3);
}
