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
void recorrer_arbol_en_orden(t_arbol* pa,int accion(void*,void*),void* param);
void recorrer_arbol_pos_orden(t_arbol* pa,int accion(void*,void*),void* param);
void recorrer_arbol_pre_orden(t_arbol*pa, int accion(void*,void*),void* param);
void vaciar_arbol(t_arbol* pa);
void podar_hasta_nivel(t_arbol* pa,int n);
int contar_nodos(t_arbol* pa);
int contar_nodos_hasta_nivel(t_arbol* pa,int n); ///CONSULTAR
int altura_arbol(t_arbol* pa);
t_nodoa** mayor_nodo(t_arbol* pa);
t_nodoa** menor_nodo(t_arbol* pa);
int eliminar_raiz(t_arbol* pa,void* elem,size_t tam);
int compINT(const void* a, const void*b);
int printear(void* elem,void* param);
int copiar_dato_arch(void* dest,void*orig,size_t tam,int pos);
int copiar_dato_vec(void* dest,void* orig,size_t tam,int pos);
int cargar_datos_rec_gen(t_arbol* pa,void* orig,size_t tam,int li,int ls,int copiar_dato(void* dest,void*orig,size_t tam,int pos));
int cargar_arbol_arch(t_arbol* pa,char* path,size_t tam);
int cargar_arbol_vec(t_arbol* pa,void* vec,int ce,size_t tam);



#endif // ARBOL_BIN_H_INCLUDED
