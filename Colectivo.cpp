#include "Colectivo.h"
#include "Parada.h"
#include "Ramal.h"
#include "Funciones.h"
#include <stdlib.h>
#define Tarifa 15
#define Extra 5


Colectivo::Colectivo(string codigo_colec, unsigned int cant_max_pas, unsigned int direccion, float peso_max, 
     Ramal* ramal): codigo_colec(codigo_colec)
{
    tarifa = Tarifa;
    this->cant_max_pas = cant_max_pas;
    this->direccion = direccion;
    this->peso_max = peso_max;
    this->ramal = ramal;
    ListaPasajerosCole = new cListaT<Pasajero>();
}

Colectivo::~Colectivo()
{
    delete ListaPasajerosCole;
}

float Colectivo::CalcularTarifa(int parada_inicial, int parada_final)
{
    //dependiendo la cantida de paradas entre la parada incial y la final, le sumamos un extra a la tarifa base.
    //cada para recorrida equivale a $5

    int diff = parada_final- parada_inicial;
    float TarifaTot = tarifa + (abs(diff) * Extra);

    return TarifaTot;
}

void Colectivo::SubirPasajero(Ramal *R)
{
    //recorrer la lista de paradas que posee el ramal, en el orden indicado
    if (R != NULL) {
        int inicio = R->GetCod();
        for (int i = inicio; i < inicio - 1; i++)
        {
            //abrimos las puertas del colectivo
            puerta = true;
            if (VerificarPesoCant()==true) 
            {
                //subimos primero los pasajeros con discapasidad
                if (i == R->ListaParadas->getItem(i)->ListaPasajeros->getItem(i)->GetParadaInicial() &&
                    R->ListaParadas->getItem(i)->ListaPasajeros->getItem(i)->GetDisc() == true)
                {
                    if (cant_pasajeros < cant_max_pas) // hay lugar en el colectivo?
                    {
                        try {
                            ListaPasajerosCole->AgregarItem(R->ListaParadas->getItem(i)->ListaPasajeros->getItem(i));
                        }
                        catch (exception* e)
                        {
                            cout << e->what() << endl;
                            break; // no suben mas pasajeros
                        }
                        //eliminamos de la lista de pasajeros de la parada, al pasajero que subimos
                        R->ListaParadas->getItem(i)->ListaPasajeros->EliminarPorItem(R->ListaParadas->getItem(i)->ListaPasajeros->getItem(i));
                        this->cant_pasajeros = cant_pasajeros + 1;
                        this->pasajeros_totales = pasajeros_totales + 1;
                    }
                }
                if (i == R->ListaParadas->getItem(i)->ListaPasajeros->getItem(i)->GetParadaInicial() &&
                    R->ListaParadas->getItem(i)->ListaPasajeros->getItem(i)->GetDisc() == false)
                {
                    if (cant_pasajeros < cant_max_pas) // hay lugar en el colectivo?
                    {
                        float tarifa = CalcularTarifa(R->ListaParadas->getItem(i)->ListaPasajeros->getItem(i)->GetParadaInicial(),
                            R->ListaParadas->getItem(i)->ListaPasajeros->getItem(i)->GetParadaFinal());

                        Cobrar(R->ListaParadas->getItem(i)->ListaPasajeros->getItem(i), tarifa);

                        try {
                            ListaPasajerosCole->AgregarItem(R->ListaParadas->getItem(i)->ListaPasajeros->getItem(i));
                        }
                        catch (exception* e)
                        {
                            cout << e->what() << endl;
                            break; // no suben mas pasajeros
                        }
                        //eliminamos de la lista de pasajeros de la parada, al pasajero que subimos
                        R->ListaParadas->getItem(i)->ListaPasajeros->EliminarPorItem(R->ListaParadas->getItem(i)->ListaPasajeros->getItem(i));
                        this->cant_pasajeros = cant_pasajeros + 1;
                        this->pasajeros_totales = pasajeros_totales + 1;
                    }
                }
            }
           
            //cerramos la puerta
            puerta = false;
        }
    }

}

void Colectivo::Cobrar(Pasajero* P, float monto)
{
    try
    {
        P->Pagar(monto);
    }
    catch (exception&e)
    {
        throw e;
        
    }
}

void Colectivo::BajarPasajero(Ramal* R)
{
    //recorrer la lista de paradas que posee el ramal, en el orden indicado
    if (R != NULL) {
        int inicio = R->GetCod();
        for (int i = inicio; i < inicio - 1; i++)
        {
            //abrimos las puertas del colectivo
            puerta = true;
            //bajamos a los pasajero cuya para final sea igual a la parada en la que nos encontramos
            if (i == ListaPasajerosCole->getItem(i)->GetParadaFinal())
            {
                try {
                    ListaPasajerosCole->EliminarPorItem(ListaPasajerosCole->getItem(i));
                }
                catch (exception* e) {
                    cout << e->what() << endl;
                }
                this->cant_pasajeros = cant_pasajeros - 1;
            }
        }
        //cerramos la puerts
        puerta = false;
    }
}

bool Colectivo::VerificarPesoCant()
{
    int ca = ListaPasajerosCole->getCA();
    for (int i = 0; i < ca; i++)
    {
        peso_actual = peso_actual + ListaPasajerosCole->getItem(i)->GetPeso();
    }
    
    if (cant_max_pas <= cant_pasajeros || peso_max <= peso_actual)
        return false;
    else 
        return true;
}

void Colectivo::ColectivoRoto(Colectivo* colec_sano, Colectivo* colec_roto)
{
    //preguntamos que tenga lugar para recibir los pasajeros del colectivo roto
    if (colec_sano->GetCantMax() - colec_sano->GetCantActual() > colec_roto->GetCantActual())
    {
        colec_sano = colec_roto;
        colec_sano->EstadoFunicionamiento = true;
        AsignarRamal(colec_sano);
    }
    else
        throw new exception("El colectivo auxiliar no posee lugar!");
}

string Colectivo::SistemaGPS()
{

    return string();
}
