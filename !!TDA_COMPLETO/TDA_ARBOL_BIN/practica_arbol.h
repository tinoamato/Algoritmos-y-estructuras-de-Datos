#ifndef PRACTICA_ARBOL_H_INCLUDED
#define PRACTICA_ARBOL_H_INCLUDED
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

void p_crear_arbol(t_arbol* pa);
int p_insertar_en_arbol(t_arbol* pa,void* elem,size_t tam,int (*cmp)(const void*,const void*));
int p_r_insertar_en_arbol(t_arbol* pa,void* elem,size_t tam,int (*cmp)(const void*,const void*));
void p_recorrer_arbol_en_orden(t_arbol* pa,void (*accion)(const void*,void*),void* param);
void p_recorrer_arbol_pre_orden(t_arbol* pa,void (*accion)(const void*,void*),void* param);
void p_recorrer_arbol_pos_orden(t_arbol* pa,void (*accion)(const void*,void*),void* param);
void p_vaciar_arbol(t_arbol* pa);
void p_podar_hasta_nivel(t_arbol* pa,int n);
int p_contar_nodos(t_arbol* pa);
int p_contar_nodos_hasta_nivel(t_arbol* pa,int n); ///CONSULTAR
int p_altura_arbol(t_arbol* pa);
t_nodoa** p_mayor_nodo(t_arbol* pa);
t_nodoa** p_menor_nodo(t_arbol* pa);


#endif // PRACTICA_ARBOL_H_INCLUDED
