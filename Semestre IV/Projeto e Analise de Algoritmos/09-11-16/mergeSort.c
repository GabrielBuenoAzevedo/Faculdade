#include <stdio.h>
#include <stdlib.h>


void merge(int *vet, int comeco, int final){
	int i,j,k,meio;
	int *vetAux = (int *) malloc(sizeof(int) * (final-comeco));

	meio = (final+comeco)/2;
	j = comeco;			//Segunda metade
	k = meio;	

	printf("Comeco %d - Meio %d - Final %d     comeco+meio+1 = %d     k = %d\n",comeco,(comeco+final)/2,final,meio, k );

	for(i = 0; i < (final - comeco); i++){
		if( (j < meio) && (k <= final) ){
			printf("j = %d , k = %d, comeco+meio+1 = %d, final = %d\n",j,k,comeco+meio+1,final);
			if(vet[j] < vet[k]){
			//	printf("vetAux[%d] = vet[%d]   (%d = %d)\n",i,j,vetAux[i] = vet[j]);
				vetAux[i] = vet[j];
				printf("vetAux[%d] = vet[%d]   (%d < %d)\n",i,j,vet[j] , vet[k]);
				j++;
			}else{
				vetAux[i] = vet[k];
				 printf("vetAux[%d] = vet[%d]   (%d < %d)\n",i,k,vet[k] , vet[j]);
				k++;
			}
		}else{
			printf("ENTROU AQUI, UAI\n");
			if(k <= final){
				vetAux[i] = vet[k];
				printf("vetAux[%d] = vet[%d]   (%d < %d)\n",i,k,vet[k] , vet[j]);
				k++;
			}else{
				vetAux[i] = vet[j];
				printf("vetAux[%d] = vet[%d]   (%d < %d)\n",i,j,vet[j] , vet[k]);
				j++;
			}
		}
	}

	for(i = 0, j = comeco; i < final - comeco; i++, j++){
		vet[j] = vetAux[i];
		printf("\nvet[%d] = %d",j,vet[j]);
	}
		printf("\nvet[%d] = %d\nFim do merge!!!\n\n\n\n\n",j,vet[j]);
}

void mergeSort(int *vet, int comeco, int final){
	int meio =(int) (comeco + final)/2;
	if(comeco < final){
		mergeSort(vet,comeco,meio);
		mergeSort(vet,meio+1,final);
		merge(vet,comeco,final);
	}
}

void main(){
	int vet[5] = {25,10,15,5,20};
	mergeSort(vet,0,5);
	
	int i ;
	for(i = 0; i < 5; i++){
		printf("%d ",vet[i]);
	}
	putchar('\n');
/*	merge(vet,0,3);
	merge(vet,4,5);
	merge(vet,0,5);*/
//	merge(vet,0,5);
}
