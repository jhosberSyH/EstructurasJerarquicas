#ifndef ArbolN_h
#define ArbolN_h
#include "NodoArbolN.h"
#include "NodoArbolN.cpp"
#include <list>
#include <vector>
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
		void imprimir(NodoArbolN<elemento>* p, int nivel);
		NodoArbolN<elemento>* buscar(NodoArbolN<elemento>* p, elemento valor);
		NodoArbolN<elemento>* buscarNodo(elemento valor);
		NodoArbolN<elemento>* encontrarPadreNodo(NodoArbolN<elemento>* p, NodoArbolN<elemento>* hijo);
		elemento encontrarPadreElemento(NodoArbolN<elemento>* p,elemento hijo);
		int altura(NodoArbolN<elemento>* p); 
		bool estaBalanceado(NodoArbolN<elemento>* p, int &altura);
		bool esEspejo(NodoArbolN<elemento>* nodo1, NodoArbolN<elemento>* nodo2);
		bool sonIsomorfos(NodoArbolN<elemento>* nodo1, NodoArbolN<elemento>* nodo2);
		bool encontrarRuta(NodoArbolN<elemento> *nodo, elemento objetivo, vector<NodoArbolN<elemento>*> &ruta);
		int contarHojas(NodoArbolN<elemento>* p);
		NodoArbolN<elemento>* ancestroComunMasReciente(NodoArbolN<elemento>* nodo, elemento nodo1, elemento nodo2);
		void diametro(NodoArbolN<elemento>* nodo, int &diametro,int &altura, vector<elemento> &camino);

	public:
		//****Metodos****//

		ArbolN(); //listo
		ArbolN(elemento e, list<ArbolN> lista); //listo
		void copiar(ArbolN &arbol); //listo
		bool esNulo(); //listo
		elemento raizElemento(); //listo
		NodoArbolN<elemento>* getRaiz();
		void imprimir(); 
		int altura();
		int getPeso(); //listo
		list<ArbolN<elemento>> hijos(); //listo
		void insertarSubArbol(ArbolN<elemento> arbol); //listo
		void eliminarSubArbol(int pos);
		void destruir();
        void insertarPadreHijo(elemento padre,elemento hijo);// casi lista 
		elemento encontrarPadreElemento(elemento valor);
		list<elemento> preorden(); //listo testeada
		list<elemento> postorden(); //listo testeada
		list<elemento> inorden(); //listo
		list<elemento> recorridoPorNiveles(); //listo
		
		//El Desastre Negro Del Orinoco
		list<elemento> encontrarCamino(elemento elemento1, elemento elemento2);
		bool sonIsomorfos(ArbolN<elemento>& otro);
		bool esEspejo();
		bool estaBalanceado();
		void imprimirArbol();// lista testeada
		int contarHojas();
		elemento ancestroComunMasReciente(elemento elemento1, elemento elemento2); 
		vector<elemento> diametro();




};
#endif
