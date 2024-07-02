#include "ArbolBin.h"
#include <list>
#include <vector>
#include <queue>
template <class elemento>
ArbolBin<elemento>::ArbolBin(){
    this->Raiz = NULL;
    this->peso = 0;
}

template <class elemento>
ArbolBin<elemento>::ArbolBin(elemento e, ArbolBin<elemento> a1, ArbolBin<elemento> a2){
    ArbolBin<elemento> arbolAux;

    this->raiz = new(NodoArbolBin<elemento>);
    this->getRaiz()->setInfo(e);
    this->getRaiz()->setHijoIzq(copiarNodos(a1.getRaiz()));
    this->getRaiz()->setHijoDer(copiarNodos(a2.getRaiz()));
}

template <class elemento>
NodoArbolBin<elemento>* ArbolBin<elemento>::copiarNodos(NodoArbolBin<elemento> *p){
    NodoArbolBin<elemento> *nuevo;

    if (p == NULL){
        return (NULL);
    }else{
        nuevo = new(NodoArbolBin<elemento>);
        nuevo->setHijoDerecho(p->getHijoDerecho());
        nuevo->setHijoIzquierdo(p->getHijoIzquierdo());
        nuevo->setInfo(p->getInfo());
        return(nuevo);
    }
}

template <class elemento>
NodoArbolBin<elemento> * ArbolBin<elemento>::getRaiz(){
    return (this->raiz);
}

template <class elemento>
ArbolBin<elemento> ArbolBin<elemento>::getHijoIzquierdo(){
    ArbolBin<elemento> hijo;
    if (this->raiz != NULL){
        hijo.raiz = copiarNodos(this->getRaiz()->getHijoIzquierdo());
    }else{
        hijo.raiz = NULL;
    }
    return (hijo);
}

template <class elemento>
ArbolBin<elemento> ArbolBin<elemento>::getHijoDerecho(){
    ArbolBin<elemento> hijo;
    if (this->raiz != NULL){
        hijo.raiz = copiarNodos(this->getRaiz()->getHijoDerecho());
    }else{
        hijo.raiz = NULL;
    }
    return (hijo);
}

template <class elemento>
elemento ArbolBin<elemento>::infoRaiz(){
    return (this->getRaiz()->getInfo());
}




template <class elemento>
void ArbolBin<elemento>::setPeso(int peso){
    this->peso = peso;
}

template <class elemento>
void ArbolBin<elemento>::setRaiz(NodoArbolBin<elemento>* p){
    this->raiz = p;
}



template <class elemento>
void ArbolBin<elemento>::insertarNodo(elemento padre, elemento hijo, NodoArbolBin<elemento> *raiz){
    NodoArbolBin<elemento> *nuevo, *aux;

    if(raiz != NULL){
        nuevo = new(NodoArbolBin<elemento>);
        nuevo->setInfo(hijo);
        nuevo->setHijoIzq(NULL);
        nuevo->setHijoDer(NULL);

        if(raiz->getInfo() == padre){
                if (raiz->getHijoIzquierdo() == NULL){
                    raiz->setHijoIzq(nuevo);
                    return;
                }
                if (raiz->getHijoDerecho() == NULL){
                    raiz->setHijoDer(nuevo);
                    return;
                }
        }else{
            insertarNodo(padre,hijo,raiz->getHijoIzquierdo());
            insertarNodo(padre,hijo,raiz->getHijoDerecho());
        }
    }
}

template <class elemento>
void ArbolBin<elemento>::insertarSubarbol(ArbolBin<elemento> subarbol){
    if (this->getRaiz()->getHijoIzquierdo() == NULL){
        this->getRaiz()->setHijoIzq(copiarNodos(subarbol.getRaiz()));
    }else{
        if (this->getRaiz()->getHijoDerecho() == NULL){
            this->getRaiz()->setHijoDer(copiarNodos(subarbol.getRaiz()));
        }
    }
}

template <class elemento>
void ArbolBin<elemento>::eliminarSubarbol(int pos) {
    NodoArbolBin<elemento> *aux;
    int i;

    if (pos==1){
        aux = this->getRaiz()->getHijoIzquierdo();
        this->getRaiz()->setHijoIzq(this->getRaiz()->getHijoDerecho());
        this->getRaiz()->setHijoDer(NULL);
    }
    else{
        aux = this->getRaiz()->getHijoDerecho();
        this->getRaiz()->setHijoDer(NULL);
    }

}


/*
template <class elemento>
NodoArbolBin<elemento>* ArbolBin<elemento>::leerArbolPreorden(list<elemento> preorden, list<elemento> inorden){
    NodoArbolBin<elemento> *r;
    list<elemento> preIzq, preDer, inIzq, inDer;

    if(!preorden.empty()){
        r = new (NodoArbolBin<elemento>);
        r->setInfo(preorden.front());
        preorden.pop_front();

        while(inorden.front() != r->getInfo()){
            inIzq.push_back(inorden.front());
            preIzq.push_back(preorden.front());
            inorden.pop_front();
            preorden.pop_front();
        }
        inorden.pop_front();

        while(!inorden.empty()){
            preDer.push_back(preorden.front());
            inDer.push_back(inorden.front());
            preorden.pop_front();
            inorden.pop_front();
        }
        r->setHijoIzq(leerArbol(preIzq, inIzq));
        r->setHijoDer(leerArbol(preDer, inDer));

        return (r);

    }else{
        return (NULL);
    }

}


template <class elemento>
NodoArbolBin<elemento> * ArbolBin<elemento>::leerArbolPostOrden(list<elemento> postorden, list<elemento> inorden){
    NodoArbolBin<elemento> *r;
    list<elemento> postIzq, postDer, inIzq, inDer;

    if(!inorden.empty()){
        r = new (NodoArbolBin<elemento>);
        r->setInfo(postorden.back());
        postorden.pop_back();
        while(inorden.front() != r->getInfo()){
            inIzq.push_back(inorden.front());
            postIzq.push_back(postorden.front());
            inorden.pop_front();
            postorden.pop_front();
        }
        inorden.pop_front(); 

        while(!inorden.empty()){
            postDer.push_back(postorden.front());
            inDer.push_back(inorden.front());
            postorden.pop_front();
            inorden.pop_front();
        }

        r->setHijoIzq(leerArbolPostOrden(postIzq, inIzq));
        r->setHijoDer(leerArbolPostOrden(postDer, inDer));

        return (r);

    }else{
        return (NULL);
    }

}
*/


template <class elemento>
bool ArbolBin<elemento>::esNulo(){
    return (this->raiz == NULL);
}


template <class elemento>
void ArbolBin<elemento>::ancestroMasCercano(NodoArbolBin<elemento> *r, elemento e1, elemento e2, bool &encontrado1, bool &encontrado2, bool &LCAEncontrado, elemento &ancestro){
    bool encontradoe1hi, encontradoe2hi, encontradoe1hd, encontradoe2hd;
    
    
    if (!LCAEncontrado){
        if (r!=NULL){
            if ((r->getHijoIzquierdo() == NULL) && (r->getHijoDerecho() == NULL)){
                encontrado1 = r->getInfo() == e1;
                encontrado2 = r->getInfo() == e2;
            }else{
                encontradoe1hi=false;
                encontradoe1hd=false;
                encontradoe2hd=false;
                encontradoe2hi=false;

                this->LCA(r->getHijoIzquierdo(), e1, e2, encontradoe1hi, encontradoe2hi, LCAEncontrado, ancestro);
                this->LCA(r->getHijoDerecho(), e1, e2, encontradoe1hd, encontradoe2hd, LCAEncontrado, ancestro);

                if(!LCAEncontrado){
                    encontrado1 = encontradoe1hi || encontradoe1hd || (r->getInfo() == e1);
                    encontrado2 = encontradoe2hi || encontradoe2hd || (r->getInfo() == e2);

                    LCAEncontrado = encontrado1 && encontrado2;

                    if (LCAEncontrado) {
                        ancestro = r->getInfo();
                    }
                }
            }
        }
    }
}

template <class elemento>
elemento ArbolBin<elemento>::ancestroMasCercano(elemento e1, elemento e2){
    bool encontrado1, encontrado2, LCAEncontrado;
    elemento Ancestro;

    encontrado1 = false;
    encontrado2 = false;
    LCAEncontrado =false;
    this->LCA(this->getRaiz(), e1, e2, encontrado1, encontrado2, LCAEncontrado, Ancestro);
    return (Ancestro);
}

template <class elemento>
list<elemento> ArbolBin<elemento>::getPrimos(elemento info, list<NodoArbolBin<elemento>*> lista){
    list<NodoArbolBin<elemento>*> sigNivel;
    bool padre = false, fin =false;;
    list<elemento> primos;

    while (!lista.empty()) {
        padre=false;
        if (lista.front()->getHijoIzquierdo() != NULL){
           
            padre = (lista.front()->getHijoIzquierdo()->getInfo() == info);
            if (lista.front()->getHijoDerecho() != NULL){
                padre = padre || (lista.front()->getHijoDerecho()->getInfo() == info);
            }
            if(!padre){
                sigNivel.push_back(lista.front()->getHijoIzquierdo());
            }else{
                fin=true;
            }
        }
        if (lista.front()->getHijoDerecho() != NULL){
            padre = (lista.front()->getHijoDerecho()->getInfo() == info);
            if (lista.front()->getHijoIzquierdo() != NULL){
                padre = padre || (lista.front()->getHijoIzquierdo()->getInfo() == info);
            }
            if(!padre){
                sigNivel.push_back(lista.front()->getHijoDerecho());
            }else{
                fin=true;
            }
        }
        lista.pop_front();
    }
    if (fin){
        while(!sigNivel.empty()){
            primos.push_back(sigNivel.front()->getInfo());
            sigNivel.pop_front();
        }
        return (primos);

    }else{
        if(!sigNivel.empty()){
            primos = getPrimos(info, sigNivel);
        }
    }
    return (primos);
}


/*
template<class Elemento>
void ArbolBin<Elemento>::find(NodoArbolBin<Elemento> *actual ,Elemento padre,NodoArbolBin<Elemento> *papa2,NodoArbolBin<Elemento> *abuelo, NodoArbolBin<Elemento> **salida, NodoArbolBin<Elemento> **dad, NodoArbolBin<Elemento> **granddad){
    if(actual == nullptr){
        return;
    }
    if(actual->getInfo() == padre){
        *granddad = abuelo;
        *dad = papa2;
        *salida = actual;
        return;
    }
    this->find(actual->getHijoIzq(),padre,actual,papa2,salida,dad,granddad);
    this->find(actual->getHijoDer(),padre,actual,papa2,salida,dad,granddad);
}
*/
template<class elemento>
void ArbolBin<elemento>::anadir(NodoArbolBin<elemento> *actual, elemento nuevo){

    NodoArbolBin<elemento> *aux = new NodoArbolBin<elemento>;
    aux->setInfo(nuevo);
    if(actual->getHijoIzquierdo() != nullptr && actual->getHijoDerecho() != nullptr){
        cout << "\n Ya tiene dos hijos \n";
        return;
    }
    ++(this->peso);
    if(actual->getHijoIzquierdo() == nullptr){
        actual->setHijoIzquierdo(aux);
        return;
    }
    actual->setHijoDerecho(aux);
}

template<class elemento>
void ArbolBin<elemento>::destruirNodos(NodoArbolBin<elemento> **ptrNodo){
    delete *ptrNodo;
}

template<class elemento>
list<elemento> ArbolBin<elemento>::preorden(){
    list<elemento> result;
    this->preorden(this->Raiz, result);
    typename list<elemento>::iterator it;
    for(it = result.begin(); it != result.end();++it){
        cout << *it << " "; 
    }
    return result;
}

template<class elemento>
list<elemento> ArbolBin<elemento>::inorden(){
    list<elemento> result;
    this->inorden(this->Raiz, result);

    typename list<elemento>::iterator it;
    for(it = result.begin(); it != result.end();++it){
        cout << *it << " "; 
    }
    return result;
}

template<class elemento>
list<elemento> ArbolBin<elemento>::postorden(){
    list<elemento> result;
    this->postorden(this->Raiz, result);

    typename list<elemento>::iterator it;
    for(it = result.begin(); it != result.end();++it){
        cout << *it << " "; 
    }
    return result;
}

template<class elemento>
list<elemento> ArbolBin<elemento>::niveles(){
    list<elemento> result;
    queue<NodoArbolBin<elemento>*> aux;
    aux.push(this->Raiz);
    this->niveles(aux,result);
    typename list<elemento>::iterator it;
    for(it = result.begin(); it != result.end();++it){
        cout << *it << " "; 
    }
    return result;
}

template<class elemento>
void ArbolBin<elemento>::preorden(NodoArbolBin<elemento> *actual, list<elemento> &result){
    if(actual == nullptr){
        return;
    }
    result.push_back(actual->getInfo());
    preorden(actual->getHijoIzquierdo(),result);
    preorden(actual->getHijoDerecho(),result);
}

template<class elemento>
void ArbolBin<elemento>::inorden(NodoArbolBin<elemento> *actual, list<elemento> &result){
    if(actual == nullptr){
        return;
    }
    inorden(actual->getHijoIzquierdo(),result);
    result.push_back(actual->getInfo());
    inorden(actual->getHijoDerecho(),result);
}

template<class elemento>
void ArbolBin<elemento>::postorden(NodoArbolBin<elemento> *actual, list<elemento> &result){
    if(actual == nullptr){
        return;
    }
    postorden(actual->getHijoIzquierdo(),result);
    postorden(actual->getHijoDerecho(),result);
    result.push_back(actual->getInfo());
}

template <typename elemento>
void ArbolBin<elemento>::niveles(queue<NodoArbolBin<elemento>*> actual,list<elemento> &result){
    queue<NodoArbolBin<elemento>*> sigNivel;
    while (!actual.empty()) {
        if (actual.front()->getHijoIzquierdo() != nullptr){
            sigNivel.push(actual.front()->getHijoIzquierdo());
        }
        if (actual.front()->getHijoDerecho() != nullptr){
            sigNivel.push(actual.front()->getHijoDerecho());
        }
        result.push_back(actual.front()->getInfo());
        actual.pop();
    }
    if(!sigNivel.empty()){
        this->niveles(sigNivel,result);
    }
}

template<class elemento>
void ArbolBin<elemento>::camino(NodoArbolBin<elemento> *actual, elemento origen, elemento destino, bool *encontrado1, bool *encontrado2, bool &LCAEncontrado, list<elemento> &salida, list<elemento> &aux){
    bool e1HI, e2HI, e1HD, e2HD;
    if(actual == nullptr || LCAEncontrado){
        return;
    }
    e1HI = e2HI = e1HD = e2HD = false;

    this->camino(actual->getHijoIzquierdo(),origen,destino, &e1HI, &e2HI,LCAEncontrado,salida,aux);
    this->camino(actual->getHijoDerecho(),origen,destino, &e1HD, &e2HD,LCAEncontrado,salida,aux);

    if(!LCAEncontrado){
        *encontrado1 = e1HI || e1HD || actual->getInfo() == origen;
        *encontrado2 = e2HI || e2HD || actual->getInfo() == destino;
        if(*encontrado1 && !*encontrado2){
            salida.push_back(actual->getInfo());
        }
        if(*encontrado2 && !*encontrado1){
            aux.push_front(actual->getInfo());
        }
        LCAEncontrado = *encontrado1 && *encontrado2;

        if(LCAEncontrado){
            salida.push_back(actual->getInfo());
            salida.splice(salida.end(),aux);
            for (auto v: salida)
            {
                cout << v << endl;
            }
            
        }
    }
}

template<class elemento>
list<elemento> ArbolBin<elemento>::camino(elemento origen, elemento destino){
    bool e1,e2, LCAEncontrado;
    list<elemento> camino,aux;

    e1 = e2 = LCAEncontrado = false;
    this->camino(this->Raiz,origen,destino,&e1,&e2,LCAEncontrado,camino,aux);
    typename list<elemento>::iterator it;
    for(it = aux.begin(); it != aux.end();++it){
        cout << *it << " "; 
    }
    return aux;
}

template <typename elemento>
NodoArbolBin<elemento> * ArbolBin<elemento>::leerArbolPreorden(list<elemento> preorden, list<elemento> inorden){
    
    NodoArbolBin<elemento> *r;
    list<elemento> preIzq, preDer, inIzq, inDer;

    if(!preorden.empty()){
        r = new (NodoArbolBin<elemento>);
        r->setInfo(preorden.front());
        preorden.pop_front();
        while(inorden.front() != r->getInfo()){
            inIzq.push_back(inorden.front());
            preIzq.push_back(preorden.front());

            inorden.pop_front();
            preorden.pop_front();
        }
        inorden.pop_front();

        while(!inorden.empty()){
            preDer.push_back(preorden.front());
            inDer.push_back(inorden.front());

            preorden.pop_front();
            inorden.pop_front();
        }

        r->setHijoIzquierdo(leerArbolPreorden(preIzq, inIzq));
        r->setHijoDerecho(leerArbolPreorden(preDer, inDer));
        return r;

    }else{
        return nullptr;
    }

}

template <typename elemento>
NodoArbolBin<elemento> * ArbolBin<elemento>::leerArbolPostorden(list<elemento> postorden, list<elemento> inorden){
    
    NodoArbolBin<elemento> *r;
    list<elemento> postIzq, postDer, inIzq, inDer;

    if(!postorden.empty()){
        r = new (NodoArbolBin<elemento>);
        r->setInfo(postorden.back());
        postorden.pop_back();

        while(inorden.front() != r->getInfo()){
            inIzq.push_back(inorden.front());
            postIzq.push_back(postorden.front());

            inorden.pop_front();
            postorden.pop_front();
        }
        inorden.pop_front();

        while(!inorden.empty()){
            postDer.push_back(postorden.front());
            inDer.push_back(inorden.front());

            postorden.pop_front();
            inorden.pop_front();
        }

        r->setHijoIzquierdo(leerPosIn(postIzq, inIzq));
        r->setHijoDerecho(leerPosIn(postDer, inDer));

        return (r);

    }else{
        return (nullptr);
    }

}

template <typename elemento>
void ArbolBin<elemento>::leerArbolPre(list<elemento> preorden, list<elemento> inorden){
    this->Raiz = this->leerArbolPreorden(preorden,inorden);
}

template <typename elemento>
void ArbolBin<elemento>::leerArbolPost(list<elemento> postorden, list<elemento> inorden){
    this->Raiz = this->leerArbolPostorden(postorden,inorden);
}

