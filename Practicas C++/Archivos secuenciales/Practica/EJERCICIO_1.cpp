/*Un gimnasio tiene un archivo de inscripción en las cuatro disciplinas que realiza INSCCRIPCION
secuencial, ordenado por DNI ascendente, que contiene un registro por cada asistente inscripto en una
disciplina deportiva
El diseño de registro de INSCPCION es DNI, Apellido y Nombre Disciplina (" F"," N"," T"," que
representan fútbol, natación, taekwondo, gimnasia)
Se pide
1:
Ge nerar cuatro archivos secuenciales, correspondientes a la inscripción de cada una de las disciplinas FUTBOL,
NATACION, TAEKONDO, GIMNASIA El diseño de registro de los mismos es idéntico al del archivo de entrada
2:
Al finalizar el proceso, emitir la cantidad de inscriptos en cada disciplina
3:
Modificar el algoritmos propuesto teniendo en cuenta que los archivos de salida deben tener solamente los
campos DNI y apellido
4:
Modificar el algoritmo teniendo en cuenta que el campo disciplina puede estar con error En este caso se debe
grabar un archivo de errores*/

#include <stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

#define _CANT 50
#define _DISCIPLINA 2
#define _NOMBRE 60

typedef char str60[_NOMBRE];

struct rRegistro{
	unsigned long int DNI;
	str60 nombre;
	char disciplina[_DISCIPLINA];
};

void pedirDatos (rRegistro &,bool &);

int main(){
	
	rRegistro tIns;
	FILE *fInscripcion;
	bool fin=false;
	fInscripcion=fopen("archivo","rb");
	
	while(!fin){
	
		if (fInscripcion==NULL){
			pedirDatos(tIns,fin);
			fInscripcion=fopen("archivo","wr+");
			
			fwrite(&tIns,sizeof(tIns),1,fInscripcion);
		
		}else{
			pedirDatos(tIns,fin);
			fwrite(&tIns,sizeof(tIns),1,fInscripcion);
		}
	
	}
	
	
	system("pause");
	return 0;
}

void pedirDatos(rRegistro &a, bool &fin){
	cout<<"INGRESE DATOS DEL ESTUDIANTE (DNI=0 PARA SALIR):\n\n";
	cout<<"DNI:\n";
	cin>>a.DNI;
	cin.ignore();
	if (a.DNI!=0){
		cout<<"Nombre completo:\n";
		cin.getline(a.nombre,sizeof(a.nombre));
		cout<<"Disciplina: FUTBOL(F), NATACION(N), TAEKONDO(T), GIMNASIA(G)\n";
		cin>>a.disciplina;
		fin=false;
		
	}else{
		fin=true;
	}
	
	
}



