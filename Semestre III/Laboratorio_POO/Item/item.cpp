#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <cmath>
#include <ctime>

#include <cstdlib>
#include <iomanip>

using std::ios;
using std::setiosflags;
using std::setprecision;
using std::setw;

class Item{
private:
	int Id;
	char Nome[100];
	char Descricao[500];
	int DataVal[3];				//[0] -> dia     [1] -> mês     [2] -> ano
	float Preco;
	int Qntd;
	float Desconto;

public:
	Item();
	void setPreco(float);
	float getPreco();
	void setDesconto(float);
	float getDesconto();
	void setQuantidade(int);
	int getQuantidade();
	float calculaPrecoTotal();
	bool verificaValidade();
	void displayInfo();
};

void Item::setPreco(float preco){
	Preco=preco;
}

float Item::getPreco(){
	return Preco;
}

void Item::setDesconto(float desc){
	if(desc <= 100)
		Desconto = desc/100;					//Pega a porcentagem e transforma em decimal.
	else
		cout << "Valor inválido. Produto ficará sem desconto." << endl;
}

float Item::getDesconto(){
	return Desconto*100;						//Retorna a porcentagem normal.
}

void Item::setQuantidade(int qnt){
	Qntd = qnt;
}

int Item::getQuantidade(){
	return Qntd;
}

float Item::calculaPrecoTotal(){
	float Pr_total = 0;						//Preço total que será retornado
	Pr_total = Qntd*Preco*(1-Desconto);	 
	return Pr_total;
}

bool Item::verificaValidade(){
	int DataHoje[3];				//Data de hoje    [0] -> Dia		[1] -> Mês		[2] -> Ano
	time_t t = time(0);
	struct tm * now = localtime( & t);
	DataHoje[0] = now->tm_mday;
	DataHoje[1] = now->tm_mon + 1;
	DataHoje[2] = now->tm_year + 1900;

	if((DataHoje[0] <= DataVal[0]) && (DataHoje[1] <= DataVal[1]) && (DataHoje[2] <= DataVal[2]))
		return false;
	else
		return true;
}

void Item::displayInfo(){
	cout << "\nINFORMAÇÕES SOBRE O PRODUTO\n" \
	     << "Nome: " << Nome << endl \
	     << "Preço: " << Preco << endl \
	     << "Data de Validade: " << DataVal[0] << '/' << DataVal[1] << '/' << DataVal[2] << endl \
	     << "Desconto: " << getDesconto() << '%' << endl \	
	     << "Descrição: " << Descricao << endl;
}

Item::Item(){
	//cin.ignore();

	cout << "Coloque a identificação do produto: ";
	cin >> Id;

	cout << "Coloque o nome do produto: ";
	cin.ignore();	
	cin.getline(Nome,100);

	cout << "Dê uma breve descrição com menos de 500 caracteres para o produto: " << endl;
	//cin.ignore();	
	cin.getline(Descricao,500);

	cout << "O produto é válido até: ";
	char c;
	cin >> DataVal[0] >> c >> DataVal[1] >> c >> DataVal[2];
}


int main(){
	Item *I1 = new Item();
	int qnt;
	
	cout << setiosflags(ios::fixed | ios::showpoint) << setprecision(2);

	cout << "Coloque o preço do produto: ";
	float Preco;
	cin >> Preco;
	I1->setPreco(Preco);

	cout << "Coloque o desconto do produto: ";
	float Desc;
	cin >> Desc;
	I1->setDesconto(Desc);

	cout << "Coloque a quantidade de itens que deseja comprar: ";
	cin >> qnt;
	I1->setQuantidade(qnt);
 
	I1->displayInfo();

	if(I1->verificaValidade())
		cout 	<< "\n///////////////////////////////////////////////" \
			<< "\n///O PRODUTO ESTÁ FORA DA DATA DE VALIDADE!!///" \
		        << "\n///////////////////////////////////////////////" << endl;

	cout << "O preço total pelo(s) produto(s) é " << I1->calculaPrecoTotal() << "!!!\n";
}
