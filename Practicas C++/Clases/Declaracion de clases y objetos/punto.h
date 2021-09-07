//declaracion de clase

class Punto{
	//atributos
	private:
		int x, y;
		
	//Metodos
	public:
		Punto(int _x, int _y){//Constructor uno
			x=_x;
			y=_y;
		}	
		
		Punto(){//Constructor dos
			x=y=0;
		}
		
		void setX(int valorX);//establecen valores de x e y
		void setY(int valorY);
		int getX();//obtienen valor de x e y;
		int getY();
};
