//Autorefecia de Objetos: this

#include <iostream>
#include "Alumno.h"
using namespace std;
int main(int argc, char** argv) {
	
	Alumno *alum=new Alumno(5,8);
	Alumno alum2(9,5);
	alum->mostrarCal();
	alum2.mostrarCal();
	
	delete alum;	//destructor de objeto dinamico
	alum2.~Alumno();	//destructor de objeto estatico

	return 0;
}
