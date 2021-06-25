#define _CRT_SECURE_NO_WARNINGS
#include "Definiciones.h"
#include "Funciones.h"

#define TICK 480

int main()
{
	//nos creamos un colectivo de cada clase
	Colectivo* nuevo = new Nuevo("01",15,eDireccion::Electrica,300); 
	Colectivo* viejo = new Viejo("02", 10, eDireccion::Hidraulica, 250);
	Nuevo* acordeon = new Acordeon("03", 20, eDireccion::Electrica, 350);

	//le asignamos un ramal a cada colectivo
	AsignarRamal(nuevo);
	AsignarRamal(viejo);
	AsignarRamal(acordeon);

	//nos creamos la lista de colectivos
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
	
	for (int i = 0; i < TICK; i++)
	{
		
		//recorremos la lista de colectivos
		for (unsigned int i = 0; i < ListaColectivos->getCA(); i++)
		{
			if (i % 5 == 0) //cada 5 min actualizamos la poscion 
			{
				int pos = ListaColectivos->getItem(i)->GetParada();
				string nombre=ListaColectivos->getItem(i)->GetRamal()->ListaParadas->getItem(pos)->GetNombre();
				cout << "Colectivo: " << ListaColectivos->getItem(i)->GetClave()
					<< "se encuentra en la parada: " << nombre << endl;
			}

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

			//recorremos la lista de paradas de cada colectivo
			int incio = ListaColectivos->getItem(i)->GetRamal()->GetCod();
			for (int i = incio; i < ListaColectivos->getItem(i)->GetRamal()->ListaParadas->getCA() - incio; i++)
			{
				//vamos actualizando la parada actual en la que se encuentra 
				ListaColectivos->getItem(i)->SetParada(i);
				//bajamos pasajeros por cada colectivo que haya en la lista
				ListaColectivos->getItem(i)->BajarPasajero(ListaColectivos->getItem(i)->GetRamal());
				//subimos pasajeros por cada colectivo que haya en la lista
				ListaColectivos->getItem(i)->SubirPasajero(ListaColectivos->getItem(i)->GetRamal());
			}

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

			//cuando el colectivo termina su recorrido, le asignamos un nuevo ramal de manera dinamica	
			AsignarRamal(ListaColectivos->getItem(i));

		
			
		}

	}
	

	viejo->SetEstado(false);
	viejo->ColectivoRoto(ListaColectivos, viejo);
	//imprimimos monto total de cada colectivo, cantidad de pasajeros que se suben y el total de todos los colectivos
	string info = InfoDia(ListaColectivos);
	cout << info << endl;



	//ver liberar memoria
	delete nuevo;
	delete viejo;
	delete acordeon;

	return 0;
}