//calcular valores de 2^1 + 2^2 + 2^3 + 2^n
#include<iostream>
#include<stdlib.h>
#include<math.h>

using namespace std;
int main(){
	
	int potencia, elevado=0,suma=0;
	
	cout<<"Ingrese un numero: ";
	cin>>potencia;
	for (int i=1;i<=potencia;i++){
		elevado= pow(2,i);
		cout<<"2^"<<i<<" = "<<elevado<<endl;
		suma=suma+elevado;
		
	}
	cout<<"La suma total es = "<<suma<<endl;
	system("pause");
	return 0;
	
}
