#include "NodoArbolBin.h"
template <class elemento>
	NodoArbolBin<elemento>::NodoArbolBin(){
		this->hijoIzquierdo = NULL;
		this->hijoDerecho = NULL;
	}
template <class elemento>
	NodoArbolBin<elemento>::NodoArbolBin(elemento e,NodoArbolBin<elemento> *izq,NodoArbolBin<elemento> *der){
		this->info = e;
		this->hijoIzquierdo = izq;
		this->hijoDerecho = der;
	}
template <class elemento>
	elemento NodoArbolBin<elemento>::getInfo(){
		return (this->info);
	}
template <class elemento>
	NodoArbolBin<elemento>* NodoArbolBin<elemento>::getHijoIzquierdo(){
		return (this->hijoIzquierdo);
	}
template <class elemento>
	NodoArbolBin<elemento>* NodoArbolBin<elemento>::getHijoDerecho(){
		return (this->hijoDerecho);
	}
template <class elemento>
	void NodoArbolBin<elemento>::setInfo(elemento e){
		this->info = e;
	}
template <class elemento>
	void NodoArbolBin<elemento>::setHijoIzquierdo(NodoArbolBin<elemento> *p){
		this->hijoIzquierdo = p;
	}
template <class elemento>
	void NodoArbolBin<elemento>::setHijoDerecho(NodoArbolBin<elemento> *p){
		this->hijoDerecho = p;
	}