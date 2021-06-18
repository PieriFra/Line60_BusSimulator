#include "Ramal.h"

Ramal::Ramal(string nombre, int codigo_parada, cListaT<Parada>* ListaParadas)
{
	this->nombre = nombre;
	this->codigo_parada = codigo_parada;
	this->ListaParadas = ListaParadas;
}

Ramal::~Ramal()
{
	//tenemos que eliminar la lista de paradas???
}
