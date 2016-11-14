#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <ctime>
#include <clocale>

class Pessoa {
        private: 			//atributos
        char nome[100];
        char CPF[14];
        int idade;
        float salario;

        public:				//Assinatura dos métodos
        Pessoa();
        void atualizarCadastro(char *Nome, char *CPF);
        void setSalario(float salario);
        float getSalario();
        void calcularIdade(int dm, int mn, int an);
        int getIdade();
        void displayInfo();
};


int main()	{
        Pessoa *P1 = new Pessoa();
        Pessoa P2;

        //cout << "\n\nPessoa 1\n";
        //P1->displayInfo();
        //cout<<"\n\nPessoa 2\n";
        //P2.displayInfo();

        //cout<< "\n\nInforme o novo salário: ";
        //float sal;
        //cin >> sal;
        //P1->setSalario(sal);
        //cout <<"O novo salário é " << P1->getSalario() << "reais por mês!" << endl;


        int mn,dn,an;
        cout << "Digite o seu dia de nascimento: ";
        cin >> dn;
        cout << "Digite o seu mês de nascimento (número do mês): ";
        cin >> mn;
        cout << "Digite o seu ano de nascimento: ";
        cin >> an;

        P1->calcularIdade(dn,mn,an);
        cout << "A idade do P1 é " << P1->getIdade() << " anos!" << endl;
}


Pessoa::Pessoa() {
        /*cout << "Informe o nome: " << endl;
        cin.getline(nome,100);
        cout << "Informe o CPF: " << endl;
        cin.getline(CPF,14);
        cout << "Informe o salario: " << endl;
        cin >> salario;
        cin.ignore();
        */
}

void Pessoa::setSalario(float Salario){
        this->salario = Salario;
}


float Pessoa::getSalario(){
    return salario;
}


int Pessoa::getIdade(){
        return idade;
}


void Pessoa::displayInfo(){
    cout << "Ola " << nome << "\nseu CPF é " << CPF << "\ne você recebe " << salario << " reais por mês." << endl;
}



void Pessoa::calcularIdade(int dn, int mn, int an){
    time_t t = time(0);
    struct tm * now =localtime( & t);

    /*cout << (now->tm_year + 1900) << '-'
         << (now->tm_mon + 1) << '-'
         << now->tm_mday
         << endl;
    */

    idade =(now->tm_year + 1900) - an ;
    if(mn > (now->tm_mon + 1))
        idade--;
    else
        if(mn == (now->tm_mon + 1))
            if(dn > now->tm_mday)
                idade --;


}
