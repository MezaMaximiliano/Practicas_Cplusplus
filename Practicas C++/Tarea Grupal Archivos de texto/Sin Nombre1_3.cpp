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

struct tCat{
	int a;
	int b;
	int c;
	int d;
	int e;
	
};

typedef tEmp vecEmp[_CANT];



void iniVec(vecEmp);
void cargarVec(vecEmp,int &);
void ordenarVec(vecEmp, int);
void corte (vecEmp,int);



int main(){
	
	vecEmp empleado;

	int cantEmp=0;
	string cadena;
	ifstream ar("Prueba.txt");
	iniVec(empleado);

	if (ar.fail()){
		cout<<"No se pudo abrir el archivo. "<<endl;
	}else{
	
	cargarVec(empleado, cantEmp);
	ordenarVec(empleado, cantEmp);

	for (int i=0;i<cantEmp;i++){
		
		printf("%-20s %20i %20i %20s\n",empleado[i].nombre.c_str(),empleado[i].edad,empleado[i].sueldo,empleado[i].cat.c_str());
		
		
	}
	
	}


	
	
	ar.close();
	system("pause");
	return 0;
}




void ordenarVec(vecEmp a,int cantEmp){
	vecEmp aux;
	int comp1=0,comp2=0,i=0,j=0;
	for(i=0;i<cantEmp;i++){
		for (j=0;j<cantEmp-1;j++){
			
			comp1=strcmp(a[j].cat.c_str(),a[j+1].cat.c_str());
								
			if (comp1>0){
				aux[0]=a[j];
				a[j]=a[j+1];
				a[j+1]=aux[0];
												
			}
				
		}
		
		
	}
	
	
		for(i=0;i<cantEmp;i++){
			for(j=0;j<cantEmp-1;j++){
				comp1=strcmp(a[j].cat.c_str(),a[j+1].cat.c_str());
				comp2=strcmp(a[j].nombre.c_str(),a[j+1].nombre.c_str());
				if ((comp1==0)and(comp2>0)){
					aux[0]=a[j];
					a[j]=a[j+1];
					a[j+1]=aux[0];
					
				}
				
			}
		}
	


/*	else if((comp1==0)and(comp2>0)){
				aux[0]=a[j];
				a[j]=a[j+1];
				a[j+1]=aux[0];	
			}
			comp1=memcmp(a[j].cat.c_str(),a[j+1].cat.c_str(),sizeof(a[j].cat.c_str()));
			comp2=memcmp(a[j].nombre.c_str(),a[j+1].nombre.c_str(),sizeof(a[j].nombre.c_str()));	
*/


}



void corte(vecEmp a, int cantEmp){
	
	
	
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
