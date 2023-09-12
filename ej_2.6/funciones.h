#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MENOR(a,b) ((a)<(b) ? (a):(b))
#define ARCH "ordenar.dat"

typedef struct sNodo
{
    void* elem;
    size_t tamElem;
    struct sNodo* sig;
}t_nodo;
typedef t_nodo* t_pila;

typedef struct
{
    int cod;
    char sector;
    float precio;
}t_producto;

void crear_lote(const char* nomArch);
void crear_pila(t_pila* pp);
int apilar(t_pila* pp,const void* elem, size_t tamElem);
int desapilar(t_pila* pp,void* elem,size_t tamElem);
int ver_tope_pila(const t_pila* pp, void* elem);
int pila_vacia(const t_pila* pp);





#endif // FUNCIONES_H_INCLUDED
