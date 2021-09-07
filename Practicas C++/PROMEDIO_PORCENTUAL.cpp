//PROMEDIO CON PORCENTAJES DE NOTAS
#include<iostream>
using namespace std;

int main(){
	float np, nt, npar, promedio=0;
	cout<<"Ingrese nota practica: ",cin>>np;
	cout<<"Ingrese nota teorica: ", cin>>nt;
	cout<<"Ingrese nota participacion: ",cin>>npar;
	
	promedio= (np*0.3)+(nt*0.6)+(npar*0.1);
	
	cout<<"\nNota final: "<<promedio<<endl;
	
	
	return 0;
}
