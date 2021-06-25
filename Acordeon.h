#pragma once
#include "Nuevo.h"

using namespace std;

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

