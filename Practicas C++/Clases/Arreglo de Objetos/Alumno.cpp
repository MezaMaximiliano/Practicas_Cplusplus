#include<iostream>
#include "Alumno.h"
using namespace std;

void Alumno::setCal(){
	cout<<"Calificacion de Matematica: ";
	cin>>calMate;
	cout<<"\nCalificacion de Geografia: ";
	cin>>calGeo;
	cout<<endl;
	
}

void Alumno::mostrarCal(){
	cout<<"Calificion de Matematica es "<<calMate;
	cout<<"\nCalificaciono de Geografia "<<calGeo<<endl;
}


