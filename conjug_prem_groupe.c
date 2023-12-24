#include <stdio.h>

char verb[20] ;
char conj1[20], conj2[20], conj3[20], conj4[20], conj5[20], conj6[20] ;
int i = 0 , imax;
void Noun_Charger(char[]);

// PROGRAMME DE VÉRIFICATION DE LA CONJUGAISON DES VERBES SE TERMINANT PAR "ER"
int main(){
    printf("--PROGRAMME DE CONJUGAISON DES VERBES--\n");
    printf("**Module 1: verbes se terminant par 'er'**\n");
    // TODO: Creer une sorte de dictionnaire des verbes du premier groupe qui nous permettra de vérfier si le verbe entré par l'utilisateur existe bel et bien.

    do{
        printf("Entrer le verbe de votre choix qui se termine par 'er' : ");
        Noun_Charger(verb);
       if (verb[imax ] != 'r' && verb[imax - 1] != 'e')printf("Votre verbe ne se termine pas par 'er' !\n");
    }while(verb[imax] != 'r' && verb[imax - 1] != 'e'); // pn dmande ` à l'utilisateur de rentre à nouveau son verbe s'il ne se termine pas par 'er'
    // TODO: La prise en charge de tous les temps verbsux
    printf("\nConjuguez à présent votre verbe '");
    for(i = 0; i <= imax; i++){
        printf("%c", verb[i]);
    }
    printf("' au present de l'indicatif: \n");
    printf("je ");
    Noun_Charger(conj1);
    printf("tu ");
    Noun_Charger(conj2);
    printf("il/elle ");
    Noun_Charger(conj3);
    printf("nous ");
    Noun_Charger(conj4);
    printf("vous ");
    Noun_Charger(conj5);
    printf("ils/elles ");
    Noun_Charger(conj6);;
    // INCOMPLET...
}

void Noun_Charger(char T[]){
    char character;
    do{
        scanf("%c", &character);
        if (character != '\n'){
                T[i] = character;
                imax = i++ ;
        }
    }while(character != '\n');
}
