	//Para un conjunto de estudiantes de los que conocemos su edad debemos calcular el promedio y mostrar en 
	//la pantalla si se trata de alumnos de primaria, secundaria o universidad.
	//Si el promedio es menos a 12 años son alumnos de primaria; si el promedio está entre 12 y 18 años 
	//se trata de alumnos de secundaria; para promedio mayores se trata de alumnos universitarios.
	
	#include<iostream>
	#include <stdlib.h>
	
	using namespace std;
	
	int main(){
		
		float alumnos, edad, suma_edad= 0;
		float promedio=0;
		cout<<"Ingrese la cantidad de alumnos: ";
		cin>>alumnos;
		
		for (int i=1; i<=alumnos; i++){
			
			cout<<"Ingrese la edad del alumno numero "<< i <<": ";
			cin>>edad;
			suma_edad=suma_edad+edad;
		}
		promedio=suma_edad/alumnos;
		cout<<"El promedio de edad es: "<<promedio<<endl;
		if (promedio<12){
			cout<<"El promedio de edad marca que se trata de alumnos de primaria."<<endl;
		}else if(promedio>=12 && promedio<=18 ){
			cout<<"El promedio de edad marca que se trata de alumnos de secundaria."<<endl;
		}else if(promedio>18){
			cout<<"El promedio de edad marca que se trata de alumnos universitarios."<<endl;
		}
		
		
		
		system("pause");
		return 0;
	}
