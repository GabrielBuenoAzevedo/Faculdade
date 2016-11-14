#ifndef ListaDE_H
#define ListaDE_H

#include "Lista.h"


/*

Implementação feita por Gabriel Bueno de Azevedo
RA: 151040362
Bacharelado em Ciência da Computação - Turma 2015 - Unesp Ibilce

*/

template <class T>
class ListaDE : public Lista<T> {
	public:
		//Construtor
		ListaDE();
		
		//Destrutor virtual vazio
		virtual ~ListaDE() { };
		
		//Métodos de Inserção
		virtual void inserirInicio(T *info);
		virtual void inserirFim(T *info);
		virtual void inserirOrdem(T *info);
		void inserirMeio(T *info, Elemento<T> *Anterior, Elemento<T> *Posterior);
		
		//Método de Pesquisa
		virtual Elemento<T>* pesquisar(T *info);
		
		//Métodos de Exclusão
		virtual void excluirFim();
		virtual void excluirInicio();
		virtual void excluirElemento(T *info);
		void excluirMeio(Elemento<T> *Anterior, Elemento<T> *Posterior);
		
		//Método para devolver o primeiro elemento da lista
		virtual T* getFirst();


};

template <class T>
ListaDE<T>::ListaDE(){
	Lista<T>::Inicio = NULL;
}

template <class T>
void ListaDE<T>::inserirMeio(T *info, Elemento<T> *Anterior, Elemento<T> *Posterior){
	Elemento<T> *novo = new Elemento<T>(info);
	if(Lista<T>::Inicio == NULL)
		Lista<T>::Inicio = novo;
	else{
		novo->ant = Anterior;
		novo->prox = Posterior;
		if(Posterior != NULL)
			Posterior->ant = novo;
		if(Anterior != NULL)
			Anterior->prox = novo;
		else
			Lista<T>::Inicio = novo;
	}
}

template <class T>
void ListaDE<T>::inserirFim(T *info){
	Elemento<T> *aux;
	while(aux->prox != NULL)
		aux = aux->prox;
	inserirMeio(info, aux, NULL);
}

template <class T>
void ListaDE<T>::inserirInicio(T *info){
	inserirMeio(info, NULL, Lista<T>::Inicio);
}

template <class T>
void ListaDE<T>::inserirOrdem(T *info){
	Elemento<T> *aux;
	aux = Lista<T>::Inicio;
	if(aux == NULL)
		inserirInicio(info);
	else{
		while(aux->prox != NULL && (aux->prox)->getInfo() < info)
			aux = aux->prox;
		inserirMeio(info,aux,aux->prox);
	}
}

template <class T>
Elemento<T>* ListaDE<T>::pesquisar(T *info){
	Elemento<T> *aux;
	aux = Lista<T>::Inicio;
	while(aux != NULL && aux->getInfo() != info)
		aux = aux->prox;
	return aux;
}

template <class T>
void ListaDE<T>::excluirMeio(Elemento<T> *Anterior, Elemento<T> *Posterior){
	Elemento<T> *aux;
	
	if(Anterior!=NULL){
		aux = Anterior->prox;
		Anterior->prox = Posterior;
		//if(Posterior!=NULL)
			//Posterior->ant = Anterior;
	} else {
		aux = Lista<T>::Inicio;
		Lista<T>::Inicio = Posterior;
	}
	delete(aux);
	//return Inicio;
}

template <class T>
void ListaDE<T>::excluirFim(){
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
		cout<<"\nA lista esta vazia, não é possível excluir nenhum elemento!"<<endl;
	}
}

template <class T>
void ListaDE<T>::excluirInicio(){
	if( Lista<T>::Inicio!=NULL)
		excluirMeio(NULL, Lista<T>::Inicio->prox);
	else
		cout<<"\nA lista esta vazia, não é possível excluir nenhum elemento!"<<endl;
}

template <class T>
void ListaDE<T>::excluirElemento(T *info){
	Elemento<T> *exc, *aux=NULL;
	
	exc = pesquisar(info);
	if(exc!=NULL){
		if(exc != Lista<T>::Inicio){
			aux = exc->ant;
		}
		excluirMeio(aux, exc->prox);
	} else {
		cout<<"\nO elemento não foi encontrado!"<<endl;
	}
}

template <class T>
T* ListaDE<T>::getFirst(){
	return Lista<T>::Inicio->getInfo();
}

#endif
