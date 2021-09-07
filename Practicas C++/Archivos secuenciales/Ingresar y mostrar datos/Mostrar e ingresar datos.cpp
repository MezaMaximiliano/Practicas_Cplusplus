#include <stdlib.h>
#include<string.h>
#include<iostream>
#include<stdio.h>
using namespace std;

typedef char str60[60];

struct tRegistro{
	unsigned long dni;
	str60 nombre;
	int edad;
	
};

void iniReg(tRegistro &);

int main(){
	
	tRegistro persona;
	bool fin=false;
	FILE *f;
	f=fopen("archivo.dat","a+b");
	iniReg(persona);
	
	while(!fin){
	
		if (f==NULL){
			//f=fopen("archivo.dat","ab+");
			cout<<"DNI:\n";
			cin>>persona.dni;
			cin.ignore();
				if (persona.dni!=0){
					cout<<"Nombre:\n";
					cin.getline(persona.nombre,sizeof(persona.nombre));
					cin.ignore();
					cout<<"Edad:\n";
					cin>>persona.edad;
					
					fin=false;
					fwrite(&persona,sizeof(persona),1,f);
				}else{
					fin=true;
				}
			}else{
				
				cout<<"DNI:\n";
				cin>>persona.dni;
				cin.ignore();
				if (persona.dni!=0){
						cout<<"Nombre:\n";
						cin.getline(persona.nombre,sizeof(persona.nombre));
						
						cout<<"Edad:\n";
						cin>>persona.edad;
						cin.ignore();
						fin=false;
						fwrite(&persona,sizeof(persona),1,f);//graba todos los campos del registro en el archivo fwrite(nombre del registro por referencia, tamaño del campo a grabar, cantidad de campos a grabar, puntero del archivo de destino)
					}else{
						fin=true;
				}
		}	
	
	}
		
	fin=false;
	fseek(f ,0, SEEK_SET ); //posiciona el puntero al inicio del archivo
	while (!fin){
		fread(&persona,sizeof(persona),1,f);
		printf ("%60s %30i %10i\n", persona.nombre,persona.dni,persona.edad);
		if (feof(f)==0){	//devuelve 0 mientras no encuentre el final del archivo
			fin=false;
		}else{
			fin=true;
		}
	}
		
	

		
	fclose(f);	
	system("pause");
	return 0;
}
	
	
	

	
	
		
	
	



void iniReg (tRegistro &persona){
	persona.dni=0;
	persona.edad=0;
	strcpy(persona.nombre,"");
}
