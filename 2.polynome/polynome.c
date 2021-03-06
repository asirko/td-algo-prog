// gcc -Wall -o exe polynome.c -lm

// Préprocesseur (ex: import de bibliothèque)
#include <stdio.h>
#include <math.h>

// Prototypes
void calculOrdre2Strict (double a, double b, double c);
void calculOrdre1Strict (double a, double b);
double calculDiscriminant (double a, double b, double c);
void gererCas (double a, double b, double c);

// Fonctions

// f(x) = ax^2 + bx + c (=> a != 0)
void calculOrdre2Strict (double a, double b, double c) {
    double delta = calculDiscriminant(a, b, c);

    if (delta > 0) {
        printf("Il y a deux solutions : %lf et %lf.\n", (-b - sqrt(delta))/(2*a), (-b + sqrt(delta))/(2*a));
    } else if (delta == 0) {
        printf("Il y a une solution double : %lf.\n", -b/(2*a));
    } else {
        printf("Il y a deux solutions complexes : (%lf - i*%lf)/%lf et (%lf + i*%lf)/%lf.\n", -b, sqrt(-delta), 2*a, -b, sqrt(-delta), 2*a);
    }
}

// f(x) = ax + b (a != 0)
void calculOrdre1Strict (double a, double b) {
    printf("Il y a une unique solution : %lf.\n", -b/a);
}

double calculDiscriminant (double a, double b, double c) {
    return b*b - 4*a*c;
}

void gererCas (double a, double b, double c) {
    if (a != 0) {
        calculOrdre2Strict(a, b, c);
    } else if (b != 0) {
        calculOrdre1Strict(b, c);
    } else if (c != 0) {
        printf("Aucune solution possible.\n");
    } else {
        printf("Tout x est solution.\n");
    }
} 

// Main
int main(int argc, char * argv[]) {
    
    gererCas(10., 20., 10.);
    
    return 0;
}
