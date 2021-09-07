// crear un archivo secuencial

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

void pedirEstudiante(tREstudiante & rEstudiante, bool & fin);		


int main(){
	FILE * fEstudiante;
	tREstudiante rEstudiante;
	bool fin;
	fEstudiante = fopen("Estudiante.txt", "wb");
	pedirEstudiante(rEstudiante, fin);
	while (!fin) {
		fwrite(&rEstudiante, sizeof(rEstudiante), 1, fEstudiante);
		pedirEstudiante(rEstudiante, fin);		
	}
    fclose(fEstudiante)	;
}

void pedirEstudiante(tREstudiante & rEstudiante, bool & fin) {
	printf("\nInresar datos de un estudiante\n");
	printf("Ingresar legajo (0=fin)=");
	cin>>rEstudiante.legajo;
	cin.ignore() ;
	if (rEstudiante.legajo!=0) {
		fin = false;
		printf("\nIngresar DNI=");
		cin>>rEstudiante.DNI;
		cin.ignore() ;
		printf("\nIngresar apellido=");
		cin.getline(rEstudiante.apellido,sizeof(rEstudiante.apellido));
		printf("\nIngresar mail=");
		cin.getline(rEstudiante.mail,sizeof(rEstudiante.mail));
	} else fin = true;
}

