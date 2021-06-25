#include "Pasajero.h"
#include <stdlib.h>
#define Dinero 500

Pasajero::Pasajero(int parada_final, int parada_inicial, string nro_boleto, bool discapacidad) : nro_boleto(nro_boleto)
{
	dinero = Dinero;
	this->parada_inicial = parada_inicial;
	this->discapacidad = discapacidad;
	peso = 65;
	this->parada_final = parada_final;

}
Pasajero::~Pasajero() {};


void Pasajero::Pagar(float monto)
{	
	if (dinero > monto)
		dinero = dinero - monto;
	else
		throw new exception("El pasajero no posee el dinero suficiente.");
}

ostream& Pasajero::operator<<(ostream& os)
{
	os << "Parada inicial: " << parada_inicial << endl;
	os << "Parada final: " << parada_final << endl << "Numero de Boleto: " << nro_boleto << endl;

	return os;
}




