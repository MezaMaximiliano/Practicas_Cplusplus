//Creamos objetos
#include <iostream>
#include "punto.h"

using namespace std;
int main(int argc, char** argv) {
	
	Punto p1(2,1);//Creacion de objeto estatico
	
	printf("El valor de X es %i\n",p1.getX());
	printf("El valor de Y es %i\n",p1.getY());
	//creacion de objeto dinamico
	Punto *p2=new Punto();//creamos el objeto usando el constructor 2
	printf ("El valor de X de p2 es %i\n", p2->getX());
	printf ("El valor de Y de p2 es %i\n", p2->getY());
	//utilizamos el metedo para establecer los valores por otros	
	p2->setX(5);
	p2->setY(10);
	printf ("El valor de X de p2 es %i\n", p2->getX());
	printf ("El valor de Y de p2 es %i\n", p2->getY());
	

	return 0;
}
