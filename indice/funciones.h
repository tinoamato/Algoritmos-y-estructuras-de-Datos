#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_nodo
{
    void* info;
    size_t tam;
    struct s_nodo *sig;

} t_nodo;
typedef t_nodo* t_lista;

typedef struct
{
    void* clave;
    int reg;
    t_nodo* sig;
}t_indice;



#endif // FUNCIONES_H_INCLUDED
