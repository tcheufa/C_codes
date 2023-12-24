#include <stdio.h>

int main()
{
    FILE *fp = fopen("fichtest.txt", "w+");
    if(!fp)
    {
        printf("Erreur de lecture");
        exit(-1);
    }
    //int tab[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (int i = 0; i < 10; i++)
        fprintf(fp, "%d\n", i);

    //fflush(fp);
    rewind(fp);
    char tmp[255];
    char nxt[255];
    int i = 0;
//    while(!feof(fp))
//    {
//        if (i == 1)
//        {
//            fseek(fp, 0, SEEK_CUR);
//            fprintf(fp, "sentinelle\n");
//            fseek(fp, 0, SEEK_SET);
//        }
//        else
//        {
//            fgets(tmp, 254, fp);
//            fseek(fp, -strlen(tmp), SEEK_CUR);
//            printf("%s", tmp);
//        }
//        i++;
//    }

    int r = 0;
    char c;
    while(!feof(fp))
    {
        fscanf(fp, "%c", &c);
        r++;
    }
    printf("Ce fichier contient %d caracteres\n", r);
    rewind(fp);
    while(!feof(fp))
    {
        printf("iiiii ");
        fscanf(fp, "%d", &r);
        if (r == 7)
        {
            printf("\n\n%d obtenu\t", r);
            fseek(fp, -1, SEEK_CUR);
            fprintf(fp, "\0\r\0");
            break;
        }
        fgetc(fp);
    }
    fclose(fp);
    return 0;
}

