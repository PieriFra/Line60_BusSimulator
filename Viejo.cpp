#include "Viejo.h"

Viejo::Viejo(string codigo_colec, unsigned int cant_max_pas, unsigned int direccion,
	float peso_max): Colectivo(codigo_colec, cant_max_pas, direccion,
		peso_max)
{
}

Viejo::~Viejo()
{
}

string Viejo::To_String()
{
	stringstream sv;
	sv << "Colectivo: Codigo " << codigo_colec << endl;
	sv << "Cantidad de pasajeros: " << cant_pasajeros << endl;
	sv << "Peso actual: " << peso_actual << endl;

	return sv.str();
}

void Viejo::Imprimir()
{
	cout << To_String() << endl;
}
