/*Desarrollar un programa que procese datos de los estudiantes de un curso (máximo 60): nombre, fecha de nacimiento y  lugar 
de residencia ('C' = Casa, 'D' = Departamento) y cuente cuántos estudiantes viven en casa y cuántos en departamento. Deben dejar los estudiantes en un vector*/

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
void casaDepto (vector alumno, int &iAlumno, int &casa, int &departamento);
int main(){
	
	vector alumno;
	int iAlumno=0;
	int casa=0;
	int departamento=0;

	pedirDatos(alumno,iAlumno);
	casaDepto(alumno, iAlumno, casa,departamento);
	cout<<"Cantidad de alumnos que viven en casa son: "<<alumno[0].anio<<" "<<casa<<endl;
	cout<<"Cantidad de alumnos que viven en departamentos son: "<<departamento<<endl;
	system("pause");
	return 0;
}
void casaDepto(vector alumno, int &iAlumno, int &casa, int &departamento){
	int i=0;
	for (i;i<iAlumno;i++){
		cout<<alumno[i].anio<<endl;
		if (strcmp(alumno[i].vivienda, "c")==0){
			casa++;
		}else if(strcmp(alumno[i].vivienda,"d")==0){
			departamento++;
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

