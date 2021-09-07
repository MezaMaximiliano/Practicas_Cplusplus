/*
Este es un programa de ejemplo, toma los datos
del archivo datos.csv 
y mediante una función parsear los separa en campos

Ordena  y lo muestra

Muestra de acuerdo a una búsqueda

Las funciones mostrar, prdenar, buscar y parser
están resuelto mediante template, permitiendo así
no clonar código

Para cualquier proceso se deben escribir (customizar)
la estructura de datos, 
los criterios de búsqueda y ordenamiento
La carga de datos (en este ejemplo se guardan en un vector)
La separación (invicada por parser) que permite transformar
los valores de la línea de texto en campos para ser procesados

*/


#include <iostream>
#include <stdio.h>

#include <stdlib.h> 
#include <string.h>
#include <math.h>   // trunc
#include <fstream>
#include <windows.h>
using namespace std;


// mirar http://www.cplusplus.com/forum/beginner/68989/
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;
void gotoXY(int x, int y); 


#define _CANTDATOS 100
#define _AAAAMMDD true

typedef char str30[30];

struct tRDatos {

	// completar el tipo de datos
   int codigo ;
   //  ....
};

struct tFecha {
   int dia;
  int mes;
  int anio;
} ;

int diferenciaFechas(tFecha f1, tFecha f2)  ;


typedef tRDatos tVDatos[_CANTDATOS];
 
void cargarDatos(char * ori, tVDatos vDatos, int & tope);

void inicializarDatos(tVDatos vDatos, int cant);

template <typename T>
T parsear(string cadena , T (*fPasoRegistro)(string p[20]) );
void     pasarPalabra(char * dest, string ori);
int      pasarPalabraNro(string ori) ;
long int pasarPalabraNroLargo(string ori) ;
double   pasarPalabraNroDoble(string ori) ;

void separaFecha(unsigned int fecha, int & anio, int & mes, int & dia, bool como ) ;

template <typename T, typename R>
void mostrar(T vec, int desde, int len, void (*mostrarFila)(R));

template <typename T, typename Q>
void ordenar(T vec, int len, int (*criterio)(Q,Q));

template <typename T, typename R, typename K>
int buscar(T vec, int desde, int len, K v, int (*criterio)(R,K));


// resolver para cada aplicación
template <typename T>
int criterioOrdenarDatos(T a1, T a2) ;
 
template <typename T, typename Q>
int criterioBuscarDatos(T a1, Q que) ; 

void mostrarDatos(tRDatos r) ;

template <typename T> 
T fPasoRegistroDatos(string palabra[20]) ;
 
 
int main(){
	tVDatos vDatos;
	int cantDatos = _CANTDATOS;
    setlocale(LC_CTYPE, "Spanish");
	inicializarDatos(vDatos, cantDatos);
	cargarDatos("datos.csv", vDatos, cantDatos);
    	
    cout<<"\nMostrar Datos ordenadas por campo\n";
	ordenar<tVDatos, tRDatos>(vDatos, cantDatos, criterioOrdenarDatos);
    mostrar<tVDatos, tRDatos>(vDatos, 0, cantDatos, mostrarDatos);

    cout<<"\nMostrar datos por criterio\n";
    int i = buscar<tVDatos, tRDatos, string>(vDatos,  0, cantDatos, "XXXXXXXX", criterioBuscarDatos); 
    while (i>-1){
  	  mostrar<tVDatos, tRDatos>(vDatos, i, i+1, mostrarDatos);
      i = buscar<tVDatos, tRDatos, string>(vDatos,  i+1, cantDatos, "XXXXXXX", criterioBuscarDatos); 
	}
	return 0;
}

// resolver en cada caso
void inicializarDatos(tVDatos vDat, int cant){
	for (int i=0;i<cant;i++){
	// se debe completar
    // vDat[i].campo_Numerico = 0;
    // strcpy(vDat[i].campo_alfabetico,"");
    // ....
   }
};

// resolver en cada caso
void cargarDatos(char * ori, tVDatos vdatos, int & tope) {
  gotoXY(0, 0);
  printf("\nCargar Datos\n");
  tRDatos rDatos;
  string cadena;

  int i = 0;
  ifstream fe(ori); 
  // ignoramos la primer línea dado que tiene los títulos de las columnas
  getline(fe, cadena);
  cout<<"Importamos de "<<ori<<" Los datos "<<cadena<<endl;
 
  cout<<"Procesa datos desde el archivo de texto "<<ori<<" a "<<endl;
  cout<<"El archivo origen es un texto que tiene ...."<<endl;
  cout<<"separado por el símbolo ; con encabezado"<<endl;
  cout<<"============================================================="<<endl;
  while(getline(fe, cadena)) { 
    rDatos = parsear<tRDatos>(cadena, fPasoRegistroDatos ) ;
	// SE DEBE COMPLETAR
	// En este ejemplo se arma un vector,.
	// En cada aplicación se debe procesar el dato
	// de acuerdo al requrimiento
	
    // vdatos[i].campo_Numerico = rDatos.campo_Numerico;
    // strcpy(vdatos[i].campo_alfabetico,rDatos.campo_alfabetico);
    // ....
    i++;
   }
   fe.close();
   printf("\n");
   tope = i ;
}


// resolver en cada caso
template <typename T, typename Q>
int criterioBuscarDatos(T a1, Q que) {
  int r=0;
//  if (a1.campo1<que) r=-1;
//  else if  (a1.campo1>que) r=1; 
  return r ;
}

// resolver en cada caso
template <typename T>
int criterioOrdenarDatos(T a1, T a2) {
  int r=0;
//  if ((strcmp(a1.campo1,a2.campo1)>0) || 
//      ((strcmp(a1.campo1, a2.campo1)==0) && 
//	   (a1.campo2>a2.campo2<0))) r = 1 ;
   return r ;
}

// resolver en cada caso
void mostrarDatos(tRDatos r){
 	// completar
    // printf("%5d \n", r.campo1) ;
 } 

// resolver en cada caso 
template <typename T> 
T fPasoRegistroDatos(string palabra[20]) {
  T reg ;
  
  // se debe completar
  // reg.campo_Numerico = pasarPalabraNro(palabra[0]);
  // pasarPalabra(reg.campo_alfabetico,palabra[1]);
  // ....
  return reg;
}



// ====================================================
//  FUNCIONES DE LIBRERÍA,   NO SE DEBEN MODIFICAR 
template <typename T, typename R>
void mostrar(T vec, int desde, int len, void (*mostrarFila)(R)){
  for(int i=desde; i<len; i++){
     mostrarFila(vec[i]);
  }
 }

 
template <typename T>
T parsear(string cadena , T (*fPasoRegistro)(string p[20]) ){
   T reg;
   int primero;
   int ultimo;
   int k=0 ;
   string palabra[20] ;

   primero=0;
   ultimo=0 ;
   while (ultimo<cadena.size()) {
	  ultimo = cadena.find(";", primero) ;  
      // en caso de finalizar la frase, indica que 
	  // el último coincide con el tamaño de la frase
      if (ultimo==-1) ultimo = cadena.size() ; 
      // arma un vector de las palabras, las extrae de la cadena, le agrega marca de
      // fin de palabra
	  palabra[k] = cadena.substr (primero,  ultimo-primero) +  '\0';
	  k++ ;
      // avanza para buscar el próximo ;
      primero = ultimo + 1;
   }
	reg     = fPasoRegistro(palabra);
	return reg;
} 

void   pasarPalabra(char * dest, string ori) {
//  pasa el campo de tipo cadena al campo cadenas
//  del registro
	int i=0 ;
	while (i<=ori.size()) {
	  dest[i] =  ori[i];
	  i++ ;
    }
	dest[i] = '\0' ;
}

int   pasarPalabraNro(string ori) {
// convierte el campo cadena de caracteres en entero
// para los casos que se requiera en el registro
   int resultado ;
   char  dest[255]  ;
   pasarPalabra(dest,  ori) ;   // primero pasa el campo a una variable simple
   resultado = atoi(dest);
   return resultado ;
}

long int   pasarPalabraNroLargo(string ori) {
// convierte el campo cadena de caracteres en entero
// para los casos que se requiera en el registro
   long int resultado ;
   char  dest[255]  ;
   pasarPalabra(dest,  ori) ;   // primero pasa el campo a una variable simple
   resultado = atol(dest);
   return resultado ;
}

double   pasarPalabraNroDoble(string ori) {
// convierte el campo cadena de caracteres en entero
// para los casos que se requiera en el registro
   int resultado ;
   char  dest[255]  ;
   pasarPalabra(dest,  ori) ;   // primero pasa el campo a una variable simple
   resultado = atof(dest);
   return resultado ;
}


//  la siguiente funcion ordena con campos de cualquier tipo, usando diferente
// criterio menor a mayor o mayor a menor
template <typename T, typename Q>
void ordenar(T vec, int len, int (*criterio)(Q,Q)) { 
    Q aux;
	bool ordenado=false;
	while(!ordenado){
	   ordenado=true;
	   for(int i=0; i<len-1; i++){
		   if( criterio(vec[i],vec[i+1])==1 ){
			 aux = vec[i];
			 vec[i] = vec[i+1];
			 vec[i+1] = aux;
			 ordenado = false;
		   } 
	   }  
	}
} 

template <typename T, typename R, typename K>
int buscar(T vec, int desde, int len, K v, int (*criterio)(R,K)) {
  int i=desde;
  while( i<len && criterio(vec[i],v)!=0 ){
    i++;
  }
  if (i==len) i=-1;
  return i;
} 

void separaFecha(unsigned int fecha, int & anio, int & mes, int & dia, bool como ) {
  if (como == _AAAAMMDD) {
	  dia = fecha % 100;
	  mes = (fecha / 100) % 100;
	  anio = (fecha / 100) / 100 ;
  } else {
  	  anio = fecha % 10000 ;
	  mes = (fecha / 10000) % 100;
  	  dia = (fecha / 10000) % 100;
  }
}


int diferenciaFechas(tFecha f1, tFecha f2)  {
  int dif;
  dif = abs((f1.anio-f2.anio)*12 +(f1.mes-f2.mes)*30 + (f1.dia-f2.dia));
 return dif; 
}

/*
cómo usar diferenciafechas:
Fecha f1 = {16,7,2020};
tFecha f2 = {5,5,2020};
int cantDias =  diferenciaFechas(f1, f2);

*/



void gotoXY(int x, int y)  { 
	CursorPosition.X = x; // Locates column
	CursorPosition.Y = y; // Locates Row
	SetConsoleCursorPosition(console,CursorPosition); // Sets position for next thing to be printed 
}





