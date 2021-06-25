#define _CRT_SECURE_NO_WARNINGS
#include "Colectivo.h"
#define Tarifa 15


Colectivo::Colectivo(string codigo_colec, unsigned int cant_max_pas, eDireccion direccion, 
    float peso_max): codigo_colec(codigo_colec)
{
    tarifa = Tarifa;
    parada = 0;
    puerta = false;
    EstadoFunicionamiento = true;
    peso_actual = 0;
    cant_pasajeros = 0;
    pasajeros_totales = 0;
    monto_total = 0;
    this->cant_max_pas = cant_max_pas;
    this->direccion = direccion;
    this->peso_max = peso_max;
    ramal = NULL;
    ListaPasajerosCole = new cListaT<Pasajero>(cant_max_pas);
}

Colectivo::~Colectivo()
{
    delete ListaPasajerosCole;
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
                //subimos primero los pasajeros con discapacidad
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
                        
                        //ver de manejar la excepcion de eliminar item
                        try {
                            R->ListaParadas->getItem(i)->ListaPasajeros->EliminarPorItem(R->ListaParadas->getItem(i)->ListaPasajeros->getItem(i));
                        }
                        catch (exception* e){
                            cout << e->what() << endl;
                        }
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
                        
                        //manejar excepcion
                        try {
                            R->ListaParadas->getItem(i)->ListaPasajeros->EliminarPorItem(R->ListaParadas->getItem(i)->ListaPasajeros->getItem(i));
                        }
                        catch (exception* e) {
                            cout << e->what() << endl;
                        }
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
    catch (exception& e)
    {
        throw e;

    }
    monto_total = monto_total + monto;
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
                    throw e;
                    //cout << e->what() << endl;
                }
                this->cant_pasajeros = cant_pasajeros - 1;
            }
        }
        //cerramos la puerta
        puerta = false;
    }
}

bool Colectivo::VerificarPesoCant()
{
    int ca = ListaPasajerosCole->getCA(); //cantidad de pasajeros en la lista
    for (int i = 0; i < ca; i++)
    {
        peso_actual = peso_actual + ListaPasajerosCole->getItem(i)->GetPeso();
    }
    
    if (cant_max_pas <= cant_pasajeros || peso_max <= peso_actual)
        return false; //si supera la capacidad de pasajeros o la capacidad de peso
    else 
        return true;//hay lugar para que suban mas pasajeros y no superan la capacidad de peso
}

void Colectivo::ColectivoRoto(cListaT<Colectivo>* Lista, Colectivo* colec_roto)
{
    for (int i = 0; i < Lista->getCA(); i++)
    {
        
        if (Lista->getItem(i)->EstadoFunicionamiento == true && colec_roto->EstadoFunicionamiento == false)
        {
            //preguntamos que tenga lugar para recibir los pasajeros del colectivo roto
            if (Lista->getItem(i)->GetCantMax() - Lista->getItem(i)->GetCantActual() > colec_roto->GetCantActual())
            {
                //colec_sano = colec_roto; //ver aca!
                cListaT<Pasajero>* aux = new cListaT<Pasajero>(Lista->getItem(i)->cant_max_pas);
                for (int i = 0; i < Lista->getItem(i)->ListaPasajerosCole->getCA(); i++)
                {
                    //nos copiamos los pasajeros del colectivo sano a la lista aux
                    aux[i] = Lista->getItem(i)->ListaPasajerosCole[i];
                }
                for (int i = aux->getCA(); i < aux->getTAM(); i++)
                {
                    //nos copiamos los pasajeros del colectivo roto a la lista aux, justo despues de los pasajeros del colectivo sano.
                    aux[i] = colec_roto->ListaPasajerosCole[i];
                }
                //vaciamos la lista de pasajeros del colectivo sano (no la eliminamos)
                delete[] Lista->getItem(i)->ListaPasajerosCole;
                //nos copiamos la lista auxiliar a nuestra lista original vacia
                Lista->getItem(i)->ListaPasajerosCole = aux;

                //-----------------TALLLER-----------------//
                colec_roto->EstadoFunicionamiento = true;
                AsignarRamal(colec_roto);
            }
        }
    }
}

ostream& Colectivo::operator<<(ostream& os)
{
    os << "Colectivo:"<<endl<< "Codigo " << codigo_colec << endl;
    os << "Cantidad Maxima de pasajeros: " << cant_max_pas<< endl;
    os << "Tarifa: " << tarifa << endl;
    os << "Ramal: " << ramal << endl;

    return os;
}
