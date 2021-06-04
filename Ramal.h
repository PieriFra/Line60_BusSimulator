#pragma once

#include "Definiciones.h"
class Parada;
template<class Parada>class cListaT;
class Ramal
{

	string nombre;
	string codigo_parada;
	static cListaT<Parada>*ListaParadas;


public:
	Ramal(string nombre, string codigo_parada, cListaT<Parada>* ListaParadas);
	~Ramal();



	string To_String();
	void Imprimir();

};

