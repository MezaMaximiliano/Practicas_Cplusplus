/*sentencia if

		if (condicion){
			
			instruccion 1
			
		}
		else{
		instruccion 2
		}
*/
#include<iostream>


using namespace std;
int main(){
	int num, dato=5;
	
	cout<<"Ingrese un numero: ";
	cin>>num;
	
	if (num!=dato){
		if (num>dato){
			cout<<"El numero es mayor a 5";
		}
		else{
			cout<<"El numero es menor a 5";
		}
	}
    else {
    	cout<<"El numero es igual a 5";
    }
	
		
	return 0;
}
