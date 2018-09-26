// gcc -Wall -o exe histo-hf.c

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int taille;
    char sexe;
} personne;

int lire_data(char * nom_fichier, personne tab[], int nb_mes_max);
int minimum(personne tab[], int size);
int maximum(personne tab[], int size);
int decompte(personne tab[], int size, personne val_ref);
void histogramme_textuel(personne tab[], int size);
void histogramme_textuel_dans_fichier(personne tab[], int size, char * nom_fichier);

int lire_data(char * nom_fichier, personne tab[], int nb_mes_max) {
    FILE * fh;
    personne valeur_lue;
    int etat_lecture;
    int i;
    fh = fopen(nom_fichier, "r");
    if (fh == NULL) {
        fprintf(stderr, "Impossible de lire le fichier '%s' !\n", nom_fichier);
        exit(1);
    }
    i = 0;
    etat_lecture = fscanf(fh, "%d %c", &valeur_lue.taille, &valeur_lue.sexe);
    while ((etat_lecture == 2) && (i < nb_mes_max)) {
        tab[i] = valeur_lue;
        i++;
        etat_lecture = fscanf(fh, "%d %c", &valeur_lue.taille, &valeur_lue.sexe);
    }
    if (etat_lecture == 0 || etat_lecture == 1) {
        fprintf(stderr, "Valeur %d illisible dans le fichier '%s'!\n", i+1, nom_fichier);
        exit(1);
    } else if (etat_lecture != EOF) {
        fprintf(stderr, "Trop de valeurs dans le fichier '%s'!\n", nom_fichier);
        exit(1);
    }
    fclose(fh);
    return i;
}

int minimum(personne tab[], int size) {
    int i;
    int min = tab[0].taille;
    for (i = 1; i < size; i++) {
        if (min > tab[i].taille) {
            min = tab[i].taille;
        }
    }
    return min;
}

int maximum(personne tab[], int size) {
    int i;
    int max = tab[0].taille;
    for (i = 1; i < size; i++) {
        if (max < tab[i].taille) {
            max = tab[i].taille;
        }
    }
    return max;
}

int decompte(personne tab[], int size, personne val_ref) {
    int res = 0;
    int i;

    for (i = 0; i < size; i++) {
        if (tab[i].taille == val_ref.taille && tab[i].sexe == val_ref.sexe) {
            res++;
        }
    }
    return res;
}

void histogramme_textuel(personne tab[], int size) {
    int i;
    int min = minimum(tab, size);
    int max = maximum(tab, size);
    personne recherche;
    int decompte_h;
    int decompte_f;

    for (i = min; i <= max; i++) {
        recherche.taille = i;
        recherche.sexe = 'h';
        decompte_h = decompte(tab, size, recherche);
        recherche.sexe = 'f';
        decompte_f = decompte(tab, size, recherche);
        printf("%3d %3d %3d\n", i, decompte_h, decompte_f);
    }
}

void histogramme_textuel_dans_fichier(personne tab[], int size, char * nom_fichier) {
    int i;
    int min = minimum(tab, size);
    int max = maximum(tab, size);
    personne recherche;
    int decompte_h;
    int decompte_f;
    FILE * fh;

    fh = fopen(nom_fichier, "w");
    if (fh == NULL) {
        fprintf(stderr, "Impossible d'ecrire le fichier '%s'!\n", nom_fichier);
        exit(1);
    }
    for (i = min; i <= max; i++) {
        recherche.taille = i;
        recherche.sexe = 'h';
        decompte_h = decompte(tab, size, recherche);
        recherche.sexe = 'f';
        decompte_f = decompte(tab, size, recherche);
        fprintf(fh, "%3d %3d %3d\n", i, decompte_h, decompte_f);
    }
    fclose(fh);
}

#define MAX 10000

int main() {
    personne mesures[MAX];
    int nb_mesures;

    nb_mesures = lire_data("mesures-taille-sexe.txt", mesures, MAX);
    printf("Nb de mesures lues : %d\n", nb_mesures);

    histogramme_textuel(mesures, nb_mesures);
    histogramme_textuel_dans_fichier(mesures, nb_mesures, "histogramme.txt");
    return 0;
}
