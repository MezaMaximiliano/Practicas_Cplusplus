//ejercicio 4 y 5
#include <iostream>
#include<stdlib.h>
using namespace std;
int main (){
	int a, b, mayor=0, menor=0;
	cout<<"Ingrese un numero: "<<endl;
	cin>>a;
	cout<<"Ingrese otro numero: "<<endl;
	cin>>b;
	if (a==b){
		cout<<"Los numeros son iguales."<<endl;
	}else if(a>b){
		mayor=a;
		menor=b;
		cout<<"El mayor de los numeros es "<<mayor<<endl;
		cout<<"El menor de los numeros es "<<menor<<endl;

	}else if (b>a){
	 
	mayor=b;
	menor=a;
	cout<<"El mayor de los numeros es "<<mayor<<endl;
	cout<<"El menor de los numeros es "<<menor<<endl;
	
	}
	system("pause");
	return 0;
}
