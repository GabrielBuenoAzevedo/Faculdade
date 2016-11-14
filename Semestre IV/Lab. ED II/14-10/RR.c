/**************************************
 * Feito por Gabriel Bueno de Azevedo *
 * RA: 151040362		      *
 * Turma 2015 B.C.C. Unesp - Ibilce   *
 * ************************************/

//Este programa foi desenvolvido para ser utilizado em sistemas linux.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "headers/lista_circular.h"

#define QUANTUM 5
#define LIMITE 20

main(){
	lista_c *inicio;
	int i, insere;								//i -> contador, insere -> parâmetro aleatório para inserir elementos
	int id, quantum;							//id -> id do prox,

	srand(time(NULL));
	system("clear");


	inicio = insereElementoRandom(inicio,1,LIMITE);				//Começa já com um processo iniciado
	if(inicio->tempoRestante == 0){
		inicio->tempoRestante = LIMITE/2;
	}	

	id = 2;									//Começa em 2 por causa do elemento já adicionado
	quantum = 1;								//Começa em 1 por causa do elemento já adicionado

	for(i = 0; i < LIMITE*5; i++){						//Número de loops 5x maior que o maior tempo possivel de processo
		insere = rand()%5;

		system("clear");
		printf("Imprime = %d\n",insere);
		imprimeLista(inicio);
		usleep(1000000);						//Deixa o terminal dormindo de segundo em segundo

		if(insere == 2){						//Insere elemento aleatoriamente
			inicio = insereElementoRandom(inicio,id,LIMITE);
			id++;
		}

		if(inicio != NULL){						//Caso tiver algum processo ativo, diminui o tempo do mesmo e verifica
			inicio->tempoRestante--;				//se ele está no fim.
			if(inicio->tempoRestante == 0){				//No fim do tempo do processo, retira ele da lista e zera o quantum
				inicio = removeElementoInicio(inicio);
				quantum = 0;
			}else if(quantum%QUANTUM == 0){				//Tempo necessário para a lista "girar" para o próximo elemento
					inicio = inicio->prox;		
				}
			quantum++;	
		}
	}
}
