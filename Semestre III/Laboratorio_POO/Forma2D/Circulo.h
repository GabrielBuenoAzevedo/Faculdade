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


///Construtor da classe círculo
Circulo::Circulo(float center_X, float center_Y, float raio){
	Forma2D::center_X = center_X;
	Forma2D::center_Y = center_Y;
	this->raio = raio;
}

///Método para obter a área do círculo
float Circulo::getArea(){
	return(PI*raio*raio);
}

///Método para calcular o perímetro do círculo
float Circulo::getPerimetro(){
	return(2*PI*raio);
}

///Método para exibir as informações do objeto
void Circulo::displayDados(){
	cout<<"\nCirculo"
		<<"\nCentro: ("<<Forma2D::center_X<<","<<Forma2D::center_Y<<")"
		<<"\nRaio: "<<raio
		<<"\nPerímetro: "<<getPerimetro()
		<<"\nÁrea: "<<getArea()<<endl;
}
#endif

