#include <iostream>
#include "DiaAnio.h"

using namespace std;

struct tCumple{
	int dia;
	int mes;
};

int main(int argc, char** argv) {
	tCumple cumpleanio;
	cumpleanio.dia=17;
	cumpleanio.mes=7;
	
	DiaAnio d1(cumpleanio.dia,cumpleanio.mes);//objeto estatico
	DiaAnio *miCumple=new DiaAnio(16,7);//objeto dinamico
	
	printf("Fecha cargada: ");d1.visualizar();
	
	printf("Mi cumple: ");miCumple->visualizar();
	
	
	if (miCumple->igual(d1)){
		printf("Es tu cumpleaños\n");
	}else{
		printf("No es tu cumpleaños\n");
	}
	

	return 0;
}
