#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Definiciones.h"
class Parada;
template<class Parada>class cListaT;

class Ramal
{
private:
	eRamal nombre;
	int codigo_parada;

public:
	static cListaT<Parada>* ListaParadas;
	Ramal(cListaT<Parada>* ListaParadas);
	~Ramal();

	int GetCod() { return codigo_parada; }
	eRamal GetNom() { return nombre; }
	void SetNom(eRamal nom) { nom = nombre; }
	void SetCod(int cod) { cod = codigo_parada; }
	string To_String();
	void Imprimir();

};

