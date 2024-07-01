#ifndef ArbolN_h
#define ArbolN_h
#include "NodoArbolN.h"
#include "NodoArbolN.cpp"
#include <list>
using namespace std;
template <class elemento>
class ArbolN{
	private:
		//****Atributo****//
		int peso;
		NodoArbolN<elemento> *raiz;
		//****Metodos****//
		NodoArbolN<elemento>* copiarNodos(NodoArbolN<elemento> *p); //listo
		void destruirNodos(NodoArbolN<elemento>* p);
		void preorden(NodoArbolN<elemento> *p,list<elemento> &result); //listo
		void postorden(NodoArbolN<elemento> *p,list<elemento> &result); //listo
		void inorden(NodoArbolN<elemento> *p,list<elemento> &result); //listo
		void insertarPadreHijo(elemento padre,elemento hijo,NodoArbolN<elemento>* &p,bool &band);
		int getPesoArboles(NodoArbolN<elemento> *p); //listo
	public:
		//****Metodos****//
		ArbolN(); //listo
		ArbolN(elemento e, list<ArbolN> lista); //listo
		void copiar(ArbolN &arbol); //listo
		bool esNulo(); //listo
		elemento getRaiz(); //listo
		int getPeso(); //listo
		list<ArbolN<elemento>> hijos(); //error
		void insertarSubArbol(ArbolN<elemento> arbol); //listo
		void eliminarSubArbol(int pos);
		void destruir();
        void insertarPadreHijo(elemento padre,elemento hijo);// casi lista 
		void imprimirArbol();// lista testeada
		list<elemento> preorden(); //listo testeada
		list<elemento> postorden(); //listo testeada
		list<elemento> inorden(); //listo
};
#endif
