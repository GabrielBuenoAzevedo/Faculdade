#ifndef ARVORE_BIN
#define ARVORE_BIN

#include <iostream>
using namespace std;

class ArvoreBin{
	private:
		ArvoreBin *dir;
		ArvoreBin *esq;
		int num;
	public: 
		ArvoreBin(int num);						//Construtor
		void InserirElemento(int num);					//Insere elemento na árvore binária
		ArvoreBin* DeletarElemento(int num);				//Deleta elemento com valor num da árvore
		bool ProcurarElemento(int num);					//Procura elemento com valor num na árvore
		void DestruirArvore();						//Destrói todos os elementos da árvore
		void DisplayArvore();						//Mostra todos os elementos da árvore.
};


#endif
