#include <iostream>
#include"Cuadrilatero.h"
using namespace std;

int main(int argc, char** argv) {
	
	float lado1, lado2;
		
	Cuadrilatero *c1;
	
/*	printf("Ingrese lado 1: ");
	scanf("%f",&lado1);
	printf("Ingrese lado 2: ");
	scanf("%f",&lado2);*/
	
	cout<<"Ingrese lado 1:";
	cin>>lado1;
	cout<<"\nIngrese lado 2: ";
	cin>>lado2;
	
	if(lado1==lado2){
		c1=new Cuadrilatero(lado1);
	}else{
		c1=new Cuadrilatero(lado1,lado2);
	}
	
/*	printf("\nEl area es = %f",c1->getArea());
	printf("\nEl perimetro es = %f\n",c1->getPerimetro());*/
	
	cout<<"\nEl area es: "<<c1->getArea()<<endl;
	cout<<"El perimetro es: "<<c1->getPerimetro()<<endl;
	
	//printf te imprime mas decimales que cout
	
	return 0;
}
