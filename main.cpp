#define _CRT_SECURE_NO_WARNINGS
#include "Definiciones.h"
#include "Funciones.h"


int main()
{
	cListaT<Parada> *ListaParadas1 = new cListaT<Parada>();
	ListaParadas1 = CargarLista(ListaParadas1);
	Ramal* ramal1 = new Ramal("Lineal 60 - Ramal 1", 1, ListaParadas1);

	cListaT<Parada>* ListaParadas2 = new cListaT<Parada>();
	ListaParadas2 = CargarLista(ListaParadas2);
	Ramal* ramal2 = new Ramal("Lineal 60 - Ramal 2", 6, ListaParadas2);

	cListaT<Parada>* ListaParadas3 = new cListaT<Parada>();
	ListaParadas3 = CargarLista(ListaParadas3);
	Ramal* ramal3 = new Ramal("Lineal 60 - Ramal 3", 12, ListaParadas3);
	
	Colectivo* nuevo = new Nuevo("01",15,1,300,ramal1); 
	Colectivo* viejo = new Viejo("02", 10, 2, 250, ramal2);
	Nuevo* acordeon = new Acordeon("03", 20, 1, 350, ramal3);

	cListaT<Colectivo>* ListaColectivos = new cListaT<Colectivo>();
	try{
		ListaColectivos->AgregarItem(nuevo);
	}
	catch (exception *ex)	{
		cout << ex->what() << endl;
		delete ex;
	}
	try {
		ListaColectivos->AgregarItem(viejo);
	}
	catch (exception* ex) {
		cout << ex->what() << endl;
		delete ex;
	}try {
		ListaColectivos->AgregarItem(acordeon);
	}
	catch (exception* ex) {
		cout << ex->what() << endl;
		delete ex;
	}

	//------------------SIMULACION------------------
	//recorremos la lista de colectivos
	for (unsigned int i = 0; i < ListaColectivos->getCA(); i++)
	{
		if (Acordeon* actual = dynamic_cast<Acordeon*>(ListaColectivos->getItem(i))) //ver
		{
			if (actual->GetAire() == false)
				actual->PrenderApagarAire(true);
			
		}
		else if (Nuevo* actual = dynamic_cast<Nuevo*>(ListaColectivos->getItem(i)))
		{
			if (actual->GetAire() == false)
				actual->PrenderApagarAire(true);
		}

		//bajamos pasajeros por cada colectivo que haya en la lista
		ListaColectivos->getItem(i)->BajarPasajero(ListaColectivos->getItem(i)->GetRamal());
		//subimos pasajeros por cada colectivo que haya en la lista
		ListaColectivos->getItem(i)->SubirPasajero(ListaColectivos->getItem(i)->GetRamal());	
		

		//apagamos los aires
		for (unsigned int i = 0; i < ListaColectivos->getCA(); i++)
		{
			if (Acordeon* actual = dynamic_cast<Acordeon*>(ListaColectivos->getItem(i))) //ver
			{
				if (actual->GetAire() == true)
					actual->PrenderApagarAire(false);
			}
			else if (Nuevo* actual = dynamic_cast<Nuevo*>(ListaColectivos->getItem(i)))
			{
				if (actual->GetAire() == true)
					actual->PrenderApagarAire(false);
			}
		}

		string nom; //variable aux
		//llamamos al metodo gps
		nom = ListaColectivos->getItem(i)->SistemaGPS(); 
		//impirimimos por codigo de colectivo la parada en la que se encuentra
		cout << "El colectivo " << ListaColectivos->getItem(i)->GetCodigo()
			<< "se encuntra en la parada: " << nom;

		if (ListaColectivos->getItem(i)->GetEstado() == false)
		{
			ListaColectivos->getItem(i)->ColectivoRoto(ListaColectivos->getItem(i), ListaColectivos->getItem(i++));

		}
	}

	//imprimimos monto total de cada colectivo, cantidad de pasajeros que se suben y el total de todos los colectivos
	float monto_totalcolectivos = 0;
	int totalidad_pasajeros = 0;
	ListaColectivos->Listar();
	for (int i = 0; i < ListaColectivos->getCA(); i++)
	{
		monto_totalcolectivos = monto_totalcolectivos + ListaColectivos->getItem(i)->GetMonto();
		totalidad_pasajeros = totalidad_pasajeros + ListaColectivos->getItem(i)->GetPasajerosTot();
	}
	cout << "Monto total recolectado: " << monto_totalcolectivos << endl;
	cout << "Cantidad total de pasajeros: " << totalidad_pasajeros << endl;

	return 0;
}