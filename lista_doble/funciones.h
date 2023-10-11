#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct s_nodo
{
    void* info;
    size_t tam;
    struct s_nodo *sig, *ant;
}t_nodod;

typedef t_nodod* t_listad;



#endif // FUNCIONES_H_INCLUDED
