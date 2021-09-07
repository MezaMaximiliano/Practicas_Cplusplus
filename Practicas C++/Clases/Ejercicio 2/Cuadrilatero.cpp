#include "Cuadrilatero.h"
#include<iostream>


	float Cuadrilatero::getPerimetro(){
		float perimetro;
		perimetro=2*ladoA+2*ladoB;
		return perimetro;		
	}
	
	float Cuadrilatero::getArea(){
		float area;
		area=(ladoA*ladoB);
		return area;		
	}
	

