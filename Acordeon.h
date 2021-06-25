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
private: 
	int cant_ruedas;
public:
	Acordeon(string codigo_colec, unsigned int cant_max_pas, eDireccion direccion,
		float peso_max);
	~Acordeon();

	//void PrenderApagarAire( bool Estado); ya esta en el padre!!
	
	bool GetAire() { return aire; }
	int GetRuedas() const { return cant_ruedas; }
	
	friend ostream& operator<<(ostream& os, const Acordeon& A);
	/*string To_String();
	void Imprimir();*/
};

