#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "headers/lista_simples.h"


#define LIMITE 20
#define SEC 1000000

main(){

	lista_s *inicio;
	int random = 0;
	int id = 1;
	int tempoProx;
	int i;

	srand(time(NULL));
	
	tempoProx = (rand()%LIMITE) + 1;
	inicio = insereElemento(id,tempoProx,inicio);
	
	for(i = 0; i < LIMITE*5; i++){
		system("clear");
		printf("Random: %d\n\n",random);
		imprimeLista(inicio);
		usleep(SEC);
	
		if(inicio != NULL){
			if(inicio->tempoRestante == 1){
				inicio = removeElemento(inicio);
			}else{
				inicio->tempoRestante--;
			}
		}
		
		random = rand()%LIMITE/4;
		if(random == LIMITE/4 - 2){
			tempoProx = (rand()%LIMITE) + 1;
			id++;
			inicio = insereElemento(id,tempoProx,inicio);
		}	
	}


}

