#include<stdio.h>

/** Ce programme :
--> stocke dans un tableau les valeurs saisies par l'utilisateur
--> divise ce tableau en deux tableaux de nombres pairs et de nombres impairs
--> additionne deux à deux les éléments d'un même tableau
--> affiche les opérations
**/

int main(){
    int tab[10];
    int paire[10] = {0};
    int impaire[10] = {0};
    int i;
    int cp = 0;
    int ci = 0;

    for (i = 0; i < 10; i++){
        printf("Entrer le nombre %d : ", i+1);
        scanf("%d", &tab[i]);
        if (tab[i] % 2 == 0){
            paire[cp] = tab[i];
            cp++;
        }
        else{
            impaire[ci] = tab[i];
            ci++;
        }
    }

    for (i = 0; i <= cp; i++){
        printf("%4d + %4d = %4d\n", paire[i], paire[i+1], paire[i] + paire[i+1]);
    }
    for (i = 0; i <= ci; i = i + 2){
         printf("%4d + %4d = %4d\n", impaire[i], impaire[i+1], impaire[i] + impaire[i+1]);
    }

}
