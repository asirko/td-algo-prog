// gcc -Wall -o exe argc-argv.c 

#include <stdio.h>

int main(int argc, char * argv[]) {
    int i;

    printf("\nVous avez tapez une commande avec %d (=argc) argument(s).\n", argc);

    printf("\nLa commande tapée est : \n\t");
    for (i = 0; i < argc; i++) {
        printf("%s ", argv[i]);
    }

    printf("\n\nLes arguments dans argv sont donc : \n");
    for (i = 0; i < argc; i++) {
        printf(" - index %d : %s\n", i, argv[i]);
    }

    return 0;
}
