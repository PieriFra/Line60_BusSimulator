#pragma once
#include "Definiciones.h"


cListaT<Parada> *CargarLista(cListaT<Parada>* Lista);
Ramal* GenerarRamal();
void AsignarRamal(Colectivo* C);
string InfoDia(cListaT<Colectivo>* Lista);
void MetodoTICK();