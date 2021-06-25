#include "Viejo.h"
#define Extra 5

Viejo::Viejo(string codigo_colec, unsigned int cant_max_pas, eDireccion direccion,
	float peso_max) :Colectivo(codigo_colec, cant_max_pas, direccion, peso_max)
{
}

Viejo::~Viejo()
{
}

float Viejo::CalcularTarifa(int parada_inicial, int parada_final)
{
	//dependiendo la cantida de paradas entre la parada incial y la final, le sumamos un extra a la tarifa base.
	//cada para recorrida equivale a $5

	int diff = parada_final - parada_inicial;
	float TarifaTot = tarifa + (abs(diff) * Extra);

	return TarifaTot;
}

