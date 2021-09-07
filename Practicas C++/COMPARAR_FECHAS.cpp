#include<iostream>
#include<stdlib.h>

using namespace std;
int main (){
	int anio, mes, dia;
	long int anio1=0, mes1=0, dia1=0, fecha1=0;
cout<<"Ingrese año: ";
cin>>anio;
cout<<"Ingrese mes: ";
cin>>mes;
cout<<"Ingrese dia: ";	
cin>>dia;

anio1= anio*10000;
mes1= mes*100;
dia1=dia;

fecha1=anio1+mes1+dia1;

cout<<"la fecha es: "<<fecha1<<endl;	
	system("pause");
	return 0;
}
