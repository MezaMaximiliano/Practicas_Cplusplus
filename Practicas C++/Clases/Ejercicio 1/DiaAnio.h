

class DiaAnio{
	private:
		int dia;
		int mes;
		
	public:
		DiaAnio(int _dia,int _mes){
			dia=_dia;
			mes=_mes;
		}
		
		void setMes(int valorMes);
		void setDia(int valorDia);
		int getDia();
		int getMes();
		bool igual(DiaAnio &);
		void visualizar();
			
		
};
