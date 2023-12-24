#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Read_Word(char[]);
void Conjugate();
void print_root(char[]);
char verb[20] ;
int i, j, compt, imax;

/* Un jour je m'en servirai
 char subj[][6] = { {'j', 't', 'i', 'n', 'v', 'i'},
                    {'e', 'u', 'l', 'o', 'o', 'l'},
                    {' ', ' ', '/', 'u', 'u', 's'},
                    {' ', ' ', 'e', 's', 's', '/'},
                    {' ', ' ', 'l', ' ', ' ', 'e'},
                    {' ', ' ', 'l', ' ', ' ', 'l'},
                    {' ', ' ', 'e', ' ', ' ', 'l'},
                    {' ', ' ', ' ', ' ', ' ', 'e'},
                    {' ', ' ', ' ', ' ', ' ', 's'},
                    {' ', ' ', ' ', ' ', ' ', ' '}
                   } ;
    for (i = 0; i < 6; i++)for(j=0;j<10;j++)printf("%c", subj[j][i]);
char suffix[3][6] = { {'e','e','e','o','e','e'},
                      {' ','s',' ','n','z','n'},
                      {' ',' ',' ','s',' ','t'}
                    };
*/



// PROGRAMME DE VÉRIFICATION DE LA CONJUGAISON DES VERBES SE TERMINANT PAR "ER"
int main()
{
    printf("--PROGRAMME DE CONJUGAISON DES VERBES--\n");
    printf("**Module 1: verbes se terminant par 'er'**\n");

    // TODO: Creer une sorte de dictionnaire des verbes du premier groupe qui nous permettra de vérfier si le verbe entré par l'utilisateur existe bel et bien.
    do
    {
        printf("Entrer le verbe de votre choix qui se termine par 'er' : ");

        Read_Word(verb);

        if (verb[imax] != 'r' && verb[imax - 1] != 'e')
            printf("Votre verbe ne se termine pas par 'er' !\n");
    }
    while(verb[imax] != 'r' && verb[imax - 1] != 'e'); // pn dmande ` à l'utilisateur de rentre à nouveau son verbe s'il ne se termine pas par 'er'

    // TODO: Créer la prise en charge de tous les temps verbsux
    printf("Conjugaison au présent de l'indicatif :\n");

    Conjugate();

  return EXIT_SUCCESS;
}


void Read_Word(char *T)
{
    char character;
    i = 0;
    do
    {
       if (scanf("%c", &character) != 1)
       {
           printf("Erreur lors de la lecture des caractères.");
            exit(EXIT_FAILURE);
       }
       if(character != '\n'){
           T[i] = character;
           imax = i++ ;
       }
    } while(character != '\n');

    T[imax + 1] = '\0';
}


// Gestion des terminaisons de verbes du premier groupe

void print_root(char T[]){

    //verbes en "ayer", "oyer" et "uyer"

    if ( ( ( verb[imax - 3] == 'o' ) || ( verb[imax - 3] == 'a' ) || ( verb[imax - 3] == 'a' ) ) &&  ( verb[imax - 2] == 'y' )  )
    {
       for(i = 0; i < imax - 2; i++)
            printf("%c", T[i]);

       if ( compt < 3 || compt == 5)
            printf("i");
        else
            printf("y");
    }

    // verbes en "eler" et "eter" : exceptions

    else if( ( strcmp(verb,"jeter") == 0 ) || ( strcmp(verb, "rejeter") == 0 ) || ( strcmp(verb, "projeter") == 0 ) || ( strcmp(verb, "appeler") == 0 ) || ( strcmp(verb, "rappeler") == 0) )
    {
        for(i = 0; i < imax - 2; i++)
            printf("%c", T[i]);

        if ( compt < 3 || compt == 5)
            printf("%c%c", T[imax - 2], T[imax - 2]);
        else
            printf("%c", T[imax - 2]);
    }

    // verbes en ecer , emer, eper, erer, ever, evrer, éber, écer, écher, écrer, éder, égler, égner, egrer, éguer, éler, erner, éner, érer, éter, évrer, éyer

    else if ( ( verb[imax - 3] == 'é' ) || ( verb[imax - 4] == 'é' ) || ( verb[imax - 3] == 'e' ) || ( verb[imax - 4] == 'e' ) )
    {
        for(i = 0; i < imax - 1; i++)
        {
            if ( compt < 3 || compt == 5)
            {
                    if (i >= imax - 4)
                    {
                        if ( T[i] == 'e' || T[i] == 'é' )
                            printf("è");
                        else
                            printf("%c", T[i]);
                    }
                    else
                        printf("%c", T[i]);
            }
            else
                printf("%c", T[i]);
        }
    }

    // cas génériques
    else
    {
        for(i = 0; i < imax - 1; i++)
            printf("%c", T[i]);
    }

}

void Conjugate()
{
    compt = 0; //sert à évaluer l'avancement de la conjugaison
    printf("je ");
    print_root(verb);
    printf("e");
    printf("\n");

    compt++;
    printf("tu ");
    print_root(verb);
    printf("es");
    printf("\n");

    compt++;
    printf("il/elle ");
    print_root(verb);
    printf("e");
    printf("\n");

    compt++;
    printf("nous ");
    print_root(verb);
    printf("ons");
    printf("\n");

    compt++;
    printf("vous ");
    print_root(verb);
    printf("ez");
    printf("\n");

    compt++;
    printf("ils/elles ");
    print_root(verb);
    printf("ent");
    printf("\n");

}

