/*programa que lea valores enteros hasta 
que se introduzca un valor en el rango [20-30]
o se introduzca el valor 0. El programa debe 
entregar la suma de los valores mayores a 0 introducidos.*/

#include<iostream>
#include<stdlib.h>

using namespace std;
int main(){
	int num, suma=0;
	do{
		cout<<"Ingrese un numero: ",cin>>num;
		if (num>0){
			suma=suma+num;
		}
		
	}while(((num<20)||(num>30))&&(num!=0));//si pongo un = incluyo el 20 y el 30 dentro dentro del rango no permitido

cout<<suma<<endl;
	system("pause");
	return 0;
}
//revisar condicion logica del while.
//el do-while se repite para todos los valores que sean mayor a 20 o menor a 30 y diferente a 0
