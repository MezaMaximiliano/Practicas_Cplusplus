#include <iostream>
#include <string.h>
using namespace std;

#define _CANT 50

typedef char str30[30] ;  

typedef struct tRegEst {
	long int DNI;
    str30 carrera;
    int anioIngreso;
	str30 apellido ;
	str30 nombre ;
};
	
typedef tRegEst tVectorEst[_CANT]	;

// prototipos
void incializarV(tVectorEst , int ) ;
void cargarV(tVectorEst vEst, int & ) ;
void mostrarV(tVectorEst , int) ;
void ordenarVEst(tVectorEst , int);
void mostrarV(tVectorEst , int) ;
void procesarCteCtrolV (tVectorEst , int) ;


int main(){
	tVectorEst  vEst ;
	int cantEst = _CANT;
	setlocale(LC_CTYPE, "Spanish");
	incializarV(vEst,_CANT) ;
	cargarV(vEst,cantEst) ;
	ordenarVEst(vEst,cantEst);
	mostrarV(vEst,cantEst) ;
	procesarCteCtrolV (vEst,cantEst) ;
	
}

void incializarV(tVectorEst v, int cant) {
	for (int i=0;i<cant;i++) {
		v[i].DNI = 0 ;
		strcpy(v[i].nombre,   ""); 
		strcpy(v[i].carrera,   "");
		strcpy(v[i].apellido,   ""); 
		v[i].anioIngreso= 0 ;

	} ;
};

void cargarV(tVectorEst v, int & cant) {
	int i=0 ;
	int dni;
	printf("Ingresar DNI(0=fin) ");
    cin>>dni;
	
	while ((i<cant) && (dni!=0)) {
		v[i].DNI = dni;
		
		printf("Ingresar nombre ");
	    fflush(stdin);
	    cin.getline(v[i].nombre, sizeof(v[i].nombre),'\n');
	    
		printf("Ingresar apellido ");
	    fflush(stdin);
	    cin.getline(v[i].apellido, sizeof(v[i].apellido),'\n');
	    
		printf("Ingresar carrera ");
	    fflush(stdin);
	    cin.getline(v[i].carrera, sizeof(v[i].carrera),'\n');

		printf("Ingresar año ingreso ");
  	    cin>>v[i].anioIngreso;

	    i++ ; 	

    	printf("Ingresar DNI(0=fin) ");
        cin>>dni;
	}
    cant = i ;
};

void mostrarV(tVectorEst v, int cant) {
	printf("%8s %-25s %-25s %-25s %4-s\n",
	     "DNI", "Nombre", "Apellido", "Carrera","Año");
	for (int i=0;i<cant;i++)
        printf("%8i %-25s %-25s %-25s %-i\n", 
		v[i].DNI, v[i].nombre, v[i].apellido, 
		v[i].carrera, v[i].anioIngreso );
	system("pause") ;
};


void cambio( tRegEst & A,  tRegEst & B){
	 tRegEst aux;
	 aux = A;
	 A = B;
	 B = aux;
}

void ordenarVEst(tVectorEst vector, int cantVector){
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
            if ( strcmp(vector[i].carrera,  vector[j].carrera)>0) {
			  cambio(vector[i], vector[j]); 
   		      fin = false ;
            } else if (( strcmp(vector[i].carrera,  vector[j].carrera)==0) 
			             && (vector[i].anioIngreso>vector[j].anioIngreso)) {
			            cambio(vector[i], vector [j]); 
   		                fin = false ;
                   }             
        }
       }  while ( ! fin ) ;
    }
}

void traer(tVectorEst v, tRegEst & r, int cant, int & ptro, bool & fin) {
   if (ptro<cant) {
   	r = v[ptro];
   	ptro++;
   	fin = false ;
   } else fin = true;
}




	
void procesarCteCtrolV (tVectorEst vEst, int cant) {
	str30 carAnt;
	int i = 0;
	tRegEst r;
	bool fin;
	int total = 0 ;
    int totalCar ;
	traer(vEst, r, cant, i, fin) ;
	while (!fin) {
		strncpy(carAnt, r.carrera, sizeof(carAnt)) ;
		totalCar = 0 ;
		printf("Carrera %s\n", carAnt);
		while ((!fin ) && (strcmp(carAnt, r.carrera)==0)) {
                totalCar ++; 				
				traer(vEst, r, cant, i, fin) ;
		}
		printf("Total carrera  %d\n",   totalCar);
		total = total + totalCar ;
	}
	printf("total ingreso de las carreras es  %d\n", total);
}



