#include<iostream>
#include<stdlib.h>

using namespace std;

struct Nodo{
	int dato;
	Nodo *der;
	Nodo *izq;
};

void menu();
Nodo *crearNodo(int);
void insertarNodo(Nodo *&,int);
void mostrarArbol(Nodo *,int contador);
bool buscarNodo(Nodo *,int);
void preOrden(Nodo *);
void inOrden(Nodo *);
void postOrden(Nodo *);

Nodo *arbol=NULL;

int main(){
	
	
	menu();
	system("pause");
	return 0;
}

void menu(){
	int dato,opcion,contador=0;
	
	do{
		cout<<"\t.:MENU:."<<endl;
		cout<<"1. Insertar un nuevo nodo"<<endl;
		cout<<"2. mostrar el arbol completo"<<endl;
		cout<<"3. buscar nodo"<<endl;
		cout<<"4. PreOrden"<<endl;//raiz,izq y der
		cout<<"5. InOrden"<<endl;//izq,raiz y der
		cout<<"6. PostOrden"<<endl;//izq,der y raiz
		cout<<"7. salir"<<endl;
		cout<<"-> ";cin>>opcion;
		
		switch(opcion){
			case 1:{
				cout<<"Digite un numero: ";cin>>dato;
				insertarNodo(arbol,dato);
				
				break;
			}
			case 2:{
				cout<<"\nMostrando el arbol completo:\n\n";
				mostrarArbol(arbol,contador);
				cout<<"\n";
				system("pause");
				break;
			}
			case 3:{
				cout<<"Numero a buscar: ";cin>>dato;
				
				if(buscarNodo(arbol,dato)){
					cout<<"El "<<dato<<" SI existe en el arbol"<<endl;
				}
				else{
					cout<<"El "<<dato<<" NO existe en el arbol"<<endl;
				}
				system("pause");
				break;
			}
			case 4:{
				preOrden(arbol);
				cout<<endl;
				system("pause");
				break;
			}
			case 5:{
				inOrden(arbol);
				cout<<endl;
				system("pause");
				break;
			}
			case 6:{
				postOrden(arbol);
				cout<<endl;
				system("pause");
				break;
			}
		}
		system("cls");
	}while(opcion!=7);
	
	
}

void insertarNodo(Nodo *&arbol,int n){
	
	if(arbol==NULL){
		Nodo *nuevoNodo=crearNodo(n);
		arbol=nuevoNodo;
	}
	else{
		int valorRaiz=arbol->dato;
		if(n<valorRaiz){
			insertarNodo(arbol->izq,n);
		}
		else{
			insertarNodo(arbol->der,n);
		}
	}
	
}

void mostrarArbol(Nodo *arbol,int contador){
	
	if(arbol==NULL){
		return;
	}
	else{
		mostrarArbol(arbol->der,contador+1);
		for(int i=0;i<contador;i++){
			cout<<"   ";
		}
		cout<<arbol->dato<<endl;
		mostrarArbol(arbol->izq,contador+1);
	}
	
}

bool buscarNodo(Nodo *arbol,int n){
	
	if(arbol==NULL){
		return false;
	}
	else if(arbol->dato==n){
		return true;
	}
	else{
		int valor=arbol->dato;
		if(n>valor){
			return buscarNodo(arbol->der,n);			
		}
		else{
			return buscarNodo(arbol->izq,n);			
		}
	}

	
}

void preOrden(Nodo *arbol){
	
	if(arbol==NULL){
		return;
	}
	else{
		cout<<arbol->dato<<" - ";
		preOrden(arbol->izq);
		
		preOrden(arbol->der);
	}
	
}

void inOrden(Nodo *arbol){
	
	if(arbol==NULL){
		return;
	}
	else{
		inOrden(arbol->izq);
		cout<<arbol->dato<<" - ";
		inOrden(arbol->der);
	}
}

void postOrden(Nodo *arbol){
	
	if(arbol==NULL){
		return;
	}
	else{
		postOrden(arbol->izq);
		postOrden(arbol->der);
		cout<<arbol->dato<<" - ";
	}
	
}

Nodo *crearNodo(int n){
	Nodo *nuevo_nodo = new Nodo();
	
	nuevo_nodo->dato=n;
	nuevo_nodo->der=NULL;
	nuevo_nodo->izq=NULL;
	
	return nuevo_nodo;
}
