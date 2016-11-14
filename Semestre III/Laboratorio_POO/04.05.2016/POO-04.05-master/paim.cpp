#include "libraries/Fila.h"
#include "libraries/Pedido.h"

#include<ctime>
#include <time.h>

using namespace std;

int main(){
	Fila<Pedido> *Pedidos = new Fila<Pedido>();
	Fila<Pedido> *Atendidos = new Fila<Pedido>();
	Pedido *Novo;

	time_t DataFin;
	char *data;

	int opcao=0;
	do{
		//system("clear");
		cout<<"----------------------------------------"<<endl;
		cout << "\nSelecione a opção que deseja escolher\n \
[1] Adicionar Pedido\n \
[2] Atender Pedido\n \
[3] Declarar Pedido com problemas\n \
[4] Sair\n\n\
Opcao: ";
		cin >> opcao;
		system("clear");

		switch(opcao){
			case 1:
				cout<<"NOVO PEDIDO"<<endl;
				Novo = new Pedido();
				system("clear");
				Pedidos->Enfileirar(Novo);
				cout<<"PEDIDO ADICIONADO"<<endl;
				Novo->display();
				break;
			case 2:
				if(Pedidos->getFirst() != NULL){
				cout << "PEDIDO ATENDIDO"<<endl;
				Pedidos->getFirst()->setStatus("Finalizado");
				Atendidos->Enfileirar( (Pedidos->getFirst()));

				//Setar a data final atualizada
				DataFin = time(0);

				Pedidos->getFirst()->setDataFinal(DataFin);
				Pedidos->getFirst()->display();



				data = ctime(&DataFin); //Data final formatada
				cout << "Data Final: " << data << endl;
				time_t TempoDecorrido;
				TempoDecorrido = Pedidos->getFirst()->getDataFinal() - Pedidos->getFirst()->getDataInicio();
				cout<<"Tempo Decorrido: "<<TempoDecorrido<<"Segundos\n\n";
				Pedidos->Desenfileirar();
				} else cout <<"Lista vazia\n";
				//cin.getLine();
				break;
			case 3:
				cout<<"STATUS ALTERADO"<<endl;
				Pedidos->getFirst()->setStatus("Com Problemas");
				Pedidos->getFirst()->display();
				Pedidos->Enfileirar( (Pedidos->getFirst()));
				Pedidos->Desenfileirar();
				break;
			case 4:
				cout << "Saindo do sistema\n";
				break;
			default: cout << "Opção inválida escolhida!\n";
		}

	}while(0 <= opcao && opcao <= 3);

}
