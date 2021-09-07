#include<iostream>
#include<stdlib.h>

using namespace std;
int main (){
	int anio, mes, dia, diamenor,mesmenor,aniomenor,diamayor,mesmayor,aniomayor;
	int anio1=0, mes1=0, dia1=0, fecha=0, fechamayor=0,fechamenor=99999999;
	string nombre, nombremayor,nombremenor;
	
	
	cout<<"Ingrese año: ";
	cin>>anio;
	cout<<"Ingrese mes: ";
	cin>>mes;
	cout<<"Ingrese dia: ";	
	cin>>dia;
	cout<<"Ingrese nombre: ";
	cin>>nombre;
	anio1=anio*10000;
	mes1=mes*100;
	fecha=anio1+mes1+dia;
	int i=1;
	do{
		if (fecha>fechamayor){
			fechamayor=fecha;
			aniomayor=anio;
			mesmayor=mes;
			diamayor=dia;
			nombremayor=nombre;
			
		}
		if (fecha<fechamenor){
			fechamenor=fecha;
			aniomenor=anio;
			mesmenor=mes;
			diamenor=dia;
			nombremenor=nombre;
		}
	cout<<"Ingrese año: ";
	cin>>anio;
	if (anio!=0){
	
		cout<<"Ingrese mes: ";
		cin>>mes;
		cout<<"Ingrese dia: ";
		cin>>dia;
		cout<<"Ingrese nombre: ";
		cin>>nombre;
		anio1=anio*10000;
		mes1=mes*100;
		fecha=anio1+mes1+dia;
	}
	}while(anio!=0);
	
	cout<<"Fecha menor: "<<diamayor<<"/"<<mesmayor<<"/"<<aniomayor<<endl;
	cout<<"Nombre de persona menor: "<<nombremayor<<endl;
	cout<<"Fecha mayor: "<<diamenor<<"/"<<mesmenor<<"/"<<aniomenor<<endl;
	cout<<"Nombre de persona mayor: "<<nombremenor<<endl;
	system("pause");
	return 0;
}
