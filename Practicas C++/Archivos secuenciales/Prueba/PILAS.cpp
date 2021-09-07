#include <cstdlib>
#include <iostream>
#include <time.h>

using namespace std;

template <typename TS> 
struct pNodo {
   TS info ;
   pNodo<TS> * pSig  ;  
} ;

template <typename TS> 
struct TDAPila {   

  pNodo<TS> * pila ;  

   bool push(TS d) {
      pNodo <TS> * p = new pNodo<TS>();
      if (p!=NULL) { 
         p->info = d ;  
         p->pSig = pila;     
         pila = p ;
         return true ;
      } else return false ;     
   };
   
   bool pop(TS & d) {
      pNodo <TS> * p = pila ;
      if (pila!=NULL) {
         d = p->info ;
         pila  = p->pSig ;     
         delete (p) ;
         return true ;
      } else return false ;     
   };

   bool verProximo(TS & d) {
      pNodo <TS> * p = pila ;
      if (pila!=NULL) {
         d = p->info ;
         return true ;
      } else return false ;     
   };

    void inicializar() {
    	pila = NULL;
	}
    
    TDAPila() { inicializar();}; 

  bool vacia(){return pila == NULL ;} ;       
} ;

template <typename TS>
void contarPila(TDAPila <TS> pila,int &n){
	TDAPila <TS> pilaAux;	
	TS elemento;
	while(!pila.vacia()){
		pila.pop(elemento);
		pilaAux.push(elemento);
		n++;
	}
	while(!pilaAux.vacia()){
		pilaAux.pop(elemento);
		pila.push(elemento);
	}
	
}


int main (){
	
	TDAPila <int> pila;
	int n=0;
	
	pila.push(5);
	pila.push(10);
	pila.push(20);
	pila.push(26);
	
	contarPila<int>(pila,n);
	
	cout<<n<<endl;
}

