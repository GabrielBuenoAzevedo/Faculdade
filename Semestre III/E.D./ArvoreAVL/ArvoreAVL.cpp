#include "ArvoreAVL.h"

//Grande parte do código foi baseada nos códigos do livro Estruturas de dados: algoritmos, análise da complexidade e implementações em JAVA e C/C++
//de Ana Fernanda Gomes Ascencio e Graziela Santos de Araújo, publicado pela editora Pearson.

//Apesar de ter me baseado nesses códigos para a implementação da árvore AVL, tive que fazer adaptações em todo o código para o mesmo aceitar a
//P.O.O. e ficar do jeito que eu queria.

//Fiz assim apenas porque foi permitida o uso dos códigos no caderno.


ArvoreAVL::ArvoreAVL(int num){						//Construtor
	p_dir = 0;
	p_esq = 0;
	this->num = num;
	dir = NULL;
	esq = NULL;
}

ArvoreAVL* ArvoreAVL::GirarEsquerda(){					//Realiza a rotação para a esquerda
	ArvoreAVL* aux1;
	ArvoreAVL* aux2;

	aux1 = this->dir;					
	aux2 = aux1->esq;

	this->dir = aux2;
	aux1->esq = this;

	if(this->dir == NULL)						
		this->p_dir = 0;
	else if (this->dir->p_esq > this->dir->p_dir)
		this->p_dir = this->dir->p_esq + 1;
	else
		this->p_dir = this->dir->p_dir + 1;

	if(aux1->esq->p_esq > aux1->esq->p_dir)
		aux1->p_esq = aux1->esq->p_esq + 1;
	else
		aux1->p_esq = aux1->esq->p_dir + 1;

	return aux1;
}

ArvoreAVL* ArvoreAVL::GirarDireita(){					//Realiza a rotação para direita
	ArvoreAVL *aux1;
	ArvoreAVL *aux2;

	aux1 = this->esq;
	aux2 = aux1->dir;

	this->esq = aux2;
	aux1->dir = this;
	
	if(this->esq == NULL)
		this->p_esq = 0;
	else if (this->esq->p_esq > this->esq->p_dir)
		this->p_esq = this->esq->p_esq + 1;
	else
		this->p_esq = this->esq->p_dir + 1;

	if(aux1->dir->p_esq > aux1->dir->p_dir)
		aux1->p_dir = aux1->dir->p_esq + 1;
	else
		aux1->p_dir = aux1->dir->p_dir + 1;

	return aux1;
}

ArvoreAVL* ArvoreAVL::Balancear(){					//Balanceia a árvore AVL
	int p_total, p_final;
	p_total = p_dir - p_esq;					//Verifica o peso/altura da árvore atual
									//Se for igual a 2 ou -2, precisa fazer rotação
	if(p_total == 2){						
		p_final = dir->p_dir - dir->p_esq;
		
		if(p_final >= 0){					
			return this->GirarEsquerda();
		}else{
			this->dir = dir->GirarDireita();
			return this->GirarEsquerda();
		}
	}
	else if(p_total == -2){
		p_final = esq->p_dir - esq->p_esq;
		
		if(p_final <=0){
			return this->GirarDireita();
		}else{
			this->esq = esq->GirarEsquerda();
			return this->GirarDireita();
		}
	}
	return this;
}


ArvoreAVL* ArvoreAVL::InserirElemento(int num){				//Insere o elemento com valor num na árvore AVL
	if(num < this->num){						//Se num for menor que o valor do elemento atual, tenta inserir na esquerda
		if(esq == NULL)					
			esq = new ArvoreAVL(num);
		else{							
		esq = esq->InserirElemento(num);
		}
		if(esq->p_dir > esq->p_esq)
			p_esq = esq->p_dir+1;
		else
			p_esq = esq->p_esq+1;
		
		return this->Balancear();
	}else{								//Se num for maior ou igual ao valor do elemento atual, tenta inserir na
		if(dir == NULL)						//direita
			dir = new ArvoreAVL(num);
		else
			dir = dir->InserirElemento(num);
		
		if(dir->p_dir > dir->p_esq)
			p_dir = dir->p_dir+1;
		else
			p_dir = dir->p_esq+1;
		
		return this;
	}
}


bool ArvoreAVL::ProcurarElemento(int num){			//Procura um elemento com valor num na árvore AVL
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

void ArvoreAVL::DisplayArvore(){			//Mostra todos os elementos da árvore com seus respectivos pesos e com o elemento direito
	if(esq != NULL)					//e esquerdo
		esq->DisplayArvore();			//***USADO PARA TESTES PARA CONFIRMAR QUE A ÁRVORE ESTAVA FUNCIONANDO DEVIDAMENTE***

	cout <<'\n' << this->num << " p_dir = " << this->p_dir << " p_esq = " << this->p_esq;
	if(dir != NULL && esq != NULL)
		cout <<'\n' << "dir = " << dir->num << "    esq = " << esq->num ;
	
	if(dir != NULL && esq == NULL)
		cout <<'\n' << "dir = " << dir->num << "    esq = VAZIO";
	if(dir == NULL && esq != NULL)
		cout << '\n'<< "dir = VAZIO" << "     esq = "<<esq->num;

	if(dir != NULL)
		dir->DisplayArvore();
		
}

ArvoreAVL* ArvoreAVL::RetirarElemento(int num){		//Retira o elemento com valor num da árvore AVL
	ArvoreAVL *aux1;				//***NESSA FUNÇÃO NÃO É FEITO O BALANCEAMENTO***
	
	if(this->num == num){
		if(esq == NULL && dir == NULL){		//Elemento não tem sub-árvore
			delete(this);
			return NULL;
		}
		if(dir == NULL){			//Elemento não tem sub-árvore direita
			aux1 = esq;
			delete this;
			return aux1;
		}
		if(esq == NULL){			//Elemento não tem sub-árvore esquerda
			aux1 = dir;
			delete this;
			return aux1;
		}
							//Elemento tem ambas as sub-árvores
		aux1 = dir;
		while(aux1->esq != NULL)
			aux1 = aux1->esq;

		aux1->esq = esq;
		aux1 = dir;

		delete this;
		return aux1;
	}
	if(num < this->num){
		if(esq != NULL)			
			esq = esq->RetirarElemento(num);
	}
	else{
		if(dir != NULL)
		dir = dir->RetirarElemento(num);
	}
	return this;
}

ArvoreAVL* ArvoreAVL::Atualizar(){				//Atualiza a árvore pós-remoção para balanceá-la novamente
	if(esq == NULL)
		p_esq = 0;
	else{
		if(esq->p_esq > esq-> p_dir)			//Pega a maior altura (direita ou esquerda) do elemento esquerdo e adiciona 1
			p_esq = esq->p_esq + 1;
		else
			p_esq = esq->p_dir + 1;
	}

	if(dir == NULL)
		p_dir = 0;
	else{
		if(dir->p_esq > dir->p_dir)			//Pega a maior altura (direita ou esquerda) do elemento direito e adiciona 1
			p_dir = dir->p_esq + 1;
		else
			p_dir = dir->p_dir + 1;
	}				

	return this->Balancear();
}

ArvoreAVL* ArvoreAVL::DeletarElemento(int num){			//Retira um elemento, depois atualiza com o (talvez) novo endereço e retorna a
	return (RetirarElemento(num)->Atualizar());		//árvore atualizada
}

void ArvoreAVL::DestruirArvore(){				//Destrói árvore
	if(esq != NULL)
		esq->DestruirArvore();
	if(dir != NULL)
		dir->DestruirArvore();
	delete(this);
}
