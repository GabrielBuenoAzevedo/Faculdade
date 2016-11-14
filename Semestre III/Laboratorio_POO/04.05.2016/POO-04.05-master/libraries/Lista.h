#ifndef Lista_H
#define Lista_H

#include "Elemento.h"

template <class T>
class Lista {
	protected:
		Elemento<T> *Inicio;
	public:	
		//Destrutor virtual vazio
		virtual ~Lista() { };
		
		//Métodos de Inserção
		virtual void inserirInicio(T *info)=0;
		virtual void inserirFim(T *info) = 0;
		virtual void inserirOrdem(T *info) = 0;
		
		//Método de Pesquisa
		virtual Elemento<T>* pesquisar(T *info) = 0;
		
		//Métodos de Exclusão
		virtual void excluirFim()=0;
		virtual void excluirInicio() = 0;
		virtual void excluirElemento(T *info) = 0;
		
		//Método para devolver o primeiro elemento da lista
		virtual T* getFirst() =0;

		virtual T* displayLista() = 0;
};

#endif
