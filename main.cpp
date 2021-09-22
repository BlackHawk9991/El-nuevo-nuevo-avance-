#include <conio.h>
#include "Controlador.h"
/*
#include<thread>
#include<cstdlib>
#include<chrono>

using namespace std::this_thread;
using namespace std::chrono;

void tiempo() {
	int segundo = 120;
	while (1 == 1) {
		system("CLS");
		cout << "Temporizador" << endl;
		cout << "Segundos : " << segundo << endl;
		sleep_for(seconds(1));
		segundo--;


		if (segundo == 0) {
			cout << "¡¡ EL TIEMPO SE ACABÓ !!";
		}
	}
}
*/
int main() {
	srand(time(NULL));
	Console::BackgroundColor = ConsoleColor::Black;
	Console::SetWindowSize(150, 35);
	Console::CursorVisible = false;
	char tecla;

	Controlador* c = new Controlador();
	while (true) {
		c->borrarTodo();

		c->Colision_Alien_Enemigo();
		if (_kbhit()) {
			tecla = _getch();
			tecla = toupper(tecla);
			c->getAlien()->mover(tecla);
		}
		c->moverTodo();

		c->dibujarTodo();

		_sleep(100);
	}

	_getch();
	return 0;
}
