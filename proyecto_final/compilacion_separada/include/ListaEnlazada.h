#ifndef LISTA_ENLAZADA_H
#define LISTA_ENLAZADA_H
#include "Sensor.h"
template <typename T>
struct NodoGen
{
    T dato;
    NodoGen<T>* siguiente;
    NodoGen(T _d){
        this->dato = _d;
        this->siguiente = nullptr;
    } 

};
//Lista generica

template<typename T>
class ListaGen
{
private:
    NodoGen<T>* head;
public:
ListaGen():head(nullptr){}
~ListaGen(){
    NodoGen<T>* actual = head;
    while (actual != nullptr)
    {
        NodoGen<T>* aux = actual->siguiente;
        delete actual->dato;
        delete actual;
        actual = aux;
    }
    head = nullptr;
}
void insertar(T nuevoDato){
    NodoGen<T>* nuevo = new NodoGen<T>(nuevoDato);
    nuevo->siguiente = head;
    head = nuevo;
}
void procesartodo( ){
    NodoGen<T>* actual = head;
    while (actual != nullptr)
    {
        actual->dato->procesarLectura();
        actual= actual->siguiente;
    }
    
}

};
#endif