#include <stdio.h>

int main () {
	int c, cont = 0, ant, cantSalto = 0, cantCar = 0, cantParr= 0, cantPal = 0, cantDigN = 0;

	while ((c = getchar()) != EOF) {
		cantCar++;
		ant = c;

		if ((c == ' ') || (c == '\n')) {
			cantPal++;
		}	
		
		cont++;
		if ((c >= '0') && (c <= '9')) {
			cantDigN++;
		}

		if ((c == '\n')) {
			cantSalto++;
		}
		if ((c != '\n') && (cantSalto == 2)) {
			cantParr++;
			cantSalto = 0;
		}
	}
	
	if ((ant != ' ') && (c == EOF)) {
		cantParr++;
	}

	printf("Caracteres: %d\nPalabras: %d\nPárrafos: %d\nDígitos numéricos: %d\n", cantCar, cantPal, cantParr, cantDigN);

	return 0;
}
