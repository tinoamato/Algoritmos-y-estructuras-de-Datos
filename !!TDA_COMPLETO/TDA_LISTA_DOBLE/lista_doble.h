#ifndef LISTA_DOBLE_H_INCLUDED
#define LISTA_DOBLE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct  s_nodo
{
    void* info;
    size_t tam;
    struct  s_nodo *ant,*sig; 
}t_nodo;

typedef t_nodo* t_listad;
void crear_lista(t_listad* pl);
void vaciar_lista(t_listad* pl);
int lista_vacia(const t_lista* pl);
int instertar_en_listad_ordenado(t_lista* pl,void* elem,size_t tam,int (*cmp)(const void*, const void*));
int eliminar_de_lista(t_listad* pl, void*elem,size_t tam,int (*cmp)(const void*,const void*));

#endif // LISTA_DOBLE_H_INCLUDED
