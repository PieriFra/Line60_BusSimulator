#include "Acordeon.h"

Acordeon::Acordeon(string codigo_colec, unsigned int cant_max_pas, eDireccion direccion,
	float peso_max):Nuevo(codigo_colec,cant_max_pas,direccion,peso_max)
{
	this->cant_ruedas = 8;
}

Acordeon::~Acordeon(){}




