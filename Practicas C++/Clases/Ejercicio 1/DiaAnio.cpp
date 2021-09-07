#include "DiaAnio.h"
#include<iostream>

		
	void DiaAnio::setDia(int valorDia){
		dia=valorDia;
	}
	
	void DiaAnio::setMes(int valorMes){
		mes=valorMes;
	}
	
	int DiaAnio::getDia(){
		return dia;
	}
	
	int DiaAnio::getMes(){
		return mes;
	}
	
	bool DiaAnio::igual(DiaAnio &d){
		if ((dia==d.dia)and (mes==d.mes)){
			return true;
		}else{
			return false;
		}
	}
	
	void DiaAnio::visualizar(){
		printf("%i / %i\n", dia, mes);
	}
