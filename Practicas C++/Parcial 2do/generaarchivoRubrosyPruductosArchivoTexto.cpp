
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h> 

/*
Genera archivos de rubros y productos a partir de los archivos de textos
*/


using namespace std;

typedef char str6[7] ;
typedef char str50[51] ;


// acá se debe definir el diseño del registro para procesar
struct tRRubro {
	str6 codigo;
	str50 descripcion;
};


// acá se debe definir el diseño del registro para procesar
struct tRProducto {
	str6 codigo;
	str50 descripcion;
	str6 rubro;
};




void cargarRubro(char * ori, char * dest) ;
void  cargarProducto(char * ori, char * dest);

void parsearRubro(string cadena , tRRubro & rubro ) ;
void parsearProducto(string cadena , tRProducto & prod ) ;
void pasarPalabra(char * dest, string ori) ;
int  pasarPalabraNro(string ori) ;
double   pasarPalabraNroDoble(string ori) ;


int main(){
  /* este es el convertidor	lee de un archivo de texto los campos separados 
   por el símbolo ; 
   los pasa a un vector y luego los procesa
  */
  cargarRubro("rubros.csv", "rubros.dat") ;   
  cargarProducto("productos.csv", "productos.dat") ;   
  return 0;
}  

void  cargarRubro(char * ori, char * dest) {
/*   Obtiene la información del archivo de texto, donde los campos están
  separados por el símbolo punto y coma.  Muestra los datos en pantalla
  Acá se debe modificar de acuerdo a cada caso  	 */
  tRRubro rubro;
  string cadena;
  // Abre un entrada de entrada cadena de caracteres
  ifstream fe(ori); 
  
  FILE * f = fopen(dest, "wb");
  getline(fe, cadena);  // se ignora la primer línea de títulos
  cout<<"Procesa rubros desde el archivo de texto "<<ori<<" a "<<endl;
  cout<<"El archivo origen es un texto que tiene nombre;edad;categoria;salario "<<endl;
  cout<<"separado por el simbolo ; sin encabezado"<<endl;
  cout<<"============================================================="<<endl;
  printf("%-7s %-50s\n", "codido", "descripcion" );
  printf("%-7s %-50s\n", "=======", "===================================" );
  
  while(getline(fe, cadena)) { // detecta la marca de fin de archivo
	  parsearRubro(cadena, rubro ) ; // separa los campos, los devuelve en el registro de acuerdo al tipo de datos
      fwrite(&rubro, sizeof(rubro), 1, f);
      printf("%-7s %-50s\n", rubro.codigo, rubro.descripcion );

   }
   fe.close();
   fclose(f);
}

void  cargarProducto(char * ori, char * dest) {
/*   Obtiene la información del archivo de texto, donde los campos están
  separados por el símbolo punto y coma.  Muestra los datos en pantalla
  Acá se debe modificar de acuerdo a cada caso  	 */
  tRProducto prod;
  string cadena;
  // Abre un entrada de entrada cadena de caracteres
  ifstream fe(ori); 
  
  FILE * f = fopen(dest, "wb");
  getline(fe, cadena);  // se ignora la primer línea de títulos
  cout<<"Procesa productos desde el archivo de texto "<<ori<<" a "<<endl;
  cout<<"El archivo origen es un texto que tiene nombre;edad;categoria;salario "<<endl;
  cout<<"separado por el simbolo ; sin encabezado"<<endl;
  cout<<"============================================================="<<endl;
  printf("%-7s %-50s %-7s\n", "codido", "descripcion", "rubro" );
  printf("%-7s %-50s %-7s\n", "=======", "===================================", "=======" );
  while(getline(fe, cadena)) { // detecta la marca de fin de archivo
	  parsearProducto(cadena, prod ) ; // separa los campos, los devuelve en el registro de acuerdo al tipo de datos
      fwrite(&prod, sizeof(prod), 1, f);
      printf("%-7s %-50s %-7s\n", prod.codigo, prod.descripcion, prod.rubro );

   }
   fe.close();
   fclose(f);
}

void parsearRubro(string cadena , tRRubro & rubro ) {
	// este proceso separa los campos de a línea del 
	// archivo de texto buscando los símbolos ;
	// y arma un vector de cadenas de caracteres
	// luego convierte cada campo de acuerdo al tipo
	// y devuelve el registro

   int primero;
   int ultimo;
   int k=0 ;
   string palabra[20] ;
  // int len;
  
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
    //  acá se modifica de acuerdo a cada caso
 
    pasarPalabra(rubro.codigo, palabra[0]) ;
	pasarPalabra(rubro.descripcion, palabra[1]) ;
   
}; // separa los campos, los devuelve en el registro de acuerdo al tipo de datos


 void parsearProducto(string cadena , tRProducto & prod ) {
	// este proceso separa los campos de a línea del 
	// archivo de texto buscando los símbolos ;
	// y arma un vector de cadenas de caracteres
	// luego convierte cada campo de acuerdo al tipo
	// y devuelve el registro

   int primero;
   int ultimo;
   int k=0 ;
   string palabra[20] ;
  // int len;
  
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
    //  acá se modifica de acuerdo a cada caso
    pasarPalabra(prod.codigo, palabra[0]) ;
	pasarPalabra(prod.descripcion, palabra[1]) ;
	pasarPalabra(prod.rubro, palabra[2]) ;   
}; // separa los campos, los devuelve en el registro de acuerdo al tipo de datos





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

double   pasarPalabraNroDoble(string ori) {
// convierte el campo cadena de caracteres en entero
// para los casos que se requiera en el registro
   int resultado ;
   char  dest[255]  ;
   pasarPalabra(dest,  ori) ;   // primero pasa el campo a una variable simple
   resultado = atof(dest);
   return resultado ;
}

