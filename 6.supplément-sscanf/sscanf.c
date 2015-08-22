// gcc -Wall sscanf.c -o exe

#include <stdio.h>

int main() {

    char * strInt = "12";
    int i;
    char * strDouble = "12.5";
    double d;

    // Utilisation basique de sscanf pour transformer des chaînes de caractère en nombre
    sscanf(strInt, "%d", &i);
    sscanf(strDouble, "%lf", &d);
    printf("strInt vaut : %d\nstrDouble : %lf\n", i, d);

    // sscanf peut extraire des information depuis une chaîne de caractère, ces arguments sont
    // 1 : la chaîne à lire
    // 2 : le format à interpréter
    // 3+: l'ensemble des pointeur sur les variables servant de conteneur pour les valeurs extraites 
    //     (pointeur : pour faire simple : le nom de la variable précédé du '&')

    // Voici quelques exemple plus complexe pour mieux comprendre
    char * strDate = "14/09/2015";
    int j, m, a;
    sscanf(strDate, "%d/%d/%d", &j, &m, &a);
    printf("La somme des jours, mois et année vaut : %d\n", j+m+a);

    char * phrase = "Il y a 365 jours dans une année.";
    char * format = "Il y a %d jours dans une année.";
    int nbJour;
    sscanf(phrase, format, &nbJour);
    printf("Il y a %d jours dans une année.\n", nbJour);

    return 0;
}
