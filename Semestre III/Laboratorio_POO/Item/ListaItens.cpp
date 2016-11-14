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


int main () {
	setlocale(LC_ALL, "portuguese");
	cout<<setiosflags(ios::fixed | ios::showpoint)<<setprecision(2);
	int op;
	ListaItens *L = new ListaItens();
	do{
		cout<<"Deseja terminar? [0] - Sim, [1] - Não ";
		cin>>op;
		
		if(op){
			L->inserir();
		}
	}while(op!=0);

	char Nome[101];	
	Item *aux;
	do{
		cout<<"Deseja editar algo? [0] - Não, [1] - Sim ";
		cin>>op;
		
		if(op){
			cout << "Entre o nome do item que deseja editar: ";
			cin.ignore();
			cin.getline(Nome,100);
			aux = L->consultarItem(Nome);
				if(aux == NULL)
					cout << "Elemento não foi achado na lista!\n";
				else
					aux->updateItem();		
		}	
	}while(op!=0);
	
	do{
		cout<<"Deseja deletar algo? [0] - Não, [1] - Sim ";
		cin>>op;
		
		if(op){
			cout << "Entre o nome do item que deseja deletar: ";
			cin.ignore();
			cin.getline(Nome,100);
			L->excluirItem(Nome);
		}	
	}while(op!=0);


	system("cls");
	cout<<"Itens Comprados\n"<<endl;
	L->imprimirLista();
	

	system("pause");
	
	return 0;
}

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
	
	if(Qntdd >= min)
		precoFinal = Qntdd*(preco*(1-desconto(100));
	else
		precoFinal = Qntdd*preco;
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

ListaItens::ListaItens(){
	Lista = NULL;
	ListaCompras = NULL;
}

void ListaItens::compraItem(){
	cout << "Digite o nome do produto que deseja comprar: ";
	char NomeProduto[100];
	cin.getline(NomeProduto,100);
	
	Item *aux;
	aux = consultarItem(NomeProduto);

	if(aux == NULL)
		cout << "Produto não foi encontrado no estoque!" << endl;
	else{
		aux->displayInfo();

		do{
		cout << "\nEntre o número de unidades que deseja comprar: ";
		int QtddProdutos;
		cin >> QntddProdutos;
		if(QntddProdutos > aux->Qtdd)
			cout << "O número de itens é maior que o do estoque!\nTente novamente." << endl;
		}while(QntddProdutos > aux->Qtdd);		

		adicionaCompra(QntddProdutos);

	}
}

void ListaItens::adicionaCompra(int QntddProdutos, Item *ProdutoEstoque){
	Item *Novo = new Item();
	Novo->setPreco(ProdutoEstoque->getPreco());
	Novo->setQntdd(QntddProdutos);
	Novo->setDesconto(ProdutoEstoque->getDesconto());
	precoVenda += Novo->getPreco()*(1-(Novo->getDesconto()/100));
	
	Novo->prox = ListaCompras;
	ListaCompras = Novo;
}

void ListaItens::EmiteBoleto(){
	
}

void ListaItens::inserir(){
	Item *Novo = new Item();
	if(Novo->verificaValidade()) {
		cout<<"\nInforme o preço do item: ";
		float preco;
		cin>>preco;
		Novo->setPreco(preco);
	
		cout<<"\nInforme o desconto: ";
		float desconto;
		cin>>desconto;
		Novo->setDesconto(desconto);
		
		cout<<"\nInforme a quantidade: ";
		int Qtdd;
		cin>>Qtdd;
		Novo->setQuantidade(Qtdd);
		
		Novo->prox = Lista;
		Lista = Novo;
	}
	else
		cout<<"\n O item está fora da validade e não pode ser inserido\n\n";
}

void ListaItens::imprimirLista(){
	Item *aux;
	
	aux = Lista;
	while(aux!=NULL){
		cout<<"\n";
		aux->displayInfo();
		aux = aux->prox;
	}
}

float ListaItens::valorTotal(){
	float total=0;
	Item *aux;
	
	aux=Lista;
	while(aux!=NULL){
		total += aux->calculaPrecoTotal();
		aux=aux->prox;
	}
	return total;
}

Item* ListaItens::consultarItem(char Nome[]){
	Item *aux;
	aux = Lista;

	while(aux != NULL){
	if(std::strcmp(aux->getNome(),Nome) == 0)
		return aux;

	aux = aux->prox;
	}

	return NULL;	
}

void ListaItens::excluirItem(char Nome[]){
	Item *aux;
	Item *auxProx;
	
	aux = Lista;
	auxProx = aux->prox;

	if(auxProx == NULL && strcmp(aux->getNome(),Nome)==0){
		cout << '\n' << Nome << " EXCLUÍDO COM SUCESSO!\n";
		delete(aux);
		Lista=NULL;
		}

	while(auxProx != NULL){
		if(strcmp(auxProx->getNome(),Nome) == 0){			
			aux->prox = auxProx->prox;
			cout << '\n'<< Nome << " EXCLUÍDO COM SUCESSO!\n";
			delete(auxProx);
			}
	aux = aux->prox;
	auxProx = auxProx->prox;
	}

	if(auxProx == NULL && Lista != NULL)
		cout << "\n\nElemento não foi achado na lista!!!!!!!\n";
}











