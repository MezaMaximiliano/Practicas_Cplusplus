//saber si un numero es par o impar

#include<iostream>
using namespace std;
int main(){

int num;
	cout<<"Ingrese un numero: ";
	cin>>num;

		if (num==0){     
			cout<<"El numero ingresado es cero.";

		}
		else if (num%2==0){    /*  EL " % " TE DA EL RESTO. ES COMO EL MOD. SOLO SE PUEDE USAR CON VARIABLES ENTERAS*/
			cout<<"El numero es par.";
		}
		else {
			cout<<"El numero es impar.";
		}
return 0;

}
