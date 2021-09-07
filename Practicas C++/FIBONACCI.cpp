//secuencia fubonacci hasta n numeros

#include<iostream>
#include<stdlib.h>
using namespace std;
int main(){
	
	int actual=1,anterior=0,transito=0,numero;
	cout<<"Ingrese un numero: ";
	cin>>numero;
	cout<<"1"<<endl;
	for (actual; actual<numero;){
		transito=actual;
		
		actual=actual+anterior;
		anterior=transito;
		
		if (numero>=actual){
		
		cout<<actual<<endl;
	}
		
	}
	
	
	
	system("pause");
	return 0;
}
