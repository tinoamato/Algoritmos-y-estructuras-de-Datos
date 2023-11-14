#ifndef PRACTICA_H_INCLUDED
#define PRACTICA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_nodo
{
    void* info;
    size_t tam;
    struct s_nodo* sig;
}t_nodo;
struct t_nodo* t_lista;

void p_crear_lista(t_lista* pl);
int p_insertar_ordenado_lista(t_lista*pl, void* elem,size_t tam);




#endif // PRACTICA_H_INCLUDED
