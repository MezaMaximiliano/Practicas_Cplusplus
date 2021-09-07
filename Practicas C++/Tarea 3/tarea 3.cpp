/*Procesar las edades de un conjunto de personas de las cuales nos informan su nombre y fecha de nacimiento.
Se debe mostrar por pantalla:
- el nombre de la persona mayor;
- el nombre de la persona menor;
- cu�ntas personas tienen menos de 20 a�os;
- cu�ntas personas tienen entre 21 y 30 a�os;
- cu�ntas personas tienen m�s de 31 a�os

Supongan que no hay dos personas que hayan nacido el mismo d�a.

Pista 1: para conocer la edad en a�os de cada estudiante pueden usar la siguiente funci�n (buscar el programa en los ejemplos publicados)

int diferenciaFechas(int dia1, int mes1, int anio1, int dia2, int mes2, int anio2) {
   int dif;

   dif =abs(((anio1-anio2)*12 +(mes1-mes2))*30 +dia1-dia2);
return dif;
}*/
#include<stdlib.h>
#include<iostream>
int contmen20=0,cont2030=0,contmas30=0;

using namespace std;

int contadoranio(int a){
	int aniocomparar=0;
	aniocomparar=2020-a;
	if (aniocomparar<20){
		contmen20=contmen20+1;
	}
	if (aniocomparar>=20 and aniocomparar<=30){
		cont2030++;
	}
	if (aniocomparar>30){
		contmas30++;
	}
}

int main(){

	int anio, mes, dia;
	string nombre;
	cout<<"Ingrese a�o: ";
	cin>>anio;
	if (anio!=0){
		do{
			cout<<"Ingrese mes: ";
			cin>>mes;
			cout<<"Ingrese dia: ";
			cin>>dia;
			cout<<"Ingrese el nombre: ";
			cin >>nombre;
			contadoranio(anio);
			cout<<"Ingrese a�o: ";
			cin>>anio;
			
			
		}while (anio!=0);
	}else{
		cout<<"Fin del programa."<<endl;
	}
	cout<<contmen20<<"  "<<cont2030<<"  "<<contmas30<<endl;
	system("pause");
	return 0;
}

