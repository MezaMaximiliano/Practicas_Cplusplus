//calculo de raices de funcion
#include<iostream>
#include<math.h>
using namespace std;
int main (){
	float a, b, c, raiz1=0, raiz2=0;
	cout<<"Ingrese valor de a: ";
	cin>>a;
	cout<<"Ingrese valor de b: ";
	cin>>b;
	cout<<"Ingrese valor de c: ";
	cin>>c;
	raiz1= (-b+sqrt(pow(b,2)-4*a*c))/(2*a);
	raiz2= (-b-sqrt(pow(b,2)-4*a*c))/(2*a);
	cout<<"\nRaiz mayor = "<<raiz1<<" y raiz menor = "<<raiz2<<endl;
	
	int valor = 4;
	string mensaje;
	
	mensaje = (valor%2==0) ? "Es par" : "Es inmpar";
	
	cout << mensaje;
	
	
	return 0;
}
