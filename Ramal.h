#pragma once

#include "Definiciones.h"
class Parada;
template<class Parada>class cListaT;
class Ramal
{
	string nombre;
	int codigo_parada;

public:
	static cListaT<Parada>* ListaParadas;
	Ramal(string nombre, int codigo_parada, cListaT<Parada>* ListaParadas);
	~Ramal();

	int GetCod() { return codigo_parada; }

	string To_String();
	void Imprimir();

};

