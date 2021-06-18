#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <time.h>
#include <ctime>
#include <iostream>
#include <sstream>
#include "Pasajero.h"
#include "Ramal.h"
#include "Colectivo.h"
#include "Acordeon.h"
#include "Nuevo.h"
#include "Viejo.h"
#include "cListaT.h"
#include "Parada.h"

typedef enum 
{
	RamalA = 0, RamalB, RamalC, RamalD
}eRamal;

typedef enum
{
	Hidraulica=0, Electrica
}eDireccion;