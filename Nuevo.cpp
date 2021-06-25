#include "Nuevo.h"
#define Extra 10


Nuevo::Nuevo(string codigo_colec, unsigned int cant_max_pas, eDireccion direccion,
	float peso_max):Colectivo(codigo_colec,cant_max_pas,direccion,peso_max)
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

float Nuevo::CalcularTarifa(int parada_inicial, int parada_final)
{
	//dependiendo la cantida de paradas entre la parada incial y la final, le sumamos un extra a la tarifa base.
	//cada para recorrida equivale a $5

	int diff = parada_final - parada_inicial;
	float TarifaTot = tarifa + (abs(diff) * Extra);

	return TarifaTot;
	return 0.0f;
}


