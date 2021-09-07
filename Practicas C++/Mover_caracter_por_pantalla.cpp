#include<stdio.h>
#include<windows.h>
//#include<iostream>
#include<conio.h>
#include<stdlib.h>



void gotoxy(int , int );


int main(){
	int x,y;
	char respuesta;
	x=y=0;
	gotoxy(x,y);
	printf("*");
	respuesta=getch();
	
	while (respuesta!='z'){
		
		
		
		switch(respuesta){
		
			case 'w':
				
				y--;
			
				break;
				
			case 's':
			
				y++;
			
				break;
				
			case 'd':
				
				x++;
				
				break;
			case 'a':
			
				x--;
				
				break;	
				
		
			default:
				respuesta='h';
				break;
		}
	system("cls");
	gotoxy(x,y);
	printf("*");	
	respuesta=getch();
	}
	
	
	
	return 0;
}




void gotoxy(int x, int y){
	HANDLE hcon;
	hcon=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X=x;
	dwPos.Y=y;
	SetConsoleCursorPosition(hcon,dwPos);
}
