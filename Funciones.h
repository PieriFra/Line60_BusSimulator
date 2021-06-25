#pragma once
#include "Enum.h"
#include "Colectivo.h"

cListaT<Parada> CargarLista(cListaT<Parada> Lista);
Ramal* GenerarRamal();
void AsignarRamal(Colectivo* Cole);
string InfoDia(cListaT<Colectivo>* Lista);
