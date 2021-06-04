#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <ctime>
using namespace std;
class Pasajero;
template<class Pasajero>class cListaT;

class Parada
{
private:
	string codigo_parada; //codigo de la parada
	string nombre_parada;
	string direccion;
	cListaT<Pasajero>* ListaPasajeros;

public:
	Parada(string codigo_parada, string nombre_parada, string direccion, cListaT<Pasajero>* ListaPasajeros);
	~Parada();

	string GetCodigoParada() { return codigo_parada; }
	string to_string();
	void Imprimir();
};

