/* premier programme en C */
#include <stdio.h>

int main() {
  double a, b;
  double x;
  double resultat;

  /* saisie des parametres */
  printf("Donnez la valeur de a : ");
  scanf("%lf", &a);

  printf("Donnez la valeur de b : ");
  scanf("%lf", b);

  printf("Donnez la valeur de x : ")
  scanf("%f", &x);

  /* calcul */
  resultat = a * x + b;

  /* affichage des resultats */
  printf("a * x + b =\n");
  printf("%g\n", resultat);

  return 0;
}