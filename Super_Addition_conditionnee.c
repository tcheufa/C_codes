/* Voici un programme qui recupere 10 valeurs entieres entrees par un utilisateur et affiche les sommes deux a deux de ces nombres
suivant qu'ils sont paires ou impaires*/

#include<stdio.h>

int main(void)
{
    int tab[10];
    int pair = 0, impair = 0;
     for (int i = 0; i < 10; i++)
     {
        printf("Entrer le nombre %d : ", i+1);
        while(scanf("%d", &tab[i]) != 1)
        {
            printf("Entrer un nombre valide svp : ");
            scanf("%s", &tab[i]);
        }
     }
     for (int i = 0; i < 10; i++)
     {
        if (tab[i] % 2 == 0)
        {
            if(pair == 0)
                pair = tab[i];
            else
            {
                printf("%d + ", pair);
                pair = pair + tab[i];
                printf("%d = %d\n", tab[i], pair);
                pair = 0;
            }
        }
        else
        {
            if(impair == 0)
                impair = tab[i];
            else
            {
                printf("%d + ", impair);
                impair = impair + tab[i];
                printf("%d = %d\n", tab[i], impair);
                impair = 0;
            }
        }
    }
}
