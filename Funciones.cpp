#pragma once
#include "Funciones.h"
#include <sstream>
#include <stdlib.h>
#include <ctime>

cListaT<Parada>* CargarLista(cListaT<Parada>* Lista)
{
	cListaT <Parada>* aux = Lista;
	string NomParada[12] = { "Catedral", "Juramento", "Olleros", "Carranza", "Pueyrredon", "Tribunales", "Cabildo", "Palermo", "PlazaItalia", "Congreso", "Bulnes", "Aguero" };
	string DireParadas[12] = { "a","b","c","d","e","f", "g", "h", "i", "j", "k", "L" };

	int parada_final=0, parada_inicial=0;

	for (int i = 0; i < 12; i++) //recorremos la lista de paradas
	{
		srand(time(0));
		int cantPasajeros = (rand() % 11) + 1;
		cListaT<Pasajero>* ListaPasajeros = new cListaT<Pasajero>();

		for (int j = 0; j < cantPasajeros; j++)
		{
			if (j % 5 == 0 && j > 0)
			{
				srand(time(0));
				do
				{
					parada_final = 1 + (rand() % (13 - 1));
					parada_inicial = 1 + (rand() % (13 - 1));
				} while (parada_final==parada_inicial);
				
				Pasajero* pasajero_discapacitado = new Pasajero(parada_final,parada_inicial,pasajero_discapacitado->GetNroBoleto(), true);
				try {
					ListaPasajeros->AgregarItem(pasajero_discapacitado);
				}
				catch (exception* ex) {
					cout << ex->what() << endl;
					delete ex;
				}
			}
			else
			{
				srand(time(0));
				do
				{
					parada_final = 1 + (rand() % (13 - 1));
					parada_inicial = 1 + (rand() % (13 - 1));
				} while (parada_final == parada_inicial);
				Pasajero* pasajero = new Pasajero(parada_final, parada_inicial, pasajero->GetNroBoleto(), true);

				try {
					ListaPasajeros->AgregarItem(pasajero);
				}
				catch (exception* ex) {
					cout << ex->what() << endl;
					delete ex;
				}
			}
		}
		Parada* parada = new Parada(i++, DireParadas[i], NomParada[i], ListaPasajeros);
		aux->operator+(parada);
	}
}
Ramal* GenerarRamal()
{
	cListaT<Parada>* ListaParadas = new cListaT<Parada>();
	ListaParadas = CargarLista(ListaParadas);
	Ramal* ramal = new Ramal(ListaParadas);
	
	srand(time(0));
	int NumRamal = (rand() % 3) + 1;

	switch (NumRamal)
	{
	case 1: {
		ramal->SetNom(eRamal::RamalA);
		ramal->SetCod(0);
		break; }
	case 2: {
		ramal->SetNom(eRamal::RamalB);
		ramal->SetCod(12);
		break; }
	case 3: {
		ramal->SetNom(eRamal::RamalC);
		ramal->SetCod(6);
		break; }
	case 4: {
		ramal->SetNom(eRamal::RamalD);
		ramal->SetCod(5);
		break; }
	}

	return ramal;
}
void AsignarRamal(Colectivo* C)
{
	Ramal* aux = GenerarRamal();
	if (C->GetRamal() == NULL)
		C->SetRamal(aux);
	else
	{
		//llamamos a la funcion GenerarRamal hasta que nos genere un ramal cuya parada inicial 
		//sea igual a la parada final de nuestro ramal actual
		do
		{
			C->SetRamal(aux);

		} while (abs(C->GetRamal()->GetCod()-aux->GetCod())!=1 || 
			abs(C->GetRamal()->GetCod() - aux->GetCod()) != 12); 
	}

	
	delete aux; //ver que puede tirar error
}

string InfoDia(cListaT<Colectivo>* Lista)
{
	stringstream Datos;

	float monto_totalcolectivos = 0;
	int totalidad_pasajeros = 0;

	//recorremos la lista de colectivos
	for (int i = 0; i < Lista->getCA(); i++)
	{
		//sumamos los montos de cada colectivo
		monto_totalcolectivos = monto_totalcolectivos + Lista->getItem(i)->GetMonto();
		//sumamos la cantidad de pasajeros que subieron en el dia por colectivo
		totalidad_pasajeros = totalidad_pasajeros + Lista->getItem(i)->GetPasajerosTot();
	}
	Datos << "Monto total recolectado: " << monto_totalcolectivos << endl;
	Datos << "Cantidad total de pasajeros: " << totalidad_pasajeros << endl;

	//recorremos la lista de colectivos
	for (int i = 0; i < Lista->getCA(); i++)
	{
		Datos << "Colectivo:" << Lista->getItem(i)->GetCodigo() << endl
			<< "Ramal: " << Lista->getItem(i)->GetRamal()->GetNom() << "Total Pasajeros: " <<
			Lista->getItem(i)->GetPasajerosTot() << endl
			<< "Total Recaudado: " << Lista->getItem(i)->GetMonto() << endl;
	}
	return Datos.str();
}

//metodo que se llama una vez por minuto, actualiza el estado de todos los objetos
void MetodoTICK() 
{
	int TICK = 360; //6 horas, 360 minutos


}





