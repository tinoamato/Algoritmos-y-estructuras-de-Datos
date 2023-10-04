#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct s_nodo
{
    void* info;
    size_t tam;
    struct s_nodo* sig;
}t_nodo;

typedef t_nodo* t_lista;
typedef t_nodo* t_colac;

int map_lista (const t_lista *pl,int(*accion)(void*,void*),void* param);
void filter_lista (t_lista *pl, int (*filtro) (const void*, void*),void* param);



#endif // FUNCIONES_H_INCLUDED
