// leer un archivo secuencial

#include <iostream>
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
using namespace std;

typedef char str60[60];

struct tREstudiante {
	int legajo;
	int DNI;
	str60 apellido;
	str60 mail;
};

void leerEstudiante(FILE * &fEstudiante, tREstudiante & rEstudiante, bool & fin);

int main(){
	FILE * fEstudiante;
	tREstudiante rEstudiante;
	bool fin;
	fEstudiante = fopen("Estudiante.dat", "rb");
	if (fEstudiante != NULL){
		printf("%6s %-8s %-30s %-30s\n", "Legajo", "DNI",
		    	"Apellido", "Mail");
		leerEstudiante(fEstudiante, rEstudiante, fin);
		while (!fin) {
			printf("%6d %8d %-30s %-30s\n", rEstudiante.legajo, rEstudiante.DNI,
		    	rEstudiante.apellido, rEstudiante.mail);
		    leerEstudiante(fEstudiante, rEstudiante, fin);		
		}
	    fclose(fEstudiante)	;
	} else
	   cout<<"No existe archivo Estudiante.dat"<<endl;
}

void leerEstudiante(FILE * & fEstudiante, tREstudiante & rEstudiante, bool & fin){
   fread(&rEstudiante, sizeof(rEstudiante), 1, fEstudiante);	
   if (feof(fEstudiante) )
      fin = true;
   else fin = false ;	
}
