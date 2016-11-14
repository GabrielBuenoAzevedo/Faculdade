#include "ArvoreBin.h"

ArvoreBin::ArvoreBin(int num){
	dir = NULL;
	esq = NULL;
	this->num = num;
}


void ArvoreBin::InserirElemento(int num){				//Insere elemento com valor num na árvore binária
	if(num < this->num){
		if(esq != NULL)
			esq->InserirElemento(num);
		else
			esq = new ArvoreBin(num);
	}else{
		if(dir != NULL)
			dir->InserirElemento(num);
		else
			dir = new ArvoreBin(num);
	}
}


ArvoreBin* ArvoreBin::DeletarElemento(int num){				//Deleta o elemento com valor num 
	if(num < this->num && esq != NULL)
		esq = esq->DeletarElemento(num);
	if(num > this->num && dir !=NULL)
		dir = dir->DeletarElemento(num);
	if(num == this->num){
		ArvoreBin *aux1 = esq;
		ArvoreBin *aux2 = dir;
		
		cout << "Chegou aqui";
		if(dir != NULL){
			while(aux2->esq!=NULL)
				aux2 = aux2->esq;	//Vai para a máxima posição esquerda do ramo direito 
		
			aux2->esq = aux1;
		
		}

		if(dir != NULL)
			aux2 = dir;
		else
			aux2 = esq;
	
		aux1=this;
		aux1->esq = NULL;
		aux1->dir = NULL;		
		delete aux1;
	
		return aux2;			//Retorna o elemento que ficará no lugar do antigo
	}
	
	return this;				//Retorna o próprio elemento chamando a função
}

void ArvoreBin::DisplayArvore(){		//Mostra a árvore binária
	if(esq != NULL)
		esq->DisplayArvore();

	cout << this->num << ' ';

	if(dir != NULL)
		dir->DisplayArvore();
		
}

bool ArvoreBin::ProcurarElemento(int num){			//Procura o elemento num na árvore binária
	if(num == this->num){					//Achou o número		
		return true;
		}

	if(num < this->num){					//Número é menor que o número do elemento atual
		if(esq != NULL)					//Se a esquerda for diferente de NULL, procura nela, se não, retorna falso
			return esq->ProcurarElemento(num);
		else{
			return false;
			}
		}
	if(num > this->num){					//Número é maior que o número do elemento atual
		if(dir != NULL)					//Se a direita for diferente de NULL, procura nela, se não, retorna falso
			return dir->ProcurarElemento(num);
		else{
			return false;
			}
		}
}

void ArvoreBin::DestruirArvore(){				//Destrói árvore
	if(esq != NULL)
		esq->DestruirArvore();
	if(dir != NULL)
		dir->DestruirArvore();
	delete(this);
}

