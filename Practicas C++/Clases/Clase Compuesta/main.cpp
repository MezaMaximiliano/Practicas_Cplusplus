#include <iostream>
#include "Alumno.h"


using namespace std;

int main(int argc, char** argv) {
	
	Alumno *a1= new Alumno(17775,6.3,"Hernandarias",2080,"Maximiliano",31,346194590);
	
	a1->mostrarDatos();
	
	cout<<"\n\nCon nueva direccion\n\n";
	
	a1->nuevaDir("Colon",1825);
	
	a1->mostrarDatos();


 

	

	
	return 0;
}
