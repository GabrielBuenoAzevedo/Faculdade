#include "ListaItens.h"

ListaItens::ListaItens(){
	Lista = NULL;
	ListaCompras = NULL;
}

void ListaItens::inserir(){
	Item *Novo = new Item();
	if(Novo->verificaValidade()) {
		cout<<"\nInforme o preço do item: ";
		float preco;
		cin>>preco;
		Novo->setPreco(preco);
	
		cout<<"\nInforme o desconto: ";
		float desconto;
		cin>>desconto;
		Novo->setDesconto(desconto);
		
		cout<<"\nInforme a quantidade: ";
		int Qtdd;
		cin>>Qtdd;
		Novo->setQuantidade(Qtdd);
		
		Novo->prox = Lista;
		Lista = Novo;
	}
	else
		cout<<"\n O item está fora da validade e não pode ser inserido\n\n";
}

void ListaItens::imprimirLista(){
	Item *aux;
	
	aux = Lista;
	while(aux!=NULL){
		cout<<"\n";
		aux->displayInfo();
		aux = aux->prox;
	}
}

float ListaItens::valorTotal(){
	float total=0;
	Item *aux;
	
	aux=Lista;
	while(aux!=NULL){
		total += aux->calculaPrecoTotal();
		aux=aux->prox;
	}
	return total;
}

Item* ListaItens::consultarItem(char Nome[]){
	Item *aux;
	aux = Lista;

	while(aux != NULL){
	if(std::strcmp(aux->getNome(),Nome) == 0)
		return aux;

	aux = aux->prox;
	}

	return NULL;	
}

void ListaItens::excluirItem(char Nome[]){
	Item *aux;
	Item *auxProx;
	
	aux = Lista;
	auxProx = aux->prox;

	if(auxProx == NULL && strcmp(aux->getNome(),Nome)==0){
		cout << '\n' << Nome << " EXCLUÍDO COM SUCESSO!\n";
		delete(aux);
		Lista=NULL;
		}

	while(auxProx != NULL){
		if(strcmp(auxProx->getNome(),Nome) == 0){			
			aux->prox = auxProx->prox;
			cout << '\n'<< Nome << " EXCLUÍDO COM SUCESSO!\n";
			delete(auxProx);
			}
	aux = aux->prox;
	auxProx = auxProx->prox;
	}

	if(auxProx == NULL && Lista != NULL)
		cout << "\n\nElemento não foi achado na lista!!!!!!!\n";
}

