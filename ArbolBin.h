#ifndef ArbolBin_h
#define ArbolBin_h
#include "NodoArbolBin.h"
#include "NodoArbolBin.cpp"
#include <list>
#include <vector>
#include <queue>
using namespace std;
template <class elemento>
class ArbolBin{
	private:
		//****Atributo****//
		int peso;
		NodoArbolBin<elemento> *Raiz;
		//****Metodos****//
		NodoArbolBin<elemento>* copiarNodos(NodoArbolBin<elemento> *ptrNodo);
		NodoArbolBin<elemento>* getRaiz();
		void setRaiz(NodoArbolBin<elemento> *p);
		void destruirNodos(NodoArbolBin<elemento> **ptrNodo);
		void anadir(NodoArbolBin<elemento> *actual, elemento nuevo);
		void insertarNodo(elemento padre, elemento hijo, NodoArbolBin<elemento> *raiz);
		void ancestroMasCercano(NodoArbolBin<elemento> *r, elemento e1, elemento e2, bool &encontrado1, bool &encontrado2, bool &LCAEncontrado, elemento &ancestro);
		void preorden(NodoArbolBin<elemento> *actual, list<elemento> &result); //listo y testeada
    	void inorden(NodoArbolBin<elemento> *actual, list<elemento> &result); //listo y testeada
    	void postorden(NodoArbolBin<elemento> *actual, list<elemento> &result); //listo y testeada
		void niveles(queue<NodoArbolBin<elemento>*> actual,list<elemento> &result); //listo y testeada
		void camino(NodoArbolBin<elemento> *actual, elemento origen, elemento destino, bool *encontrado1, bool *encontrado2, bool &LCAEncontrado, list<elemento> &salida, list<elemento> &aux);
		NodoArbolBin<elemento>* leerArbolPreorden(list<elemento> preorden, list<elemento> inorden); //listo y testeada
		NodoArbolBin<elemento>* leerArbolPostorden(list<elemento> postorden, list<elemento> inorden);
	public:
		//****Metodos****//
		ArbolBin();
		ArbolBin(elemento e, ArbolBin a1,ArbolBin a2);
		void copiar(ArbolBin &arbol);
		bool esNulo();
		elemento infoRaiz();
		void setPeso(int peso);
		ArbolBin getHijoIzquierdo();
		ArbolBin getHijoDerecho();
		void insertarSubarbol(ArbolBin<elemento> subarbol);
		void eliminarSubarbol(int pos);
		void destruir();
		elemento ancestroMasCercano(elemento e1, elemento e2);
		list<elemento> getPrimos(elemento info, list<NodoArbolBin<elemento>*> lista);
		void leerArbolPre(list<elemento> preorden, list<elemento> inorden); //listo y testeada
    	void leerArbolPost(list<elemento> postorden, list<elemento> inorden);
		list<elemento> camino(elemento origen, elemento destino);
		list<elemento> preorden(); //listo y testeada
		list<elemento> inorden(); //listo y testeada
		list<elemento> postorden(); //listo y testeada
		list<elemento> niveles(); //listo y testeada
};
#endif
