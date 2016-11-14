#include <stdio.h>
#include <stdlib.h>

//Declaracao da estrutura da lista circular.
typedef struct celula{
	char *estado;			//Estado da celula atual
	int id;					//ID da celula atual
	int tempoRestante;			//Tempo restante (em ms) para terminar de executar a tarefa
	struct celula *prox;				//Proxima celula na lista
	}lista_c;


//Funcoes relativas a implementacao da lista
lista_c* insereElemento(lista_c *inicio,int id, int tempoRestante);	//Insere um elemento com os parâmetros sendo passados	
lista_c* removeElementoInicio(lista_c *inicio);				//Remove o "primeiro" elemento da lista
void imprimeLista(lista_c *inicio);					//Imprime toda a lista na tela
lista_c* insereElementoRandom(lista_c *inicio,int id,int limite);		//Insere um elemento com parâmetros aleatórios (exceto pelo ID)
void imprimeUltimoElemento(lista_c *inicio);

//Implementacao funcoes da lista

lista_c* insereElemento(lista_c *inicio,int id, int tempoRestante){
	if(inicio == NULL){
		if(inicio = (lista_c *) malloc(sizeof(lista_c))){
			inicio->prox = inicio;
			inicio->id = id;
			inicio->tempoRestante = tempoRestante;
			inicio->estado = "Execução";
			//printf("O elemento foi criado com sucesso!\n");
		}else{
			printf("Ocorreu um erro na criação do elemento!\n");
		}
	}else{
		lista_c *aux,*novo;
		if(novo = (lista_c *) malloc(sizeof(lista_c))){
			aux = inicio;
			while(aux->prox != inicio){
				aux = aux->prox;
				}
			aux->prox = novo;
			novo->prox = inicio;
			novo->id = id;
			novo->tempoRestante = tempoRestante;
			novo->estado = "Pronto";
			//printf("O elemento foi criado com sucesso!\n");
		}else{
			printf("Ocorreu um erro na criação do elemento!\n");
		}
	}
	return inicio;
}

lista_c* insereElementoRandom(lista_c *inicio, int id,int limite){
	int tempoRestante;
	tempoRestante = rand()%limite+1;
	insereElemento(inicio,id,tempoRestante);
}

lista_c *removeElementoInicio(lista_c* inicio){
	if(inicio == NULL){
		printf("A lista está vazia!\n\n");
		return NULL;
	}
	
	lista_c *auxDel, *aux;
	auxDel = inicio->prox;
	aux = inicio;
	while(auxDel->prox != inicio){
		auxDel = auxDel->prox;
	}
	auxDel->prox = aux->prox;
	inicio = aux->prox;
	inicio->estado = "Execução";
	if(inicio == aux){
		return NULL;
	}else{
	free(aux);
	return inicio;
	}
}



void imprimeLista(lista_c *inicio){
	lista_c *aux;
	
	if(inicio != NULL){
		aux = inicio->prox;
		printf("------------------------------------------------------------\nElemento %d\nEstado: %s\nTempo Restante de Processamento: %d\n------------------------------------------------------------\n",inicio->id,inicio->estado,inicio->tempoRestante);
		while(aux != inicio){
		printf("Elemento %d\nEstado: %s\nTempo Restante de Processamento: %d\n------------------------------------------------------------\n",aux->id,aux->estado,aux->tempoRestante);
		aux = aux->prox;
		}
	}
}

void imprimeUltimoElemento(lista_c *inicio){
	lista_c *aux;

	if(inicio != NULL){
		aux = inicio->prox;
		while(aux->prox != inicio){
			aux = aux->prox;
		}
		printf("-----------------------------------------------------------\nElemento %d\nEstado: %s\nTempo Restante de Processamento: %d\n------------------------------------------------------------\n",aux->id,aux->estado,aux->tempoRestante);
	}
}

