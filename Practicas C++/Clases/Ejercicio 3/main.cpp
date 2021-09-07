#include <iostream>
#include"Punto.h"


int main(int argc, char** argv) {
	
	int op,x,y;
	Punto *p1=new Punto();
	
	p1->mostrarCoordenada();
	
	printf("Desea cambiar las coordenadas del punto? (1=si/0=no): ");
	scanf("%i",&op);
//	printf("\n");
	while (op!=0){
			printf("\nMovimiento en X: ");
			scanf("%i",&x);
			printf("\nMovimiento en Y: ");
			scanf("%i",&y);
			p1->mover(x,y);
			printf("\nDesea cambiar las coordenadas del punto? (1=si/0=no): ");
			scanf("%i",&op);
	}
	
	
	p1->mostrarCoordenada();
	return 0;
}
