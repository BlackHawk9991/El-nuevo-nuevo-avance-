#pragma once
#include "Plutonio.h"
#include "Enemigo.h"
#include "Asteroide.h"
#include "Nave.h"
#include "Alien.h"

using namespace System::Drawing;

class Controlador {
private:
	Alien* a;
	Nave* objNave;
	Plutonio** arrP;
	int nP;
	Asteroide** arrA;
	int nA;
	Enemigo** arrE;
	int nE;
	int n;
	int cont;
	int contTotal;
public:
	Controlador() {
		a = new Alien();
		objNave = new Nave();
		cont = 0;
		contTotal = 0;
		n = 0;
		nP = 0; nA = 0; nE = 0;
		for (int i = 0; i < 100; i++) {
			agregarPlutonio();
		}
		for (int i = 0; i < 10; i++) {
			agregarAsteroide();
		}
		for (int i = 0; i < 5; i++) {
			agregarEnemigo();
		}
	}

	~Controlador() {}

	//Inicializar arreglo de plutonio
	void agregarPlutonio() {
		Plutonio* p = new Plutonio();
		Plutonio** aux = new Plutonio * [nP + 1];
		for (int i = 0; i < nP; i++) {
			aux[i] = arrP[i];
		}
		aux[nP] = p;
		nP++;
		arrP = aux;
	}

	//Inicializar arreglo de asteroide
	void agregarAsteroide() {
		Asteroide* a = new Asteroide();
		Asteroide** aux = new Asteroide * [nA + 1];
		for (int i = 0; i < nA; i++) {
			aux[i] = arrA[i];
		}
		aux[nA] = a;
		nA++;
		arrA = aux;
	}

	//inicializar arreglo de enemigo
	void agregarEnemigo() {
		Enemigo* e = new Enemigo();
		Enemigo** aux = new Enemigo * [nE + 1];
		for (int i = 0; i < nE; i++) {
			aux[i] = arrE[i];
		}
		aux[nE] = e;
		nE++;
		arrE = aux;
	}

	void borrarTodo() {
		//Objeto de Alien
		a->borrar();
		//Arreglo de Plutonio
		for (int i = 0; i < nP; i++) {
			arrP[i]->borrar();
		}
		//Arreglo de Asteroide
		for (int i = 0; i < nA; i++) {
			arrA[i]->borrar();
		}
		//Arreglo de Enemigo
		for (int i = 0; i < nE; i++) {
			arrE[i]->borrar();
		}
	}

	void moverTodo() {
		//Arreglo de Asteroide
		for (int i = 0; i < nA; i++) {
			arrA[i]->mover();
		}
		//Arreglo de Enemigo
		for (int i = 0; i < nE; i++) {
			arrE[i]->mover();
		}
	}

	void dibujarTodo() {
		//Objeto de Alien
		a->dibujar();
		//Arreglo de Plutonio
		for (int i = 0; i < nP; i++) {
			arrP[i]->dibujar();
		}
		//Arreglo de Asteroide
		for (int i = 0; i < nA; i++) {
			arrA[i]->dibujar();
		}
		//Arreglo de Enemigo
		for (int i = 0; i < nE; i++) {
			arrE[i]->dibujar();
		}
	}

	void Colision_Alien_Nave() {

	}

	void Colision_Alien_Enemigo() { //funciona!
		for (int i = 0; i < nE; i++) {
			if (a->getRectangle().IntersectsWith(arrE[i]->getRectangle())) {
				a->restarVidas();
				a->posicionInicial();
			}
		}
	}


	void Colision_Alien_Asteroide() { 
		for (int i = 0; i < nA; i++) {
			if (a->getRectangle().IntersectsWith(arrA[i]->getRectangle())) {
				a->menorVelocidad();
			}
		}
	}

	void Colision_Alien_Plutonio() {
		/*for (int i = 0; i < n; i++) {
			if (a->getRectangle().IntersectsWith(arr[i]->getRectangle())) {
				
			}
		}*/
	}

	int getcont() { return cont; }
	int getContTotal() { return contTotal; }

	Alien* getAlien() {
		return a;
	}

	Nave* getNave() {
		return objNave;
	}
};
