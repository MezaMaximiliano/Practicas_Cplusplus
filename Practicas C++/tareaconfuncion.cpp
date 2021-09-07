#include<iostream>
#include<stdlib.h>

using namespace std;

int fechato(int anio1=0,int mes1=0,int dia1=0, int fecha1=0){
	anio1=anio1*10000;
	mes1=mes1*100;
	fecha1=anio1+mes1+dia1;
	
}

int main (){
	int anio, mes, dia, diamenor,mesmenor,aniomenor,diamayor,mesmayor,aniomayor;
	int fecha=0, fechamayor=0,fechamenor=99999999;
	string nombre, nombremayor,nombremenor;
	
	
	cout<<"Ingrese año: ";
	cin>>anio;
	if (anio!=0){
	
	
	cout<<"Ingrese mes: ";
	cin>>mes;
	cout<<"Ingrese dia: ";	
	cin>>dia;
	cout<<"Ingrese nombre: ";
	cin>>nombre;
	
	fecha=fechato(anio,mes,dia);
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
		if(anio!=0){
			cout<<"Ingrese mes: ";
			cin>>mes;
			cout<<"Ingrese dia: ";	
			cin>>dia;
			cout<<"Ingrese nombre: ";
			cin>>nombre;
			
		}
		fecha=fechato(anio,mes,dia);
	}while (anio!=0);
	cout<<"menor: "<<diamayor<<"/"<<mesmayor<<"/"<<aniomayor<<endl;
	cout<<"mayor: "<<diamenor<<"/"<<mesmenor<<"/"<<aniomenor<<endl;
	}else{
		cout<<"No ingreso valores."<<endl;
	}
	
	system("pause");
	return 0;
}
