#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(a,b) ((a)<(b) ? (a):(b))

typedef struct sNodo
{
    void* elem;
    size_t tamElem;
    struct sNodo* sig;

}t_nodo;

typedef t_nodo* pila;

void crear_pila(pila* pp);
bool apilar (pila* pp, const void* elem, size_t tamElem);
bool desapilar (pila* pp,void* elem,size_t tamElem);
bool ver_tope_de_pila(const pila* pp, void* elem,size_t tamElem);
bool pila_vacia(const pila* pp);
bool pila_llena(const pila* pp, size_t tamElem);
void vaciar_pila(pila* pp);

int max_mov(int anillos);


#endif // FUNCIONES_H_INCLUDED
