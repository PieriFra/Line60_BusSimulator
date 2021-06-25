#include "Ramal.h"

cListaT<Parada> Ramal::ListaParadas = cListaT<Parada>();

Ramal::Ramal(cListaT<Parada> ListaParadas)
{
	nombre = eRamal::RamalA;
	codigo_parada = 0;
	codigo_final = codigo_parada - 1;
	this->ListaParadas = ListaParadas;
}

Ramal::~Ramal()
{}

ostream& Ramal::operator<<(ostream& os)
{
	os << "Ramal: " << nombre << endl << "Codigo Parada Incio: " << codigo_parada << endl << "Codigo Parada Fin: "
		<< codigo_final << endl;

	return os;
}



