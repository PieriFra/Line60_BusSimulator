#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Enum.h"
#include "Pasajero.h"
#include "Parada.h"
#include "Ramal.h"
#include "Funciones.h"
using namespace std;

class Colectivo
{
protected:
	const string codigo_colec;
	unsigned int cant_max_pas; //cantidad maxima de pasajeros
	unsigned int cant_pasajeros; //pasajeros actuales en el colectivo
	unsigned int pasajeros_totales;
	eDireccion direccion; //direccion hidraulica (1), direccion electrica (2)
	bool puerta;//sera true si la puerta esta abierta
	int parada;
	float monto_total; //va guardando el monto juntado por dia
	float peso_max; //peso maximo de pasajeros permitida
	float peso_actual;//peso actual del colectivo
	float tarifa; //valor fijo de la tarifa
	bool EstadoFunicionamiento; //true si esta sano, false si esta roto
	Ramal* ramal; //puntero al ramal correspondiente que tiene su lista de paradas
	//static int counter; //cuenta la cantidad de colectivos

	cListaT<Pasajero>* ListaPasajerosCole;

public:
	//metodos
	Colectivo(string codigo_colec, unsigned int cant_max_pas,eDireccion direccion,
		float peso_max);
	~Colectivo();

	virtual float CalcularTarifa(int parada_inicial, int parada_final)=0;
	
	void SubirPasajero(Ramal *R);
	void Cobrar(Pasajero* P, float monto);
	void BajarPasajero(Ramal* R);
	bool VerificarPesoCant(); //verifica que el peso y la cantidad de pasajeros sea la permitida
	
	void ColectivoRoto(cListaT<Colectivo>*Lista, Colectivo *colec_roto);
	
	void SetParada(int i) { parada = i; }
	int GetParada() { return parada; }

	void SetEstado(bool Estado) { Estado = EstadoFunicionamiento; }
	void SetRamal(Ramal* R) { ramal = R; }
	void SetPuerta(bool puerta) { this->puerta = puerta; }
	Ramal* GetRamal() { return ramal;}
	unsigned int GetCantMax() { return cant_max_pas; }
	unsigned int GetCantActual() { return cant_pasajeros; }
	float GetMonto() { return monto_total; }
	const string GetClave() { return codigo_colec; }
	bool GetEstado() { return EstadoFunicionamiento; }
	unsigned int GetPasajerosTot() { return pasajeros_totales; }

	ostream& operator<<(ostream& os);

	/*string To_String();
	virtual void Imprimir()=0;*/
};

