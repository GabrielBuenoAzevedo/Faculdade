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

//M�todo para obter a �rea do ret�ngulo
float Retangulo::getArea(){
	return(base*altura);	
}

//M�todo para obter o per�metro do ret�ngulo
float Retangulo::getPerimetro(){
	return(2*base+2*altura);
}

///M�todo para exibir as informa��es do objeto
void Retangulo::displayDados(){
	cout<<"\nRetangulo"
		<<"\nCentro: ("<<Forma2D::center_X<<","<<Forma2D::center_Y<<")"
		<<"\nBase: "<<base<<" Altura: "<<altura
		<<"\nPer�metro: "<<getPerimetro()
		<<"\n�rea: "<<getArea()<<endl;
}

#endif
