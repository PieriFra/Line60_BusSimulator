#include "Nuevo.h"

Nuevo::Nuevo(string codigo_colec, unsigned int cant_max_pas, unsigned int direccion, float peso_max,  
	Ramal* ramal):Colectivo(codigo_colec, cant_max_pas,direccion,peso_max,ramal)
{
	aire = false;
}

Nuevo::~Nuevo(){}

void Nuevo::PrenderApagarAire(bool Estado)
{
	if (Estado == true)
		Estado = false;
	else
		Estado = true;
}
