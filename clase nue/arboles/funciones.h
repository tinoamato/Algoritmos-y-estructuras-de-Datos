#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
typedef struct s_nodoa
{
    void* info;
    size_t tam;
    struct s_nodoa *izq, *der;
}t_nodoa;
typedef t_nodoa *t_arbol;

///crear_arbol

int insertar_arbol(t_arbol* pa,void* info,size_t tam, int (*cmp)(const void*,const void*));
int r_insertar_arbol(t_arbol* pa,void* info,size_t tam, int (*cmp)(const void*,const void*));
void recorrer_arbol_en_orden(const t_arbol* pa,void(*accion)(void*,void*),void* param);
void recorrer_arbol_pos_orden(const t_arbol* pa,void(*accion)(void*,void*),void* param);


#endif // FUNCIONES_H_INCLUDED
