#include <iostream>
#include "Personaje.h"



int main(int argc, char** argv) {
	
	Personaje *p1=new Personaje(50,60);	
	
	p1->mostrarDatos();
	
	modificarDatos(*p1,100,150);
	printf("\n");
	p1->mostrarDatos();
	
	return 0;
}

void modificarDatos(Personaje &p, int def, int ata){
	p.ataque=ata;
	p.defensa=def;
}

/*Al declarar la funcion para poder modifcar los atributos lo hicimos por referencia, entonces, cuando la funcion es llamada
debe hacer pasando el objeto como puntero*/
