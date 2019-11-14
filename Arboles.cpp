#include <iostream>
#include <stdlib.h>
#include<conio.h>
using namespace std;

struct Nodo{
	int dato;
	Nodo *der;
	Nodo *izq;
};

void menu();

Nodo *crearNodo(int);
void agregarNodo(Nodo *&,int);

Nodo *arbol = NULL;

int main(){
	menu();
	
	getch();
	return 0;
}


void menu(){
	int dato, opcion;
cout<<"Agregar nodos a un arbol binario sin imprimir \n ";	
	do{
		cout<<"\t ***M E N U***"<<endl;
		cout<<"1.-Agregar un nodo"<<endl;
		cout<<"2-Salir"<<endl;
		cout<<"Elige una opcion: ";
		cin>>opcion;
		
		switch(opcion){
			case 1: cout<<"\nIngresa un numero: ";
					cin>>dato;
					agregarNodo(arbol,dato);
					cout<<"\nValor agregado correctamente \n ";
					system("pause");
					break;
		}
		system("cls");
	}while(opcion != 2);
}


Nodo *crearNodo(int n){
	Nodo *nuevoNodo = new Nodo();
	
	nuevoNodo->dato = n;
	nuevoNodo->der = NULL;
	nuevoNodo->izq = NULL;
	
	return nuevoNodo;
}

void agregarNodo(Nodo *&arbol, int n){
	if (arbol == NULL){
		Nodo *nuevoNodo = crearNodo(n);
		arbol = nuevoNodo;
	}
	else{
		int valorRaiz= arbol->dato;
		if (n < valorRaiz){
			agregarNodo(arbol->izq,n);
		}
		else{
			agregarNodo(arbol->der,n);
		}
	}
	
}
