#include "Fila.h"
#include "Pedido.h"

#include<ctime>
#include <time.h>
#include <limits.h>
using namespace std;

int main(){
	Fila<Pedido> *Pedidos = new Fila<Pedido>();
	Fila<Pedido> *Atendidos = new Fila<Pedido>();
	Pedido *Novo;
	Pedido *MaisDemorado = NULL;
	Pedido *MaisRapido = NULL;
	int TempoTotal=0,NroAtendidos=0;

	time_t DataFin;
	char *data;

	int opcao=0;
	do{
		//system("clear");
		cout<<"----------------------------------------"<<endl;
		cout << "\nSelecione a opção que deseja escolher\n" << \
			  "[1] Adicionar Pedido\n" << \
			  "[2] Atender Pedido\n"  << \
			  "[3] Declarar primeiro pedido da fila com problemas\n" << \
			  "[4] Ver atendimento mais rápido \n" << \
			  "[5] Ver atendimento mais demorado\n" << \
			  "[6] Ver tempo médio de atendimento\n" << \
			  "[7] Sair\n" << \
			  "Opcao: ";
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

					//Enfileirando na fila de atendidos
					Atendidos->Enfileirar( (Pedidos->getFirst()));

					//Setar a data final atualizada
					DataFin = time(0);

					Pedidos->getFirst()->setDataFinal(DataFin);
					Pedidos->getFirst()->display();

					data = ctime(&DataFin); //Data final formatada
					cout << "Data Final: " << data << endl;

					time_t TempoDecorrido; //Tempo decorrido para atendimento do pedido
					TempoDecorrido = Pedidos->getFirst()->getDataFinal() - Pedidos->getFirst()->getDataInicio();
					cout<<"Tempo Decorrido: "<<TempoDecorrido<<" segundos\n\n";

					//Atualizando tempo total dos atendimentos e numero de Atendidos
					TempoTotal+=TempoDecorrido;
					NroAtendidos++;

					//Inicializa o MaisDemorado e MaisRapido caso estiverem vazios
					if(MaisDemorado == NULL && MaisRapido == NULL){
						MaisDemorado = MaisRapido = Novo;
					}

					//Verificar se o elemento atual é o mais demorado ou mais rápido até o momento atual
					if( ( Pedidos->getFirst()->getTempoAtendimento() ) > ( MaisDemorado->getTempoAtendimento() ) )
						MaisDemorado = Atendidos->getFirst();
					else if( (Pedidos->getFirst()->getTempoAtendimento() ) < ( MaisRapido->getTempoAtendimento() ) )
						MaisRapido = Atendidos->getFirst();

					//Desenfileirando da lista de pedidos em aberto
					Pedidos->Desenfileirar();
				}
				else
					cout << "Não existe nenhum pedido atualmente!\n";
				break;
			case 3:
				if(Pedidos->getFirst() != NULL){
					cout<<"STATUS ALTERADO"<<endl;
					Pedidos->getFirst()->setStatus("Com Problemas");
					Pedidos->getFirst()->display();
					//Levando pedido com problemas do começo para o fim da fila
					Pedidos->Enfileirar( (Pedidos->getFirst()));
					Pedidos->Desenfileirar();
				}
				else
					 cout << "Não existe nenhum pedido atualmente!\n";
				break;
			case 4:
				if(MaisRapido != NULL)
					MaisRapido->display();
				else
					cout << "Nenhum cliente ainda foi atendido!\n";
				break;
			case 5:
				if(MaisDemorado != NULL)
					MaisDemorado->display();
				else
					cout << "Nenhum cliente ainda foi atendido!\n";
				break;
			case 6:
				cout<<"TEMPO MÉDIO DE ATENDIMENTO"<<endl;
				cout<<(TempoTotal/NroAtendidos)<<" segundos"<<endl;
				break;
			default: cout << "Opção inválida escolhida!\n";
		}

	}while(0 <= opcao && opcao <= 8);

}
