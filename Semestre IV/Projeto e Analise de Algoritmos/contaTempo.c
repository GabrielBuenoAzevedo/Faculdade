#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20000
#define TAM 500
int MATA[N][N];
int MATB[N][N];
int MATC[N][N] = {0};

void imprimeMatriz(char c, int tam){
	for(int i = 0; i < tam; i++){
		for(int j = 0; j < tam; j++){
			if(c == 'A')
				printf("%d ",MATA[i][j]);
			if(c == 'B')
				printf("%d ",MATB[i][j]);
			if(c == 'C')
				printf("%d ",MATC[i][j]);
			}
		putchar('\n');
	} 
}

void multiplicaMatriz(int tam){
	for(int i = 0; i < tam; i++)
		for(int j = 0; j < tam; j++)
			for(int k = 0; k < tam; k++)
				MATC[i][j] += MATA[i][k] * MATB[k][j];						
}

void zeraMatriz(int tam){
	for(int i = 0; i < tam; i++)
		for(int j = 0; j < tam; j++)
			MATC[i][j] = 0;
}

int main(){

	srand(time(NULL));
	clock_t inicio, final;
	FILE *arq;

	//Inicia os vetores
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			MATA[i][j] = rand()%10;
			MATB[i][j] = rand()%10;
		}
	}

	//Faz as iterações para jogar no arquivo resultado.txt
	int iteracao = 1;
	if(arq=(fopen("resultado.txt","w"))){
		for(int k = 1; k <= N/TAM; k++){
			zeraMatriz(k*TAM);			//Zerar as posições usadas anteriormente no vetor C

			inicio = clock();
			
			multiplicaMatriz(TAM*k);

			final = clock();

			printf("%lf\t%d\n\n",((float)(final - inicio)/(CLOCKS_PER_SEC)),k*TAM);
		}
	}
	
}


