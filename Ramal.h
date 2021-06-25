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
	int codigo_final;
public:
	static cListaT<Parada>* ListaParadas;

	Ramal(cListaT<Parada>* ListaParadas);
	~Ramal();

	int GetCod() { return codigo_parada; }
	int GetFinal() { return codigo_final; }
	eRamal GetNom() { return nombre; }
	void SetNom(eRamal nom) { nom = nombre; }
	void SetCod(int cod) { cod = codigo_parada; }

	/*string To_String();
	void Imprimir();*/

};

