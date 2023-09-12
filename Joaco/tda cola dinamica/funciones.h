#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MIN(A,B) ((A>B)?(A):(B))

typedef struct s_nodo
{
    void *info;
    size_t tam;
    struct s_nodo* sig;
}t_nodo;


typedef struct
{
    t_nodo *pri;
    t_nodo *ult;
}t_cola;

void crear_cola(t_cola *pc);
int poner_en_cola(t_cola *pc,const void *pd, size_t tam);
int sacar_de_cola(t_cola *pc, void* pd, size_t tam);
int cola_llena(t_cola *pc, size_t tam);
int frente_de_cola(t_cola *pc, void* elem, size_t tam);
void vaciar_cola(t_cola *pc);
int cola_vacia(t_cola *pc);
#endif // FUNCIONES_H_INCLUDED
