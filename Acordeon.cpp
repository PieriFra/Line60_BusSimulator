#include "Acordeon.h"



Acordeon::Acordeon(string codigo_colec, unsigned int cant_max_pas, eDireccion direccion,
	float peso_max):Nuevo(codigo_colec,cant_max_pas,direccion,peso_max)
{
	this->cant_ruedas = 8;
}

Acordeon::~Acordeon()
{}

string Acordeon::To_String()
{
	stringstream sa;
	sa << "Colectivo: Codigo " << codigo_colec << endl;
	sa << "Cantidad de pasajeros: " << cant_pasajeros << endl;
	sa << "Peso actual: " << peso_actual << endl;

	return sa.str();
}

void Acordeon::Imprimir()
{
	cout << To_String() << endl;
}