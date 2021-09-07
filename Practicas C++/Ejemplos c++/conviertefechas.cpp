#include <iostream>
using namespace std;


/*
tercer programa, dad una fecha en formato d m y a convertir a formato AAAAMMDD
*/

// declaracion de funciones o prototipos

int convF(int d, int m, int a) ;
void convFAMD(int AMD, int & d, int & m, int & a) ;



int main() {
   int d;
   int m;
   int a;
   int AMD ;
   int aux ; 



   cout<<"ingresar dia mes y anio separados por la tecla enter"<<endl;
   cin>>d;
	 cin>>m;
	 cin>>a; 
   //AMD = 1 * d + 100 * m + 10000 * a;

   AMD = convF(d, m, a) ;
	 
	 cout<<AMD<<endl;
   
   
   AMD = 20190606;
     
   convFAMD(AMD, d, m, a) ; 
 
	 
	 cout<<d<<"/"<<m<<"/"<<a<<endl;
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





