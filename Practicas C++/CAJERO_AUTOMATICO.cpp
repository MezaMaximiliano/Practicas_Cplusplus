//Cajero automatico con 3 opciones. Saldo inicial 1000
#include<iostream>
using namespace std;
int main(){
float saldo=1000, dinero=0;
int opcion;
 cout<<"\tElija la opcion de la operacion a realizar: "<<endl; /* "\t" te da un espacio de tabulacion*/
 cout<<"1-Retirar efectivo."<<endl<<"2-Ingresar efectivo."<<endl<<"3-Salir"<<endl;
 cin>>opcion;
 switch (opcion){
 	case 1:
 		cout<<"Su saldo actual es de "<<saldo<<" pesos."<<endl;
 		cout<<"Cuanto dinero desea retirar: $";
 		cin>>dinero;
 	    if (dinero<=saldo){
 	    	cout<<"Usted tiene un saldo actual de $"<<saldo<<". Va a retirar $"<<dinero<<endl;
 	    	
 	    	saldo=saldo-dinero;
 	    	cout<<"Su saldo actual es de $"<<saldo;
 	    } else{
 	    	cout<<"No posea saldo suficiente para su extraccion.";
 	    }
 		break;
 	case 2:
 		cout<<"Usted tiene un saldo actual de $"<<saldo<<endl;
 		cout<<"Cuanto dinero desea ingresar: $",cin>>dinero;
 		if (dinero>0){
 			cout<<"Usted ha ingresado $"<<dinero<<endl;
 			saldo=saldo+dinero;
 			cout<<"Su saldo actual es de $"<<saldo;
 		} else{
 			cout<<"Valor no valido para operar.";
 		}
 		break;
 	case 3: cout<<"Ha elegido la opcion de Salir.";
 		break;
 	default: cout<<"No ha elegido una opcion valida.";
 		break;
 	
 }
 
return 0;
}
