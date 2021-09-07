/*Procesar un conjunto de personas de las cuales conocemos su nombre y fecha de nacimiento. Se debe

Mostrar por pantalla nos nombres y las fechas de nacimiento ordenado por edad.
Mostrar por pantalla la cantidad de personas por edad*/



#include <iostream>
#include <string.h>
#include <stdlib.h>

#define _CANT 10
struct fecha{
 int dia;
 int mes;
 int anio; 
};
typedef char str20[20];
struct persona{
  str20 nombre;
  fecha fechaNacimiento;
  int edad;
};

typedef persona vPersona[_CANT];

void cargaDatos(vPersona, int &,fecha);
void inicializarVector(vPersona);
void pedirFecha (fecha &);
void difEdad(vPersona, int, fecha);
void ordenar(vPersona,int);
//void devolverViejo(vPersona, int);
void corte(vPersona, int);
void devolver(vPersona, int);

int main() {

  setlocale(LC_ALL, "spanish");
  vPersona personas;
  int vCant=0;
  fecha fecHoy;
 
  inicializarVector(personas);
  pedirFecha (fecHoy);
  cargaDatos(personas, vCant, fecHoy);
  system("cls");
  std::cout<<"\n";
  std::cout<<"Vector en la forma que se ingreso:\n";
  devolver(personas,vCant);
  std::cout<<"\n";
  std::cout<<"Vector ordenado por edad:\n";
  ordenar(personas,vCant);
  devolver(personas,vCant);
  std::cout<<"\n";
  std::cout<<"Cantidad total por edades:\n";
  corte(personas,vCant);

  return 0;
}

void corte(vPersona persona, int tope){
	int edadAnt=0,edadAct=0;
	int i =0,cantEdades=0;
	
	printf("%-20s %-4s\n","Nombre","Edad");
	while (i<tope){
		
		edadAnt=persona[i].edad;
		edadAct= edadAnt;
		while (((edadAnt==persona[i].edad)) and (i<=tope)){
			
			
      printf("%-20s %-4i\n",persona[i].nombre,persona[i].edad);
      i++;
			cantEdades++;
		
		}
  
  std::cout<<"TOTAL "<<edadAnt<<": "<<cantEdades<<"\n";
  
  cantEdades=0;
	}
		
	}

void ordenar(vPersona v, int cantVector) {
  vPersona aux;
  int minimo;
  for(int i=0;i<cantVector;i++) {
    minimo = i ;
	  for(int j=i+1;j<cantVector;j++) {
	 	if(v[j].edad<v[minimo].edad){
      minimo = j ;
     }
    }
    aux[0]=v[i];
    v[i]=v[minimo];
	  v[minimo]=aux[0];	
  }
}

void inicializarVector (vPersona v){
  for (int i=0;i<_CANT;i++){
    v[i].edad=0;
    v[i].fechaNacimiento.dia=0;
    v[i].fechaNacimiento.mes=0;
    v[i].fechaNacimiento.anio=0;
    strcpy(v[i].nombre,"");
  }
}

void difEdad(vPersona v, int i, fecha f){
  int difAnio=0;
  int difMes=0;
  int difDia=0;
  
  difAnio=(f.anio - v[i].fechaNacimiento.anio);
  difMes= abs(f.mes - v[i].fechaNacimiento.mes);
  difDia= abs(f.dia - v[i].fechaNacimiento.dia);
	v[i].edad=((difAnio*12+difMes)*30+difDia)/360;/*Nos esta sumando 1 año mas porque cada mes tiene 30 dias*/
  
}

void cargaDatos(vPersona v, int &c, fecha f){
  char seguir[]={"s"};
  
  while ((c<60)&&(strcmp(seguir,"s")==0)){
   std:: cout<<"\n ";
   std::cout<<"Ingresar nombre: ";
   std:: cin>>v[c].nombre;
   std:: cout<<"Ingresar dia, mes y año de nacimiento:\n";
   std:: cin>>v[c].fechaNacimiento.dia;
   std:: cin>>v[c].fechaNacimiento.mes;
   std:: cin>>v[c].fechaNacimiento.anio;
    difEdad(v,c,f);
    c++;
   std:: cout<<"Desea continuar? s/n ";
   std:: cin>>seguir;
  }

}

void pedirFecha (fecha & f){
 std:: cout<<"Ingrese la fecha actual\n";
 std:: cout<<"Día: ";
 std:: cin>>f.dia;
 std:: cout<<"Mes: ";
 std:: cin>>f.mes;
 std:: cout<<"Año: ";
 std:: cin>>f.anio;
}

/*void devolverViejo(vPersona v, int cantidad){
  for (int i=0;i<cantidad;i++){
    cout<<"   "<<v[i].nombre<<" nacio el "<<v[i].fechaNacimiento.dia<<"/"<<v[i].fechaNacimiento.mes<<"/"<<v[i].fechaNacimiento.anio<<" y su edad es: "<<v[i].edad<<endl;
  }
}*/

void devolver(vPersona v, int cantidad){
  printf("%-20s %-4s\n","Nombre","Edad");/*,%-3s,%-3s,%-4s*//*"Dia","Mes","Año"*/
  for (int i=0;i<cantidad;i++){
    printf("%-20s %-4i\n",v[i].nombre,v[i].edad);/*,%-3s,%-3s,%-4s*//*v[i].fechaNacimiento.dia,v[i].fechaNacimiento.mes,v[i].fechaNacimiento.anio*/
  }
}
