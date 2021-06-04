#pragma once
#pragma once
#define NMAX 20
#include <string>
using namespace std;

template <class T>

class cListaT
{
protected:
	T** vector;
	unsigned int CA, TAM;

public:
	cListaT(unsigned int TAM = NMAX);
	~cListaT();

	void Redimencionalizar();

	bool AgregarItem(T* item);

	T* QuitarPorClave(string clave);
	T* QuitarPorItem(T* item);
	T* QuitarenPos(unsigned int pos);

	void EliminarPorClave(string clave);
	void EliminarPorItem(T* item);
	void EliminarEnPos(unsigned int pos);

	void Listar();

	T* BuscarItem(string clave);
	T* getItem(unsigned int pos);

	unsigned int getItemPos(string clave);

	unsigned int getCA();
	unsigned int getTAM();

	T* operator[] (unsigned int pos);
	void operator+(T* item);
	void operator<<(T* item);
};

template<class T>
inline cListaT<T>::cListaT(unsigned int TAM)
{
	vector = new T * [TAM];
	for (unsigned int i = 0; i < TAM; i++)
	{
		vector[i] = NULL;
	}
	this->TAM = TAM;
	CA = 0;
}

template<class T>
inline cListaT<T>::~cListaT()
{
	if (vector != NULL)
	{
		for (unsigned int i = 0; i < CA; i++)
		{
			if (vector[i] != NULL)
			{
				delete vector[i];
			}
		}
		delete[] vector;
	}
}

template<class T>
inline void cListaT<T>::Redimencionalizar()
{
	unsigned int tam_aux = TAM * 2;
	T** lista_aux = new T * [tam_aux]; //pedimos memoria para crear la lista auxiliar
	for (unsigned int i = 0; i < CA; i++)
	{
		//nos copiamos la informacion de la lista actual a la lista auxiliar
		lista_aux[i] = vector[i];
	}

	//vaciamos la lista vieja (no la eliminamos)
	delete[] vector;

	//nos copiamos la lista auxiliar a nuestra lista original vacia
	vector = lista_aux;
}

template<class T>
inline bool cListaT<T>::AgregarItem(T* item)
{
	T* aux = BuscarItem(item->GetClave()); //chequeamos que el item no se encuentre en la lista
	if (aux != NULL) throw new exception("Ya se encuentra en la lista"); //tiramos una excepcion avisando que el elemento ya se encuentra en la lista

	if (CA < TAM) //preguntamos que si hay lugar en la lista
	{
		//si hay lugar agregamos el item al final de la lista y actualizamos la CA
		vector[CA++] = item;
	}
	else //en caso de que no hay lugar 
	{
		Redimencionalizar(); //redimencionalizamos la lista
		vector[CA++] = item; //una vez agrandada la lista, agregamos el nuevo item al final y actualizamos la CA
	}
	return true; //devolvemos ture si pudimos agg el elemento con exito
}

template<class T>
inline T* cListaT<T>::QuitarPorClave(string clave)
{
	unsigned int pos = getItemPos(clave); //almacenamos la posicion del elemento al que le corresponde la clave que pasamos por parametro
	if (pos >= CA)
		return NULL; //quiere decir que el elemento no se encuentra en la lista y devolvemos NULL

	return QuitarenPos(pos); //en caso de que se encuentre en la lista, llamamos al metodo QuitarenPos, que quita y reotorna el elemento quitado
}

template<class T>
inline T* cListaT<T>::QuitarPorItem(T* item)
{
	//IDEM metodo QUITAR(string clave), pero pasamos como parametro un item

	unsigned int pos = getItemPos(item->GetClave());
	if (pos >= CA)
		return NULL;
	return QuitarenPos(pos);
}

template<class T>
inline T* cListaT<T>::QuitarenPos(unsigned int pos)
{
	if (pos >= CA) //verfiacamos que la posicion se encuentre dentro de la lista
		throw new exception("Posicion invalida"); //en caso de que no este en la lista, lanzamos una excepcion

	//si la posicion es valida y existe el elemento
	T* aux = vector[pos]; //nos alamcenamos en una variable aux el elemento que se encuentra en esa poscion

	//recorremos la lista desde la posicon del elemento que quitamos hasta el ultimo elemento -1
	for (unsigned int i = pos; i < CA - 1; i++)
	{
		//vamos subiendo los elementos una posicion mas arriba
		vector[i] = vector[i + 1];
	}
	vector[CA - 1] = NULL; //ponemos en null el ultimo elemento
	CA--; //actualizamos la cantidad actual 
	return aux; //retornamos el elemento que quitamos 
}

template<class T>
inline void cListaT<T>::EliminarPorClave(string clave)
{
	unsigned int pos = getItemPos(clave); //obtenemos la posicion del elemento a eliminar
	if (pos < CA) //revisamos que este en la lista
		EliminarEnPos(pos);//llamamos a la funcion elimar por poscion para elimar el elemento
	else
		throw new exception("No se encuentra en la lista");
	/*
	T* dato = QuitarPorClave(clave); //si esta en la lista, llamamos a la funcion quitar, y nos alamcenamos el elemento que se retorna

	if (dato != NULL) //verificamos que el dato que recibimos no sea nulo
		delete dato; //si no es nulo lo eliminamos
	else {
		//en caso de que es nulo, quiere decir que no se encontraba, y lanzamos un excepcion informando esto
		throw new exception("No se encontro el elemento buscado.");
	}
	*/
}

template<class T>
inline void cListaT<T>::EliminarPorItem(T* item)
{
	EliminarPorClave(item->GetClave());
}

template<class T>
inline void cListaT<T>::EliminarEnPos(unsigned int pos)
{
	T* dato = QuitarenPos(pos); //si esta en la lista, llamamos a la funcion quitar, y nos alamcenamos el elemento que se retorna 

	if (dato != NULL) //verificamos que el dato que recibimos no sea nulo
		delete dato; //si no es nulo lo eliminamos

}

template<class T>
inline void cListaT<T>::Listar()
{
	//recorre la lista 
	for (unsigned int i = 0; i < CA; i++)
	{
		//imprime cada elemento de la lista
		vector[i]->Imprimir();
	}
}

template<class T>
inline T* cListaT<T>::BuscarItem(string clave)
{
	//recorre la lista
	for (unsigned int i = 0; i < CA; i++)
	{
		//busca los elemntos cuya clave coincida con la clave pasada por parametro
		if (vector[i]->GetClave() == clave)
			return vector[i]; //cuando lo encuentra retorna ese elemento
	}
	return NULL; //en caso de no encontrarlo devuelve null
}

template<class T>
inline T* cListaT<T>::getItem(unsigned int pos)
{
	if (pos < CA) //revisa que la poscion se encuentre en la lista
		return vector[pos]; //si se encuentra devuelve el elmento que esta en esa posicion
	else
		return NULL; //en caso de no encontrarlo devuelve null
}

template<class T>
inline unsigned int cListaT<T>::getItemPos(string clave)
{
	//recorre la lista
	for (unsigned int i = 0; i < CA; i++)
	{
		//busca los elemntos cuya clave coincida con la clave pasada por parametro
		if (vector[i]->GetClave() == clave)
			return i; //si se encuentra devuelve la posicion del elemento 
	}
	return INT_MAX;
}

template<class T>
inline unsigned int cListaT<T>::getCA()
{
	return CA;
}

template<class T>
inline unsigned int cListaT<T>::getTAM()
{
	return TAM;
}

template<class T>
inline T* cListaT<T>::operator[](unsigned int pos)
{
	//sobrecargamos el operador []
	return getItem(pos);
}

template<class T>
inline void cListaT<T>::operator+(T* item)
{
	//pregunta si hay lugar en la lista
	if (CA < TAM)
		vector[CA++] = item; //sobrecarga el operador +

}

template<class T>
inline void cListaT<T>::operator<<(T* item)
{
	item->Imprmir();
}
