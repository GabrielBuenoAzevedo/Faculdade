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

//Método para obter a área do triangulo
float Triangulo::getArea(){
	float semiP = getPerimetro()/2.0;
	float area = sqrt(semiP*(semiP-lado1)*(semiP-lado2)*(semiP-lado3)); //fórmula de Herão
	
	return(area);
}

//Método para obter o perímetro do triângulo
float Triangulo::getPerimetro(){
	return(lado1+lado2+lado3);
}

///Método para exibir as informações do objeto
void Triangulo::displayDados(){
	cout<<"\nTriangulo"
		<<"\nCentro: ("<<Forma2D::center_X<<","<<Forma2D::center_Y<<")"
		<<"\nLado: "<<lado1<<" Lado2: "<<lado2<<" Lado 3: "<<lado3
		<<"\nPerímetro: "<<getPerimetro()
		<<"\nÁrea: "<<getArea()<<endl;
}
#endif
