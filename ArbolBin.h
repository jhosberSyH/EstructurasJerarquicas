#ifndef ArbolN_h
#define ArbolBIn_h
#include "NodoArbolBin.h"
#include <list>
using namespace std;
template <class elemento>
class ArbolBin{
	private:
		//****Atributo****//
		int peso;
		NodoArbolBin<elemento> *Raiz;
		//****Metodos****//
		static NodoArbolBin<elemento>* copiarNodos(NodoArbolBin<elemento> *ptrNodo);
	public:
		//****Metodos****//
		ArbolBin();
		ArbolBin(elemento e, ArbolBin a1,ArbolBin a2);
		void copiar(ArbolBin &arbol);
		bool esNulo();
		elemento getRaiz();
		ArbolBin getHijoIzquierdo();
		ArbolBin getHijoDerecho();
		void destruir();
};
#endif
