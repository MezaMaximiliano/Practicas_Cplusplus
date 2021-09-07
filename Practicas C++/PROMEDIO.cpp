//promedio de notas
#include<iostream>

using namespace std;

	int main(){
		float nota1, nota2, nota3, nota4, promedio;
		
		cout<<"ingrese nota 1: ",cin>>nota1;
		cout<<"ingrese nota 2: ",cin>>nota2;
		cout<<"ingrese nota 3: ",cin>>nota3;
		cout<<"ingrese nota 4: ",cin>>nota4;
	
		promedio= (nota1+nota2+nota3+nota4)/4;
		cout<<"\nEl promedio de las notas es: "<<promedio<<endl;
	
		return 0;
	
	
	
}
