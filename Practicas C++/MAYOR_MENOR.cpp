//Mayor de dos numeros

#include<iostream>
using namespace std;
int main(){
	float num1,num2;
	cout<<"Ingrese DOS numeros: "<<endl;
	cin>>num1>>num2;

	if (num1==num2) {
	cout<<"Los numeros ingresados son iguales.";
	
	}
	else if (num1>num2){
		cout<<num1<<" es mayor que "<<num2;
		}
		else {
			
			cout<<num2<<" es mayor que "<<num1;
		}
		
	
	
	
	return 0;
}
