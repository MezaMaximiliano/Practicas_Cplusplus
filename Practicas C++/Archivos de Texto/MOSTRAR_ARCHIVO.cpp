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
};

typedef tPersona vecTPersona[20];
void iniVec(vecTPersona);

int main(){
	vecTPersona persona;
	string cadena;
	string palabra[20];
	ifstream ar("Prueba.txt");

	int ultimo=0,primero=0;
	

	
	while (!ar.eof()){
	
		getline(ar,cadena);
	
		ultimo=cadena.find(";",primero);
		palabra[0]=cadena.substr(primero,ultimo-primero);
		primero=ultimo+1;
		ultimo=cadena.find(";",primero);
		palabra[1]=cadena.substr(primero,ultimo-primero);
		primero=ultimo+1;
		ultimo=cadena.find(";",primero);
		palabra[2]=cadena.substr(primero,ultimo-primero);
		primero=ultimo+1;
		cout<<palabra[0]<<"\t"<<palabra[1]<<"\t"<<palabra[2]<<endl;
	}
	ar.close();
	system("pause");
	return 0;
}

/*void iniVec(vecTPersona a){
	
	for (int i=0;i<20;i++){
		a[i].sueldo=0;
		memcpy(a[i].categoria,"");
		memcpy(a[i].nombre,"");
	}
	
}*/

