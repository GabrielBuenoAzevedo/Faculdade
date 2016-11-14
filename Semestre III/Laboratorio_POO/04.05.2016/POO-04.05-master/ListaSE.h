#ifndef ListaSE_H
#define ListaSE_H

#include "Lista.h"

template <class T>
class ListaSE : public Lista<T> {
	public:
		//Construtor
		ListaSE();

		//Destrutor virtual vazio
		virtual ~ListaSE() { };

		//M�todos de Inser��o
		virtual void inserirInicio(T *info);
		virtual void inserirFim(T *info);
		virtual void inserirOrdem(T *info);
		void inserirMeio(T *info, Elemento<T> *Anterior, Elemento<T> *Posterior);

		//M�todo de Pesquisa
		virtual Elemento<T>* pesquisar(T *info);

		//M�todos de Exclus�o
		virtual void excluirFim();
		virtual void excluirInicio();
		virtual void excluirElemento(T *info);
		void excluirMeio(Elemento<T> *Anterior, Elemento<T> *Posterior);

		//M�todo para devolver o primeiro elemento da lista
		virtual T* getFirst();

		T* displayLista();
};

//Construtor
template <class T>
ListaSE<T>::ListaSE(){
	Lista<T>::Inicio = NULL;
}

//M�todo base da inser��o
template <class T>
void ListaSE<T>::inserirMeio(T *info, Elemento<T> *Anterior, Elemento<T> *Posterior){
	Elemento<T> *novo = new Elemento<T>(info);

	if(Anterior == NULL){
		novo->prox = Posterior;
		Lista<T>::Inicio = novo;
	} else {
		Anterior->prox = novo;
		novo->prox = Posterior;
	}

	//return Inicio;
}

//M�todo de inser��o no in�cio
template <class T>
void ListaSE<T>::inserirInicio(T *info){
	inserirMeio(info, NULL, Lista<T>::Inicio);
}

template <class T>
void ListaSE<T>::inserirFim(T *info){
	Elemento<T> *aux;

	aux = Lista<T>::Inicio;
	if(aux!=NULL) {
		while(aux->prox!=NULL)
			aux = aux->prox;
	}

	inserirMeio(info, aux, NULL);
}

//M�todo para inserir elementos em uma lista ordenada
template <class T>
void ListaSE<T>::inserirOrdem(T *info){
	Elemento<T> *aux1=NULL, *aux2=NULL;

	aux1 = Lista<T>::Inicio;
	if(aux1!=NULL){
		while(aux1!=NULL && aux1->getInfo() < info)
			aux1=aux1->prox;

		if(aux1!=Lista<T>::Inicio){
			aux2 = Lista<T>::Inicio;
			while(aux2->prox != aux1)
				aux2 = aux2->prox;
		}
	}
	inserirMeio(info, aux2, aux1);
}

//M�todo para pesquisar um elemento
template <class T>
Elemento<T>* ListaSE<T>::pesquisar(T *info){
	Elemento<T> *aux;

	aux=Lista<T>::Inicio;
	while(aux!=NULL && aux->getInfo() != info)
		aux = aux->prox;
	return aux;
}

//M�todo base da exclus�o
template <class T>
void ListaSE<T>::excluirMeio(Elemento<T> *Anterior, Elemento<T> *Posterior){
	Elemento<T> *aux;

	if(Anterior!=NULL){
		aux = Anterior->prox;
		Anterior->prox = Posterior;
	} else {
		aux = Lista<T>::Inicio;
		Lista<T>::Inicio = Posterior;
	}
	delete(aux);
	//return Inicio;
}

//M�todo para exclus�o de um elemento do inicio da lista
template <class T>
void ListaSE<T>::excluirInicio(){
	if( Lista<T>::Inicio!=NULL)
		excluirMeio(NULL, Lista<T>::Inicio->prox);
	else
		cout<<"\nA lista esta vazia, não é possível excluir nenhum elemento!"<<endl;
}

//M�todo para excluir elemento do fim da lista
template <class T>
void ListaSE<T>::excluirFim(){
	Elemento<T> *aux;

	if(Lista<T>::Inicio!=NULL){
		if(Lista<T>::Inicio->prox == NULL){
			excluirMeio(NULL,NULL);
		} else {
			aux = Lista<T>::Inicio;
			while((aux->prox)->prox !=NULL)
				aux = aux->prox;
			excluirMeio(aux, NULL);
		}
	} else {
		cout<<"\nA lista esta vazia, n�o � poss�vel excluir nenhum elemento!"<<endl;
	}
}

//M�todo para remover um elemento espec�fico
template <class T>
void ListaSE<T>::excluirElemento(T *info){
	Elemento<T> *exc, *aux=NULL;

	exc = pesquisar(info);
	if(exc!=NULL){
		if(exc != Lista<T>::Inicio){
			aux = Lista<T>::Inicio;
			while(aux->prox != exc)
				aux = aux->prox;
		}
		excluirMeio(aux, exc->prox);
	} else {
		cout<<"\nO elemento n�o foi encontrado!"<<endl;
	}
}

///M�todo para retornar o primeiro elemento da lista
template <class T>
T* ListaSE<T>::getFirst(){
	return Lista<T>::Inicio->getInfo();
}


template <class T>
T* ListaSE<T>::displayLista(){

	Lista<T>::Inicio = Lista<T>::Inicio->prox;
	Elemento<T> *aux=Lista<T>::Inicio;
	while(aux!=NULL)
		cout<<aux->getInfo()<<endl;
}


#endif
