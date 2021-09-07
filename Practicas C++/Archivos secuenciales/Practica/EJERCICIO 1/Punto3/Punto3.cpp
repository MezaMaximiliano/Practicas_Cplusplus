#include<stdlib.h>
#include<stdio.h>
#include<ostream>
#include<fstream>
#include<iostream>
#include<string.h>

using namespace std;

#define NOMBRE 60
#define DISCIPLINA 2
#define CANT 100

typedef char str60[NOMBRE];
typedef char str1[DISCIPLINA];

struct tIns {
	unsigned long int DNI;
	string nombre;
	string disciplina;
};

struct rCant{
	int f;
	int n;
	int t;
	int g;
	int errores;
};

typedef tIns vecIns[CANT];

void iniVec (vecIns,rCant &);
void cargarVec(vecIns,int &);
void ordenarVec(vecIns,int );
void cargarFile(vecIns,int,rCant &);
void mostrarCant();

int main(){
	
	vecIns vecTemp;
	rCant cantIns;
	int cantAlum=0;
	iniVec(vecTemp,cantIns);
	ifstream ar("INSCRIPCION.txt");
	

	cargarVec(vecTemp,cantAlum);
	ordenarVec(vecTemp,cantAlum);
	cargarFile(vecTemp,cantAlum,cantIns);
	mostrarCant();
	
	system("pause");
	return 0;
}

void mostrarCant(){
	FILE *fInscripcion;
	rCant cantIns2;
	fInscripcion=fopen("Cantidad.dat","rb");
	fread(&cantIns2, sizeof(rCant), 1, fInscripcion);
	
	cout<<"Natacion: "<<cantIns2.n<<endl; 
	cout<<"Taekondo: "<<cantIns2.t<<endl;
	cout<<"Gimnasia: "<<cantIns2.g<<endl;
	cout<<"Futbol  : "<<cantIns2.f<<endl;
	cout<<"Errores : "<<cantIns2.errores<<endl;
	
	fclose(fInscripcion);
	
}

void cargarFile(vecIns a,int b, rCant &cant){
	
	FILE *fInscripcion;
	
	for (int i=0;i<b;i++){
		
		if ((strcmp(a[i].disciplina.c_str(),"F")==0)){
			fInscripcion=fopen("Futbol.dat","rb+");
			if (fInscripcion==NULL){
				fInscripcion=fopen("Futbol.dat","wb+");
				fwrite(&a[i].DNI,sizeof(unsigned long int),1,fInscripcion);
				fwrite(&a[i].nombre,sizeof(string),1,fInscripcion);
			}else{
				fwrite(&a[i].DNI,sizeof(unsigned long int),1,fInscripcion);
				fwrite(&a[i].nombre,sizeof(string),1,fInscripcion);
				
			}
				
			cant.f++;						
		}else if (strcmp(a[i].disciplina.c_str(),"T")==0){
			fInscripcion=fopen("Taekondo.dat","rb+");
			if (fInscripcion==NULL){
				fInscripcion=fopen("Taekondo.dat","wb+");
				fwrite(&a[i].DNI,sizeof(unsigned long int),1,fInscripcion);
				fwrite(&a[i].nombre,sizeof(string),1,fInscripcion);
			}else{
				fwrite(&a[i].DNI,sizeof(unsigned long int),1,fInscripcion);
				fwrite(&a[i].nombre,sizeof(string),1,fInscripcion);
				
			}
			
			cant.t++;
		}else if (strcmp(a[i].disciplina.c_str(),"G")==0){
			fInscripcion=fopen("Gimnasia.dat","rb+");
			if (fInscripcion==NULL){
				fInscripcion=fopen("Gimnasia.dat","wb+");
				fwrite(&a[i].DNI,sizeof(unsigned long int),1,fInscripcion);
				fwrite(&a[i].nombre,sizeof(string),1,fInscripcion);
			}else{
				
				fwrite(&a[i].DNI,sizeof(unsigned long int),1,fInscripcion);
				fwrite(&a[i].nombre,sizeof(string),1,fInscripcion);
				
			}
			cant.g++;
		}else if (strcmp(a[i].disciplina.c_str(),"N")==0){
			fInscripcion=fopen("Natacion.dat","rb+");
			if (fInscripcion==NULL){
				fInscripcion=fopen("Natacion.dat","wb+");
				fwrite(&a[i].DNI,sizeof(unsigned long int),1,fInscripcion);
				fwrite(&a[i].nombre,sizeof(string),1,fInscripcion);
			}else{
				fwrite(&a[i].DNI,sizeof(unsigned long int),1,fInscripcion);
				fwrite(&a[i].nombre,sizeof(string),1,fInscripcion);
				
			}
			cant.n++;
		}else{
		cant.errores++;
	}
		
	}
	
	
	
	fInscripcion=fopen("Cantidad.dat","rb+");
	if(fInscripcion==NULL){
		fInscripcion=fopen("Cantidad.dat","wb+");
		fwrite(&cant,sizeof(rCant),1,fInscripcion);
	}else{
		fwrite(&cant,sizeof(rCant),1,fInscripcion);
	}
	
	fclose(fInscripcion);
}



void ordenarVec(vecIns a,int b){
	
	int i, j;
	tIns varAux;
	
	
	for (i=0; i<b;i++){
		
		for (j=0;j<b-1;j++){ 
			
			if (a[j].DNI>a[j+1].DNI){ 
			
				varAux=a[j];
				a[j]=a[j+1];	
				a[j+1]=varAux;	
				
			}
			
		}
			
	}
}

void cargarVec(vecIns a,int &cantAlum){
	cantAlum=0;
	int primero=0,ultimo=0, i=0;
	string cadena;
	ifstream ar("INSCRIPCION.txt");
	while (!ar.eof()){
	
		getline(ar,cadena);
		
		ultimo=cadena.find(";",primero);
		a[i].DNI=atoi(cadena.substr(primero,ultimo-primero).c_str());
		primero=ultimo+1;
	
		ultimo=cadena.find(";",primero);
		a[i].nombre=cadena.substr(primero,ultimo-primero).c_str();
		primero=ultimo+1;
		
		ultimo=cadena.find(";",primero);
		a[i].disciplina=cadena.substr(primero,ultimo-primero).c_str();
		primero=ultimo+1;
		
		i++;
	
	}
	cantAlum=i;
	
	ar.close();
	
}


void iniVec(vecIns a,rCant &b){
	
	for (int i=0;i<CANT;i++){
		a[i].DNI=0;
		a[i].nombre="";
		a[i].disciplina="";
	}
	b.g=0;
	b.f=0;
	b.t=0;
	b.n=0;
	b.errores=0;
}
