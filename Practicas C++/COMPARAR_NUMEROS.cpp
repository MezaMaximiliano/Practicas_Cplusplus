//comparar numeros

#include<iostream>
using namespace std;
int main(){
	int n1,n2,n3, n4,caso=0;
	cout<<"Ingrese 3 numeros:"<<endl;
	cin>>n1>>n2>>n3;
	cout<<"Ingrese numero a comparar:"<<endl;
	cin>>n4;
	if (n4==n1){
		caso=1;
	}else if (n4==n2){
		caso=2;
	} else if(n4==n3){
		caso=3;
	}
	switch (caso){
		case 1: cout<<"El numero ingresado es igual al primer numero.";
			break;
		case 2: cout<<"El numero ingresado es igual al segundo numero.";
			break;
		case 3: cout<<"El numero ingresado es igual al tercer numero.";
			break;
		default : cout<< "El numero ingresado no es igual a ningun numero.";
			break;
		
	}
	
	return 0;
}
