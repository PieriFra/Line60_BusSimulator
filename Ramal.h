#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Enum.h"

class Parada;
template<class Parada>class cListaT;

class Ramal
{
private:
	eRamal nombre;
	int codigo_parada;
	int codigo_final;
	static cListaT<Parada> ListaParadas;

public:

	Ramal(cListaT<Parada> ListaParadas);
	~Ramal();

	friend class Colectivo;

	ostream& operator<<(ostream& os);
	static cListaT<Parada>& GetLista() { return ListaParadas; }
	int GetCod() { return codigo_parada; }
	int GetFinal() { return codigo_final; }
	eRamal GetNom() { return nombre; }
	void SetNom(eRamal nom) { nom = nombre; }
	void SetCod(int cod) { cod = codigo_parada; }


};

