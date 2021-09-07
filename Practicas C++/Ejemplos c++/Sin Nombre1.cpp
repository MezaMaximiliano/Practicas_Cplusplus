void procesarCorte(tVectorEst vEst, int cant){
	str30 carAnt;  //char[30]
	int i =0;
	tRegEst r; //estructura con dni, carrera, apellido, nombre, anio ingreso
	bool fin;
	int total=0;
	int totalCar;
	traer(vEst,t,cant,i,fin);  //tVectorEst vector de estructuras tRegEst 
	while(!fin){
		strcpy(carAnt,r.carrera);
		totalCar=0;
		cout<<"Carrera "<<cartAnt<<endl;
		while ((!fin)and (strcmp(carAnt,r.carrera)==0)){
			totalCar++;
			traer(vEst,r,cant,i,fin);
		}
		
		cout<<"Total Carrera "<<totalCar<<endl;
		total=total+totalCar;
	}
	
	cout<<"Total ingreso de las carreras es "<<total<<endl;
}

void traer(tVectorEst v, tRegEst &r,int cant, int &ptro,bool &fin){
	if (ptro<cant){
		r=v[ptro];
		ptro++;
		fin=false;
	}else fin=true;
}

