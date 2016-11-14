#ifndef Circulo_H
#define Circulo_H


#define PI 3.14

#include"Forma2D.h"

class Circulo:public Forma2D {
	protected:
		float raio;
	public:
		Circulo(float center_X, float center_Y, float raio);
		virtual ~Circulo() { } //Destrutor virtual vazio
		virtual float getArea();
		virtual float getPerimetro();
		virtual void displayDados();
};


///Construtor da classe c�rculo
Circulo::Circulo(float center_X, float center_Y, float raio){
	Forma2D::center_X = center_X;
	Forma2D::center_Y = center_Y;
	this->raio = raio;
}

///M�todo para obter a �rea do c�rculo
float Circulo::getArea(){
	return(PI*raio*raio);
}

///M�todo para calcular o per�metro do c�rculo
float Circulo::getPerimetro(){
	return(2*PI*raio);
}

///M�todo para exibir as informa��es do objeto
void Circulo::displayDados(){
	cout<<"\nCirculo"
		<<"\nCentro: ("<<Forma2D::center_X<<","<<Forma2D::center_Y<<")"
		<<"\nRaio: "<<raio
		<<"\nPer�metro: "<<getPerimetro()
		<<"\n�rea: "<<getArea()<<endl;
}
#endif

