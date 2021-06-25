#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Colectivo.h"
#include <string>
#include <iostream>
#include <ctime>
using namespace std;
class Ramal;

class Viejo : public Colectivo
{
public:
	Viejo(const string codigo_colec, unsigned int cant_max_pas, eDireccion direccion,
		float peso_max);
	~Viejo();

	float CalcularTarifa(int parada_inicial, int parada_final);

	string To_String();
	void Imprimir();

};

