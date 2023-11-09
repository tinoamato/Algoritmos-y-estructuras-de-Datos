#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
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

typedef t_nodo* t_lista;

///PRIMITIVAS LISTA

void crear_lista(t_lista* pl);
int lista_vacia(t_lista* pl);
void vaciar_lista(t_lista* pl);
#endif // LISTA_H_INCLUDED
