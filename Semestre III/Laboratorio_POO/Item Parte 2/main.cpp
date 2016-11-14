#include "ListaItens.h"

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

