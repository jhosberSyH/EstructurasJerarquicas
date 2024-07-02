#include<iostream>
#include "ArbolN.h"
#include "ArbolN.cpp"
#include "ArbolBin.h"
#include "ArbolBin.cpp"
using namespace std;
int main(){
	ArbolBin<int> arbolito;
	ArbolN<int> aaaaa;
	list<int> pre,in,preorden;
	int padre,c; 
	pre.push_back(10);
	pre.push_back(5);
	pre.push_back(4);
	pre.push_back(3);
	pre.push_back(1);
	pre.push_back(0);
	in.push_back(5);
	in.push_back(4);
	in.push_back(3);
	in.push_back(10);
	in.push_back(0);
	in.push_back(1);
	cout<<"Paso 1 Insertar elementos"<<endl;
	arbolito.leerArbolPre(pre,in);
	preorden = arbolito.niveles();
	
	return 0;
}