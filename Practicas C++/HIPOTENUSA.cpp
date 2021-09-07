//calculo hipotenusa

#include<iostream>
#include<math.h>
using namespace std;
int main(){
	float cateto1, cateto2;
	float hipotenusa=0;
	
	cout<<"Ingrese cateto 1: ", cin>>cateto1;
	cout<<"Ingrese cateto 2: ", cin>>cateto2;
	
	hipotenusa= sqrt(pow(cateto1,2)+pow(cateto2,2));
	
	cout<<"\nHipotenusa vale: "<<hipotenusa<<endl;
	
	
	
	
	return 0;
}
