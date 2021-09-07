#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

#define _AREAS 10
#define _TAREAS 10
#define _CANTALUM 10

typedef char str30[30];

struct tRFecha {
  int dia;
  int mes;
  int anio;
};

struct tarea{
  bool entregada;
  tRFecha fEntrega;
};

typedef tarea tMTareasxAreas[_TAREAS][_AREAS];

struct tREstudiante{
  str30 nombre;
  str30 apellido;
  tMTareasxAreas entregas;
  int totalFila[_TAREAS];
  int totalColumna[_AREAS-1];
};

typedef tREstudiante tAlumno[_CANTALUM];
typedef string materias[_AREAS];

int devolverNArea(char [2]);
void iniVec(tAlumno );
void cargarDatosEstudiante (tAlumno,int &);
void mostrar(tAlumno,int);

int main() {
  tAlumno vEst;
  iniVec(vEst);
  int cantAlumnosIngresada=0;
  cargarDatosEstudiante (vEst,cantAlumnosIngresada);
  mostrar(vEst,cantAlumnosIngresada);
  
  return 0; 
}

void mostrar(tAlumno a,int cantAlumI){
  materias area={"CS", "CN", "PDL", "MA", "MS", "PL", "EF", "TX", "IG","TOTAL"};
  cout<<"\t";
  
  for (int e=0;e<=cantAlumI;e++){
    cout<<"\nAlumno: "<<a[e].nombre<<" "<<a[e].apellido<<"\n\t";
    for (int i=0;i<_AREAS;i++){
		  cout<<""<<area[i]<<"\t";
		  if (i==8){
			  cout<<"\t";
		  }
    }  
    for (int fila=0;fila<_TAREAS;fila++){
      cout<<"\n"<<fila+1<<")"<<"\t";
      for (int columna=0;columna<_AREAS-1;columna++){
          if (a[e].entregas[fila][columna].entregada==true){
          cout<<"SI"<<"\t";
          }else{
           cout<<"\t";
          }
          
          if (columna==8){
            cout<<"\t\t"<<a[e].totalFila[fila];
          }
      } 
    }
  
    cout<<"\nTOTAL:\n\t";
    for(int k=0;k<_AREAS-1;k++){
      cout<<a[e].totalColumna[k]<<"\t";
    }
    cout<<"\n";
    //system("pause");
    //system("cls");
  }
}

void iniVec(tAlumno a){
  for (int i =0;i<_CANTALUM;i++){
    strcpy(a[i].nombre,"");
    strcpy(a[i].apellido,"");
    
    for (int fila=0;fila<_TAREAS;fila++){
      for (int columna=0;columna<_AREAS;columna++){
        a[i].entregas[fila][columna].entregada=false;
        a[i].entregas[fila][columna].fEntrega.dia=0;
        a[i].entregas[fila][columna].fEntrega.mes=0;
        a[i].entregas[fila][columna].fEntrega.anio=0;
      }
    }
  }
}

void cargarDatosEstudiante (tAlumno e,int & cantAlumI){
  int i=0;
  int tarea,areaNum;
  char codArea[3];
  char continuar[2];
  while (i<_CANTALUM){
    cout<<"¿Desea agregar un alumno?('si' para continuar): ";
    cin>>continuar;
    if (strcmp(continuar,"si")!=0){
      break;
    }
    cantAlumI++;
    cout<<"Ingrese el nombre: ";
    cin>>e[i].nombre;
    cout<<"Ingrese el apellido: ";
    cin>>e[i].apellido;
    cout<<"Ingrese area: ";
    cin>>codArea;
    areaNum=devolverNArea(codArea);
    while (areaNum!=-1){
      cout<<"Ingrese tarea: ";
      cin>>tarea;
      e[i].entregas[tarea-1][areaNum].entregada=true;
      e[i].totalFila[tarea-1]++;
      e[i].totalColumna[areaNum]++;
      cout<<"Ingrese dia: ";
      cin>>e[i].entregas[tarea-1][areaNum].fEntrega.dia;
      cout<<"Ingrese mes: ";
      cin>>e[i].entregas[tarea-1][areaNum].fEntrega.mes;
      cout<<"Ingrese anio: ";
      cin>>e[i].entregas[tarea-1][areaNum].fEntrega.anio;
      cout<<"Ingrese area: ";
      cin>>codArea;
      areaNum=devolverNArea(codArea);
    }
    i++;
  }
}

int devolverNArea(char a[2]){
  int b=0;
  if (strcmp(a,"CS")==0){
    b=0;
  } else if (strcmp(a,"CN")==0){
    b=1;
  } else if (strcmp(a,"PDL")==0){
    b=2;
  } else if (strcmp(a,"MA")==0){
    b=3;
  } else if (strcmp(a,"MS")==0){
    b=4;
  } else if (strcmp(a,"PL")==0){
    b=5;
  } else if (strcmp(a,"EF")==0){
    b=6;
  } else if (strcmp(a,"TX")==0){
    b=7;
  } else if (strcmp(a,"IG")==0){
    b=8;
  }else{
    b=-1;
  }
  return b;
}
