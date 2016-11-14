#ifndef Fila_H
#define Fila_H

#include "Lista.h"
#include "ListaSE.h"

template <class T>
class Fila:public ListaSE{
	protected:
		Elemento<T> *Fim;
		int Qntd;
	public:
		Fila();
		void Enfileirar(T *info);
		void Desenfileirar();
		int getQntd();
		T* getFirst();
}

template <class T>
Fila<T>::Fila(){
	Lista<T>::Inicio = NULL;
	Qntd = 0;
	Fim = NULL;
}

template <class T>
void Fila<T>::Enfileirar(T *info){
	ListaSE::inserirFim(info);
	if(Fim == NULL)
		Fim = Lista<T>::Inicio;
		else
		Fim = Fim->prox;
	Qntd++;
}

template <class T>
void Fila<T>::Desenfileirar(){
	ListaSE<T>::excluirInicio();
	Qntd--;
}

template <class T>
int Fila<T>::getQntd(){
	return Qntd;
}

template<class T>
T* Fila<T>::getFirst(){
	return (Lista<T>::Inicio)->getInfo();
}


















#endif

