#ifndef PILA_DIN_H_INCLUDED
#define PILA_DIN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEN(x,y) ((x)<(y)?(x):(y))

typedef struct s_nodo
{
    void* info;
    size_t tam;
    struct s_nodo* sig;
}t_nodo;

typedef t_nodo* t_pila;

void crear_pila(t_pila* pp);
int poner_en_pila(t_pila* pp, void* elem,size_t tam);
int sacar_de_pila(t_pila* pp,void* elem,size_t tam);
int ver_tope_pila(t_pila*pp, void* elem,size_t tam);
int pila_vacia(t_pila* pp);
int pila_llena(t_pila* pp, size_t tam);

#endif // PILA_DIN_H_INCLUDED
