#pragma once
#include "Colectivo.h"
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <ctime>
using namespace std;
class Ramal;

class Nuevo : public Colectivo
{
protected:
	bool aire; //sera true si esta encendido, y false si esta apagado
public:
	//metodos
	//using Colectivo::Colectivo;
	Nuevo(string codigo_colec, unsigned int cant_max_pas, unsigned int direccion,
		float peso_max);
	~Nuevo();

	void PrenderApagarAire(bool Estado);

	bool GetAire() { return aire; }

	string to_string();
	void Imprimir();

};

