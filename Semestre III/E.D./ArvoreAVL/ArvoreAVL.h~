#ifndef ARVORE_AVL
#define ARVORE_AVL

#include <iostream>
using namespace std;

class ArvoreAVL{
	private:
		int p_dir;
		int p_esq;
		int num;
		ArvoreAVL *dir;
		ArvoreAVL *esq;
	public:
		ArvoreAVL(int num);					//Construtor
		ArvoreAVL* InserirElemento(int num);			//Insere o elemento com valor num na árvore AVL
		ArvoreAVL* GirarEsquerda();				//Realiza a rotação para a esquerda
		ArvoreAVL* GirarDireita();				//Realiza a rotação para direita
		ArvoreAVL* Balancear();					//Balanceia a árvore AVL
		bool ProcurarElemento(int num);				//Procura um elemento com valor num na árvore AVL
		ArvoreAVL* RetirarElemento(int num);			//Retira o elemento com valor num da árvore AVL
		ArvoreAVL* Atualizar();					//Atualiza a árvore pós-remoção para balanceá-la novamente
		ArvoreAVL* DeletarElemento(int num);			//Retira e balanceia 
		void DestruirArvore();				//Destrói a árvore AVL
		void DisplayArvore();					//Mostra todos os elementos da árvore
};

#endif
