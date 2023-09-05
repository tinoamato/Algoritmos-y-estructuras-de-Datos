#ifndef FUNCT_H_INCLUDED
#define FUNCT_H_INCLUDED

#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define MIN(A,B) ((A)<(B)?(A):(B))


typedef struct SNodo
{
    void* elem;
    size_t tamElem;
    struct SNodo* sig;
}
Nodo;

typedef Nodo* Pila;

void crearPila(Pila *pp);
int apilar(Pila *pp, const void* elem, size_t tamElem);
void calculadora(char *nomArch);
void crearLotePrueba(char* nomArch);
int verTopeDePila(const Pila* pp, void* elem);

#endif // FUNC_H_INCLUDED
