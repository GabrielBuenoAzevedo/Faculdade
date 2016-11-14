#ifndef Forma2D_H
#define Forma2D_H

#include<iostream>

using std::cout;
using std::cin;
using std::endl;

class Forma2D {
	protected:
		float center_X, center_Y;
	public:
		virtual ~Forma2D() { }; //Destrutor virtual vazio
		virtual float getArea() = 0;
		virtual float getPerimetro() = 0;
		void deslocamentoX(float);
		void deslocamentoY(float);
		virtual void displayDados() = 0;
};


void Forma2D::deslocamentoX(float desloc){
	center_X = center_X+desloc;	
}

void Forma2D::deslocamentoY(float desloc){
	Forma2D::center_Y = center_Y+desloc;	
}

#endif
