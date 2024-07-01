#include "NodoArbolN.h"
template <class elemento>
	NodoArbolN<elemento>::NodoArbolN(){
		this->hijoIzquierdo = NULL;
		this->hermanoDerecho = NULL;
	}
template <class elemento>
	NodoArbolN<elemento>::NodoArbolN(elemento e,NodoArbolN<elemento> *izq,NodoArbolN<elemento> *der){
		this->info = e;
		this->hijoIzquierdo = izq;
		this->hermanoDerecho = der;
	}
template <class elemento>
	elemento NodoArbolN<elemento>::getInfo(){
		return (this->info);
	}
template <class elemento>
		NodoArbolN<elemento>* NodoArbolN<elemento>::getHijoIzquierdo(){
			return (this->hijoIzquierdo);
		}
template <class elemento>
		NodoArbolN<elemento>* NodoArbolN<elemento>::getHermanoDerecho(){
			return (this->hermanoDerecho);
		}
template <class elemento>
		void NodoArbolN<elemento>::setInfo(elemento e){
			this->info = e;
		}
template <class elemento>
		void NodoArbolN<elemento>::setHijoIzquierdo(NodoArbolN<elemento> *p){
			this->hijoIzquierdo = p;
		}
template <class elemento>
		void NodoArbolN<elemento>::setHermanoDerecho(NodoArbolN<elemento> *p){
			this->hermanoDerecho = p;
		}
template <class elemento>
	void NodoArbolN<elemento>::destruir(){
		this->setHermanoDerecho(NULL);
		this->setHijoIzquierdo(NULL);
	}
