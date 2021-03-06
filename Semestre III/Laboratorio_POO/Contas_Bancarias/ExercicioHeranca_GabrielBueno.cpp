/*
Nome: Julio Cesar Momente
Disciplina - Lab de POO e Lab de ED
*/


#include <string.h>
#include <iostream>
#include<ctime>
using std::cin;
using std::cout;
using std::ios;    //manipula o cout, para que a saida deja no formato monetario
using std::endl;

//biblioteca para manipular cout
#include <iomanip>
using std::setprecision; //funcao para determinar numero de casas decimais
using std::setiosflags;  //manipula cout para que a saida seja no formato monetario


#include <cstdlib>
using std::atoi;

//superclasse - informa�oes comuns
class Conta_Bancaria {
      protected:
          char Nome[50];
          int Agencia;
          int NroConta;
          float Saldo;
      public:
          Conta_Bancaria();
          virtual void Cadastro();
	  virtual float getSaldo();
	  virtual bool deposito(float valor);
	  virtual bool saque(float valor);			
};

// Construtor
Conta_Bancaria::Conta_Bancaria() {
      strcpy (Nome, " ");
      Agencia = 0;
	  NroConta=0;
      Saldo = 0.0;
      }

//entrada de valores pelo usuario
void Conta_Bancaria::Cadastro() {
      cout<<"\nAtencao, utilize sempre ponto (.) para separar casas decimais\n";
      cout<<"\nNome: ";   
	  cin.ignore();
	  cin.getline(Nome,50);
      cout<<"\nNumero da Ag�ncia: ";
	  cin>>Agencia;
      cout<<"\nNumero da Conta: ";
	  cin>>NroConta;
      cout<<"\nSaldo: ";   
	  cin>>Saldo;
	  
      }

//dep�sito
bool Conta_Bancaria::deposito (float valor) {
	if(valor>0) {
 		Saldo += valor;
 		return true;
 	} else {
 		return false;	
 	}
}

//saue
bool Conta_Bancaria::saque (float valor) {
     if(valor>0){
     	if(Saldo-valor>=0){
     		Saldo -= valor;
     		return true;
     	}
    }
    return false;
}

float Conta_Bancaria::getSaldo(){
	return Saldo;
}

//Subclasse - Conta Corrente
class Conta_Corrente:public Conta_Bancaria{
      private:
      	float Manutencao;
		int diaAniversario;
		int mesCobrado;
	  public:
          Conta_Corrente();
          void aplicarManutencao();
          void Cadastro();
          float getSaldo();
          
      };

//construtor
Conta_Corrente::Conta_Corrente():Conta_Bancaria(){
	Manutencao = 0;
	diaAniversario = 5;
	mesCobrado = 4;
}

void Conta_Corrente::aplicarManutencao(){
	time_t t = time(0);   // obter a hora atual
    struct tm *now = localtime( & t );
	int dia, mes;
	
	mes = now->tm_mon+1;
	dia = now->tm_mday;
	
	if(mes>mesCobrado && dia > diaAniversario)
		Saldo -=Manutencao;
}

float Conta_Corrente::getSaldo(){
	aplicarManutencao();
	return Saldo;	
}

//Cadastro da conta corrente
void Conta_Corrente::Cadastro(){
	Conta_Bancaria::Cadastro();
	cout<<"\nManutencao: ";   
	cin>>Manutencao;
}

//Subclasse Conta especial
class Conta_Especial:public Conta_Corrente {
      private:
          float limite, juros;
      public:
          Conta_Especial();
         virtual void Cadastro();
         virtual bool deposito (float valor);
         virtual bool saque(float valor);
      };

//construtor
Conta_Especial::Conta_Especial():Conta_Corrente() {
      limite=0.0;
      juros=0.0;
      }

//entrada de valores pelo usuario
void Conta_Especial::Cadastro() {
      Conta_Corrente::Cadastro();
      cout<<"\nLimite: ";   
	  cin>>limite;
      cout<<"\nJuros: ";   
	  cin>>juros;
      }
      
bool Conta_Especial::saque(float valor) {
      if(valor>0){
      	if(Saldo+limite-valor>=0){
      		Saldo -= valor;
      		return true;
      	}
      }
      return false;
}

//M�todo deposito
bool Conta_Especial::deposito(float valor) {
      if(valor>0){
      	if(Saldo<0){
      		float saldoCorrig = Saldo*(1+juros);
			Saldo = saldoCorrig + valor;
      		return true;
      	} else {
      		Saldo += valor;
      		return true;
      	}
      }
      return false;
}



//Subclasse Conta Poupanca - Superclasse de Poupanca premium
class Conta_Poupanca:public Conta_Bancaria {
      protected:
          float taxa;
	  char Aniversario[11];
      public:
          Conta_Poupanca();			//Construtor
          virtual void Cadastro();			//M�todo para realiza��o do cadastro 
          virtual float getSaldo();			//M�todo para a visualiza��o do saldo atual
          void fazAniversario();		//M�todo para verificar se a conta fez anivers�rio e se deve aplicar o ganho ou n�o
    };

/*
Implementa��o da classe Conta_Poupanca feita por
Gabriel Bueno de Azevedo
RA 151040362
Dia 06/04/2016
*/

Conta_Poupanca::Conta_Poupanca():Conta_Bancaria(){
      	taxa = 0.0;
	strcpy(Aniversario, " ");
}

void Conta_Poupanca::Cadastro(){
	Conta_Bancaria::Cadastro();	

	cout << "Taxa a ser aplicada (porcentagem): ";
	cin >> taxa;

	cout << "Anivers�rio da conta (DD/MM/AAAA): ";
	cin.ignore();
	cin.getline( Aniversario,11);	
}

void Conta_Poupanca::fazAniversario(){
	time_t t = time(0);   // obter a hora atual
    	struct tm *now = localtime( & t );

	int data_hoje[3];		//[0] - Dia   [1] - Mes    [2] - Ano
	int data_aniversario[3];	//[0] - Dia   [1] - Mes    [2] - Ano

	data_hoje[0] = now->tm_mday;		//Atribui a data de hoje para data_hoje
	data_hoje[1] = now->tm_mon+1;
	data_hoje[2] = now->tm_year+1990;

	data_aniversario[0] = atoi(Aniversario);	//Atribui a data de anivers�rio da conta para data_aniversario
	data_aniversario[1] = atoi(&Aniversario[3]);
	data_aniversario[2] = atoi(&Aniversario[6]);

	if(data_hoje[0] > data_aniversario[0] && data_hoje[1] > data_aniversario[1])
		Saldo = Saldo*(1+taxa/100);
}

float Conta_Poupanca::getSaldo(){
	fazAniversario();
	return Saldo;
}
    
main () {
      int op, aux;
      // op escolhe a opera��o a ser realizada
      // aux - percorre o menu e determina a saida do mesmo
      double v;
      /*Conta_Corrente Obj1;
      Conta_Especial Obj2;
      Conta_Poupanca Obj3;
      */

      Conta_Bancaria *Obj;
      do {  // menu principal
          aux=0;
          op=0;
          system("cls");
          cout<<".....Banco do Cliente --- Sua Conta.....";
          cout<<"\n\nEscolha uma opcao!\n";
          cout<<"\n[1] Conta Corrente";
          cout<<"\n[2] Conta Especial";
          cout<<"\n[3] Conta Poupanca";
          cout<<"\n[4] Sair\n\n";
          cout<<"Sua opcao e: ";
          cin>>aux;
          
          switch (aux) {
              case 1:
                   //system("cls"); // limpa a tela
                   Obj = new Conta_Corrente();
		   cout<<">>> Conta Corrente <<<\n\n";
                   Obj->Cadastro();
                   Obj->deposito(100.00);
                   cout<<"\nSaldo = "<<Obj->getSaldo();
                   system("pause");
                   break;
              case 2:
                   //system("cls");
		   Obj = new Conta_Especial();
                   cout<<">>> Conta Especial <<<\n\n";
                   Obj->Cadastro();
                   break;
              case 3:
                   //system("cls");
		   Obj = new Conta_Poupanca();
                   cout<<">>> Conta Poupanca <<<\n\n";
                   Obj->Cadastro();
                   break;
              case 4: // sair do menu e do programa
                   break;
              default: // caso a o usuario escolha uma op��o invalida
                   //system("cls");
                   aux=0;
                   cout<<"Opcao invalida!!\n\n";
                   system("pause");
                   break;
              }
      }
      while(aux!=4);

}
