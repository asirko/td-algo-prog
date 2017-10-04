// ************************************************************
// *************** Commande de compilation ********************
// ************************************************************
// Il est plus simple lorsque l'on travaille à plusieurs de placer 
// la commande de compilation en tête de fichier
// gcc structure.c -Wall -o exe


// ************************************************************
// **************** Préprocesseurs ****************************
// ************************************************************
// Les préprocécesseurs sont générallement à placer en tête de fichier
// il est mieux de déclarer les bibliothèques avant d'utiliser leurs fonctionnalités
#include <stdio.h>


// ************************************************************
// *************** Structures ********************************
// ************************************************************
// Les structures sont des types qui peuvent être utilisé par le reste 
// du programme. Il faut donc les définir avant le reste.
typedef struct {
    int x;
    int y;
} point;

// ************************************************************
// *************** Prototypes *********************************
// ************************************************************
// Les prototypes permettent de déclarer les foctions ainsi l'ordre de 
// déclaration des fonctions peut être quelconque.
point somme(point p1, point p2);

// ************************************************************
// *************** Fonctions **********************************
// ************************************************************
// Les fonctions permettent de découper le code en portions élémentaires 
// plus lisibles est donc maintenable.
point somme(point p1, point p2) {
    point pr;
    pr.x = p1.x + p2.x;
    pr.y = p1.y + p2.y;
    return pr;
}

// ************************************************************
// *************** Main ***************************************
// ************************************************************
// La fonction main est particulière : c'est le point d'entrée du programme.
// Cette fonction doit être mise à une place facillement visible mais ne peut 
// pas être mise avant les prototypes. La place la plus visible est donc la 
// toute fin du fichier

int main(int argc, char const *argv[]) {
    point p, pDouble;

    p.x = 2;
    p.y = 3;
    pDouble = somme(p, p);

    printf("pDouble.x = %d | pDouble.y = %d\n", pDouble.x, pDouble.y);

    return 0;
}
