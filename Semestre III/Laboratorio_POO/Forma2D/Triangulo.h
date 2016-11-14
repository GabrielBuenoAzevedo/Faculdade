#ifndef Triangulo_H
#define Traingulo_H

#include <cmath>
#include "Forma2D.h"

class Triangulo : public Forma2D {
	protected:
		float lado1, lado2, lado3;
	public:
		Triangulo(float center_X, float center_Y, float lado1, float lado2, float lado3);
		virtual ~Triangulo() { }; //Destrutor virtual vazio
		virtual float getArea();
		virtual float getPerimetro();
		virtual void displayDados();
};

///Construtuor da Classe
Triangulo::Triangulo(float center_X, float center_Y, float lado1, float lado2, float lado3){
	Forma2D::center_X = center_X;
	Forma2D::center_Y = center_Y;
	this->lado1 = lado1;
	this->lado2 = lado2;
	this->lado3 = lado3;
}

//M�todo para obter a �rea do triangulo
float Triangulo::getArea(){
	float semiP = getPerimetro()/2.0;
	float area = sqrt(semiP*(semiP-lado1)*(semiP-lado2)*(semiP-lado3)); //f�rmula de Her�o
	
	return(area);
}

//M�todo para obter o per�metro do tri�ngulo
float Triangulo::getPerimetro(){
	return(lado1+lado2+lado3);
}

///M�todo para exibir as informa��es do objeto
void Triangulo::displayDados(){
	cout<<"\nTriangulo"
		<<"\nCentro: ("<<Forma2D::center_X<<","<<Forma2D::center_Y<<")"
		<<"\nLado: "<<lado1<<" Lado2: "<<lado2<<" Lado 3: "<<lado3
		<<"\nPer�metro: "<<getPerimetro()
		<<"\n�rea: "<<getArea()<<endl;
}
#endif
