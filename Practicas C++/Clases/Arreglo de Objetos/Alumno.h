

class Alumno{
	
	private:
		float calMate;
		float calGeo;
		
	public:
		Alumno(float calMate, float calGeo){
			this->calMate=calMate;
			this->calGeo=calGeo;
		}
		Alumno(){
			
		}
		
		~Alumno(){	//Destructor de Objetos
		}
		
		void setCal();
		void mostrarCal();
		
		
		
};
