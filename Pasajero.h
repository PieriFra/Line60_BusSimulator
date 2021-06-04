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
	int parada_inicial; //por codigo
	int parada_final; //por codigo
	unsigned int nro_boleto; //boleto unico del pasajero
	float peso;//peso del pasajero
	bool discapacidad;//true si usa silla de ruedas

public:
	Pasajero(int parada_final, unsigned int nro_boleto, bool discapacidad);
	~Pasajero();

	int GetParadaInicial() { return parada_inicial; }
	int GetParadaFinal() { return parada_final; }
	void SetParadIncio(int CodParada) { CodParada = parada_inicial; }
	void SetPeso(float peso) { this->peso = peso; }
	string to_string();
	void Imprimir();


};

