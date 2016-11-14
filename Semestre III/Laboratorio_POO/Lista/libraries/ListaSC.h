#ifndef ListaSC_H
#define ListaSC_H

#include "Lista.h"

/*

Implementação feita por Gabriel Bueno de Azevedo
RA: 151040362
Bacharelado em Ciência da Computação - Turma 2015 - Unesp Ibilce

*/




template<class T>
class ListaSC: public Lista<T> {
	public:
		//Construtor
		ListaSC();
		
		//Destrutor Virtual
		virtual ~ListaSC() { };

		//Métodos de inserção		
		virtual void inserirInicio(T *info);
		virtual void inserirFim(T *info);
		virtual void inserirOrdem(T *info);
		void InserirMeio(T *info, Elemento<T> *anterior, Elemento<T> *posterior);

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

//Construtor
template <class T>
ListaSC<T>::ListaSC(){
	Lista<T>::Inicio = NULL;
}

//Método base para a inserção
template <class T>
void ListaSC<T>::InserirMeio(T *info, Elemento<T> *Ant, Elemento<T> *Post){
	Elemento<T> *Novo = new Elemento<T>(info);
	Elemento<T> *aux;

	if(Ant == NULL){
	Lista<T>::Inicio = Novo;
	Novo->prox = Novo;
	}else{
		Ant->prox = Novo;
		Novo->prox = Post;
	}
}

//Método de inserção no início
template <class T>
void ListaSC<T>::inserirInicio(T *info){
	Elemento<T> *aux;
	aux = Lista<T>::Inicio;
	
	if(Lista<T>::Inicio == NULL)
		InserirMeio(info, NULL, Lista<T>::Inicio);
	else{
		while(aux->prox != Lista<T>::Inicio)
			aux=aux->prox;
		InserirMeio(info,aux,Lista<T>::Inicio);	
	}
}

template <class T>
void ListaSC<T>::inserirFim(T *info){
	inserirInicio(info);
}

//Método para inserir elementos em uma lista ordenada
template <class T>
void ListaSC<T>::inserirOrdem(T *info){
	Elemento<T> *aux1=NULL, *aux2=NULL;
	
	if(Lista<T>::Inicio!=NULL){
		aux1 = Lista<T>::Inicio;	
		while(aux1->getInfo() < info && aux1 != Lista<T>::Inicio){
			aux2= aux1;			
			aux1=aux1->prox;
			}
		InserirMeio(info, aux2, aux1);
	}else
	inserirInicio(info);
}

//Método para pesquisar um elemento
template <class T>
Elemento<T>* ListaSC<T>::pesquisar(T *info){
	Elemento<T> *aux;
	
	aux=Lista<T>::Inicio;
	if(aux->getInfo() == info)
		return aux;
	else{
		aux = aux->prox;
		while(aux!=Lista<T>::Inicio && aux->getInfo() != info)
			aux = aux->prox;
	}
	if(aux == Lista<T>::Inicio)
		return NULL;
	else
		return aux;
}
	
//Método base da exclusão
template <class T>
void ListaSC<T>::excluirMeio(Elemento<T> *Anterior, Elemento<T> *Posterior){
	Elemento<T> *aux;

	aux = Anterior->prox;
	Anterior->prox = Posterior;

	delete(aux);
	//return Inicio;
}
	
//Método para exclusão de um elemento do inicio da lista
template <class T>
void ListaSC<T>::excluirInicio(){
	Elemento<T> *aux;
	

	if( Lista<T>::Inicio!=NULL){
		aux = Lista<T>::Inicio->prox;
		while(aux->prox != Lista<T>::Inicio)
			aux = aux->prox;

		excluirMeio(aux, Lista<T>::Inicio->prox);		
		}
	else
		cout<<"\nA lista esta vazia, não é possível excluir nenhum elemento!"<<endl;
}

//Método para excluir elemento do fim da lista	
template <class T>
void ListaSC<T>::excluirFim(){
	excluirInicio();
}

//Método para remover um elemento específico	
template <class T>
void ListaSC<T>::excluirElemento(T *info){
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
		cout<<"\nO elemento não foi encontrado!"<<endl;
	}
}

///Método para retornar o primeiro elemento da lista
template <class T>
T* ListaSC<T>::getFirst(){
	return Lista<T>::Inicio->getInfo();
}

#endif
