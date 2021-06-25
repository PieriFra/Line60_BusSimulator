#pragma once
#include "Enum.h"
#include "Parada.h"
#include "Ramal.h"
#include "Colectivo.h"

cListaT<Parada> *CargarLista(cListaT<Parada>* Lista);
Ramal* GenerarRamal();
void AsignarRamal(Colectivo* C);
string InfoDia(cListaT<Colectivo>* Lista);
