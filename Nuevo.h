#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Colectivo.h"
#include <string>
#include <iostream>
#include <ctime>
using namespace std;
class Ramal;

class Nuevo: public Colectivo
{
protected:
	bool aire; //sera true si esta encendido, y false si esta apagado
public:
	//metodos
	Nuevo(const string codigo_colec, unsigned int cant_max_pas, eDireccion direccion,
		float peso_max);
	~Nuevo();

	void PrenderApagarAire(bool Estado);
	float CalcularTarifa(int parada_inicial, int parada_final);

	bool GetAire() { return aire; }
};

