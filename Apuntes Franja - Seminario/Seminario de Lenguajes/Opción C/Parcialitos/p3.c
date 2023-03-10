#include <stdio.h>
#include <string.h>
#include <strings.h>

typedef struct coord{
	int X;
	int Y;
} t_punto;

t_punto crearPunto(int x, int y){
	t_punto punto;

	punto.X = x;
	punto.Y = y;

	return(punto);
}

/*string puntoToString(t_punto punto){
	
	return();
}*/

t_punto sumarPuntos(t_punto punto1, t_punto punto2){
	t_punto spunto;
	spunto.X = punto1.X + punto2.X;
	spunto.Y = punto1.Y + punto2.Y;

	return(spunto);
}

void trasladarX(t_punto* punto1, int X){
	printf("Corrimiento X: %d\n",X);
	punto1->X = punto1->X + X;
}

void trasladarY(t_punto* punto1, int Y){
	printf("Corrimiento Y: %d\n",Y);
	punto1->Y = punto1->Y + Y;
}

t_punto distanciaOrigen(t_punto punto){

	if (punto.X < 0){
		punto.X = punto.X * (-1);
	}
	if (punto.Y < 0){
		punto.Y = punto.Y * (-1);
	}	

	return(punto);
}

int main(){
	int X, Y;
	t_punto punto1, punto2, punto3, punto4, sumapuntos, origen;
	printf("Coordenadas: \n");
	X = 8;
	Y = 8;
	punto1 = crearPunto(X,Y);
	X = -1;
	Y = 5;
	punto2 = crearPunto(X,Y);
	X = 6;
	Y = -2;
	punto3 = crearPunto(X,Y);
	X = -9;
	Y = -7;
	punto4 = crearPunto(X,Y);

	printf("Punto1: (%d,%d)\n",punto1.X,punto1.Y);
	printf("Punto2: (%d,%d)\n",punto2.X,punto2.Y);
	printf("Punto3: (%d,%d)\n",punto3.X,punto3.Y);
	printf("Punto4: (%d,%d)\n",punto4.X,punto4.Y);

	printf("\nSuma puntos 1 y 2: \n");
	sumapuntos = sumarPuntos(punto1,punto2);
	printf("(%d,%d)\n",sumapuntos.X,sumapuntos.Y);

	printf("\nTrasladar X e Y del Punto 3 \n");
	X= -5;
	Y= 7;
	trasladarX(&punto3, X);

	trasladarY(&punto3, Y);
	printf("Punto3: (%d,%d)\n",punto3.X,punto3.Y);

	printf("\nDistancia origen del Punto 1: \n");
	origen = distanciaOrigen(punto1);
	printf("Distancia: (%d,%d)\n",origen.X,origen.Y);
	printf("\nDistancia origen del Punto 2: \n");
	origen = distanciaOrigen(punto2);
	printf("Distancia: (%d,%d)\n",origen.X,origen.Y);
	printf("\nDistancia origen del Punto 3: \n");
	origen = distanciaOrigen(punto3);
	printf("Distancia: (%d,%d)\n",origen.X,origen.Y);
	printf("\nDistancia origen del Punto 4: \n");
	origen = distanciaOrigen(punto4);
	printf("Distancia: (%d,%d)\n",origen.X,origen.Y);
	
	/*puntoToString(punto1);*/

	return 0;
}
