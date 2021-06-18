#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <ctime>
using namespace std;
class Pasajero;
class Ramal;
class Parada;

class Colectivo
{
protected:
	const string codigo_colec;
	unsigned int cant_max_pas; //cantidad maxima de pasajeros
	unsigned int cant_pasajeros; //pasajeros actuales en el colectivo
	unsigned int pasajeros_totales;
	unsigned int direccion; //direccion hidraulica (1), direccion electrica (2)
	bool puerta;//sera true si la puerta esta abierta
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
	Colectivo(string codigo_colec, unsigned int cant_max_pas,unsigned int direccion,
		float peso_max, Ramal* ramal);
	~Colectivo();

	float CalcularTarifa(int parada_inicial, int parada_final);
	
	void SubirPasajero(Ramal *R);
	void Cobrar(Pasajero* P, float monto);
	void BajarPasajero(Ramal* R);
	bool VerificarPesoCant(); //verifica que el peso y la cantidad de pasajeros sea la permitida
	
	bool ColectivoRoto(Colectivo *colec_sano, Colectivo *colec_roto);

	string SistemaGPS(); //retorna cada cinco minutos el nombre de la parada en la que se encuentra el colectivo

	void SetPuerta(bool puerta) { this->puerta = puerta; }
	Ramal* GetRamal() { return ramal;}
	float GetMonto() { return monto_total; }
	const string GetCodigo() { return codigo_colec; }
	bool GetEstado() { return EstadoFunicionamiento; }
	unsigned int GetPasajerosTot() { return pasajeros_totales; }
	
	//verrrr
	ostream& operator<<(ostream& os)
	{
		os << To_String() << endl;
		return os;
	}

	string To_String();
	virtual void Imprimir()=0;
};

