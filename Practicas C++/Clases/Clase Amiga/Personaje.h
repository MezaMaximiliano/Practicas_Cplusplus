class Personaje{
	
	friend void modificarDatos(Personaje &, int, int);//declaracion de funcion amiga, algo asi como el prototipo de la funcion
	
	private:
		int defensa;
		int ataque;
		
	public:
		
		Personaje(int defensa, int ataque){
			this->defensa=defensa;
			this->ataque=ataque;
		}	
		
		void mostrarDatos(){
			printf ("\nAtaque: %i",ataque);
			printf("\nDefensa: %i", defensa);
		}
};
