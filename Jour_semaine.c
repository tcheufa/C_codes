#include <stdio.h>

int main(void)
{
	unsigned j, m, a, ver;
	printf("DÉTERMINER LE JOUR DE LA SEMAINE\n");

	do
    {
		printf("Entrer une date (au format jj/mm/aaaa) : ");
		ver = scanf("%u/%u/%u", &j, &m, &a);
		if (ver != 3 && ((j > 31 && j <= 0) || (m > 12 && m <= 0 ) || a <= 0)) printf("La date saisie n'est pas valide\n");
	}
    while (ver != 3 && ((j > 31 && j <= 0) || (m > 12 && m <= 0 ) || a <= 0)); //La boucle se répète tant que le format ou les limites sur la date ne sont pas respectées, et que le nombre de valeur fournies est égal à 3

	unsigned nj = (a - 1) * 365 + (a - 1) / 4; //+le nombre de jours à ajouter par année bissextile (calendrier Julien)

    if (a > 1852)
    //passage au calendrier Grégorien
    {
        nj -= (a - 1) / 100; //On retranche les jours correspondant aux années multiples de 100
        nj += (a - 1) / 400; //+nombres de jours correspondant aux années  multiples de 400
        nj += 2; //+les 2jours correspondant aux années omises lors du passage du cal. Julien au cal. Grégorien
    }

    //+Nbre de jours jusqu'à la fin du mois précédent

    nj += (m - 1) * 31; //On suppose que tous les mois ont le même nombre de jours

    //on retranche les jours excédants pour chacun des mois irréguliers

    switch (m)
    {
        case 12:
            --nj;
        case 11:
        case 10:
            --nj;
        case 9:
        case 8:
        case 7:
            --nj;
        case 6:
        case 5:
            --nj;
        case 4:
        case 3:
            if ((a % 4 == 0 && a % 100 != 0) || a % 400 == 0)
                nj -= 2;
            else
                nj -= 3;
            break;
    }

	nj += j - 1;	//Nbre total jours entre le 1/1/1 et la date saisie

	//Affichage du jour de la semaine

	printf("C'est un ");
	switch ((nj) % 7)
	{
	    case 0: printf("samedi"); break;
		case 1: printf("dimanche"); break;
		case 2: printf("lundi"); break;
		case 3: printf("mardi"); break;
		case 4: printf("mercredi"); break;
		case 5: printf("jeudi"); break;
		case 6: printf("vendredi"); break;
	}

	return 0;
}
