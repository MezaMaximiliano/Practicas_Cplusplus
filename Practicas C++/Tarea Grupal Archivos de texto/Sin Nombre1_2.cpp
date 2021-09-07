#include<stdlib.h>
#include<stdio.h>
#include<ostream>
#include<fstream>
#include<iostream>
#include<string.h>

#define _CANT 60
#define _CANTCAT 5

using namespace std;

struct tEmp{
	int edad;
	int sueldo;
	string cat;
	string nombre;

};

struct tCategoria{
	int a;
	int b;
	int c;
	int d;
	int e;
	
};

typedef tEmp vecEmp[_CANT];
typedef tCategoria vecCat[_CANTCAT];


void iniVec(vecEmp);
void cargarVec(vecEmp,int &);
void ordenarVec(vecEmp, int,vecCat);
void corte (vecEmp,int,vecCat);
void iniVecCat(vecCat);


int main(){
	
	vecEmp empleado;
	vecCat cantCat;
	int cantEmp=0;
	string cadena;
	ifstream ar("Prueba.txt");
	iniVec(empleado);
	iniVecCat(cantCat);
	if (ar.fail()){
		cout<<"No se pudo abrir el archivo. "<<endl;
	}else{
	
	cargarVec(empleado, cantEmp);
	ordenarVec(empleado, cantEmp,cantCat);

	for (int i=0;i<cantEmp;i++){
		
		printf("%-20s  %20i %20i %20s\n",empleado[i].nombre.c_str(),empleado[i].edad,empleado[i].sueldo,empleado[i].cat.c_str());
		
		
	}
	
	}


	
	
	ar.close();
	system("pause");
	return 0;
}

void iniVecCat(vecCat a){
	for (int i=0;i<_CANTCAT;i++){
		a[i].a=0;
		a[i].b=0;
		a[i].c=0;
		a[i].d=0;
		a[i].e=0;
	}
}


void ordenarVec(vecEmp a,int cantEmp,vecCat cantCat){
	vecEmp aux;
	int comp1=0,comp2=0;
	for(int i=0;i<cantEmp;i++){
		for (int j=0;j<cantEmp-1;j++){
			
			comp1=memcmp(a[j].cat.c_str(),a[j+1].cat.c_str(),sizeof(a[j].cat.c_str()));
			if (comp1>0){
				aux[0]=a[j];
				a[j]=a[j+1];
				a[j+1]=aux[0];
								
			}
		}
	}	

		

	comp1=0,comp2=0;
	for(int i=0;i<cantEmp;i++){
		for(int j=0;j<cantEmp-1;j++){
			
			comp1=memcmp(a[j].cat.c_str(),a[j+1].cat.c_str(),sizeof(a[j].cat.c_str()));
			comp2=memcmp(a[j].nombre.c_str(),a[j+1].nombre.c_str(),sizeof(a[j].nombre.c_str()));
			if((comp1==0)and(comp2>0)){
				aux[0]=a[j];
				a[j]=a[j+1];
				a[j+1]=aux[0];	
			}
		}
	}

}

/*for (i=0; i<5;i++){
		
		for (j=0;j<4;j++){ //el segundo bucle se debe ejecutar hasta cantidad de elementos - 1
			
			if (vector[j]>vector[j+1]){  //si numero actual es mayor a numero siguiente
			
				varAux=vector[j];	//variable auxiliar es igual a numero actual
				vector[j]=vector[j+1];	//numero actual es igual a numero siguiente
				vector[j+1]=varAux;		//numero siguiente es igual a numero actual(que habia sido guardado en la primer linea del if
				
			}
			
		}
			
	}*/


void corte(vecEmp a, int cantEmp, vecCat cantCat){
	
	
	
}

void iniVec(vecEmp a){

	for (int i=0;i<_CANT;i++){
		a[i].edad=0;
		a[i].sueldo=0;
		a[i].nombre="";
		a[i].cat="";
		
	}
	
	
}

void cargarVec(vecEmp persona, int &cantEmp){
	cantEmp=0;
	int primero=0,ultimo=0, i=0;
	string cadena;
	ifstream ar("Prueba.txt");
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
		persona[i].cat=cadena.substr(primero,ultimo-primero);
		primero=ultimo+1;
		
		i++;
	
	}
	cantEmp=i;
	
	ar.close();
}
