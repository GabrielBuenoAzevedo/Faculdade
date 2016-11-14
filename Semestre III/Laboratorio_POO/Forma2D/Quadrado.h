#ifndef Quadrado_H
#define Quadrado_H

#include "Forma2D.h"

class Quadrado : public Forma2D {
	protected:
		float lado;
	public:
		Quadrado(float center_X, float center_Y, float lado);
		virtual ~Quadrado() { }; //Destrutor virtual vazio
		virtual float getArea();
		virtual float getPerimetro();
		virtual void displayDados();
};

///Construtuor da Classe
Quadrado::Quadrado(float center_X, float center_Y, float lado){
	Forma2D::center_X = center_X;
	Forma2D::center_Y = center_Y;
	this->lado = lado;
}

//Método para obter a área do quadrado
float Quadrado::getArea(){
	return(lado*lado);	
}

//Método para obter o perímetro do quadrado
float Quadrado::getPerimetro(){
	return(4*lado);
}

///Método para exibir as informações do objeto
void Quadrado::displayDados(){
	cout<<"\nQuadrado"
		<<"\nCentro: ("<<Forma2D::center_X<<","<<Forma2D::center_Y<<")"
		<<"\nLado: "<<lado
		<<"\nPerímetro: "<<getPerimetro()
		<<"\nÁrea: "<<getArea()<<endl;
}
#endif
