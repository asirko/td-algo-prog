// gcc -Wall -o exe histo-complet.c

#include <stdio.h>
#include <stdlib.h>

int lire_data(char * nom_fichier, int tab[], int nb_mes_max);
int minimum(int tab[], int size);
int maximum(int tab[], int size);
int decompte(int tab[], int size, int val_ref);
void histogramme_textuel(int tab[], int size);
void histogramme_textuel_dans_fichier(int tab[], int size, char * nom_fichier);

int lire_data(char * nom_fichier, int tab[], int nb_mes_max) {
    FILE * fh;
    int valeur_lue;
    int etat_lecture;
    int i;

    fh = fopen(nom_fichier, "r");
    if (fh == NULL) {
        fprintf(stderr, "Impossible de lire le fichier '%s' !\n", nom_fichier);
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

int minimum(int tab[], int size) {
    int i;
    int min = tab[0];
    for (i = 1; i < size; i++) {
        if (min > tab[i]) {
            min = tab[i];
        }
    }
    return min;
}

int maximum(int tab[], int size) {
    int i;
    int max = tab[0];
    for (i = 1; i < size; i++) {
        if (max < tab[i]) {
            max = tab[i];
        }
    }
    return max;
}

int decompte(int tab[], int size, int val_ref) {
    int res = 0;
    int i;

    for (i = 0; i < size; i++) {
        if (tab[i] == val_ref) {
            res++;
        }
    }
    return res;
}

void histogramme_textuel(int tab[], int size) {
    int i;
    int min = minimum(tab, size);
    int max = maximum(tab, size);

    for (i = min; i <= max; i++) {
        printf("%d %d\n", i, decompte(tab, size, i));
    }
}

void histogramme_textuel_dans_fichier(int tab[], int size, char * nom_fichier) {
    int i;
    int min = minimum(tab, size);
    int max = maximum(tab, size);
    FILE * fh;

    fh = fopen(nom_fichier, "w");
    if (fh == NULL) {
        fprintf(stderr, "Impossible d'ecrire le fichier '%s'!\n", nom_fichier);
        exit(1);
    }
    for (i = min; i <= max; i++) {
        fprintf(fh, "%d %d\n", i, decompte(tab, size, i));
    }
    fclose(fh);
}

#define MAX 10000

int main() {
    int mesures[MAX];
    int nb_mesures;

    nb_mesures = lire_data("mesures-taille.txt", mesures, MAX);
    printf("Nb de mesures lues : %d\n", nb_mesures);

    histogramme_textuel(mesures, nb_mesures);
    histogramme_textuel_dans_fichier(mesures, nb_mesures, "histogramme.txt");
    return 0;
}
