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
void fechaPedirDatos(Fecha &dato){
	dato.anio=1989;
	dato.mes=07;
	dato.dia=16;
	dato.diaSemana="martes";

}
int main(){

	Fecha a;
	fechaPedirDatos(a);
	
	cout<<endl<<a.anio<<endl;
	cout<<a.mes<<endl;
	cout<<a.dia<<endl;
	cout<<a.diaSemana<<endl;
	return 0;
}
