#include <stdio.h>
#include <stdlib.h>

//Estrutura da lista_s simples
typedef struct elemento{
	int id;
	int tempoRestante;
	char *estado;
	struct elemento *prox;
}lista_s;


//Funções utilizadas
lista_s *insereElemento(int id, int tempoRestante, lista_s *inicio);
lista_s *removeElemento(lista_s *inicio);
void imprimeLista(lista_s *inicio);



lista_s *insereElemento(int id,int tempoRestante,lista_s *inicio){
	lista_s *novo,*aux;
	
	if( novo = (lista_s *) malloc(sizeof(lista_s)) ){
		novo->id = id;
		novo->tempoRestante = tempoRestante;
		novo->prox = NULL;
		if(inicio == NULL){
			inicio = novo;
			novo->estado = "Execução";
		}else{
			aux = inicio;
			while(aux->prox != NULL){
				aux = aux->prox;
			}
			aux->prox = novo;
			novo->estado = "Aguardando";
		}
		return inicio;
	}else{
		printf("Deu algo errado na alocação de memória\n");
	}
}


lista_s *removeElemento(lista_s *inicio){
	lista_s *aux;
	
	if(inicio != NULL){
		aux = inicio;
		inicio = inicio->prox;
	}

	if(inicio != NULL){
		inicio->estado = "Execução";
	}

	free(aux);
	return inicio;
}


void imprimeLista(lista_s *inicio){
	lista_s *aux;
	aux = inicio;
	while(aux != NULL){
		printf("Processo %d\nEstado %s\nTempo Restante %d\n\n",aux->id,aux->estado,aux->tempoRestante);
		aux = aux->prox;
	}	
}
