#include<iostream>
#include "ArbolN.h"
#include "ArbolN.cpp"
using namespace std;
int main(){
	ArbolN<int> arbolito,superArbolito,arbolito2;
	list<int> lis,camino;
	list<int> lista2;
	list<int> lista3;
	list<ArbolN<int>> hijos;
	int padre;
	cout<<"Paso 1 Insertar elementos"<<endl;
	arbolito.insertarPadreHijo(50,40);
	arbolito.insertarPadreHijo(50,45);
	arbolito.insertarPadreHijo(50,43);
	arbolito.insertarPadreHijo(40,30);
	arbolito.insertarPadreHijo(30,10);
	arbolito.insertarPadreHijo(10,5);
	arbolito.insertarPadreHijo(10,4);
	arbolito.insertarPadreHijo(10,3);
	arbolito.insertarPadreHijo(10,2);
	arbolito.insertarPadreHijo(10,1);
	arbolito.insertarPadreHijo(10,0);
	arbolito2.insertarPadreHijo(50,40);
	arbolito2.insertarPadreHijo(50,5);
	arbolito2.insertarPadreHijo(50,43);
	arbolito2.insertarPadreHijo(40,30);
	arbolito2.insertarPadreHijo(30,10);
	arbolito2.insertarPadreHijo(10,5);
	arbolito2.insertarPadreHijo(10,4);
	arbolito2.insertarPadreHijo(10,3);
	arbolito2.insertarPadreHijo(10,2);
	arbolito2.insertarPadreHijo(10,1);
	arbolito2.insertarPadreHijo(10,0);
	superArbolito.insertarPadreHijo(150,100);
	cout<<"Paso 2 preorden"<<endl;
	lis = arbolito.preorden();
	//arbolito.imprimirArbol();
	cout<<"Paso 3 postOrden"<<endl;
	lista2 = arbolito.postorden();
	arbolito.imprimirArbol();
	cout<<"Paso 4 inOrden"<<endl;
	lista3 = arbolito.inorden();
	//arbolito.imprimirArbol();
	cout<<"Peso Arbolito :"<<arbolito.getPeso()<<endl;
	while(lis.empty() != 1){
		cout<<lis.front()<<" ";
		lis.pop_front();
	}
	cout<<endl;
	while(lista2.empty() != 1){
		cout<<lista2.front()<<" ";
		lista2.pop_front();
	}
	cout<<endl;
	while(lista3.empty() != 1){
		cout<<lista3.front()<<" ";
		lista3.pop_front();
	}
	cout<<endl;
	cout<<"paso 5 imprimir arbol"<<endl;
	arbolito.imprimirArbol();
	//arbolito.eliminarSubArbol(2);
	//arbolito.imprimirArbol();
	cout<<"paso 6 Insertar sub arbol"<<endl;
	superArbolito.insertarSubArbol(arbolito);
	hijos = superArbolito.hijos();
	cout<<"paso 7 mostrar hijo"<<endl;
	superArbolito.imprimirArbol();
	lis = superArbolito.preorden();
	while(lis.empty() != 1){
		cout<<lis.front()<<" ";
		lis.pop_front();
	}
		cout<<endl;
	//superArbolito.eliminarSubArbol(2);
	superArbolito.imprimir();
	cout<<"Esta Balanceado :"<<superArbolito.estaBalanceado()<<endl;
	lis = superArbolito.recorridoPorNiveles();
	padre = superArbolito.encontrarPadreElemento(10);
	cout<<"El Padre es: "<<padre<<endl;
	camino = superArbolito.encontrarCamino(43,50);
	while(camino.empty() != 1){
		cout<<camino.front()<<" ";
		camino.pop_front();
	}
		cout<<endl;
		cout<<"Son insomorfos:"<<arbolito.sonIsomorfos(arbolito2)<<endl;
		arbolito.imprimirArbol();
		arbolito2.imprimirArbol();
		cout<<"altura:"<<superArbolito.altura()<<endl;
		cout<<"Hojas:"<<superArbolito.contarHojas()<<endl;
		cout<<"Ancestro:"<<superArbolito.ancestroComunMasReciente(100,50)<<endl;
	return 0;
}