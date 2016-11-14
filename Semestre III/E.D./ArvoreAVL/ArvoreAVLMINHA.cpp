#include "ArvoreAVL.h"

ArvoreAVL::ArvoreAVL(int num){
	p_dir = 0;
	p_esq = 0;
	p_total--;
	this->num = num;
	dir = NULL;
	esq = NULL;
}

ArvoreAVL* ArvoreAVL::InserirElemento(int num){
	if(num < this->num){
		if(esq != NULL)
			esq = esq->InserirElemento(num);
		else
			esq = new ArvoreAVL(num);

	}else{
		if(dir != NULL)
			dir = dir->InserirElemento(num);
		else
			dir = new ArvoreAVL(num);

	}

	if(dir != NULL){
		if(dir->p_dir > dir->p_esq)
			p_dir = dir->p_dir + 1;
		else
			p_dir = dir->p_esq + 1;
	}
	if(esq != NULL){
		if(esq->p_esq > esq->p_dir)
			p_esq = esq->p_esq + 1;
		else
			p_esq = esq->p_dir + 1;
	}

	p_total = p_dir - p_esq;
	//cout << "O item atual é " << this->num << " com p_dir = " << p_dir << " e p_esq = " << p_esq << " sendo p_total = " << p_total << "       ";

	this->DisplayArvore();


	
	//Começa a validação para ver que tipo de balanceamento fazer (se precisar fazer algum)
	if(p_total == -2){
		if(esq->p_total == -1)
			return this->GirarDireita();
		else{
			esq = esq->GirarEsquerda();
			return this->GirarDireita();
		}
	}

	if(p_total == 2){
		if(dir->p_total == 1)
			return this->GirarEsquerda();
		else{						
			dir = dir->GirarDireita();
			return this->GirarEsquerda();
		}
	}


	//cout << '\n';
	//Se estiver balanceada, simplesmente se retorna
	return this;
}

ArvoreAVL* ArvoreAVL::GirarEsquerda(){
	ArvoreAVL *aux = dir->esq;
	ArvoreAVL *aux1 = dir;


	//Balanceia as cargas antes de mudar tudo
//	this->p_dir--;
//	dir->p_esq++;
//	this->p_total--;
//	dir->p_total--;


	dir->esq = this;
	this->dir = aux;
	aux1->Balancear();
	//cout << "\n\nESQUERDA\n";
	aux1->DisplayArvore();
	//cout << "\n\n";
	return aux1;
}

ArvoreAVL* ArvoreAVL::GirarDireita(){
	ArvoreAVL *aux = esq->dir;
	ArvoreAVL *aux1 = esq;
	
	
	//Balanceia as cargas antes de mudar tudo
//	this->p_esq--;
//	esq->p_dir++;
//	this->p_total++;
//	dir->p_total++;

	//aux1->Balancear();

	esq->dir = this;
	this->esq = aux;


	aux1->Balancear();
	//cout << "\n\nDIREITA\n";
	aux1->DisplayArvore();
	//cout << "\n\n";
	return aux1; 
}

void ArvoreAVL::DisplayArvore(){
	if(esq != NULL)
		esq->DisplayArvore();

	//cout <<'\n' << this->num << " p_dir = " << this->p_dir << " p_esq = " << this->p_esq;
	if(dir != NULL && esq != NULL)
		//cout <<'\n' << "dir = " << dir->num << "    esq = " << esq->num ;
	
	if(dir != NULL && esq == NULL)
		//cout <<'\n' << "dir = " << dir->num << "    esq = VAZIO";
	if(dir == NULL && esq != NULL)
		//cout << '\n'<< "dir = VAZIO" << "     esq = "<<esq->num;

	if(dir != NULL)
		dir->DisplayArvore();
		
}

int ArvoreAVL::Balancear(){
	if(esq != NULL)
		p_esq = esq->Balancear() + 1;
	else
		p_esq = 0;
	if(dir != NULL)
		p_dir = dir->Balancear() + 1;
	else
		p_dir = 0;

	p_total = p_dir - p_esq;
	
	if(p_dir > p_esq)
		return p_dir;
	else
		return p_esq;
}


bool ArvoreAVL::ProcurarElemento(int num){
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
	
ArvoreAVL* ArvoreAVL::DeletarElemento(int num){
	
}

