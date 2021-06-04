#pragma once
#include "Nuevo.h"
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <ctime>
using namespace std;

class Acordeon : public Nuevo
{
	static const int cant_ruedas=8;//chan
public:
	Acordeon(string codigo, unsigned int cant_max_pas, unsigned int cant_pasajeros,
		unsigned int pasajeros_totales, bool aire, bool puerta, float monto_total,
		float peso_max, float peso_actual,static const int cant_ruedas);
	~Acordeon();

	bool PrenderApagarAire();
	
	string to_string();
	void Imprimir();
};

