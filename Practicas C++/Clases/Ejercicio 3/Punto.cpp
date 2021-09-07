#include<iostream>
#include"Punto.h"

void Punto::mover(int x, int y){
	ejeX=ejeX+x;
	ejeY=ejeY+y;
	printf("Nueva coordenada del punto: (%i,%i)\n",ejeX, ejeY);
}

void Punto::mostrarCoordenada(){
	printf("Coodenada actual del punto: (%i,%i)\n",ejeX,ejeY);
}

