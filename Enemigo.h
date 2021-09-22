#pragma once
#include <iostream>

using namespace std;
using namespace System;
using namespace System::Drawing;

int generador[5] = { 1, 2, 3, 4, 5 };
int posicionesx[13] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130 };
int posicionesy[5] = { 5, 6, 7, 8, 9 };
int dxs[3] = { 1, 2, 3 };

class Enemigo {
private:
	int x, y;
	int dx, dy;
	int ancho, alto;
	int g;
public:
	Enemigo() {
		x = posicionesx[rand() % 13];
		y = posicionesy[rand() % 5];
		dx = dxs[rand() % 3];
		dy = dx;
		ancho = 13;
		alto = 3;
		g = generador[rand() % 3];

	}

	~Enemigo() {}

	void borrar() {
		Console::SetCursorPosition(x, y); cout << "             ";
		Console::SetCursorPosition(x, y + 1); cout << "             ";
		Console::SetCursorPosition(x, y + 2); cout << "             ";
	}

	void mover() {
		if (x < 5 || x + ancho >= 144) {
			dx *= -1;
		}
		if (y < 5 || y + alto >= 31) {
			dy *= -1;
		}
		x += dx;
		y += dy;
	}

	int getG() {
		return g;
	}

	void dibujar() {
		switch (getG()) {
		case 1:
			Console::ForegroundColor = ConsoleColor::DarkRed; break;
		case 2:
			Console::ForegroundColor = ConsoleColor::DarkBlue; break;
		case 3:
			Console::ForegroundColor = ConsoleColor::DarkYellow;  break;
		case 4:
			Console::ForegroundColor = ConsoleColor::DarkGreen; break;
		case 5:
			Console::ForegroundColor = ConsoleColor::DarkMagenta; break;
		}

		Console::SetCursorPosition(x, y); cout << "    __!__    ";
		Console::SetCursorPosition(x, y + 1); cout << "_____(_)_____";
		Console::SetCursorPosition(x, y + 2); cout << "   !  !  !   ";
	}

	Rectangle getRectangle() {
		return Rectangle(x, y, ancho, alto);
	}
};