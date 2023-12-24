#include <stdio.h>
#include <stdlib.h>

int main(void) {
	unsigned annee;
	printf("ANNEE BISSEXTILE ?\n");
	do
    {
		printf("Veuillez entrer une année : ");
		if(scanf("%u", &annee) != 1)
            return EXIT_FAILURE;
	}
	while(annee <= 0);

	if (annee % 4 == 0 && annee % 100 != 0 || annee % 400 == 0)
        printf("%u est une année bissextile !", annee);
	else printf("%u n'est pas bissextile", annee);
	return EXIT_SUCCESS;
}
