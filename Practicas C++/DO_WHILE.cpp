/*sentencia DO WHILE

		do{
		
		conjunto de instrucciones;
		
		}while (condicion logica);
		
*/
#include<iostream>
#include<stdlib.h> /*contiene el comando system("pause") */
using namespace std;
int main(){
	int i;
	i =1;
	do{
		cout<<i<<endl;
		i++;
	}while(i<=10); //el ciclo se repite para todos los valores de i menores o iguales a  10
	
	system("pause");
	return 0;
}
