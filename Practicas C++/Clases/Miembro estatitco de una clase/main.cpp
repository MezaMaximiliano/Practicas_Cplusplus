#include <iostream>
#include"Estatico.h"


int main(int argc, char** argv) {
	Estatico p1;
	Estatico *p2=new Estatico();
	
	printf("%i\n",p1.getContador());
	
	delete p2;
	
	printf("%i\n",p1.getContador());
	
	p1.~Estatico();
	
	printf("%i\n",p1.getContador());
	return 0;
}

/*Los miembros estaticos de la clase son algo asi como variables globales pero para las clases.
Le pertenecen a las clases y no a los objetos.*/
