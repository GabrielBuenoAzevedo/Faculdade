#include <stdio.h>
#include <stdlib.h>

//Declaração da estrutura usada
typedef struct elemento{
	int tamanho;					//Tamanho do processo/espaço livre
	int id;						//ID:  > 0 caso processo, 0 caso espaco livre
	char tipo;					//Tipo: L caso espaco livre, P caso processo 
	struct elemento *prox;				//Proximo elemento da lista
	struct elemento *ant;
}lista;

//Funções básicas de lista
lista* insereElemento(lista* ant,int id, int tamanho, char tipo);
lista* removeElemento(lista* elem, lista* ant);
void imprimeLista(lista* inicio);
//Funções focadas para o uso de gerenciamento de memória
lista* primeiroEspacoLivre(lista* inicio, int tamanho);
lista* piorEspacoLivre(lista* inicio, int tamanho);
lista* melhorEspacoLivre(lista* inicio, int tamanho);
lista* procuraProcesso(lista* inicio, int id);
lista* procuraEspacoLivre(lista* inicio, lista* espaco);
int adicionaProcesso(lista* inicio,int id, int tam,char tipoBusca);
lista* removeProcesso(lista* inicio,int id);
lista* juntaEspacosLivres(lista *elem);
lista* inicializaMemoria(int tam);

//Insere um elemento depois do elemento ant
lista* insereElemento(lista *ant, int id, int tamanho, char tipo){
	lista *novo = (lista*)malloc(sizeof(lista));
	novo->id = id;
	novo->tamanho = tamanho;
	novo->tipo = tipo;

	if(ant == NULL){					//Elemento anterior = NULL -> novo é o comeco da lista
		ant = novo;
		novo->ant = NULL;
		novo->prox = NULL;
		}
	else{
		novo->prox = ant->prox;
		ant->prox = novo;
		novo->ant = ant;
		if(novo->prox != NULL)
			novo->prox->ant = novo;
	}

	return ant;
}


//Remove o elem, que fica depois do elemento ant
lista* removeElemento(lista* elem,lista *ant){
	lista *aux = elem;

	if(elem != NULL){
		if(ant == NULL)					//elem é o primeiro elemento da lista (ou unico)
			ant = elem->prox;
		else{
			ant->prox = elem->prox;
			if(ant->prox != NULL)
				ant->prox->ant = ant;
		}
		free(aux);
	}
	return ant;
}


//Imprime toda a lista
void imprimeLista(lista* inicio){
	lista *aux = inicio;
	while(aux != NULL){
		if(aux->tipo == 'L')
			printf("Espaço Livre\n");
		else
			printf("Processo ID %d\n",aux->id);
		printf("Espaço: %d\n\n",aux->tamanho);
		aux = aux->prox;
	}
}


//Procura o primeiro espaço livre em que o processo caiba e retorna o anterior
lista* primeiroEspacoLivre(lista *inicio, int tamanho){
	lista *aux1;

	aux1 = inicio;

	if(aux1 == NULL){
		printf("Não existe memória instanciada!\n");
		return 0;
	}			

	while(aux1 != NULL && (aux1->tipo != 'L' || aux1->tamanho < tamanho) ){
		aux1 = aux1->prox;
	}

	return aux1;
}


//Procura o pior espaço livre em que o processo caiba e retorna o anterior
lista* piorEspacoLivre(lista *inicio, int tamanho){
	lista *aux, *piorEspaco;

	aux = inicio;
	piorEspaco = NULL;
	
	if(aux == NULL){
		printf("Não existe memória instanciada!\n");
	}

	while(aux != NULL){
		if(aux->tipo == 'L' && aux->tamanho >= tamanho){
			if(piorEspaco == NULL)
				piorEspaco = aux;
			else{
			if(aux->tamanho > piorEspaco->tamanho)
				piorEspaco = aux;
			}
		}
		aux = aux->prox;
	}

	if(piorEspaco == NULL){
		printf("Nenhum espaco livre foi achado!\n");
		return 0;
	}

	return piorEspaco;
}


//Procura o melhor espaço livre em que o processo caiba e retorna o anterior
lista* melhorEspacoLivre(lista *inicio, int tamanho){
	lista *aux, *melhorEspaco;

	aux = inicio;
	melhorEspaco = NULL;

	if(inicio == NULL){
		printf("Não existe memória instanciada!!\n");
		return 0;
	}
	

	int i =0;
        while(aux != NULL){
                if(aux->tipo == 'L' && aux->tamanho >= tamanho){
                        if(melhorEspaco == NULL){
                                melhorEspaco = aux;
			}
                        else{
                        if(aux->tamanho < melhorEspaco->tamanho)
                                melhorEspaco = aux;
                        }
                }
                aux = aux->prox;
        }

        if(melhorEspaco == NULL){
                printf("Nenhum espaco livre foi achado!\n");
		return 0;
	}

        return melhorEspaco;
}


//Procura o processo com o ID indicado e retorna o elemento anterior ao mesmo
lista* procuraProcesso(lista *inicio, int id){
	lista *aux1, *aux2;

	aux1 = inicio;

	while(aux1 != NULL){
		if(aux1->id == id)
			return aux1;
		aux1 = aux1->prox;
	}	
	printf("O processo não foi encontrado!!\n");
	return 0;
}


//Adiciona um processo executando à memória
int adicionaProcesso(lista *inicio,int id, int tamanho,char tipoBusca){
	lista *busca;

	switch(tipoBusca){
	case 'B':
		busca = melhorEspacoLivre(inicio,tamanho);
		break;
	case 'W':
		busca = piorEspacoLivre(inicio,tamanho);
		break;
	case 'F':
		busca = primeiroEspacoLivre(inicio,tamanho);
		break;
	default:
		printf("Argumento errado fornecido para a função!!\n");
	}

	if(busca != NULL){
		if(busca->tamanho == tamanho){
			busca->id = id;
			busca->tipo = 'P';
		}else{
			busca->tamanho -= tamanho;
			insereElemento(busca,id,tamanho,'P');
		}
		return 1;
	}else{	
		return 0;
	}
}


//Remove um processo que está sendo executado
lista* removeProcesso(lista *inicio, int id){
	lista *elem;
	elem = procuraProcesso(inicio,id);

	elem->tipo = 'L';
	elem->id = 0;

	juntaEspacosLivres(elem);
}


//Junta espaços de memória livre adjacentes
lista* juntaEspacosLivres(lista *elem){
	lista *prox, *ant, *aux;

	aux = elem;
	prox = elem->prox;
	ant = elem->ant;

	if(prox != NULL && prox->tipo == 'L'){
		elem->tamanho += prox->tamanho;
		removeElemento(prox,elem);
	}
	if(ant != NULL && ant->tipo == 'L'){
		ant->tamanho += elem->tamanho;
		removeElemento(elem,ant);
		aux = ant;
	}
	
	return aux;
}


//Inicializa a memória com tam de memória
lista* inicializaMemoria(int tam){
	lista *inicio;
	inicio = insereElemento(NULL,0,tam,'L');
	return inicio;
}
