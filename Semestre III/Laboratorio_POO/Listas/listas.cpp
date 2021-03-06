/* Created by Gabriel */

#include <string.h>

#include<iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ios;

#include<iomanip>
using std::setprecision;
using std::setiosflags;

// Começo do programa

class Elemento {
	private:
		int info;
	public:
		Elemento *prox;
		
		Elemento(int info);
		void setInfo(int info);
		int getInfo();
		void displayData();
}

Elemento::Elemento(int info){
	setInfo(info);
	prox = NULL;
}

void Elemento::setInfo(int info){
	this->info = info;
}

int Elemento::getInfo(){
	return info;
}

void Elemento::displayData(){
	cout << info;
}


class Lista {
	private: 
		Elemento *Inicio;
	public:
		Lista();				//Construtor		
		
		//Inserção de elementos
		void *inserirInicio(int info);	//Insere no início da lista
		void *inserirFim(int info);		//Insere no fim da lista
		void *inserirOrdem(int info);	//Insere na ordem 
		Elemento *inserirMeio(int info, Elemento *Ant, Elemento *Post);		//Insere no meio dos elementos desejados

		//Pesquisa de elementos
		Elemento *pesquisar(int info);
		
		//Exclusão de elementos
		Elemento *excluirInicio();
		Elemento *excluirFim();
		Elemento *excluirElemento(int info);
		Elemento *excluirMeio(Elemento *Ant, Elemento *Post);

		//Impressão da lista
		void imprimeLista();	
}


Lista::Lista(){
	Inicio = NULL;
}

Elemento *Lista::inserirMeio(int info, Elemento *Ant, Elemento *Post){
	Elemento *novo = new Elemento(info);

	if(Ant == NULL){
		novo->prox = Post;
		Inicio = novo;	
	}
	else{
		novo->prox = Post;
		Ant->prox = novo;
	}
	
	return Inicio;
}

void Lista::inserirInicio(int info){
	Inicio = inserirMeio(info, NULL, Inicio);

}

void Lista::inserirFim(int info){
	Elemento *aux;

	aux = Inicio;
	if(aux != NULL)
		while(aux->prox != NULL)
			aux = aux->prox;

	Inicio = inserirMeio(info,aux, NULL);
}


void Lista::inserirOrdem(int info){
	Elemento *aux1 = NULL , *aux2 =  NULL;

	aux1=Inicio;
	if(aux1=NULL){
		while( (aux1 != NULL) && (aux1->getInfo() < info))
			aux1 = aux1->prox;

		if(aux1 != Inicio){
			aux2 = Inicio;
			while(aux2->prox != aux1)
				aux2 = aux2->prox;
		}
	}

	Inicio = inserirMeio(info,aux2,aux1);
}


Elemento* Lista::pesquisar(int info){
	Elemento *aux;

	aux = Inicio;

	while( (aux!=NULL) && (aux->getInfo() != info) )
		aux = aux->prox;
	
	return aux;
}


Elemento* Lista::excluirMeio(Elemento *Anterior, Elemento *Posterior){
	Elemento *aux;
	
	if( Anterior != NULL){
		aux = Anterior->prox;	
		Anterior->prox = Posterior;
	} 
	else{
		aux = Inicio;
		Inicio = Posterior;
	}

	delete(aux);
	return Inicio;
}


void Lista::exluirInicio(){
	Inicio = excluirMeio(NULL, Inicio->prox);
}	

void Lista::excluirFim(){
	Elemento *aux;
	if(Inicio != NULL){
		if(Inicio->prox == NULL){
			Inicio = excluirMeio(NULL,NULL);
		}
		else{
			aux = Inicio;
			while( (aux->prox)->prox != NULL)
				aux = aux->prox;
			Inicio = excluirMeio(aux, NULL);
		}
	}
	else
		cout<<"A lista está vazia!!"<<endl;
}







