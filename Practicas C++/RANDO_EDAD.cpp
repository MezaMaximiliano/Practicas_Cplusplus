//rango de edad entre 18-25 a�os
#include<iostream>

using namespace std;
int main(){
	int edad;
	cout<<"Ingrese su edad: ";
	cin>>edad;

	if ((edad>=18)&&(edad<=25)){
		cout<<"Su edad se encuentra en el rango de 18-25 a�os.";
	}
	else{
		cout<<"Su edad no se encuentra en el rango de 18-25 a�os.";
	}
	

	return 0;
}
