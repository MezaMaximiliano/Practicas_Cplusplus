#include <iostream>

class Persona{
	private:
		string nombre;
		int edad;
		unsigned long int dni;
		
		
	public:
		Persona(string nombre, int edad, unsigned long int dni){
			this->dni=dni;
			this->nombre=nombre;
			this->edad=edad;
		}
		Persona(){
			
		}
		
		void setPersona(string nombre, int edad, unsigned long int dni){
			this->dni=dni;
			this->nombre=nombre;
			this->edad=edad;
		}
		
		unsigned long int getDni(){
			return dni;
		}
		
		string getNombre(){
			return nombre;
		}
		int getEdad(){
			return edad;
		}
		
		
		void mostrarDatos(){
			cout<<"Nombre: "<<nombre<<endl;
			cout<<"Edad: "<<edad<<endl;
			cout<<"DNI: "<<dni<<endl;
		}
};
	
