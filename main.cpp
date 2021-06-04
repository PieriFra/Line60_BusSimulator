#define _CRT_SECURE_NO_WARNINGS
#include "Definiciones.h"


int main()
{

	//parametros Pasajero(Parada parada_inicial, Parada parada_final, unsigned int nro_boleto,
	//	float peso, bool discapacidad);




	//parametros colectivo string codigo_colec, unsigned int cant_max_pas, unsigned int direccion,
	//	float peso_max, float tarifa
	Colectivo* nuevo1 = new Nuevo("01",15,"Callao",300,5); 

	Colectivo* viejo1 = new Viejo("02", 10, "Juramento", 250,5);

	Nuevo* acordeon1 = new Acordeon("03",20,"Congreso",350,5);




	return 0;
}