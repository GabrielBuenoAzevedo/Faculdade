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
		
		//M�todos de Inser��o
		virtual void inserirInicio(T *info)=0;
		virtual void inserirFim(T *info) = 0;
		virtual void inserirOrdem(T *info) = 0;
		
		//M�todo de Pesquisa
		virtual Elemento<T>* pesquisar(T *info) = 0;
		
		//M�todos de Exclus�o
		virtual void excluirFim()=0;
		virtual void excluirInicio() = 0;
		virtual void excluirElemento(T *info) = 0;
		
		//M�todo para devolver o primeiro elemento da lista
		virtual T* getFirst() =0;

		virtual T* displayLista() = 0;
};

#endif
