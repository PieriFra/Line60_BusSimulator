#pragma once
#include "Colectivo.h"
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <ctime>
using namespace std;
class Ramal;

class Viejo : public Colectivo
{
public:
	Viejo(const string codigo_colec, unsigned int cant_max_pas, unsigned int direccion,
		float peso_max, const float tarifa, Ramal *ramal);
	~Viejo();

	string to_string();
	void Imprimir();

};

