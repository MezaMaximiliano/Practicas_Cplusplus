#include<iostream>
using namespace std;
	
	int main (){;	
		float precio;
		float productoiva;
		float iva;
		
		precio=0, productoiva=0;
		cout<<"Ingrese precio de producto: ", cin>>precio;
		
		iva=precio*0.21;
		productoiva=iva + precio;
		
		
		cout<<"\nEl precio del producto con IVA es: " <<productoiva<<endl;
		
		return 0;
		
		
	
		
	
	
	
	}
