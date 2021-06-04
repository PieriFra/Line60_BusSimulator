#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <ctime>
using namespace std;
class Pasajero;
class Ramal;
class Colectivo
{
protected:
	const string codigo_colec;
	unsigned int cant_max_pas; //cantidad maxima de pasajeros
	unsigned int cant_pasajeros; //pasajeros actuales en el colectivo
	unsigned int pasajeros_totales;
	unsigned int direccion; //direccion hidraulica (1), direccion electrica (2)
	//ver aire
	bool aire; //sera true si tiene aire
	bool puerta;//sera true si la puerta esta abierta
	float monto_total; //va guardando el monto juntado por dia
	float peso_max; //peso maximo de pasajeros permitida
	float peso_actual;//peso actual del colectivo
	const float tarifa; //valor fijo de la tarifa
	Ramal* ramal; //puntero al ramal correspondiente que tiene su lista de paradas
	//static int counter; //cuenta la cantidad de colectivos

public:
	//metodos
	Colectivo(string codigo_colec, unsigned int cant_max_pas,unsigned int direccion,
		float peso_max,float tarifa,Ramal* ramal);
	~Colectivo();

	float CalcularTarifa(string codigo_parada);
	//aca pasariamos dos codigos, el de la parada inicial y final
	
	void BajarSubirPasajero(Pasajero pasajero);
	bool VerificarPesoCant(); //verifica que el peso y la cantidad de pasajeros sea la permitida
	
	
	void ColectivoRoto(Colectivo colec_sano,Colectivo colec_roto);

	ostream& operator<<(ostream& os, cListaT<T>& Lista)
	{
		os << To_String() << endl;
		return os;
	}


	string To_String();
	virtual void Imprimir()=0;



};

