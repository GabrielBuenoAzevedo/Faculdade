#include <clocale>
#include "Retangulo.h"
#include "Quadrado.h"
#include "Triangulo.h"
#include "Circulo.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Forma2D *obj;
	int op;
	float x, y;
	
	setlocale(LC_ALL,"portuguese");
	
	do{
		system("cls");
		cout<<"Forma Bidimensional\n"
			<<"[1] Retângulo\n"
			<<"[2] Quadrado\n"
			<<"[3] Triangulo\n"
			<<"[4] Círculo\n"
			<<"[0] Sair\n"
			<<"Informe a opção desejada: ";
		cin>>op;
		
		if(op>0 && op <=4) {
			system("cls");
			cout<<"Informe as coordenadas do centro da forma\n"
				<<"x: ";
			cin>>x;
			cout<<"\ny: ";
			cin>>y;
		}
		
		switch(op){
			case 1:
				float base, altura;
				cout<<"\nInforme o tamanho da base: ";
				cin>>base;
				cout<<"Informe o tamanho da altura: ";
				cin>>altura;
				obj = new Retangulo(x, y, base, altura);
				break;
			case 2:
				float lado;
				cout<<"\nInforme o tamanho do lado: ";
				cin>>lado;
				obj = new Quadrado(x, y, lado);
				break;
			case 3:
				float lado1, lado2, lado3;
				cout<<"\nInforme o tamanho do lado 1: ";
				cin>>lado1;
				cout<<"\nInforme o tamanho do lado 2: ";
				cin>>lado2;
				cout<<"\nInforme o tamanho do lado 3: ";
				cin>>lado3;
				obj = new Triangulo(x, y, lado1, lado2, lado3);
				break;
			case 4:
				float raio;
				cout<<"\nInforme o tamanho do raio: ";
				cin>>raio;
				obj = new Circulo(x, y, raio);
				break;
			case 0:
				cout<<"\nEncerrando...\n\n";
				break;
			default:
				cout<<"\nOpção Inválida! Tente novamente.\n\n";
				break;
		}
		
		if(op>0 && op<=4){
			float desX, desY;
			obj->displayDados();
			cout<<"\nInforme um deslocamento no eixo x: ";
			cin>>desX;
			cout<<"\nInforme um deslocamento no eixo y: ";
			cin>>desY;
			
			obj->deslocamentoX(desX);
			obj->deslocamentoY(desY);
			
			obj->displayDados();
		}
		
		cout<<endl;
		system("pause");
	} while(op!=0);
	
	
	return 0;
}
