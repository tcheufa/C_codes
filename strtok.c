#include <stdio.h>

char *xstrtok (char *s, char *list) {
    char *l = list;
    int count = 0;
    static char *substring = NULL;
    static char *string = NULL;

    if (s == NULL) {
        substring = string;
        if (*substring == '\0') {
            printf("Woourrf");
            return NULL;
        }
        else {
            while (*substring != '\0') {
                ++substring;
            }
            ++substring;
            return substring;
        }
    }
    else {
        char *c = s;
        while (*c != '\0') {
            while (*l != '\0') {
                if (*c == *l) {
                    *c = '\0';
                    string = (c+1);
                    return s;
                }
                ++l;
            }
            ++c;
            l = list;
        }

        return  NULL;
    }
}

int main (int argc, char *argv[]) {

    char chaine[] = "un, deux, trois\0";

    char *c = xstrtok(chaine, ",\0");

    for (int i = 1; c != NULL; ++i) {
        printf("%d:%s\n", i, c);
        c = xstrtok(NULL, ",");
    }

}
