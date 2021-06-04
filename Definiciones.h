#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <time.h>
#include <ctime>
#include <iostream>
#include <sstream>
using namespace std;

enum class eRamal1 {
	Hospitales = 1,
	Once,
	Corrientes,
	Cordoba,
	SantaFe,
	LasHeras,
	FacultadDerecho,

	ENUM_MAX
};

enum class eRamal2
{
	Catedral = 1,
	Tribunales,
	Bulnes,
	PlazaItalia,
	Palermo,
	MinistroCarranza,
	Juramento,

	ENUM_MAX
};

enum class eRamal3
{
	Alem = 1,
	Pellegrini,
	Callao,
	Uruguay,
	Medrano,
	Malabia,
	Lacroze,

	ENUM_MAX

};

//string ConvertirRamalString(eRamal1 ramal);