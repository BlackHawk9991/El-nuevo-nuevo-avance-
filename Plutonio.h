#pragma once
#include <iostream>

using namespace std;
using namespace System;
using namespace System::Drawing;

class Plutonio {
private:
	int x, y;
	int ancho, alto;
public:
	Plutonio() {
		x = rand() % (147 - 4) + 3;
		y = rand() % (33 - 4) + 3;
		ancho = 1;
		alto = 1;
	}

	~Plutonio() {}

	void borrar() {
		Console::SetCursorPosition(x, y); cout << " ";
	}

	void dibujar() {
			Console::ForegroundColor = ConsoleColor::Red;
			Console::SetCursorPosition(x, y); cout << char(4);
	}

	void dibujarNegro() {
		Console::ForegroundColor = ConsoleColor::Black;
		Console::SetCursorPosition(x, y); cout << char(4);
	}

	Rectangle getRectangle() {
		return Rectangle(x, y, ancho, alto);
	}

};
