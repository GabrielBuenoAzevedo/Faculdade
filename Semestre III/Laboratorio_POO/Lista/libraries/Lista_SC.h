#ifndef ListaSC_H
#define ListaSC_H

#include "Lista.h"

template<class T>
class ListaSC: public Lista<T>{
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
		
		//Método para devolver o primeiro elemento da lista
		virtual T* getFirst();
};

//Construtor
template <class T>
ListaSC<T>(){
	Inicio = NULL;
}

//Método base para a inserção
void ListaSC<T>::InserirMeio(T *info, Elemento<T> *Ant, Elemento<T> *Post){
	Elemento<T> *Novo = new Elemento<T>(info);
	Elemento<T> *aux;

	if(ant == NULL){
	Lista<T>::Inicio = Novo;
	Novo->prox = Novo;
	}else{
		Ant->prox = Novo;
		novo->prox = Post;
	}
}

//Método de inserção no início
template <class T>
void ListaSC<T>::inserirInicio(T *info){
	Elemento<T> *aux;
	aux = Lista<T>::Inicio;
	
	if(Lista<T>::Inicio == NULL)
		inserirMeio(info, NULL, Lista<T>::Inicio);
	else{
		while(aux->prox != Lista<T>::Inicio)
			aux=aux->prox;
		inserirMeio(info,aux,Lista<T>::Inicio);	
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

//Método para pesquisar um elemento
template <class T>
Elemento<T>* ListaSC::pesquisar(T *info){
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
void ListaSC::excluirMeio(Elemento<T> *Anterior, Elemento<T> *Posterior){
	Elemento<T> *aux;

	aux = Anterior->prox;
	Anterior->prox = Posterior;

	delete(aux);
	//return Inicio;
}
	
//Método para exclusão de um elemento do inicio da lista
template <class T>
void ListaSC::excluirInicio(){
	Elemento<T> *aux;
	aux = Lista<T>::Inicio->prox;

	if( Lista<T>::Inicio!=NULL){
		
		while(aux->prox != Lista<T>::Inicio)
			aux = aux->prox;

		excluirMeio(aux, Lista<T>::Inicio->prox);		
		}
	else
		cout<<"\nA lista esta vazia, não é possível excluir nenhum elemento!"<<endl;
}

//Método para excluir elemento do fim da lista	
template <class T>
void ListaSC::excluirFim(){
	excluirInicio();
}

//Método para remover um elemento específico	
template <class T>
void ListaSC::excluirElemento(T *info){
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
T* ListaSC::getFirst(){
	return Lista<T>::Inicio->getInfo();
}

























#endif
