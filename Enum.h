#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <time.h>
#include <ctime>
#include <iostream>
#include <sstream>
#include "cListaT.h"

enum eRamal { RamalA = 0, RamalB, RamalC, RamalD };
typedef enum eRamal;

enum eDireccion
{
	Hidraulica = 0, Electrica
}; typedef enum eDireccion;
