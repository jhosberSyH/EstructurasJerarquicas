#include "ArbolN.h"
#include <list>
#include <vector>
/********************************************************************************************************************************************************************/


template <class elemento>
	ArbolN<elemento>::ArbolN(){
		this->raiz = NULL;
		this->peso = 0;
	}
	
	
/********************************************************************************************************************************************************************/


template <class elemento>
	NodoArbolN<elemento>* ArbolN<elemento>::copiarNodos(NodoArbolN<elemento> *p){
		NodoArbolN<elemento> *nuevoNodo;
		if(p == NULL){
			return (NULL);
		}else{
			nuevoNodo = new(NodoArbolN<elemento>);
			nuevoNodo->setInfo(p->getInfo());
			nuevoNodo->setHijoIzquierdo(this->copiarNodos(p->getHijoIzquierdo()));
			nuevoNodo->setHermanoDerecho(this->copiarNodos(p->getHermanoDerecho()));
			return (nuevoNodo);
		}
	}
/********************************************************************************************************************************************************************/


template <class elemento>
	ArbolN<elemento>::ArbolN(elemento e,list<ArbolN> lista){
		NodoArbolN<elemento> *aux;
		this.raiz->setInfo(e);
		if(!lista.empaty()){
			this.raiz->setHijoIzquierdo(this->copiarNodos(lista.front()->getRaiz()));
			lista.pop_front();
			aux = this.raiz->getHijoIzquierdo();
			while(!lista.empaty()){
				aux->setHermanoDerecho(this->copiarNodos(lista.front()->getRaiz()));
				lista.pop_front();
				aux = aux->getHermanoDerecho();
			}
		} 
		
		
	}
	
/********************************************************************************************************************************************************************/
template <class elemento>
	void ArbolN<elemento>::preorden(NodoArbolN<elemento> *p,list<elemento> &result){
		NodoArbolN<elemento> *hijo;
		if(p != NULL){
			result.push_back(p->getInfo());
			hijo = p->getHijoIzquierdo();
			while(hijo != NULL){
				this->preorden(hijo,result);
				hijo = hijo->getHermanoDerecho();
			}
		}
	}
template <class elemento>
	list<elemento> ArbolN<elemento>::preorden(){
		list<elemento> result;
		NodoArbolN<elemento> *p;
		p = this->raiz;
		if(p == NULL){
			cout<<"esta vacia la raiz"<<endl;
		}
		this->preorden(p,result);
		return (result);
	}
/*********************************************************************************************************************************************************************/


/********************************************************************************************************************************************************************/
template <class elemento>
	void ArbolN<elemento>::postorden(NodoArbolN<elemento> *p,list<elemento> &result){
		NodoArbolN<elemento> *hijo;
		if(p != NULL){
			hijo = p->getHijoIzquierdo();
			while(hijo != NULL){
				this->postorden(hijo,result);
				hijo = hijo->getHermanoDerecho();
			}
			result.push_back(p->getInfo());
		}
	}
template <class elemento>
	list<elemento> ArbolN<elemento>::postorden(){
		list<elemento> result;
		NodoArbolN<elemento> *p;
		p = this->raiz;
		if(p == NULL){
			cout<<"esta vacia la raiz"<<endl;
		}
		this->postorden(p,result);
		return (result);
	}
/*********************************************************************************************************************************************************************/


/********************************************************************************************************************************************************************/
template <class elemento>
	void ArbolN<elemento>::inorden(NodoArbolN<elemento> *p,list<elemento> &result){
		NodoArbolN<elemento> *hijo;
		if(p != NULL){
			hijo = p->getHijoIzquierdo();
			this->inorden(hijo,result);
			result.push_back(p->getInfo());
			if(hijo != NULL){
				hijo = hijo->getHermanoDerecho();
			}
			while(hijo != NULL){
				this->inorden(hijo,result);
				hijo = hijo->getHermanoDerecho();
			}
		}
	}
template <class elemento>
	list<elemento> ArbolN<elemento>::inorden(){
		list<elemento> result;
		NodoArbolN<elemento> *p;
		p = this->raiz;
		if(p == NULL){
			cout<<"esta vacia la raiz"<<endl;
		}
		this->inorden(p,result);
		return (result);
	}
	
	
/*********************************************************************************************************************************************************************/
template <class elemento>
	void ArbolN<elemento>::copiar(ArbolN<elemento> &arbol){
		this->raiz = this->copiarNodos(arbol.raiz);
	}


/*********************************************************************************************************************************************************************/
template <class elemento>
	bool ArbolN<elemento>::esNulo(){
		return (this->raiz == NULL);
	}

		
/*********************************************************************************************************************************************************************/
template <class elemento>
	elemento ArbolN<elemento>::raizElemento(){
		return (this->raiz->getInfo());		
	}
template <class elemento>
	NodoArbolN<elemento>* ArbolN<elemento>::getRaiz(){
		return (this->raiz);		
	}
template <class elemento>
	int ArbolN<elemento>::getPeso(){
		return (this->peso);
	}	
		
/*********************************************************************************************************************************************************************/
template <class elemento>
	list<ArbolN<elemento>> ArbolN<elemento>::hijos(){
		ArbolN<elemento> arbolAux;
		list<ArbolN> lista;
		NodoArbolN<elemento> *aux;
		aux = this->raiz->getHijoIzquierdo();
		while(aux != NULL){
			arbolAux.raiz = aux;
			lista.push_back(arbolAux);
			aux = aux->getHermanoDerecho();
		}
		return (lista);
	}

		
/*********************************************************************************************************************************************************************/
template <class elemento>
void ArbolN<elemento>::insertarSubArbol(ArbolN<elemento> arbol){
	NodoArbolN<elemento> *aux;
	if(this->raiz->getHijoIzquierdo() == NULL){
		this->raiz->setHijoIzquierdo(this->copiarNodos(arbol.raiz));
	}else{
		aux = this->raiz->getHijoIzquierdo();
		while(aux->getHermanoDerecho() != NULL ){
			aux = aux->getHermanoDerecho();
		}
		aux->setHermanoDerecho(this->copiarNodos(arbol.raiz));
	}
	this->peso = this->peso + arbol.getPeso();
}


/*********************************************************************************************************************************************************************/



/*********************************************************************************************************************************************************************/
template <class elemento>
void ArbolN<elemento>::insertarPadreHijo(elemento padre,elemento hijo,NodoArbolN<elemento>* &p,bool &band){
    NodoArbolN<elemento> *aux,*nuevoHijo = new NodoArbolN<elemento>(hijo,NULL,NULL); 
	if(p == NULL){
		NodoArbolN<elemento> *nuevo = new NodoArbolN<elemento>(padre,NULL,NULL);
        nuevo->setHijoIzquierdo(nuevoHijo);
		p = nuevo;
		band = true;
		this->peso++;
    }else{
		aux = p;
		if(p->getInfo() == padre ){
			band = true;
			if(aux->getHijoIzquierdo() == NULL){
				aux->setHijoIzquierdo(nuevoHijo);         
			}else{
				aux = aux->getHijoIzquierdo();
				while(aux->getHermanoDerecho() != NULL){
					aux = aux->getHermanoDerecho();                 
				}                
				aux->setHermanoDerecho(nuevoHijo);
			}
		}
		aux = aux->getHijoIzquierdo();
		while((aux != NULL) && (!band)){
			if(aux->getInfo() == padre ){
				band = true;
				if(aux->getHijoIzquierdo() == NULL){
					aux->setHijoIzquierdo(nuevoHijo);         
				}else{
					aux = aux->getHijoIzquierdo();
					while(aux->getHermanoDerecho() != NULL){
						aux = aux->getHermanoDerecho();                 
					}                
					aux->setHermanoDerecho(nuevoHijo);
				}           
			}else{
				this->insertarPadreHijo(padre,hijo,aux,band);
			}    
			aux = aux->getHermanoDerecho();
		}
		
    }
}

template <class elemento>
void ArbolN<elemento>::insertarPadreHijo(elemento padre,elemento hijo){
      NodoArbolN<elemento> *p;
	  bool band = false;
	  p = this->raiz;
      this->insertarPadreHijo(padre,hijo,p,band);
	  if(p == NULL){
		cout<<"esta vacio"<<endl;
	  }
	  this->raiz = p; 
	  this->peso++;
}

template <class elemento>
void ArbolN<elemento>::imprimirArbol(){
	NodoArbolN<elemento> *hijo;
	list<NodoArbolN<elemento>* > cola;
	if(this->raiz != NULL){
		int i = 0,j = this->peso,k = 0,nHijos =0;
		cola.push_back(this->raiz);
		i = j;
		for(j; j >  0; j--){
			cout<<" ";
		}
		cout<<this->raiz->getInfo()<<endl;
		j = i-1;
		while(cola.empty() != 1){
			hijo = cola.front();
			nHijos = this->getPesoArboles(hijo);
			hijo = hijo->getHijoIzquierdo();
			j = j - nHijos;
			i = j;

			while(hijo != NULL){
				cola.push_back(hijo);
				for(j; j >  0; j--){
					cout<<" ";
				}
				if(k > 0){
					cout<<"-"<<hijo->getInfo();
				}else{
					cout<<hijo->getInfo();
				}
				hijo = hijo->getHermanoDerecho();
				k++;
			}
			j = i-1;
			if(k> 0){
				cout<<endl;
				k = 0;
			}
			cola.pop_front();
		}
	}else{
		cout<<"La raiz esta Vacia"<<endl;
	}
}
template <class elemento>
int ArbolN<elemento>::getPesoArboles(NodoArbolN<elemento> *p){
	int result = 0;
	if (p != NULL)
	{
		p = p->getHijoIzquierdo();
		while(p != NULL){
			p = p->getHermanoDerecho();
			result++;
		}
	}
	return (result);
}




/*********************************************************************************************************************************************************************/
template <class elemento>
void ArbolN<elemento>::destruirNodos(NodoArbolN<elemento>* p){
	if(p != NULL){
		if(p->getHermanoDerecho() != NULL){
			//cout<<"valor a destruir: "<<p->getHermanoDerecho()->getInfo()<<endl;
			this->destruirNodos(p->getHermanoDerecho());
		}
		if(p->getHijoIzquierdo() != NULL){
			this->destruirNodos(p->getHijoIzquierdo());
		}
		p->destruir();
		p = NULL;
	}
}

template <class elemento>
void ArbolN<elemento>::destruir(){
	this->destruirNodos(this->raiz);
	this->raiz = NULL;
}

template <class elemento>
void ArbolN<elemento>::eliminarSubArbol(int pos){
	NodoArbolN<elemento> *aux,*eliminar;
	int i = 0 ;
	if(pos == 1){
		eliminar = this->raiz->getHijoIzquierdo();
		this->raiz->setHijoIzquierdo(this->raiz->getHijoIzquierdo()->getHermanoDerecho());
	}else{
		aux = this->raiz->getHijoIzquierdo();
		for(i = 2;i < pos; i++){
			aux = aux->getHermanoDerecho();
		}
		eliminar = aux->getHermanoDerecho();
		if(aux->getHermanoDerecho() != NULL){
			aux->setHermanoDerecho(aux->getHermanoDerecho()->getHermanoDerecho());
		}
	}
	if(eliminar != NULL){
		eliminar->setHermanoDerecho(NULL);
		this->destruirNodos(eliminar);
	}
}


template <class elemento>
void ArbolN<elemento>::imprimir(NodoArbolN<elemento>* p, int nivel) {
    NodoArbolN<elemento>* hijo;
	if (p != NULL){
		for (int i = 0; i < nivel; i++) {
        	cout << "  ";
   		 }
    	cout << p->getInfo() << endl;
    	hijo = p->getHijoIzquierdo();
   		while (hijo != NULL) {
        	imprimir(hijo, nivel + 1);
        	hijo = hijo->getHermanoDerecho();
    	}
	}
}

template <class elemento>
void ArbolN<elemento>::imprimir() {
    imprimir(this->raiz, 0);
}

template <class elemento>
bool ArbolN<elemento>::estaBalanceado(NodoArbolN<elemento>* p, int &altura) {
	int alturaIzquierda = 0, alturaDerecha = 0;
	bool balanceadoIzquierda = false,balanceadoDerecha = false,result = true;
	if (p == NULL) {
        altura = 0;
        result = true;
    }else{
		balanceadoIzquierda = this->estaBalanceado(p->getHijoIzquierdo(), alturaIzquierda);
    	balanceadoDerecha = this->estaBalanceado(p->getHermanoDerecho(), alturaDerecha);
    	altura = max(alturaIzquierda, alturaDerecha) + 1;
		if (abs(alturaIzquierda - alturaDerecha) > 1) {
			result = false;
		}else{
			result = balanceadoIzquierda && balanceadoDerecha;
		}
	}
    return (result);
}

template <class elemento>
bool ArbolN<elemento>::estaBalanceado() {
    int altura = 0;
	bool result = true;
	result = this->estaBalanceado(this->raiz, altura);
    return (result);
}

template <class elemento>
list<elemento> ArbolN<elemento>::recorridoPorNiveles() {
    list<elemento> result;
	list<NodoArbolN<elemento>*> cola;
	NodoArbolN<elemento> *actual,*hijo;
    if (this->raiz != NULL){
		cola.push_back(this->raiz);
		while (!cola.empty()) {
			actual = cola.front();
			result.push_back(actual->getInfo());
			hijo = actual->getHijoIzquierdo();
			while (hijo != NULL) {
				cola.push_back(hijo);
				hijo = hijo->getHermanoDerecho();
			}
			cola.pop_front();
		}
	} 
    return result;
}

template <class elemento>
NodoArbolN<elemento>* ArbolN<elemento>::encontrarPadreNodo(NodoArbolN<elemento>* p, NodoArbolN<elemento>* hijo) {
    NodoArbolN<elemento> *padre = NULL, *actual;
	if (p != NULL){
		actual = p->getHijoIzquierdo();
		while (actual != NULL) {
			if ((actual == hijo) || (actual->getHermanoDerecho() == hijo)) {
				return (p);
			}else{
				padre = encontrarPadre(actual, hijo);
				if(padre != NULL){
					return (padre);
				}
			}
        	actual = actual->getHermanoDerecho();
    	}
	}
	return (NULL);
}

template <class elemento>
NodoArbolN<elemento>* ArbolN<elemento>::buscar(NodoArbolN<elemento>* p, elemento valor) {
    NodoArbolN<elemento> *hijo, *result;
	if (p != NULL){
		if (p->getInfo() == valor){
			return (p);
		} 
    	hijo = p->getHijoIzquierdo();
    	while (hijo != NULL) {
			result = buscar(hijo, valor);
			if (result != NULL){
				return (result);
			} 
        	hijo = hijo->getHermanoDerecho();
   		}
	} 
    return (NULL);
}

template <class elemento>
NodoArbolN<elemento>* ArbolN<elemento>::buscarNodo(elemento valor) {
    NodoArbolN<elemento> *result;
	result = buscar(this->raiz, valor);
	return(result);
}

template <class elemento>
elemento ArbolN<elemento>::encontrarPadreElemento(NodoArbolN<elemento>* p,elemento hijo) {
    NodoArbolN<elemento>  *actual;
	elemento padre;
	if (p != NULL){
		actual = p->getHijoIzquierdo();
		while (actual != NULL) {
			if(actual->getHermanoDerecho() != NULL){
				if(actual->getHermanoDerecho()->getInfo() == hijo){
					return (p->getInfo());
				}
			}
			if (actual->getInfo() == hijo) {
				return (p->getInfo());
			}else{
				padre = encontrarPadreElemento(actual, hijo);
				if(padre != -1){
					return (padre);
				}
			}
        	actual = actual->getHermanoDerecho();
    	}
	}
	return (-1);
}
template <class elemento>
elemento ArbolN<elemento>::encontrarPadreElemento(elemento valor){
    elemento padre;
	if(this->raiz != NULL){
		padre = this->encontrarPadreElemento(this->raiz,valor);
	}else{
		cout<<"Raiz esta vacia"<<endl;
	}
	return (padre);
}

template <class elemento>
int ArbolN<elemento>::altura(NodoArbolN<elemento>* p) {
   	int maxAltura = 0,cont = 0;
    NodoArbolN<elemento>* hijo;
    if (p != NULL){
		hijo = p->getHijoIzquierdo();
    	while (hijo != NULL) {
       		maxAltura = max(maxAltura, altura(hijo));
        	hijo = hijo->getHermanoDerecho();
    	}
		cont = 1;
	} 
    return (cont + maxAltura);
}

template <class elemento>
int ArbolN<elemento>::altura(){
	int result = 0;
	result = altura(this->raiz);
    return (result);
}

template <class elemento>
int ArbolN<elemento>::contarHojas(NodoArbolN<elemento>* p) {
	NodoArbolN<elemento>* hijo;
	int count = 0;
	if (p != NULL){
		if (p->getHijoIzquierdo() == NULL){
			return (1);
		} 
		 hijo = p->getHijoIzquierdo();
		while (hijo != NULL) {
			count += contarHojas(hijo);
			hijo = hijo->getHermanoDerecho();
		}
	} 
    return (count);
}

template <class elemento>
int ArbolN<elemento>::contarHojas() {
	int result = 0;
	result = this->contarHojas(this->raiz);
    return (result);
}
template <class elemento>
bool ArbolN<elemento>::esEspejo(NodoArbolN<elemento>* nodo1, NodoArbolN<elemento>* nodo2) {
    NodoArbolN<elemento> *hijo1, *hijo2,*n1,*n2;
	list<NodoArbolN<elemento>*> pila1, pila2;

	if (nodo1 == NULL && nodo2 == NULL){
		return true;
	} 
    if (nodo1 == NULL || nodo2 == NULL){
		return false;
	} 

    if (nodo1->getInfo() != nodo2->getInfo()){
		return false;
	}

    hijo1 = nodo1->getHijoIzquierdo();
    hijo2 = nodo2->getHijoIzquierdo();
    while (hijo1 != NULL || hijo2 != NULL) {
        if ((hijo1 != NULL && hijo2 == NULL) || (hijo1 == NULL && hijo2 != NULL)) {
            return (false);
		}
        if (hijo1->getInfo() != hijo2->getInfo()) {
            return (false);
        }

        pila1.push_back(hijo1);
        pila2.push_back(hijo2);
        hijo1 = hijo1->getHermanoDerecho();
        hijo2 = hijo2->getHermanoDerecho();
    }

    while (!pila1.empty() && !pila2.empty()) {
        n1 = pila1.back();
        n2 = pila2.back();
        if (!esEspejo(n1->getHijoIzquierdo(), n2->getHijoIzquierdo())) {
            return (false);
        }
		pila1.pop_back();
        pila2.pop_back();
    }

    return (pila1.empty() && pila2.empty());
}

template <class elemento>
bool ArbolN<elemento>::esEspejo() {
    bool result = false;
	if (this->raiz == NULL){
		result = true;
	}else{
		result = esEspejo(this->raiz->getHijoIzquierdo(), this->raiz->getHijoIzquierdo());
	}
    return (result);
}

template <class elemento>
bool ArbolN<elemento>::sonIsomorfos(NodoArbolN<elemento>* nodo1, NodoArbolN<elemento>* nodo2) {
    NodoArbolN<elemento> *hijo1,*hijo2;
	if ((nodo1 == NULL) && (nodo2 == NULL)){
		return (true);
	} 
    if ((nodo1 == NULL) || (nodo2 == NULL)){
		return (false);
	} 
    hijo1 = nodo1->getHijoIzquierdo();
    hijo2 = nodo2->getHijoIzquierdo();
    while ((hijo1 != NULL) && (hijo2 != NULL)) {
        if (!sonIsomorfos(hijo1, hijo2)) {
            return (false);
        }
        hijo1 = hijo1->getHermanoDerecho();
        hijo2 = hijo2->getHermanoDerecho();
    }
    return (hijo1 == NULL && hijo2 == NULL);
}

template <class elemento>
bool ArbolN<elemento>::sonIsomorfos(ArbolN<elemento>& otro) {
	bool result = false;
	result = sonIsomorfos(this->raiz, otro.getRaiz());
    return (result);
}

template <class elemento>
list<elemento> ArbolN<elemento>::encontrarCamino(elemento elemento1, elemento elemento2) {
    vector<NodoArbolN<elemento>*> ruta1, ruta2;
	list<elemento> camino;
	int i = 0;
    if ((encontrarRuta(this->raiz, elemento1, ruta1)) || (encontrarRuta(this->raiz, elemento2, ruta2))) {
        while ((i < ruta1.size()) && (i < ruta2.size()) && (ruta1[i] == ruta2[i])) {
			i++;
		}

		for (int j = 0; j < i; j++) {
			camino.push_back(ruta1[j]->getInfo());
		}

		for (int j = i; j < ruta1.size(); j++) {
			camino.push_back(ruta1[j]->getInfo());
		}

		for (int j = ruta2.size() - 1; j >= i; j--) {
			camino.push_back(ruta2[j]->getInfo());
		}
    }
    return (camino);
}

template <class elemento>
bool ArbolN<elemento>::encontrarRuta(NodoArbolN<elemento>* nodo, elemento objetivo, vector<NodoArbolN<elemento>*> &ruta) {
    NodoArbolN<elemento> *hijo;
	if (nodo != NULL){
		ruta.push_back(nodo);
		if (nodo->getInfo() == objetivo){
			return (true);
		} 
		hijo = nodo->getHijoIzquierdo();
		while (hijo != NULL) {
			if (encontrarRuta(hijo, objetivo, ruta)) {
				return (true);
			}
			hijo = hijo->getHermanoDerecho();
		}
		ruta.pop_back();
	}
    return (false);
}

template <class elemento>
NodoArbolN<elemento>* ArbolN<elemento>::ancestroComunMasReciente(NodoArbolN<elemento>* nodo, elemento elemento1, elemento elemento2) {
    vector<NodoArbolN<elemento>*> ruta1, ruta2;
	int i = 0;
    if ((!encontrarRuta(nodo, elemento1, ruta1)) || (!encontrarRuta(nodo, elemento2, ruta2))) {
        return (NULL); 
    }
    while ((i < ruta1.size()) && (i < ruta2.size()) && (ruta1[i] == ruta2[i])) {
        i++;
    }
    return (ruta1[i - 1]);
}

template <class elemento>
elemento ArbolN<elemento>::ancestroComunMasReciente(elemento elemento1, elemento elemento2) {
    elemento result;
	NodoArbolN<elemento> *ancestro;
	ancestro = ancestroComunMasReciente(this->raiz, elemento1, elemento2);
	if(ancestro != NULL){
		result = ancestro->getInfo();
	}
	return (result);
}

template <class elemento>
void ArbolN<elemento>::diametro(NodoArbolN<elemento>* p, int& diametro,int &altura, vector<elemento>& camino) {
    int alturaMax2 = 0, alturaHijo;
	altura = 0;
	vector<elemento> caminoMax1, caminoMax2;
	NodoArbolN<elemento>* hijo;
	if (p != NULL){
		hijo = p->getHijoIzquierdo();
		while (hijo != NULL) {
			vector<elemento> caminoHijo;
			this->diametro(hijo, diametro,alturaHijo,caminoHijo);
			if (alturaHijo > altura) {
				alturaMax2 = altura;
				caminoMax2 = caminoMax1;
				altura = alturaHijo;
				caminoMax1 = caminoHijo;
			} else if (alturaHijo > alturaMax2) {
				alturaMax2 = alturaHijo;
				caminoMax2 = caminoHijo;
			}
			hijo = hijo->getHermanoDerecho();
		}

		if (altura + alturaMax2 > diametro) {
			diametro = altura + alturaMax2;
			camino = caminoMax1;
			camino.push_back(p->getInfo());
			camino.insert(camino.end(), caminoMax2.rbegin(), caminoMax2.rend());
		}

		caminoMax1.push_back(p->getInfo());
		altura++;
	}
}

template <class elemento>
vector<elemento> ArbolN<elemento>::diametro() {
    int diametro = 0,altura = 0;
    vector<elemento> camino;
    this->diametro(this->raiz, diametro, altura, camino);
    return (camino);
}
