#ifndef Elemento_H
#define Elemento_H

#include <string.h>
#include <iostream>
#include<ctime>
using std::cin;
using std::cout;
using std::endl;
using std::ios;    //manipula o cout, para que a saida deja no formato monetario

//biblioteca para manipular cout
#include <iomanip>
using std::setprecision; //funcao para determinar numero de casas decimais
using std::setiosflags;  //manipula cout para que a saida seja no formato monetario

template <class T>
class Elemento{
		private:
			T *info;
		public:
			Elemento<T> *prox;
			Elemento<T> *ant;
					
			Elemento(T *info);
			void setInfo(T *info);
			T* getInfo();
};

template <class T>
Elemento<T>::Elemento(T *info){
	setInfo(info);
	prox = NULL;
}

template <class T>
void Elemento<T>::setInfo(T *info) {
	this->info = info;
}

template <class T>
T* Elemento<T> ::getInfo() {
	return info;
}

#endif
