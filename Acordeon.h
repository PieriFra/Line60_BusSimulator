#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "Nuevo.h"
#include <string>
#include <iostream>
#include <ctime>
#include "Definiciones.h"
using namespace std;
class Ramal;

class Acordeon : public Nuevo
{
private: 
	int cant_ruedas;

public:
	Acordeon(const string codigo_colec, unsigned int cant_max_pas, eDireccion direccion,
		float peso_max);
	~Acordeon();

	bool GetAire() { return aire; }
	int GetRuedas() const { return cant_ruedas; }
	
};

