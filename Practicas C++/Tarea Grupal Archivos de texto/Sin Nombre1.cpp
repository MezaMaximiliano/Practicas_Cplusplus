#include<stdlib.h>
#include<ostream>
#include<fstream>
#include<iostream>
#include<string.h>

#define _CANT 60
#define _CANTNOM 30

using namespace std;

struct tEmp{
	int edad;
	int sueldo;
	string cat;
	string nombre;

};

typedef tEmp vecEmp[_CANT];

void iniVec(vecEmp);
void cargarVec(vecEmp,int &);
void ordenarVec(vecEmp, int);


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
		cout<<empleado[i].nombre<<"\t\t\t"<<empleado[i].edad<<"\t\t"<<empleado[i].sueldo<<"\t\t"<<empleado[i].cat<<endl;
	}
	
	}


	
	
	ar.close();
	system("pause");
	return 0;
}

void ordenarVec(vecEmp a,int cantEmp){
	string catAnt,catAct;
	int k=0;

 	vecEmp aux;
  	int minimo=0;
 	for(int i=0;i<cantEmp;i++) {
    	minimo = i ;
	  	for(int j=i+1;j<cantEmp;j++) {
	  	 	if  (memcmp(a[j].cat.c_str(),a[minimo].cat.c_str(),sizeof(a[j].cat.c_str()))<0)  {
      		minimo = j ;
     	    }
    	 }
   		aux[0]=a[i];
   		a[i]=a[minimo];
    	a[minimo]=aux[0];	
 	}
	
	
	while(k<cantEmp){
		
		if (memcmp(a[k].cat.c_str(),a[k+1].cat.c_str(),sizeof(a[k].cat.c_str()))==0){
			if(memcmp(a[k+1].nombre.c_str(),a[k].nombre.c_str(),sizeof(a[k].nombre.c_str()))<0){
				
				aux[0]=a[k];
				a[k]=a[k+1]; 
				a[k+1]=aux[0];
				
			}
			
		}
	
		k++;
	
	}

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
