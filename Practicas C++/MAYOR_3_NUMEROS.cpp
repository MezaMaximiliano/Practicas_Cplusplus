//Mayor de tres numeros

#include<iostream>
using namespace std;
int main(){
	
	float n1,n2,n3,mayor=0;
	
	cout<<"Ingrese TRES numeros: "<<endl;
	cin>>n1>>n2>>n3;
	
	if ((n1>n2)&&(n1>n3)){
		cout<<n1<<" Es el mayor.";
	}
	else if ((n2>n1)&&(n2>n3)){
		cout<<n2<<" Es el mayor.";
	}
	else if ((n3>n1)&&(n3>n2)){
		
		cout<<n3<<" Es el mayor.";
	}
	else if ((n1==n2)&&(n2==n3)){
		cout<<"Los numeros ingresados son iguales.";
	}
	
	return 0;
}   	//como hacer si dos son iguales y el otro no?
