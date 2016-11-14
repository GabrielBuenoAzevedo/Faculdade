#ifndef Retangulo_H
#define Retangulo_H

#include "Forma2D.h"

class Retangulo : public Forma2D {
	protected:
		float base, altura;
	public:
		Retangulo(float center_X, float center_Y, float base, float altura);
		virtual ~Retangulo() { }; //Destrutor virtual vazio
		virtual float getArea();
		virtual float getPerimetro();
		virtual void displayDados();
};

///Construtuor da Classe
Retangulo::Retangulo(float center_X, float center_Y, float base, float altura){
	Forma2D::center_X = center_X;
	Forma2D::center_Y = center_Y;
	this->base = base;
	this->altura = altura;
}

//Método para obter a área do retângulo
float Retangulo::getArea(){
	return(base*altura);	
}

//Método para obter o perímetro do retângulo
float Retangulo::getPerimetro(){
	return(2*base+2*altura);
}

///Método para exibir as informações do objeto
void Retangulo::displayDados(){
	cout<<"\nRetangulo"
		<<"\nCentro: ("<<Forma2D::center_X<<","<<Forma2D::center_Y<<")"
		<<"\nBase: "<<base<<" Altura: "<<altura
		<<"\nPerímetro: "<<getPerimetro()
		<<"\nÁrea: "<<getArea()<<endl;
}

#endif
