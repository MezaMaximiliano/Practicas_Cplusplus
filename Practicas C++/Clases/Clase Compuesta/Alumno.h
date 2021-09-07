#include "Direccion.h"
#include "Persona.h"
using namespace std;
class Alumno{
	private:
		int legajo;
		float promedio;
		Direccion dir;
		Persona per;
	
	public:
		Alumno(int legajo,float promedio, str30 _calle, int _altura,string nombre, int edad, unsigned long int dni): dir(_calle, _altura), per(nombre, edad, dni) {
			
			this->legajo=legajo;
			this->promedio=promedio;
			
		}
		
		void mostrarDatos(){
			per.mostrarDatos();
			cout<<"Legajo: "<<legajo<<endl;
			dir.mostrarDir();
			cout<<"Promedio: "<<promedio<<endl;
			
		}
		
		void nuevaDir(str30 calle,int altura){
			dir.setDire(calle,altura);
		}
		
		unsigned long int mostrarDni(){
			return per.getDni();
		}
};
