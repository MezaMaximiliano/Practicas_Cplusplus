#include <iostream>
using namespace std;


/*
segundo programa, variables globales y locales
*/


int main() {
	int x=10;
	int y=20;
	
	cout<<"1.   x="<<x<<"  y="<<y<<endl;
	
				{
					int x=1;
					int y=2;
			   	cout<<"2.   x="<<x<<"  y="<<y<<endl;
				}
	
	cout<<"3.   x="<<x<<"  y="<<y<<endl;
  return 0;
}

