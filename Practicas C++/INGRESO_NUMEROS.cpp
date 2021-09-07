//ingresar numero hasta digitar el cero y contar los positivos ingresados

#include<iostream>
#include<stdlib.h>
using namespace std;
int main(){
	int num,contador;
	contador=0;
	do{
		cout<<"Ingrese un numero: ";
		cin>>num;
		if (num>0){
			contador++;
		}
	}while(num!=0);
	
	cout<<"\nHa ingresado "<<contador<<" numeros mayores a cero.\n"<<endl;
	
	
	
	
	
	
	system("pause");
	return 0;
}
