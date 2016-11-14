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

class Item 
{
	private:
		int ID;
		char Nome[100];
		char Desc[100];
		char Validade[11];
		float Preco;
		int Qtdd;
		float Desconto;
		
	public:
		Item *prox;
		Item();
		void setPreco(float Preco);
		float getPreco();
		void setDesconto(float Desconto);
		float getDesconto();
		void setQuantidade(int Qtdd);
		int getQuantidade();
		char* getNome();
		void setNome();
		float calculaPrecoTotal();
		float calculaPrecoTotal(int min);
		bool verificaValidade();
		void displayInfo();
		void updateItem();
};
