#include "Nuevo.h"

Nuevo::Nuevo(string codigo_colec, unsigned int cant_max_pas, unsigned int direccion, float peso_max,  
	Ramal* ramal):Colectivo(codigo_colec, cant_max_pas,direccion,peso_max,ramal)
{
	this->cant_max_pas = cant_max_pas;
	this->direccion = direccion;
	this->peso_max = peso_max;
	this->ramal = ramal;
}

Nuevo::~Nuevo()
{ 
	//eliminamos el ramal???
}

void Nuevo::PrenderApagarAire(bool Estado)
{

}
