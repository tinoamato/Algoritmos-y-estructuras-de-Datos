#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_nodo
{
    void* info;
    size_t tam;
    struct s_nodo *sig;

} t_nodo;
typedef t_nodo* t_lista;

int poner_al_final_lista (t_lista* pl, void* pd,size_t tam);



#endif // FUNCIONES_H_INCLUDED
