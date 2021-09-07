#include <iostream>
#include <string.h>
#include<stdlib.h>
using namespace std;

#define _CANT 50


	
typedef int tVector[_CANT]	;

// prototipos
void incializarV(tVector , int ) ;
void cargarV(tVector, int & ) ;
void mostrarV(tVector, int) ;
void ordenarV(tVector, int);
void mostrarV(tVector, int) ;
void apareo (tVector, int, tVector, int, tVector, int &) ;


int main(){
	tVector  v1 ;
	tVector  v2 ;
	tVector  v3 ;	

	int cant1 = _CANT;
	int cant2 = _CANT;
	int cant3 = _CANT;
		
	setlocale(LC_CTYPE, "Spanish");
	incializarV(v1,_CANT) ;
	incializarV(v2,_CANT) ;
	incializarV(v3,_CANT) ;
	
	printf("Ingresar valores primer vector \n");
	cargarV(v1,cant1) ;
	printf("Ingresar valores segundo vector \n");
	cargarV(v2,cant2) ;	
	ordenarV(v1,cant1);
	ordenarV(v2,cant2);	
	mostrarV(v1,cant1) ;
	mostrarV(v2,cant2) ;	
	
	apareo (v1, cant1, v2, cant2, v3, cant3) ;
	mostrarV(v3,cant3) ;		
}

void incializarV(tVector v, int cant) {
	for (int i=0;i<cant;i++) {
		v[i]= 0 ;
	} ;
};

void cargarV(tVector v, int & cant) {
	int i=0 ;
	int nro;
	printf("Ingresar número (0=fin) ");
    cin>>nro;
	
	while ((i<cant) && (nro!=0)) {
		v[i] = nro;
		i++ ; 	
    	printf("Ingresar número(0=fin) ");
        cin>>nro;
	}
    cant = i ;
};

void mostrarV(tVector v, int cant) {

	for (int i=0;i<cant;i++)
      printf("%4i", v[i]);
    printf("\n"); 
	system("pause") ;
};


void cambio( int & A,  int & B){
	 int aux;
	 aux = A;
	 A = B;
	 B = aux;
}

void ordenarV(tVector vector, int cantVector){
 int i , j , k , salto ;   bool fin ;

   salto = cantVector ;
   while ( salto > 0 )  {
     salto = salto / 2 ;
     do  {
       fin = true ;
         k  = cantVector - salto ;
         for ( i = 0 ; i < k ; i++ ) {
         //	cout<<"i="<<i<<" j="<<j<<endl;
            j = i + salto ;
            if ( vector[i] >  vector[j]) {
			  cambio(vector[i], vector[j]); 
   		      fin = false ;
            }           
        }
       }  while ( ! fin ) ;
    }
}

void traer(tVector v, int & r, int cant, int & ptro, bool & fin) {
   if (ptro<cant) {
   	r = v[ptro];
   	ptro++;
   	fin = false ;
   } else fin = true;
}


void pasar(tVector v, int cant, int & ptro, int r) {
	if (ptro<cant) {
		v[ptro] = r;
		ptro ++ ;
	}
}

void apareo (tVector v1, int c1, tVector v2, int c2, tVector v3, int & c3) {
	int i1=0;
	int i2=0;
	int i3=0;
	int r1, r2, r3;
	bool fin1, fin2;
	traer(v1, r1, c1, i1, fin1) ;
	traer(v2, r2, c2, i2, fin2) ;
	while((!fin1)&&(!fin2)){
		printf("r1 = %2i   r2=%2i", r1, r2) ;
		if (r1<r2) {
		   pasar(v3,c3,i3,r1) ;
   		   printf(" agrego r1 = %2i\n", r1) ;
	       traer(v1, r1, c1, i1, fin1) ;
		} else {
		   if (r1>r2) {
			   pasar(v3,c3,i3,r2) ;
	   		   printf(" agrego r2 = %2i\n", r2) ;
			   traer(v2, r2, c2, i2, fin2) ;
	   	   } else {
			   pasar(v3,c3,i3,r1) ;
			   printf(" agrego r1 o r2 = %2i\n", r1) ;
	   	   	   traer(v1, r1, c1, i1, fin1) ;
		       traer(v2, r2, c2, i2, fin2) ;
 		   }
		}
  	}    
    if (!fin1) {
      do { 
	   pasar(v3,c3,i3,r1) ;
       traer(v1, r1, c1, i1, fin1) ;
      } while (!fin1);
    } else {
  	  do { 
	    pasar(v3,c3,i3,r2) ;
        traer(v2, r2, c2, i2, fin2) ;
      } while (!=fin2);		  
  }
  c3 = i3 ;	
}


	

