#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "lista_ordenada.h"

//Constantes de tamanho de memória e processos
#define MAX_MEMORIA	256
#define MAX_PROCESSO	64
#define MIN_PROCESSO	4

//Constantes para serem usadas no rand para aumentar/diminuir probabilidade de adicionar ou remover elementos, sendo as mesmas de 1/MAX_RANDOM
#define MAX_RANDOM	10

main(){
	lista *inicio, *busca;
	int opcao,random, tamanhoProcesso,id,numProcessos, processoDeletado;
	char algoritmo,lixo;

//	int resultados[] = { 4,4,4,4,4,4,6,6,4,4,6,4,6,6,6,6};
//	int i = 0;

	inicio = inicializaMemoria(MAX_MEMORIA);

	do{
		printf("Escolha o algoritmo de gerenciamento de alocação de memória:\n	[1] Best Fit\n	[2] Worst Fit\n	[3] First Fit\n\nOpção: ");
		scanf(" %d", &opcao);
	}while(opcao < 1 || opcao > 3);

	switch(opcao){
		case 1:
			algoritmo = 'B';
			break;
		case 2:
			algoritmo = 'W';
			break;
		case 3:
			algoritmo = 'F';
			break;
		default:
			algoritmo = 'F';
			printf("Ocorreu algum erro!\nPor causa disso, First Fit foi escolhido com o algoritmo!\n");
	}

	srand(time(NULL));
	id = 1;
	numProcessos = 0;
	while(1){
		system("clear");
		random = rand()%MAX_RANDOM;
	//	random = resultados[i];
	//	i++;
		printf("Random: %d\nNumProcessos: %d\n",random,numProcessos);
		imprimeLista(inicio);
		if(random == (MAX_RANDOM/3)+1){
			tamanhoProcesso = ( rand()%(MAX_PROCESSO - MIN_PROCESSO) ) + MIN_PROCESSO;
			if(adicionaProcesso(inicio,id,tamanhoProcesso,algoritmo)){
				id++;
				numProcessos++;
			}
		}
		if( (numProcessos > 0) && (random == (MAX_RANDOM/2)+1) ){
			processoDeletado = rand()%numProcessos+1;
			busca = inicio;
			if(busca->tipo == 'P')
				processoDeletado--;
			while(processoDeletado > 0){
				busca = busca->prox;
				if(busca->tipo == 'P')
					processoDeletado--;
			}
			removeProcesso(inicio, busca->id);
			numProcessos--;
		}
		usleep(500000);	
	}

}
