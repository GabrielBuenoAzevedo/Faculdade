/*
Criado por Gabriel Bueno de Azevedo
Data: 07/04/2016
					DIAGRAMA DE CLASSES	
		---------------------------		--------------------------
	       |           Circulo         |	       | 	 Ponto 2D	  |
	       |---------------------------|	       |--------------------------|
	       |  #centro: Ponto2D         |	       |  #coordY: T		  |
	       |  #raio: T                 |	       |  #coordX: T		  |
	       |---------------------------|	       |--------------------------|
	       |  +Circulo()               |	       |  +Ponto2D(T x, T y)	  |
	       |  +getCentro():Ponto2D     |	       |  +getCoordX(): T	  |
	       |  +setCentro(Ponto2D):void |           |  +getCoordY(): T	  |
	       |  +getRaio(): T		   |	       |  +setCoordX(T x): void   |
	       |  +setRaio(T): void        |  	       |  +setCoordY(T y): void   |
	       |  +getArea(): T		   |           |  +display: void	  |
	       |  +getPerimetro(): T	   |            --------------------------
		---------------------------
			^       ^      ^
			|	|      |
			|	|      -------------------------------------------------------------
			|	|								   |
			|	-----------------------------					   |
			|				    |    				   |
	 ----------------------------		--------------------------	      --------------------------
	|          Cilindro          |	       |	   Cone           |	     |	         Esfera         |
	|----------------------------|	       |--------------------------|          |--------------------------|
	|  #altura: T		     |	       |  #altura: T		  |	     |				|
 	|----------------------------|         |  #geratriz: T		  |	     |--------------------------|
	|  +Cilindro()		     |	       |--------------------------|	     |  +Esfera();		|
	|  +getAltura(): T	     |	       |  +Cone()	          |	     |  +getArea(): T	        |
	|  +setAltura(T): void       |	       |  +getAltura(): T	  |	     |  +getVolume(): T         |
	|  +getArea(): T	     |	       |  +getGeratriz(): T	  |	      --------------------------
	|  +getVolume():T	     |	       |  +setAltura(T): void	  |
	 ----------------------------	       |  +setGeratriz()(T): void |
					       |  +getArea(): T		  |
					       |  +getVolume(): T	  |
						--------------------------
*/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <cmath>
#include <iomanip>

#define PI 3.14

template <class T>
class Ponto2D{
	protected: 
		T coordY;
		T coordX;
	public:
		Ponto2D(T x,T y);
		T getCoordX();
		T getCoordY();
		void setCoordX(T x);
		void setCoordY(T y);
		void display();
};

//Construtor Ponto2D
template <class T>
Ponto2D<T>::Ponto2D(T x, T y){
	setCoordX(x);
	setCoordY(y);
}

template <class T>
T Ponto2D<T>::getCoordX(){
	return coordX;
}

template <class T>
T Ponto2D<T>::getCoordY(){
	return coordY;
}

template <class T>
void Ponto2D<T>::setCoordX(T x){
	coordX = x;
}

template <class T>
void Ponto2D<T>::setCoordY(T y){
	coordY = y;
}

template <class T>
void Ponto2D<T>::display(){
	cout << "(" << coordX<<"," << coordY << ")"<<endl;
}

template <class T>
class Circulo{
	protected:
		Ponto2D<T> *centro;
		T raio;
	public:
		Circulo();
		Ponto2D<T>* getCentro();
		void setCentro(Ponto2D<T> *centro);
		T getRaio();
		void setRaio(T raio);
		T getArea();
		T getPerimetro();
		void displayCentro();
};

template <class T>
Circulo<T>::Circulo(){	
	
	cout << "Entre as coordenadas do ponto central do círculo (formato (x,y)): ";
	
	char lixo;
	cin >> lixo;
	
	T coordX;
	cin >> coordX;
	
	cin >> lixo;
	
	T coordY;
	cin >> coordY;

	cin >>	 lixo;	

	Ponto2D<T> *Centro = new Ponto2D<T>(coordX,coordY);	
	setCentro(Centro);

	cout << "Coloque o tamanho do raio: ";
	T raio;
	cin >> raio;
	setRaio(raio);
}

template <class T>
void Circulo<T>::setCentro(Ponto2D<T> *centro){
	this->centro = centro;
}

template <class T>
Ponto2D<T>* Circulo<T>::getCentro(){
	return centro;
}

template <class T>
T Circulo<T>::getRaio(){
	return raio;
}

template <class T>
void Circulo<T>::setRaio(T raio){
	this->raio = raio;
}

template <class T>
T Circulo<T>::getArea(){
	T area;
	area = (T)pow(raio,2)*PI;
	return area;
}

template <class T>
T Circulo<T>::getPerimetro(){
	T perimetro;
	perimetro = (T) 2*3.14*raio;
	return perimetro;
}

template <class T>
void Circulo<T>::displayCentro(){
	centro->display();
}

template <class T>
class Cilindro : public Circulo<T>{
	protected:
		T altura;
	public:
		Cilindro();
		T getAltura();
		void setAltura(T altura);
		T getArea();
		T getVolume();	
};

template <class T>
Cilindro<T>::Cilindro():Circulo<T>(){

	T altura;
	cout << "Altura: ";
	cin >> altura;
	setAltura(altura);

}

template <class T>
void Cilindro<T>::setAltura(T altura){
	this->altura = altura;
}

template <class T>
T Cilindro<T>::getAltura(){
	return altura;
}

template <class T>
T Cilindro<T>::getArea(){
	T area;
	area = (T) (2*M_PI*Circulo<T>::getRaio()*(Circulo<T>::getRaio() + altura));
	return area;
}

template <class T>
T Cilindro<T>::getVolume(){
	T volume;
	volume = (T) (M_PI * pow(Circulo<T>::getRaio(),2) * altura);
	return volume;
}


template <class T>
class Cone: public Circulo<T>{
	protected:
		T altura;
		T geratriz;
	public: 
		Cone();
		T getAltura();
		T getGeratriz();
		void setAltura(T);
		void setGeratriz(T);
		T getArea();
		T getVolume();	
};


template <class T>
Cone<T>::Cone():Circulo<T>(){
	T altura;
	cout << "Coloque a altura: ";
	cin >> altura;	

	T geratriz;
	cout << "Coloque o tamanho da geratriz: ";
	cin >> geratriz;

	setAltura(altura);
	setGeratriz(geratriz);
}

template <class T>
T Cone<T>::getAltura(){
	return altura;
}

template <class T>
T Cone<T>::getGeratriz(){
	return geratriz;
}

template <class T>
void Cone<T>::setAltura(T altura){
	this->altura = altura;
}

template <class T>
void Cone<T>::setGeratriz(T geratriz){
	this->geratriz = geratriz;
}

template <class T>
T Cone<T>::getArea(){
	T area;
	area = (T) (M_PI*Circulo<T>::getRaio()*( Circulo<T>::getRaio() + geratriz));
	return area;
}

template <class T>
T Cone<T>::getVolume(){
	T volume;
	volume = (T) ((1.0/3.0) * M_PI * pow(Circulo<T>::getRaio(),2) * altura);
	return volume;
}

template <class T>
class Esfera: public Circulo<T>{	
	public:
		Esfera();
		T getArea();
		T getVolume();		
};

template <class T>
Esfera<T>::Esfera():Circulo<T>(){ };

template <class T>
T Esfera<T>::getArea(){
	T area;
	area = (T) (4 * M_PI * pow(Circulo<T>::getRaio(),2));
	return area;
}

template <class T>
T Esfera<T>::getVolume(){
	T volume;
	volume = (T) ((4.0/3.0) * M_PI * pow(Circulo<T>::getRaio(),3));
	return volume;
}


int main(){
	Circulo<float> *circ1 = new Circulo<float>();	
	
	cout << "Circulo\n\n";
	circ1->displayCentro();

	cout << endl;
	
	cout << "Area: " << circ1->getArea()<<endl;
	
	cout << "Perimetro: "<<	circ1->getPerimetro() << endl;

	cout << "\n\nEsfera\n";
	Esfera<float> *esf1 = new Esfera<float>();
	
	cout << "Area: " << esf1->getArea() << endl;
	cout << "Volume: " << esf1->getVolume() << endl;

	cout << "\n\nCilindro\n";
	Cilindro<float> *cil1 = new Cilindro<float>();

	cout << "Area: " << cil1->getArea() << endl;
	cout << "Volume: " << cil1->getVolume() << endl;

	cout << "\n\nCone\n";
	Cone<float> *con1 = new Cone<float>();

	cout << "Area: " << con1->getArea() << endl;
	cout << "Volume: " << con1->getVolume() << endl;

	return 0;
}





















