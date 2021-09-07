/*Sentencia while
	while (expresion logica){
		conjunto de instrucciones
	}
	*/

#include<iostream>
#include<conio.h> /*incluye el comando getch()*/
using namespace std;
int main(){
	int i=1;
	while (i<=10){  /* "<=" o ">=" incluye los valores dentro del conjunto. Intervalo cerrado.*/
		cout<<i<<endl;
		i++; /* i++ es igual a escribir i=i+1. Lo mismo para i--=i-1 */
	}
	
	getch(); /*espera hasta que presiones un caracter*/
	return 0;
	
}
