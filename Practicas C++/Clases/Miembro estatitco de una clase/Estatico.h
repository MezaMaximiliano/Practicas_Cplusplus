class Estatico{
	
	private:
		static int contador;  //declaracion miembro estatico de una clase
		
		
	public:
		
		Estatico(){//cada vez que se crea un objeto el contador suma 1
			contador++;
		}
		~Estatico(){
			contador--;
		}
		
		int getContador(){
			return contador;
		}
		
		
	
};
