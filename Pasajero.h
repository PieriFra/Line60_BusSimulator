#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Enum.h"
#include "Parada.h"
using namespace std;

class Pasajero
{
	friend Parada;
private:
	int parada_inicial; //por codigo
	int parada_final; //por codigo
	string nro_boleto; //boleto unico del pasajero
	float peso;//peso del pasajero
	float dinero;
	bool discapacidad;//true si usa silla de ruedas

public:
	Pasajero(int parada_final,int parada_inicial, string nro_boleto, bool discapacidad);
	~Pasajero();

	void Pagar(float monto);

	ostream& operator<<(ostream& os);

	int GetParadaInicial() { return parada_inicial; }
	int GetParadaFinal() { return parada_final; }
	void SetParadIncio(int CodParada) { CodParada = parada_inicial; }
	float GetPeso() { return peso; }
	void SetPeso(float peso) { this->peso = peso; }
	bool GetDisc() { return discapacidad; }
	string GetClave() { return nro_boleto; }
};

