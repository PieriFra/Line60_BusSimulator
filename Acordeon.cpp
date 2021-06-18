#include "Acordeon.h"



Acordeon::Acordeon(string codigo_colec, unsigned int cant_max_pas, unsigned int direccion, 
	float peso_max, Ramal* ramal): Nuevo (codigo_colec, cant_max_pas,
		direccion, peso_max, ramal)
{
	this->cant_ruedas = 8;
}

Acordeon::~Acordeon()
{

}


