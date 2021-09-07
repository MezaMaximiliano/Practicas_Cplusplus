#include "punto.h"

//Establecemos valor de X

void Punto::setX(int valorX){
	x /*este es el atributo de la clase*/=valorX;
}

//Establecemos valor de Y

void Punto::setY(int valorY){
	y=valorY;
}

//obtenemos el valor de X
int Punto::getX(){
	return x;
}

//obtenemos el valor de Y
int Punto::getY(){
	return y;
}
