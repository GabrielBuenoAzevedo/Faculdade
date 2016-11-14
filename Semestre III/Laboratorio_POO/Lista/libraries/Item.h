#ifndef Item_H
#define Item_H

#include<iostream>
#include<clocale>
#include<ctime>
#include<cstdlib>
#include<iomanip>

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
		float Preco;
		
	public:
		Item();
		void setPreco(float Preco);
		float getPreco();
		void setID(int ID);
		int getID();
		char* getNome();
		void setNome(char* Nome);
		void displayInfo();
};

//Método Construtuor da classe
Item::Item(){
	
	time_t t = time(0);
	ID = t;
	cout<<"ID = "<<ID<<endl;
	
	cout<<"Nome do Produto: ";
	cin.getline(Nome, 100);
	cin.clear();
	
	cout<<"Preço do produto: ";
	cin>>Preco;
	cin.ignore();
	
}

//Método para exibir as informações
void Item::displayInfo(){
	cout<<"\nProduto: "<<ID
		<<"\n"<<Nome
		<<"\nR$"<<Preco<<endl;
}

void Item::setPreco(float Preco){
	this->Preco = Preco;
}

float Item::getPreco(){
	return Preco;
}

int Item::getID(){
	return ID;
}

void Item::setID(int ID){
	this->ID = ID;
}

char* Item::getNome(){
	return Nome;
}

void Item::setNome(char* Nome){
	strcpy(this->Nome,Nome);
}

#endif
