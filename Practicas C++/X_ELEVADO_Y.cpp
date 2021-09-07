//usuario ingresa valor de x, y valor de y, el programa eleva x a y (x^y)
#include<iostream>
#include<stdlib.h>
using namespace std;
int main(){
	int x, y,resultado=0;
	cout<<"Ingrese un numero: ";
	cin>>x;
	cout<<"Ingrese a cual potencia elevar el numero ingresado: ";
	cin>>y;
	resultado=x;
	for (int i=1;i<y;i++){
		resultado=resultado*x;
	}
	cout<<resultado<<endl;
	system("pause");
	return 0;
}
