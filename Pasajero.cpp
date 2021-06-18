#include "Pasajero.h"

Pasajero::Pasajero(int parada_final, unsigned int nro_boleto, bool discapacidad)
{
}

Pasajero::~Pasajero()
{
}

void Pasajero::Pagar(float monto)
{
	if (dinero > monto)
		dinero = dinero - monto;
	else
		throw new exception("El pasajero no posee el dinero suficiente.");
}
