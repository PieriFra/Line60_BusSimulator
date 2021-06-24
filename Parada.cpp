#include "Parada.h"

Parada::Parada(int codigo_parada, string nombre_parada, string direccion, 
	cListaT<Pasajero>* ListaPasajeros):codigo_parada(codigo_parada)
{
	this->direccion = direccion;
	this->nombre_parada = nombre_parada;
	this->ListaPasajeros = ListaPasajeros;
}

Parada::~Parada()
{
}

string Parada::To_String()
{
	stringstream spa;

	spa << "Parada: " << nombre_parada << endl;
	spa << "Direccion: " << direccion << endl;

	return spa.str();
}

void Parada::Imprimir()
{
	cout << To_String() << endl;
}
