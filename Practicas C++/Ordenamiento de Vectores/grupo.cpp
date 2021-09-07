#include <iostream>
#include<stdlib.h>
#include<cstring>
using namespace std;
typedef char str30[30];

struct Fecha{
  int dia;
  int mes;
  int anio;
};

struct datos{
  Fecha fecha_nac;
  str30 nombre;
  int edad;
};

typedef datos vector[60];
void iniVector(vector);
void cargaDatos(vector, int &);
void devolverVector (vector, int);

int main() {
  setlocale(LC_ALL, "spanish");
  vector persona;
  vector personasMayores;
  int cant=0;
  iniVector(persona);
  iniVector(personasMayores);
  cargaDatos(persona, &cant);
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
  char seguir[1]={'s'};
  while ((c<60)&&(strcmp(seguir,"s")==0)){
    cout<<"Ingresar nombre";
    cin>>v[c].nombre;
    cout<<"Ingresar dia, mes y año de nacimiento:"<<endl;
    cin>>v[c].fecha_nac.dia;
    cin>>v[c].fecha_nac.mes;
    cin>>v[c].fecha_nac.anio;
    cout<<"Desea continuar? s/n";
    c++;
    cin>>seguir;
  }
}



void devolverVector (vector & v,int cantidad){
  for (int i=0;i<cantidad;i++){
    cout<<v[i].nombre<<" nacio el "<<v[i].fecha_nac.dia<<"/"<<v[i].fecha_nac.mes<<"/"<<v[i].fecha_nac.anio<<endl;
  }
}

