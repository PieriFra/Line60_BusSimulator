#pragma once
#include "Nuevo.h"
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <ctime>
using namespace std;

class Acordeon : public Nuevo
{
	const int cant_ruedas=8;
public:
	Acordeon(string codigo_colec, unsigned int cant_max_pas, unsigned int direccion,
		float peso_max, float tarifa,static const int cant_ruedas);
	~Acordeon();

	bool PrenderApagarAire();
	
	string to_string();
	void Imprimir();
};

