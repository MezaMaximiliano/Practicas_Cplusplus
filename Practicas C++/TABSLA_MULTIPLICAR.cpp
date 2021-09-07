//tabla de multiplicar de numero ingresado del 1 al 10
#include<iostream>
#include<stdlib.h>
using namespace std;
int main(){
	
	int numero, multiplicador;
	do{
	
	cout<<"Ingrese un numero: ";
	cin>>numero;
	if ((numero<1)||(numero>10)){
		
	cout<<"Numero fuera de rango."<<endl;
	
	}
	}while ((numero<1)||(numero>10));
	for (multiplicador=1;multiplicador<=10;multiplicador++){
		cout<<numero*multiplicador<<endl;
	}
	
	
	system("pause");
	return 0;
}
