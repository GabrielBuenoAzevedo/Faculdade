#include "libraries/Fila.h"
#include "libraries/Pedido.h"

#include<ctime>
#include <time.h>
#include <limits.h>
using namespace std;

int main(){
	Fila<Pedido> *Pedidos = new Fila<Pedido>();
	Fila<Pedido> *Atendidos = new Fila<Pedido>();
	Fila<Pedido> *aux = new Fila<Pedido>();

	Pedido *Novo;
	Pedido *MaisDemorado = NULL;
	Pedido *MaisRapido = NULL;

	time_t DataFin;
	time_t TempoTotal = 0;
	
	float TempoMedioAtendimento;

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
			  "[6] Ver lista de atendimentos concluídos\n" << \
			  "[7] Ver quantidade média de tempo nos atendimentos\n" << \
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
					Atendidos->Enfileirar( (Pedidos->getFirst()));
					aux->Enfileirar( (Pedidos->getFirst()));

					//Setar a data final atualizada
					DataFin = time(0);

					Pedidos->getFirst()->setDataFinal(DataFin);
					Pedidos->getFirst()->display();



					data = ctime(&DataFin); //Data final formatada
					cout << "Data Final: " << data << endl;
					time_t TempoDecorrido;
					TempoDecorrido = Pedidos->getFirst()->getDataFinal() - Pedidos->getFirst()->getDataInicio();
					cout<<"Tempo Decorrido: "<<TempoDecorrido<<"Segundos\n\n";

					TempoTotal+=TempoDecorrido;

					//Inicializa o MaisDemorado e MaisRapido caso estiverem vazios
					if(MaisDemorado == NULL){
						MaisDemorado = MaisRapido = Novo;
					}


					
					//Verificar se o elemento atual é o mais demorado ou mais rápido até o momento atual
					if( ( Pedidos->getFirst()->getTempoAtendimento() ) > ( MaisDemorado->getTempoAtendimento() ) )
						MaisDemorado = Atendidos->getFirst();
					else if( (Pedidos->getFirst()->getTempoAtendimento() ) < ( MaisRapido->getTempoAtendimento() ) )
						MaisRapido = Atendidos->getFirst();
					
					//Verifica se o elemento atual é o mais demorado ou mais rápido e atualiza a variável da classe
					Pedidos->Desenfileirar();
				}else{														
					cout << "Não existe nenhum pedido atualmente!\n";
				}
				break;
			case 3:
				if(Pedidos->getFirst() != NULL){
					cout<<"STATUS ALTERADO"<<endl;
					Pedidos->getFirst()->setStatus("Com Problemas");
					Pedidos->getFirst()->display();
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
				while(aux->getFirst() != NULL){
					aux->getFirst()->display();
					aux->Desenfileirar();
				}
				break;
			case 7:
				cout << Atendidos->getQntd() << endl;
				TempoMedioAtendimento = TempoTotal/Atendidos->getQntd();
				cout << "O tempo médio de atendimento é " << TempoMedioAtendimento << endl;
				break;
			default: cout << "Opção inválida escolhida!\n";
		}

	}while(0 <= opcao && opcao <= 8);

}
