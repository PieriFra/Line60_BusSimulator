#pragma once
#include "Colectivo.h"
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <ctime>
using namespace std;

class Nuevo : public Colectivo
{
public:
	//metodos
	//using Colectivo::Colectivo;
	Nuevo(string codigo, unsigned int cant_max_pas, unsigned int cant_pasajeros,
		unsigned int pasajeros_totales, bool aire, bool puerta, float monto_total,
		float peso_max, float peso_actual);
	~Nuevo();

	bool PrenderApagarAire();


	string to_string();
	void Imprimir();

};

