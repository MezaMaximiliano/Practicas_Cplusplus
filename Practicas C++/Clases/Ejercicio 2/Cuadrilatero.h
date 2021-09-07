class Cuadrilatero{
	
	private:
		float ladoA;
		float ladoB;
	
		
	public:
		Cuadrilatero(float ladoA, float ladoB){
			this->ladoA=ladoA;
			this->ladoB=ladoB;
				
		}
		Cuadrilatero(float lado){
			this->ladoA=this->ladoB=lado;
		
		}
		Cuadrilatero(){
		}
		
		~Cuadrilatero(){
		}
		
	
		float getArea();
		float getPerimetro();
	
	
};
