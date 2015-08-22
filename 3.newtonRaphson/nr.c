// gcc -Wall nr.c -o exe -lm

// Préprocesseur
#include <stdio.h>
#include <math.h>

// Prototypes
void newtonRaphson(double x0, double eps1, double eps2, int itermax);
double F(double x);
double FPrime(double x);
double demande_double(char * nom);
int demande_int(char * nom);

// Fonctions
double F(double x) {
	double y;
	y = 0.05*x*x + 0.13*x - 0.1;
	return y;
}

double FPrime(double x) {
	double y;
	y = 2*0.05*x + 0.13;
	return y;
}

double demande_double(char * nom) {
	double reponse;
	printf("valeur de %s : ", nom);
	scanf("%lf", &reponse);
	return reponse;
}

int demande_int(char * nom) {
	int reponse;
	printf("valeur de %s : ", nom);
	scanf("%d", &reponse);
	return reponse;
}

void newtonRaphson(double x0, double eps1, double eps2, int itermax) {
	// initialisation valeurs qui évolue lors des itérations
	double x = x0, fx = F(x), fpx = FPrime(x);
	int nbiter = 0; /* compteur d'iterations */

	while ((nbiter < itermax) && (fabs(fx) >= eps1) && (fabs(fpx) >= eps2)) {
		/* affichage du quadruplet courant */
		printf("x = %15.9g; f(x) = %15.9g; f'(x) = %15.9g; nbiter=%d\n", x, fx, fpx, nbiter);
		/* calcule du quadruplet suivant */
		x = x - fx/fpx;
		fx = F(x);
		fpx = FPrime(x);
		nbiter++;
	}

	/* traitement du dernier quadruplet */
	printf("x = %15.9g; f(x) = %15.9g; f'(x) = %15.9g; nbiter=%d\n", x, fx, fpx, nbiter);
	if (fabs(fx) < eps1) {
		printf("Solution atteinte.\n");
	} else if (nbiter >= itermax) {
		printf("Nombre maximum d'iterations atteint.\n");
	} else {
		printf("Derivee (quasi) nulle !\n");
	}
}

// le main (point d'entrée du programme)
int main(int argc, char * argv[]) {
	// définition
	double x0, eps1, eps2;
	int itermax;

	// initialisation
	// demandé à l'utilisateur
	x0 = demande_double("x0");
	eps1 = demande_double("epsilon1");
	eps2 = demande_double("epsilon2");
	itermax = demande_int("itermax");

	newtonRaphson(x0, eps1, eps2, itermax);
	
	return 0;
}