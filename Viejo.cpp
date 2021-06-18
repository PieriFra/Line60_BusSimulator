#include "Viejo.h"

Viejo::Viejo(string codigo_colec, unsigned int cant_max_pas, unsigned int direccion,
	float peso_max, Ramal* ramal): Colectivo(codigo_colec, cant_max_pas, direccion,
		peso_max, ramal)
{
}

Viejo::~Viejo()
{
}
