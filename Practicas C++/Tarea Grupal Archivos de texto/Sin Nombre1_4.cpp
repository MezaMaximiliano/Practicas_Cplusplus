#include<stdlib.h>
#include<stdio.h>
#include<ostream>
#include<fstream>
#include<iostream>
#include<string.h>

#define _CANT 60
#define _CANTCAT 5

using namespace std;

struct tTotal{
	int totalSueldo;
	int totalEmp;
	float promedioCat;

};

struct tEmp{
	int edad;
	int sueldo;
	string cat;
	string nombre;

};

typedef tTotal vecTotal[_CANTCAT];



typedef tEmp vecEmp[_CANT];



void iniVec(vecEmp);
void cargarVec(vecEmp,int &);
void ordenarVec(vecEmp, int);
void mostrarVec(vecEmp,int);
void mostrarPromedio(vecTotal);
void corte (vecEmp,int);



int main(){
	
	vecEmp empleado;

	int cantEmp=0;
	string cadena;
	string titulo[]={"NOMBRE","EDAD","SUELDO","CATEGORIA"};
	
	ifstream ar("Prueba.txt");
	iniVec(empleado);

	printf("%-20s %20s %20s %20s\n",titulo[0].c_str(),titulo[1].c_str(),titulo[2].c_str(),titulo[3].c_str());
	
	if (ar.fail()){
		cout<<"No se pudo abrir el archivo. "<<endl;
	
	}else{

	cargarVec(empleado, cantEmp);
	ordenarVec(empleado, cantEmp);
	mostrarVec(empleado,cantEmp);
	
	}
	ar.close();
	system("pause");
	return 0;
	
	}


	
	



void mostrarVec(vecEmp empleado, int cantEmp){
	int total=0;
	vecTotal vecTotales;
	int j=0;
	int aux=0;
		cout<<"================================================================================================"<<endl;
	for (int i=0;i<cantEmp;i++){
		int comp1=strcmp(empleado[i].cat.c_str(),empleado[i+1].cat.c_str());
		if(comp1==0){
		
		printf("%-20s |%20i |%20i |%20s|\n",empleado[i].nombre.c_str(),empleado[i].edad,empleado[i].sueldo,empleado[i].cat.c_str());
		
		total=total+empleado[i].sueldo;
		}else{
			printf("%-20s |%20i |%20i |%20s|\n",empleado[i].nombre.c_str(),empleado[i].edad,empleado[i].sueldo,empleado[i].cat.c_str());
			
			total=total+empleado[i].sueldo;
			vecTotales[j].totalSueldo=total;
			if ((strcmp(empleado[i].cat.c_str(),"A"))==0)
			{
			
			vecTotales[j].totalEmp=(i+1)-aux;
			aux=i;
			vecTotales[j].promedioCat=((vecTotales[j].totalSueldo)*1.00)/((vecTotales[j].totalEmp)*1.00);		
			cout<<"\nTOTAL DE CATEGORIA "<<empleado[i].cat<<" ES "<<vecTotales[j].totalSueldo<<endl;
				cout<<"================================================================================================"<<endl;
			cout<<endl;
			
			total=0;
			j++;
			}else{
				vecTotales[j].totalEmp=(i)-aux;
			aux=i;
			vecTotales[j].promedioCat=(vecTotales[j].totalSueldo)*1.00/(vecTotales[j].totalEmp)*1.00;		
			cout<<"\nTOTAL DE CATEGORIA "<<empleado[i].cat<<" ES "<<vecTotales[j].totalSueldo<<endl;
				cout<<"================================================================================================"<<endl;
			cout<<endl;
			total=0;
			j++;
			}
		}
	
	}
	mostrarPromedio(vecTotales);
}

void mostrarPromedio(vecTotal a){
	cout<<"================================================================================================"<<endl;
	for(int i=0;i<_CANTCAT;i++){
		if (i==0){
			cout<<"\n\nTOTAL EMPLEADOS DE CATEGORIA A: "<<a[i].totalEmp<<" || PROMEDIO DE SUELDO ES "<<a[i].promedioCat<<endl;
		}else if(i==1){
			cout<<"\n\nTOTAL EMPLEADOS DE CATEGORIA B: "<<a[i].totalEmp<<" || PROMEDIO DE SUELDO ES "<<a[i].promedioCat<<endl;
		}else if(i==2){
			cout<<"\n\nTOTAL EMPLEADOS DE CATEGORIA C: "<<a[i].totalEmp<<" || PROMEDIO DE SUELDO ES "<<a[i].promedioCat<<endl;
		}else if(i==3){
			cout<<"\n\nTOTAL EMPLEADOS DE CATEGORIA D: "<<a[i].totalEmp<<" || PROMEDIO DE SUELDO ES "<<a[i].promedioCat<<endl;
		}else if(i==4){
			cout<<"\n\nTOTAL EMPLEADOS DE CATEGORIA E: "<<a[i].totalEmp<<" || PROMEDIO DE SUELDO ES "<<a[i].promedioCat<<endl;
		}
	}
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
				comp1=strcmp(a[j].cat.c_str(),a[j+1].cat.c_str());
				comp2=strcmp(a[j].nombre.c_str(),a[j+1].nombre.c_str());								
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
