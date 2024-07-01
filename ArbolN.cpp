#include "ArbolN.h"
#include <list>
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
	elemento ArbolN<elemento>::getRaiz(){
		return (this->raiz->getInfo());		
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
}

template <class elemento>
void ArbolN<elemento>::eliminarSubArbol(int pos){
	NodoArbolN<elemento> *aux,*eliminar;
	int i = 0 ;
	if(pos = 1){
		eliminar = this->raiz->getHijoIzquierdo();
		this->raiz->setHijoIzquierdo(this->raiz->getHijoIzquierdo()->getHermanoDerecho());
	}else{
		aux = this->raiz->getHijoIzquierdo();
		for(i = 2;i < pos; i++){
			aux = aux->getHermanoDerecho();
		}
		eliminar = aux->getHermanoDerecho();
		aux->setHermanoDerecho(aux->getHermanoDerecho()->getHermanoDerecho());
	}
	eliminar->setHermanoDerecho(NULL);
	this->destruirNodos(eliminar);
}


