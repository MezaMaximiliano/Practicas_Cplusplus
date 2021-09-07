#include<iostream>
#include<stdlib.h>
using namespace std;

struct dato {
	int dia;
	int mes;
};


void probar(dato &);
int main(){
	
	dato numero;
	
	probar(numero);
	cout<<"dia "<<numero.dia<<" mes "<<numero.mes<<endl;
	
	system("pause");
	return 0;
}

void probar(dato &n){
cout<<"Ingrese mes: "<<endl;
cin>>n.mes;
cout<<"Ingrese dia: "<<endl;	
cin>>n.dia;
}
