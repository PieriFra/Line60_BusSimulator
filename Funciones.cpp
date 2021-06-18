#pragma once
#include "Funciones.h"

cListaT<Parada>* CargarLista(cListaT<Parada>* Lista)
{
	cListaT <Parada>* aux = Lista;
	string NomParada[12] = { "Catedra", "Juramento", "Olleros", "Carranza", "Pueyrredon", "Tribunales", "Cabildo", "Palermo", "PlazaItalia", "Congreso", "Bulnes", "Aguero" };
	string DireParadas[12] = { "a","b","c","d","e","f", "g", "h", "i", "j", "k", "L" };

	for (int i = 0; i < 12; i++) //recorremos la lista de paradas
	{
		int cantPasajeros = (rand() % 11) + 1;
		cListaT<Pasajero>* ListaPasajeros = new cListaT<Pasajero>();

		for (int j = 0; j < cantPasajeros; j++)
		{
			if (j % 5 == 0 && j > 0)
			{
				try {
					Pasajero* pasajero_discapacitado = new Pasajero((1 + (rand() % (13 - 1))), (1 + (rand() % (20))), true);
					ListaPasajeros->AgregarItem(pasajero_discapacitado);
				}
				catch (exception* ex) {
					cout << ex->what() << endl;
					delete ex;
				}
			}
			else
			{
				try {
					Pasajero* pasajero = new Pasajero((1 + (rand() % (13 - 1))), (1 + (rand() % (20))), true);
					ListaPasajeros->AgregarItem(pasajero);
				}
				catch (exception* ex) {
					cout << ex->what() << endl;
					delete ex;
				}
			}
		}
		//Parada(string codigo_parada, string nombre_parada, string direccion, cListaT<Pasajero>* ListaPasajeros);
		Parada* parada = new Parada(i++, DireParadas[i], NomParada[i], ListaPasajeros);
		aux->operator+(parada);
	}
}

bool VerificarLugar(Colectivo* C1, Colectivo* C2)
{
	if(C1.)
	return false;
}



