#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <ctime>
#include "Parada.h"
using namespace std;

class Pasajero
{
	friend Parada;
private:
	Parada parada_inicial;
	Parada parada_final;
	unsigned int nro_boleto;
	float peso;//peso del pasajero
	bool discapacidad;//true si usa silla de ruedas

public:
	Pasajero(Parada parada_inicial, Parada parada_final, unsigned int nro_boleto,
		float peso, bool discapacidad);
	~Pasajero();

	Parada GetParadaInicial() { return parada_inicial; }
	Parada GetParadaFinal() { return parada_final; }
	Pasajero GetPasajero() { return pasajero; }

	string to_string();
	void Imprimir();


};

