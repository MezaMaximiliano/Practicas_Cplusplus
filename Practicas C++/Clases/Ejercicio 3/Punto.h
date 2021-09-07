class Punto{
	
	private:
		int ejeX;
		int ejeY;
		
	public:
		
		Punto(int ejeX, int ejeY){
			this->ejeX=ejeX;
			this->ejeY=ejeY;
		}
		Punto(){
			this->ejeX=this->ejeY=0;
		}
		
		void mover(int x, int y);
	
		void mostrarCoordenada();
};
