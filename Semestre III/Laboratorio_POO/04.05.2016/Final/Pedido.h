#ifndef Pedido_H
#define Pedido_H

#include <iostream>
#include<ctime>
#include<clocale>
#include <iomanip>
#include<cstdlib>
#include<iomanip>
#include<cstring>
#include <time.h>

using namespace std;

class Pedido
{
	protected:
		time_t DataInicio;
		int codCupom;
		char Descricao[200];
		float Valor;
		char Status[50];
		time_t DataFinal;
		time_t TempoAtendimento;		

	public:
		Pedido();
		void setStatus(char *Status);
		char *getStatus();
		int getCodCupom();
		void setDataFinal(time_t DataFinal);
		time_t getDataInicio();
		time_t getDataFinal();
		void display();
		void calcTempoAtendimento();		//Calcula o tempo de atendimento do pedido
		time_t getTempoAtendimento();		//Retorna o tempo de atendimento do pedido
};

//Construtor da classe pedido
Pedido::Pedido()
{
	DataInicio = time(0);
	DataFinal = 0;
	TempoAtendimento = 0;
		
	codCupom = DataInicio;

	cout << "\nDescriçao: ";
	cin.ignore();
	cin.getline(Descricao, 200);
	cin.clear();

	cout << "\nValor: ";
	cin >> Valor;
	cin.ignore();

	strcpy(Status,"Em Aberto");
}

//Metodos de pedido
void Pedido::setStatus(char *Status)
{
    strcpy(this->Status,Status);
}

char *Pedido::getStatus()
{
	return Status;
}

int Pedido::getCodCupom()
{
	return codCupom;
}

void Pedido::setDataFinal(time_t DataFinal) //receber data final quando elemento for retirado da fila
{
	this -> DataFinal = DataFinal;
	calcTempoAtendimento();
}

time_t Pedido::getDataInicio()
{
	return DataInicio;
}

time_t Pedido::getDataFinal()
{
	return DataFinal;
}

void Pedido::display()
{
	char *data;
	data = ctime(&DataInicio);
	cout << "\nCodigo do Cupom: " << codCupom
		 << "\nDescrição: " << Descricao
		 << "\nValor: R$" << Valor
		 << "\nStatus: " << Status
		 << "\nData Inicio: " << data; //Impressão da data inicio formatada

//	data = ctime(&DataFinal);
//	cout << "\nData Final: " << data << endl;
}

void Pedido::calcTempoAtendimento(){
	TempoAtendimento = Pedido::DataFinal - Pedido::DataInicio;
}

time_t Pedido::getTempoAtendimento(){
	return Pedido::TempoAtendimento;
}

#endif
