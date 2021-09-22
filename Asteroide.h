#pragma once
#include <iostream>

using namespace std;
using namespace System;
using namespace System::Drawing;

int datos[2] = { 1, -1 };

class Asteroide {
private:
	int x, y;
	int dx, dy;
	int ancho, alto;
public:
	Asteroide() {
		x = rand() % (135 - 3 + 1) + 3;
		y = 2;
		dx = datos[rand() % 2];
		dy = 1;
		ancho = 1;
		alto = 1;
	}

	~Asteroide() {}

	void borrar() {
		Console::SetCursorPosition(x, y); cout << " ";
	}

	void mover() {
		if (x < 2 || x + ancho > 148) {
			dx = 0;
			dy = 0;
		}
		if (y < 2 || y + alto > 32) {
			dx = 0;
			dy = 0;
		}
		x += dx;
		y += dy;
	}

	void dibujar() {
		Console::ForegroundColor = ConsoleColor::Blue;
		Console::SetCursorPosition(x, y); cout << char(220);
	}

	Rectangle getRectangle() {
		return Rectangle(x, y, ancho, alto);
	}
};