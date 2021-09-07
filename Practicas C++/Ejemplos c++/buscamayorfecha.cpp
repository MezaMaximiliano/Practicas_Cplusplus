#include <iostream>
using namespace std;


/*
cuarto programa, pedir fechas en formato d, m y a hasta que llegue un dia en 0 y mostrar cual
fecha corresponde a la mayor persona
*/

// declaracion de funciones o prototipos

int convF(int d, int m, int a) ;
void convFAMD(int AMD, int & d, int & m, int & a) ;



int main() {
   int d;
   int m;
   int a;
   int menorFecha = 99991231 ;  // valor inicial alto para buscar una fecha mas chica
   int AMD;

   cout<<"ingresar dia (0=fin)"<<endl;
   cin>>d;
   while (d!=0) {
	   cout<<"ingresar mes y anio separados por la tecla enter"<<endl;
	   cin>>m;
	   cin>>a;

     AMD = convF(d, m, a) ;

     if (AMD<menorFecha) {
     	  menorFecha = AMD ;
		 }

	   cout<<"ingresar dia (0=fin)"<<endl;
  	 cin>>d;
 	 } // while (d!0)

   convFAMD(menorFecha , d, m, a) ; 
   cout<<"le persone mayor nacio el "<<d<<"/"<<m<<"/"<<a<<endl; 
}  // main



/*  subproceso x <- convF(d, m, a)
       x = 1 * d + 100 * m + 10000 * a
    finsubroceso
*/





int convF(int d, int m, int a) {
	int x = 1 * d + 100 * m + 10000 * a ;
//	return 1 * d + 100 * m + 10000 * a ;
	return x;
} // conF
      
 
void convFAMD(int AMD, int & d, int & m, int & a) { 
   int aux ;
	 
	 
	 d  = AMD % 100 ;
   aux = AMD / 100 ;
	 m = aux % 100 ;
	 a = aux / 100 ;
}  //  convFAMD





