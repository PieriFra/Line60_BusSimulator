#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <ctime>
using namespace std;

class Colectivo
{
protected:
	string codigo_colec;
	unsigned int cant_max_pas; //cantidad maxima de pasajeros
	unsigned int cant_pasajeros; //pasajeros actuales en el colectivo
	unsigned int pasajeros_totales;

	//ver aire
	bool aire; //sera true si tiene aire
	bool puerta;//sera true si la puerta esta abierta
	float monto_total; //va guardando el monto juntado por dia
	float peso_max; //peso maximo de pasajeros permitida
	float peso_actual;//peso actual del colectivo
	const float tarifa;

public:
	//metodos
	Colectivo(string codigo_colec, unsigned int cant_max_pas,unsigned int cant_pasajeros,
		unsigned int pasajeros_totales,bool aire,bool puerta,float monto_total,
		float peso_max,float peso_actual,const float tarifa);
	~Colectivo();

	float CalcularTarifa(string codigo_parada);
	//aca pasariamos dos codigos, el de la parada inicial y final
	
	void BajarSubirPasajero(Pasajero pasajero);
	bool VerificarPesoCant(); //verifica que el peso y la cantidad de pasajeros sea la permitida
	
	//preguntar gps						  
	//string GPS();
	
	void ColectivoRoto(Colectivo colec_sano,Colectivo colec_roto);

	string To_String();
	virtual void Imprimir()=0;



};

