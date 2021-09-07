/*Definir un tipo de datos ESTRUCTURA que permita representar una fecha con el a�o, el mes, el d�a y el d�a de la semana (lunes, martes, mi�rcoles�.)*/

#include<stdlib.h>
#include<iostream>

using namespace std;
typedef int entero;
struct Fecha {
	entero anio;
	entero mes;
	entero dia;
	string diaSemana;
};
void fechaPedirDatos(Fecha &dato); //prototipo de funcion fechaPedirDatos
int main(){

	Fecha a;
	fechaPedirDatos(a);
	
	cout<<endl<<a.anio<<endl;
	cout<<a.mes<<endl;
	cout<<a.dia<<endl;
	cout<<a.diaSemana<<endl;
	return 0;
}
void fechaPedirDatos(Fecha &dato){
	
	cout<<"Ingrese a�o: "<<endl;
	cin>>dato.anio;
	cout<<"Ingrese mes: "<<endl;
	cin>>dato.mes;
	cout<<"Ingrese dia: "<<endl;
	cin>>dato.dia;
	cout<<"Ingrese dia de la semana: "<<endl;
	cin>>dato.diaSemana;
}
