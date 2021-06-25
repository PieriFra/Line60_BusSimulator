#include "Ramal.h"

Ramal::Ramal(cListaT<Parada>* ListaParadas)
{
	nombre = eRamal::RamalA;
	codigo_parada = 0;
	codigo_final = codigo_parada - 1;
	this->ListaParadas = ListaParadas;
}

Ramal::~Ramal()
{
	//tenemos que eliminar la lista de paradas???
}

string Ramal::To_String()
{
	stringstream sr;

	sr << "Ramal: " << nombre << endl;

	return sr.str();
}

void Ramal::Imprimir()
{
	cout << To_String() << endl;
}
