#pragma once
#include "Nuevo.h"
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <ctime>
using namespace std;
class Ramal;

class Acordeon : public Nuevo
{
	const int cant_ruedas;
public:
	Acordeon(string codigo_colec, unsigned int cant_max_pas, unsigned int direccion,
		float peso_max, float tarifa, Ramal *ramal);
	~Acordeon();

	void PrenderApagarAire( bool Estado);
	
	bool GetAire() { return aire; }
	string to_string();
	void Imprimir();
};

