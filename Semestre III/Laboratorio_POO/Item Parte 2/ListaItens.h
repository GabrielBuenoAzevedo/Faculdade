#include "Item.h"

#include<iostream>
//#include<clocale>
#include<ctime>
#include<cstdlib>
#include<iomanip>
#include<cstring>

using std::cout;
using std::cin;
using std::endl;
using std::ios;

using std::setw;
using std::setiosflags;
using std::setprecision;

class ListaItens {
		private:
			Item *Lista;			//Estoque
			Item *ListaCompras;
			float PrecoCompra;
		public:
			ListaItens();
			void inserir();
			Item* consultarItem(char Nome[]);
			void excluirItem(char Nome[]);
			float valorTotal();
			void imprimirLista();
			void emiteBoleto();
};



