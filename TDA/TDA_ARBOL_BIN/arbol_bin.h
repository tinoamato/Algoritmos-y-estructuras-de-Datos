#ifndef ARBOL_BIN_H_INCLUDED
#define ARBOL_BIN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX(x,y) ((x)>(y)?(x):(y))

typedef struct s_nodoa
{
    void* info;
    size_t tam;
    struct s_nodoa* izq,*der;
}t_nodoa;

typedef t_nodoa* t_arbol;

void crear_arbol(t_arbol* pa);
int insertar_en_arbol(t_arbol* pa,void* elem,size_t tam,int cmp(const void*,const void*));
int r_insertar_en_arbol(t_arbol* pa,void* elem,size_t tam,int cmp (const void*,const void*));

#endif // ARBOL_BIN_H_INCLUDED
