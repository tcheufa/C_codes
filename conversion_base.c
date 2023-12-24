#include<stdio.h>
int main(){
    int exp = 0;
    int dec, dec2, dec3;
    int base;
    printf("Entrer un nombre : ");
    scanf("%d", &dec);
    dec3 = dec2 = dec;
    printf("Veuillez entrer le nombre correspondant à la base où vous souhaitez afficher votre nombre : ");
    scanf("%d", &base);
    do{
        dec2 = dec2 / base;
        exp++;
    }while(dec2 > 0);
    char conv[exp];
    for(int i = exp - 1; i >= 0; i--){
             if(conv[i] < 10){
            printf("%d", conv[i]);
        }
        else{
            conv[i] = 65 + ( - 10));
        conv[i] = dec3 % base;
        dec3 = dec3 / base;
    }
    printf("%d dans la base %d est egal a : ", dec, base);
    for(int i = 0; i < exp; i++){
        if(conv[i] < 10){
            printf("%d", conv[i]);
        }
        else{
            printf("%c", 65 + (conv[i] - 10));
        }
    }
    printf("\n%d a %d chiffre(s) dans la base %d.", dec, exp, base);

}
