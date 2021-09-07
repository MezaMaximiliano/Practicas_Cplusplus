//comparar numeros

#include<iostream>
using namespace std;
int main(){
	int n1,n2,n3, n4,caso=0;
	cout<<"Ingrese 3 numeros:"<<endl;
	cin>>n1>>n2>>n3;
	cout<<"Ingrese numero a comparar:"<<endl;
	cin>>n4;
	if ((n4==n1)||(n4==n2)||(n4==n3)){
		cout<<"El numero es igual a alguno de los anteriores.";
		
	} else{
		cout<<"El numero no es igual.";
	}
}
