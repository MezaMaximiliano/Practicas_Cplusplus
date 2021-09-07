//MENU  3 OPCIONES
//INTENTARLO HACER PERO USANDO ACCIONES EN VEZ DE ESCRIBIR EL CODIGO COMPLETO
#include<iostream>
using namespace std;
int main(){
	int opcion, num;
	float cubo,cunum;
	cout<<"Eliga una opcion:"<<endl<<"1-Cubo de un numero."<<endl<<"2-Numero par o impar."<<endl<<"3-Salir."<<endl;
	cin>>opcion;
	switch (opcion){
		case 1:
			cout<<"Ingrese un numero: ",cin>>num;
			cunum=num;
			cubo=num*num*num;
			cout<<"El cubo de "<<cunum<<" es "<<cubo;
			break;
		case 2:
			cout<<"Ingrese un numero: ";
			cin>>num;

			if (num==0){     
				cout<<"El numero ingresado es cero.";

			}
			else if (num%2==0){    /*EL " % " TE DA EL RESTO. ES COMO EL MOD. SOLO SE PUEDE USAR CON VARIABLES ENTERAS*/
				cout<<"El numero es par.";
			}
			else {
				cout<<"El numero es impar.";
			}
			break;
		case 3:
			cout<<"Ha elegido salir.";
			break;
		default:
			cout<<"No ha elegido una opcion valida.";
			break;
		
	}
	
	return 0;
}
