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
void mostrarArbol(Nodo *,int);
void preOrden(Nodo*);
void enOrden(Nodo *);
void postOrden(Nodo *);

Nodo *arbol = NULL;

int main(){
	menu();
	
	getch();
	return 0;
}


void menu(){
	int dato, opcion,contador=0;
	cout<<"Se agrega Post-Orden\n";
	do{
		cout<<"\t**M E N U***"<<endl;
		cout<<"1.-Agregar un nodo"<<endl;
		cout<<"2.-Mostrar arbol"<<endl;
		cout<<"3.-Pre-Orden"<<endl;
		cout<<"4.-Orden"<<endl;
		cout<<"5.-Post-Orden"<<endl;
		cout<<"6-Salir"<<endl;
		cout<<"Elige una opcion: ";
		cin>>opcion;
		
		switch(opcion){
			case 1: cout<<"\nDame un numero: ";
					cin>>dato;
					agregarNodo(arbol,dato);
					cout<<"\nValor agregado correctamente \n ";
					system("pause");
					break;
			case 2: cout<<"\nSe muestra el arbol:\n\n";
					mostrarArbol(arbol,contador);
					cout<<"\n";
					system("pause");
					break;
			case 3: cout<<"\n Se muestra el recorrido en Pre-Orden: ";
					preOrden(arbol);
					cout<<"\n\n";
					system("pause");
					break;
			case 4: cout<<"\n Se muestra el recorrido en Orden: ";
					enOrden(arbol);
					cout<<"\n\n";
					system("pause");
					break;
			case 5: cout<<"Se muestra el recorrido Post-Orden: ";
					postOrden(arbol);
					cout<<"\n\n";
					system("pause");
					break;
		}
		system("cls");
	}while(opcion != 6);
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

void mostrarArbol(Nodo *arbol, int cont){
	if(arbol == NULL){
		return;
	}
	else{
		mostrarArbol(arbol->der,cont+1);
		for(int i=0;i<cont;i++){
			cout<<"   ";
		}
		cout<<arbol->dato<<endl;
		mostrarArbol(arbol->izq,cont+1);
	}
}

void preOrden(Nodo *arbol){
	if(arbol == NULL){
		return;
	}
	else{
		cout<<arbol->dato<<" - ";
		preOrden(arbol->izq);
		preOrden(arbol->der);
	}
}

void enOrden(Nodo *arbol){
	if(arbol == NULL){
		return;
	}
	else{
		enOrden(arbol->izq);
		cout<<arbol->dato<<" - ";
		enOrden(arbol->der);
	}
}

void postOrden(Nodo *arbol){
	if(arbol == NULL){
		return;
	}
	else{
		enOrden(arbol->izq);
		enOrden(arbol->der);
		cout<<arbol->dato<<" - ";
	}
}
