#include<stdlib.h>
#include<stdio.h>
#include<ostream>
#include<fstream>
#include<iostream>
#include<string.h>

using namespace std;

#define NOMBRE 60
#define DISCIPLINA 2
#define CANT 100

typedef char str60[NOMBRE];
typedef char str1[DISCIPLINA];

struct tIns {
	unsigned long int DNI;
	string nombre;
	string disciplina;
};

typedef tIns vecIns[CANT];

void iniVec (vecIns);
void cargarVec(vecIns,int &);


int main(){
	
	vecIns vecTemp;
	int cantAlum=0;
	iniVec(vecTemp);
	ifstream ar("INSCRIPCION.txt");
	cargarVec(vecTemp,cantAlum);
	
	for (int i=0;i<cantAlum;i++){
		cout<<vecTemp[i].DNI<<endl;
	}
	
	
	system("pause");
	return 0;
}

void cargarVec(vecIns a,int &cantAlum){
	cantAlum=0;
	int primero=0,ultimo=0, i=0;
	string cadena;
	ifstream ar("INSCRIPCION.txt");
	while (!ar.eof()){
	
		getline(ar,cadena);
		
		ultimo=cadena.find(";",primero);
		a[i].DNI=atoi(cadena.substr(primero,ultimo-primero).c_str());
		primero=ultimo+1;
	
		ultimo=cadena.find(";",primero);
		a[i].nombre=cadena.substr(primero,ultimo-primero).c_str();
		primero=ultimo+1;
		
		ultimo=cadena.find(";",primero);
		a[i].disciplina=cadena.substr(primero,ultimo-primero).c_str();
		primero=ultimo+1;
		
		i++;
	
	}
	cantAlum=i;
	
	ar.close();
	
}


void iniVec(vecIns a){
	
	for (int i=0;i<CANT;i++){
		a[i].DNI=0;
		a[i].nombre="";
		a[i].disciplina="";
	}
	
}
