//ejercicio 3

#include<iostream>
#include<stdlib.h>
#include<math.h>

using namespace std;

float quin (float n, float q=0){  /*la funcion asi declarada es por valor.*/
								  /*si la quiero por referencia (direccion de memoria seria:*/
	q=n/5;						  /* float quin (float &n, float q=0)  el & causa usar la referencia en vez de el valor*/
	return q;
	
}

float res (int n, float r=0 ){
	r=n % 5;
	return r;
}

float sep (float n, float s=0){
	s=(n/5)/7;
	return s;
}

int main (){
	float numero; 
	float  septima=0,resto=0;
	double quinta=0;
	cout<<"Ingrese un numero: "<<endl;
	cin>>numero;
	
	quinta=quin(numero);
	septima=sep(numero);
	resto=res(numero);
	
	cout<<"La quinta parte es: "<<quinta<<endl;
	cout<<"La septima parte de la quinta parte es: "<<septima<<endl;
	cout<<"El de dividirlo por 5 es: "<<resto<<endl;
	
	
	
	system("pause");
	return 0;
}
