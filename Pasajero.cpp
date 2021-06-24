#include "Pasajero.h"
#include <stdlib.h>
#define Dinero 500
Pasajero::Pasajero(int parada_final, int nro_boleto, bool discapacidad):nro_boleto(contador++)
{
	dinero = Dinero;
	parada_inicial = 0;
	this->discapacidad = discapacidad;
	peso = 65;
	this->parada_final = parada_final;
	//this->nro_boleto = nro_boleto;

}

Pasajero::~Pasajero(){}

int Pasajero::contador = 0;


void Pasajero::Pagar(float monto)
{
	if (dinero > monto)
		dinero = dinero - monto;
	else
		throw new exception("El pasajero no posee el dinero suficiente.");
}

string Pasajero::To_String()
{
	//ver
	stringstream sp;

	sp << "Parada inicial: " << parada_inicial<< endl;
	sp << "Parada final: " << parada_final << endl;
	return sp.str();
}

void Pasajero::Imprimir()
{
	cout << To_String() << endl;
}
