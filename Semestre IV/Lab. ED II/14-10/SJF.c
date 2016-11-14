#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "headers/lista_prioridade.h"

#define SEC 1000000
#define LIMITE 20

main(){
/*
	lista_p *inicio;
	inicio = insereElemento(12,15,inicio);
	imprimeLista(inicio);



	printf("\n\n\n------\n\n\n");
	inicio = insereElemento(15,20,inicio);
	imprimeLista(inicio);
	

	printf("\n\n\n------\n\n\n");
	inicio = insereElemento(10,30,inicio);	
	imprimeLista(inicio);
*/
	lista_p *inicio;
	int id=1;
	int tempoProx;	
	int random;	
	int i;

	srand(time(NULL));

	tempoProx = rand()%LIMITE + 1;
	inicio = insereElemento(tempoProx,id,inicio);

	for(i = 0; i < LIMITE*5; i++){
		system("clear");
		printf("random = %d\n\n",random);
		imprimeLista(inicio);

		if(inicio != NULL){		
			if(inicio->tempoRestante == 1){
				inicio = removeElemento(inicio);
			}else{
				inicio->tempoRestante--;
			}
		}

		random = rand()%(LIMITE/2);
		if(random == (LIMITE/4)-2 ){
			tempoProx = rand()%LIMITE + 1;
			id++;
			inicio = insereElemento(tempoProx,id,inicio);
		}
		usleep(SEC);
	}

}
