#include "Ramal.h"

Ramal::Ramal(cListaT<Parada>* ListaParadas)
{
	nombre = eRamal::RamalA;
	codigo_parada = 0;
	this->ListaParadas = ListaParadas;
}

Ramal::~Ramal()
{
	//tenemos que eliminar la lista de paradas???
}
