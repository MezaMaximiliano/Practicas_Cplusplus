#include <iostream>
#include<stdlib.h>
using namespace std;

int dateDiff (int day1, int month1, int year1, int day2, int month2, int year2) {
	return ( ( ( year1 - year2 ) * 12 + ( month1 - month2 ) ) * 30 + day1 - day2 );
}

int formattedDate (int day, int month, int year) {
	return day + ( month * 100 ) + ( year * 10000 );
}

void askDate (int &day, int &month, int &year, string &name) {
	cout<<"Primero ingrese anio: " <<endl;
	cin>>year;
	cout<<"Ahora ingrese mes: " <<endl;
	cin>>month;
	cout<<"Ahora ingrese el dia: " <<endl;
	cin>>day;
	cout<<"Y Ahora ingrese nombre: " <<endl;
	cin>>name;
}

void keepAdding(bool &keepRunning) {
  	int answer;
	cout<<"Desea continuar?: (presione 1 para continuar o cualquier otra para terminar)" <<endl;
	cin>>answer;
	if (answer == 1) {
		keepRunning = true;
	} else {
		keepRunning = false;
	}
}

int main() {
	int year, month, day, amountDiffDates, overThirty, betweenAges, underTwentyOne, date;
	int currentYear, currentMonth, currentDay;
	int majorDate, minorDate;
	bool keepRunning = true;
	string name, oldName, firtsName;
	betweenAges = 0;
	majorDate=0;
	minorDate=99999999;
	cout<<"-----------Bienvenido!------------- "<<endl;
	cout<<"-----------------------------------"<<endl;
	cout<<"Por Favor ingrese la fecha actual:"<<endl;
	cout<<"El anio actual: "<<endl;
	cin>>currentYear;
	cout<<"El mes actual: "<<endl;
	cin>>currentMonth;
	cout<<"El dia actual: "<<endl;
	cin>>currentDay;
	system("cls");
	cout<<"Ahora ingrese las fechas y los nombres: "<<endl;
	while ( keepRunning ) {
		askDate( day, month, year, name );

		date = formattedDate( day, month, year );

		if ( date < minorDate ) {
			minorDate = date;
			firtsName = name;
		} else if ( date > majorDate ) {
			majorDate = date;
			oldName = name;
		}

		amountDiffDates = dateDiff( currentDay, currentMonth, currentYear, day, month, year );

		if ( amountDiffDates < 7560 ) {
			underTwentyOne++;
		} else if ( amountDiffDates < 10800 ) {
			betweenAges++;
		} else {
			overThirty++;
		}
		keepAdding(keepRunning);
	}
	cout<<"Los Mayores de 30 son: "<<overThirty<<endl;
	cout<<"Los Mayores de 21 y menores de 30 son: "<<betweenAges<<endl;
	cout<<"Los menores de 21 son: "<<underTwentyOne<<endl;
	cout<<"El nombre de la persona mayor: "<<firtsName<<endl;
	cout<<"El nombre de la persona menor: "<<oldName<<endl;
	
	system("pause");
	return 0;
}

