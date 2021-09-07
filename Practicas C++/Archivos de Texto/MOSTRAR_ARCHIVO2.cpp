/*Leer desde un .txt y mostrar el contenido en pantalla*/
#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<ostream>
#include<string.h>
#include<cstring>

using namespace std;

struct tPersona{
	string nombre;
	string categoria;
	int sueldo;
	int edad;
};

typedef tPersona vecTPersona[20];
void iniVec(vecTPersona);

int main(){
	vecTPersona persona;
	string cadena;
	string palabra[20];
	ifstream ar("Prueba.txt");
	iniVec(persona);
	int ultimo=0,primero=0;
	int i=0;


	while (!ar.eof()){
	
		getline(ar,cadena);
	
		ultimo=cadena.find(";",primero);
		persona[i].nombre=cadena.substr(primero,ultimo-primero);
		primero=ultimo+1;
		
		ultimo=cadena.find(";",primero);
		persona[i].edad=atoi(cadena.substr(primero,ultimo-primero).c_str());
		primero=ultimo+1;
		
		ultimo=cadena.find(";",primero);
		persona[i].sueldo=atoi(cadena.substr(primero,ultimo-primero).c_str());
		primero=ultimo+1;
		
		ultimo=cadena.find(";",primero);
		persona[i].categoria=cadena.substr(primero,ultimo-primero);
		primero=ultimo+1;
		
		i++;
	
	}
		
	for (int j=0;j<=i-1;j++){
		
		cout<<persona[j].nombre<<"\t\t\t"<<persona[j].edad<<"\t\t\t"<<persona[j].sueldo<<"\t\t\t"<<persona[j].categoria<<endl;
		
		
	}
	
	ar.close();
	system("pause");
	return 0;
}

void iniVec(vecTPersona a){
	
	for (int i=0;i<20;i++){
		a[i].sueldo=0;
		a[i].edad=0;
		a[i].categoria="";
		a[i].nombre="";
	}
	
}

