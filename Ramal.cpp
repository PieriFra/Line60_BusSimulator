#include "Ramal.h"

Ramal::Ramal(cListaT<Parada>* ListaParadas)
{
	codigo_parada = 0;
	this->ListaParadas = ListaParadas;
}

Ramal::~Ramal()
{
	//tenemos que eliminar la lista de paradas???
}
