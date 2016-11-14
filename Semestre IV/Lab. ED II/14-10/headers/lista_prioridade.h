#include <stdio.h>
#include <stdlib.h>

//Definição da estrutura
typedef struct elemento{
	int id;
	int tempoRestante;
	char *estado;
	struct elemento* prox;
}lista_p;

//Funções usadas
lista_p *insereElemento(int tempoRestante, int id, lista_p *inicio);	//Insere elemento na posição certa (com prioridade sendo menor tempo)
lista_p *insereElementoEntre( lista_p* ant);				//Insere elemento entre o *ant e o *prox
lista_p *procuraPosicao(int tempoRestante,lista_p *inicio);			//Procura a melhor posição para inserir elemento
lista_p *removeElemento(lista_p *inicio);					//Remove o primeiro elemento da lista_p
void imprimeLista(lista_p *inicio);					//Imprime a lista_p

/////////////////////////////
//Implementação das funções//
/////////////////////////////

lista_p *insereElemento(int tempoRestante, int id, lista_p *inicio){
	lista_p *aux;
	lista_p *novo;

	if(inicio == NULL){
		novo = insereElementoEntre(NULL);
		inicio = novo;
	}else{
		aux =  procuraPosicao(tempoRestante,inicio);
		novo = insereElementoEntre(aux);
		if(aux == NULL){
			novo->prox = inicio;
			inicio->estado = "Aguardando";
			inicio = novo;
		}
	}

	if(novo != NULL){
		novo->tempoRestante = tempoRestante;
		novo->id = id;
	}else{
		printf("Algo deu errado na inserção do elemento\n");
	}

	return inicio;
}



lista_p *insereElementoEntre(lista_p *ant){
	lista_p *novo;

	novo = (lista_p *) malloc(sizeof(lista_p));
	if(novo != NULL){
		if(ant != NULL){
			novo->prox = ant->prox;
			ant->prox = novo;
			novo->estado = "Aguardando";
		}else{
			novo->prox = NULL;
			novo->estado = "Execução";
		}
	}else{
		printf("Algo deu errado na alocação da memória\n");
	}

	return novo;
}


lista_p *procuraPosicao(int tempoRestante, lista_p *inicio){
	lista_p *aux1, *aux2;
	
	aux2 = NULL;
	aux1 = inicio;

	while(aux1 != NULL && aux1->tempoRestante <= tempoRestante){
		aux2 = aux1;
		aux1 = aux1->prox;
	}
	
	return aux2;
}


lista_p *removeElemento(lista_p *inicio){
	lista_p *aux;

	aux = inicio;
	
	if(inicio != NULL){
		inicio = inicio->prox;
		if(inicio != NULL){
			inicio->estado = "Execução";
		}
		free(aux);
	}
	
	return inicio;
}


void imprimeLista( lista_p *inicio){
	lista_p *aux;
	
	aux = inicio;
	while(aux != NULL){
		printf("Elemento %d\nEstado: %s\nTempo Restante: %d\n\n",aux->id,aux->estado,aux->tempoRestante);
		aux = aux->prox;
	}
}



