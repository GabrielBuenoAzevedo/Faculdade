#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <cmath>

class Carrinho{
	private:
		float Velocidade[3];
		float VelEscalar;
	public:
		Carrinho();
		void Norma();
		float getVelocidade(); 
};


Carrinho::Carrinho(){
	cout << "Digite as componentes do vetor velocidade."
	     << "utilize o formato x,y,z" << endl;
	char c;
	cin >> Velocidade[0] >> c >> Velocidade[1] >> c >> Velocidade[2];
}

void Carrinho::Norma(){
	VelEscalar = sqrt(Velocidade[0]*Velocidade[0] + Velocidade[1]*Velocidade[1] + Velocidade[2]*Velocidade[2]);
}

float Carrinho::getVelocidade(){
	return VelEscalar;
}

int main(){
	//Carrinho *C1 = new Carrinho();

	Carrinho C[3];
	//C1->Norma();
	for(int i=0;i<3;i++){
		C[i].Norma();
		cout << "A velocidade escalar é " << C[i].getVelocidade() << endl;
	}
}
