// obligatorio Programacion Avanzada.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Socio.h"
#include <list>
using namespace std;
int main()
{
	int a = 2;
	list<int> miLista = { 1, 2, 3, 4, 5 };
	size_t tamano = miLista.size() - a;
	cout << tamano;
	return 0;
}


