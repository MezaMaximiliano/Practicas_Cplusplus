/* la sentencia switch

		switch (expresion) {
		
		case literal_1:	
			conjunto de instrucciones1;
			break;
		case literal_2:
			conjunto de intrucciones2
			break;
		case literal_n:
			conjuntod de instrucciones_n
			break
		default:
			conjunto de instrucciones por defecto;
			break;
			
		}
		
*/

#include<iostream>
using namespace std;

int main (){
	
	int num;
	cout<<"Ingrese un numero: ";
	cin>>num;
	switch (num){
	
	case 5:
		cout<<"El numero es 5.";
		break;
	case 6:
		cout<<"El numero es 6.";
		break;
	case 7:
		cout<<"El numero es 7.";
		break;
	default:
		cout<<"El valor no valido";
		break;
	}

	
	
	
	return 0;
}
