// gcc -Wall -o exe histogramme.c

#include <stdio.h>
#include <stdlib.h>

int lire_data(char * nom_fichier, int tab[], int nb_mes_max) {
    FILE * fh;
    int valeur_lue;
    int etat_lecture;
    int i;

    fh = fopen(nom_fichier, "r");
    if (fh == NULL) {
        fprintf(stderr, "Impossible de lire le fichier '%s' !\n",
         nom_fichier);
        exit(1);
    }

    i = 0;
    etat_lecture = fscanf(fh, "%d", &valeur_lue);
    while ((etat_lecture > 0) && (i < nb_mes_max)) {
        tab[i] = valeur_lue;
        i++;
        etat_lecture = fscanf(fh, "%d", &valeur_lue);
    }
    if (etat_lecture == 0) {
        fprintf(stderr, "Valeur %d illisible dans le fichier '%s'!\n", i + 1, nom_fichier);
        exit(1);
    } else if (etat_lecture != EOF) {
        fprintf(stderr, "Trop de valeurs dans le fichier '%s'!\n", nom_fichier);
        exit(1);
    }
    fclose(fh);
    return i;
}

#define MAX 10000

int main() {
    int mesures[MAX];
    int nb_mesures;

    nb_mesures = lire_data("mesures-taille.txt", mesures, MAX);

    printf("Nb de mesures lues : %d\n", nb_mesures);

    return 0;
}
