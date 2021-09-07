//intercambiar valores de variables

#include<iostream>

using namespace std;

int main(){
	float var1;
	float var2;
	float varcont;
	
	cout<<"Ingrese variable 1: ",cin>>var1;
	
	cout<<"Ingrese variable 2: ",cin>>var2;
	
	varcont=var1;
	var1=var2,
	var2=varcont;
	
	cout<<"\nVariable 1 ahora es: "<<var1;
	cout<<"\nVariable 2 ahora es: "<<var2;
	
	return 0;
	
	
	
	
	
	
}

