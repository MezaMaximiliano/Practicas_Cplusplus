//expresiones 2
#include<iostream>


using namespace std;

int main (){
	float num1, num2,num3,num4,num5,num6,num7,resultado=0;
	
	cout<<"Ingrese numero 1: ", cin>>num1;
	cout<<"\nIngrese numero 2: ", cin>>num2;
	cout<<"\nIngrese numero 3: ", cin>>num3;
	cout<<"\nIngrese numero 4: ", cin>>num4;
	cout<<"\nIngrese numero 5: ", cin>>num5;
	cout<<"\nIngrese numero 6: ", cin>>num6;
	
	resultado= (num1+(num2/num3))/ (num4+(num5/num6));
	cout<<"\nEl resultado es: "<<resultado<<endl;
		
	
	return 0;
}
