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
	const int codigo_parada; //codigo de la parada
	string nombre_parada;
	string direccion;
	cListaT<Pasajero>* ListaPasajeros;

public:
	Parada(int codigo_parada, string nombre_parada, string direccion, cListaT<Pasajero>* ListaPasajeros);
	~Parada();

	friend class Colectivo;

	int GetCodigoParada() { return codigo_parada; }
	string to_string();
	void Imprimir();
};

