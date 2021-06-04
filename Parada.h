#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <ctime>
using namespace std;

class Parada
{
private:
	string codigo_parada; //codigo de la parada
	string nombre_parada;
	string direccion;

	string GetCodigoParada() { return codigo_parada; }
	string to_string();
	void Imprimir();
};

