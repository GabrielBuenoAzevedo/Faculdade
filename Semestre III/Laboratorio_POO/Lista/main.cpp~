#include <iostream>
#include <clocale>
#include <cstdlib>

#include<stdio.h>

#include "libraries/ListaSE.h"
#include "libraries/Item.h"
#include "libraries/ListaSC.h"
#include "libraries/ListaDE.h"
#include "libraries/ListaDC.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
		
	
	Lista<int> *L1 = new ListaDE<int>();
	//Elemento<int> *I;
	int *im;

	for(int i=0; i<5; i++) {
		//I = new Item();
		im = new int;		
		cin >> *im;
		//I = new Elemento<int>(im);
		L1->inserirOrdem(im);
		cout<<endl;
		
		
	}

	//L1->excluirFim();
	cout << *L1->getFirst() << endl;

	for(int i=0; i< 10;i++)
	cout << *(L1->getFirst()) << std::endl;
	return 0;
}

