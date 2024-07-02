#ifndef NodoArbolBin_h
#define NodoArbolBin_h
#include <iostream>
#include <list>
#include <vector>
using namespace std;
template <class elemento>
class NodoArbolBin{
	private:
		//****Atributos****//
		elemento info;
		NodoArbolBin<elemento> *hijoIzquierdo,*hijoDerecho;
	public:
		//****Metodos****//
		NodoArbolBin();
		NodoArbolBin(elemento e,NodoArbolBin<elemento> *izq,NodoArbolBin<elemento> *der);
		elemento getInfo();
		NodoArbolBin<elemento>* getHijoIzquierdo();
		NodoArbolBin<elemento>* getHijoDerecho();
		void setInfo(elemento e);
		void setHijoIzquierdo(NodoArbolBin<elemento> *p);
		void setHijoDerecho(NodoArbolBin<elemento> *p);
};
#endif
