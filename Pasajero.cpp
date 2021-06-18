#include "Pasajero.h"
#define Dinero 500
Pasajero::Pasajero(int parada_final, string nro_boleto, bool discapacidad)
{
	dinero = Dinero;
	parada_inicial = 0;
	this->discapacidad = discapacidad;
	peso = 65;
	this->parada_final = parada_final;
	this->nro_boleto = nro_boleto;
}

Pasajero::~Pasajero(){}

void Pasajero::Pagar(float monto)
{
	if (dinero > monto)
		dinero = dinero - monto;
	else
		throw new exception("El pasajero no posee el dinero suficiente.");
}
