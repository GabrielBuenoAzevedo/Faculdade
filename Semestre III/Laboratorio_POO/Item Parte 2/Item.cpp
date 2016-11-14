#include "Item.h"

//Método Construtor da classe
Item::Item(){
	time_t t = time(0);
	ID = t;
	cout<<"ID = "<<ID<<endl;
	cout<<"Nome do Produto: ";
	cin.ignore();
	cin.getline(Nome, 100);
	cout<<"Descricao do Produto: ";
	cin.getline(Desc, 100);
	cout<<"Validade [dd/mm/aaaa]: ";
	cin.getline(Validade, 11);
	
	prox = NULL;
}

void Item::updateItem(){
		int Opcao;
		float NovoPreco;
		int NovaQntdd;
		char NovoNome[100];
		bool Continua = true;	
	
	cout << "Informações anteriores desse item: \n";
	displayInfo();

	do{
		cout << "Escolha a opção que deseja atualizar:\n" \
		     << "[1] - Preço\n"\
		     << "[2] - Quantidade de Itens\n" \
	  	     << "[3] - Nome\n" \
		     << "[4] - Sair\n" << endl;
		
		cin >> Opcao;

		switch(Opcao){
			case 1:
				cout << "Entre o novo preço: ";
				cin >> NovoPreco;
				setPreco(NovoPreco);
				cout << "O preço foi mudado para " << NovoPreco << endl;
				break;
			case 2:
				cout << "Entre a nova quantidade de itens: ";
				cin >> NovaQntdd;
				setQuantidade(NovaQntdd);
				cout << "A quantidade de itens foi mudada para " << Qtdd << endl;
				break;
			case 3:
				cout << "Entre o novo nome: ";
				cin.ignore();
				cin.getline(Nome,100);
				cout << "O nome foi mudado para " << Nome << endl;
				break;
			case 4: 
				Continua = false;
				break;					
			default: cout << "Entrada inválida, tente novamente." << endl;
			}	
		}while(Continua);

		cout << "\nEssas são as novas informações do item: "<<endl;
		displayInfo();
}

//Método para exibir as informações
void Item::displayInfo(){
	cout<<"\nProduto: "<<ID
		<<"\n"<<Nome<<" - "<<Desc
		<<"\nVálido até: "<<Validade
		<<"\nQuantidade: "<<Qtdd
		<<"\nR$"<<Preco<<" - Desconto: "<<Desconto<<"%"<<endl;
}

void Item::setPreco(float Preco){
	this->Preco = Preco;
}

float Item::getPreco(){
	return Preco;
}

void Item::setDesconto(float Desconto){
	this->Desconto = Desconto;
}

float Item::getDesconto(){
	return Desconto;
}

void Item::setQuantidade(int Qtdd){
	this->Qtdd = Qtdd;
}

int Item::getQuantidade() {
	return Qtdd;
}

float Item::calculaPrecoTotal(){
	float precoFinal;
	
	precoFinal = Qtdd*(Preco - Preco*(Desconto/100));
	
	return precoFinal;
}

float Item::calculaPrecoTotal(int min){
	float precoFinal;
	
	if(Qtdd >= min)
		precoFinal = Qtdd*Preco*(1-Desconto/100);
	else
		precoFinal = Qtdd*Preco;
	return precoFinal;
}

char* Item::getNome(){
	return Nome;
}

bool Item::verificaValidade(){
	int dia, mes, ano;
	bool eValido = true;
	time_t t = time(0);   // obter a hora atual
    struct tm *now = localtime( & t );
	
	dia = atoi(Validade);
	mes = atoi(&Validade[3]);
	ano = atoi(&Validade[6]);
	
	if((now->tm_year+1900) > ano){
		eValido = false;
	}
	else if((now->tm_year+1900) == ano && (now->tm_mon+1) > mes) {
		eValido = false;
	}
	else if((now->tm_year+1900) == ano && (now->tm_mon+1) == mes && now->tm_mday > dia) {
		eValido = false;
	}
	return eValido;
}

