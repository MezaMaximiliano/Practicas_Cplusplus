#include <iostream>
#include<stdlib.h>
#include<cstring>
using namespace std;
typedef char str30[30];

struct Fecha{
  int dia;
  int mes;
  int anio;
}f;

struct datos{
  Fecha fecha_nac;
  str30 nombre;
  int edad;
};

typedef datos vector[60];
void iniVector(vector);
void fechaHoy();
void cargaDatos(vector, int &);
void devolverResultados (vector, int);
void difEdad(vector, int);
void ordenar(vector, int);
void calculoMayores(vector, int, vector, int &);
void devolverOrdenados (vector, int);

int main() {
  setlocale(LC_ALL, "spanish");
  vector persona;
  vector personasMayores;
  int cant=0;
  int cantMay=0;

  iniVector(persona);
  iniVector(personasMayores);
  fechaHoy();
  cargaDatos(persona, cant);
 
  difEdad(persona, cant);
  cout<<" "<<endl;
  cout<<"Calcule edad"<<endl;
  cout<<" "<<endl;
  devolverResultados (persona, cant);
  ordenar (persona, cant);
  cout<<" "<<endl;
  cout<<"Ordeno"<<endl;
  cout<<" "<<endl;
  devolverOrdenados (persona, cant);
  cout<<" "<<endl;
  cout<<"Calculo mayor"<<endl;
  cout<<" "<<endl;
  calculoMayores(persona,cant, personasMayores,cantMay);
  devolverOrdenados (personasMayores, cantMay);

  return 0;
}

void iniVector(vector v){
  for(int i=0;i<=60;i++){
    v[i].fecha_nac.dia=0;
    v[i].fecha_nac.mes=0;
    v[i].fecha_nac.anio=0;
    strcpy(v[i].nombre,"");
  }
}

void cargaDatos(vector v, int &c){
  char seguir[]={"s"};

  while ((c<60)&&(strcmp(seguir,"s")==0)){
    cout<<" "<<endl;
    cout<<"Ingresar nombre: ";
    cin>>v[c].nombre;
    cout<<"Ingresar dia, mes y año de nacimiento:"<<endl;
    cin>>v[c].fecha_nac.dia;
    cin>>v[c].fecha_nac.mes;
    cin>>v[c].fecha_nac.anio;
    c++;
    cout<<"Desea continuar? s/n ";
    cin>>seguir;
  }
}

void devolverResultados (vector v,int cantidad){
  for (int i=0;i<cantidad;i++){
    cout<<"   "<<v[i].nombre<<" nacio el "<<v[i].fecha_nac.dia<<"/"<<v[i].fecha_nac.mes<<"/"<<v[i].fecha_nac.anio<<" y su edad es: "<<v[i].edad<<endl;
  }
}

void devolverOrdenados(vector v,int cantidad){
  for (int i=0;i<cantidad;i++){
    cout<<"   "<<v[i].nombre<<" y su edad es: "<<v[i].edad<<endl;
  }
}

void ordenar(vector v, int cantVector) {
  vector aux;
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

void difEdad(vector v, int c){
  int difAnio;
  int difMes;
  int difDia;
	for (int i=0;i<c;i++){
    difAnio=(f.anio - v[i].fecha_nac.anio);
    difMes= abs(f.mes - v[i].fecha_nac.mes);
    difDia= abs(f.dia - v[i].fecha_nac.dia);
		v[i].edad=(((difAnio*12+difMes)*30+difDia)/360);
	}
}

void fechaHoy (){
  cout<<"Ingresar dia, mes y año actual:"<<endl;
  cin>>f.dia;
  cin>>f.mes;
  cin>>f.anio;
}

void calculoMayores(vector v, int c, vector m, int &cantMay){
  for (int i=0;i<c;i++){
    if (v[i].edad>=25){
			m[cantMay]=v[i];
      cantMay++;
		}
  }
}

