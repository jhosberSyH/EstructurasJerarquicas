#ifndef NodoArbolN_h
#define NodoArbolN_h
#include <iostream>
using namespace std;
template <class elemento>
class NodoArbolN{
	private:
		//****Atributos****//
		elemento info;
		NodoArbolN<elemento> *hijoIzquierdo,*hermanoDerecho;
	public:
		//****Metodos****//
		NodoArbolN();
		NodoArbolN(elemento e,NodoArbolN<elemento> *izq,NodoArbolN<elemento> *der);
		elemento getInfo();
		NodoArbolN<elemento>* getHijoIzquierdo();
		NodoArbolN<elemento>* getHermanoDerecho();
		void setInfo(elemento e);
		void setHijoIzquierdo(NodoArbolN<elemento> *p);
		void setHermanoDerecho(NodoArbolN<elemento> *p);
		void destruir();
};
#endif
