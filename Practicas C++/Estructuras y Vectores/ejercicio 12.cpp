#include<stdlib.h>
#include<iostream>
#include<cstring>


using namespace std;

struct dato {
	string nombre;
	int anio;
	int mes;
	int dia;
	char vivienda[1];
};
typedef dato vector[60];
void pedirDatos(vector a,int &iAlumno);
void casaDepto (vector alumno, vector casa, vector departamento, int &iAlumnos);
int main(){
	
	vector alumno;
	vector casa;
	vector departamento;
	int iAlumno=0;
	
	setlocale(LC_ALL, "spanish");

	pedirDatos(alumno,iAlumno);
	casaDepto(alumno, casa,departamento, iAlumno);
	int respuesta;
	cout<<"Ingrese el valor: "<<endl;cin>>respuesta;
	
	cout<<casa[respuesta].anio<<endl;
	cout<<departamento[respuesta].anio<<endl;
	
	system("pause");
	return 0;
}
void casaDepto(vector alumno, vector casa, vector departamento, int &iAlumno){
	int c=0;
	int d=0;
    for (int i=0; i<iAlumno;i++){
    	if (strcmp(alumno[i].vivienda,"c")==0){
    		
    		casa[c]=alumno[i];
    		c++;
    	}else if(strcmp(alumno[i].vivienda,"d")==0){
    	departamento[d]=alumno[i];
    	d++;
    	
    	}
	}
}
void pedirDatos(vector a, int &iAlumno){
	bool seguir=true;
	int respuesta=1;
	for (seguir; seguir==true;){
		
		cout<<"Ingrese nombre del alumno: ";
		cin>>a[iAlumno].nombre;
		cout<<"Ingrese año de nacimiento: ";
		cin>>a[iAlumno].anio;
		cout<<"Ingrese mes de nacimiento: ";
		cin>>a[iAlumno].mes;
		cout<<"Ingrese dia de nacimiento: ";
		cin>>a[iAlumno].dia;
		cout<<"Ingrese lugar de residencia (Casa \"C\" o Departamento \"D\"): ";
		cin>>a[iAlumno].vivienda;
		cout<<"Ingrese 0 para salir: ";
		cin>>respuesta;
		if (respuesta!=0){
			seguir=true;
		}else{
			seguir=false;
		}
		
		iAlumno++;
	}
	
}

