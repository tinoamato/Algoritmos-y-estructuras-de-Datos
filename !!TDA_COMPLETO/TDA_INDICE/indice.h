#ifndef INDICE_H_INCLUDED
#define INDICE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(x,y) ((x)<(y)?(x):(y))



typedef struct s_nodo
{
    void* info;
    size_t tam;
    struct  s_nodo* sig;
    
    
}t_nodo;

typedef t_nodo* t_lista;

typedef struct  
{
   size_t tam_clave;
   t_lista lista;
   int (*cmp)(const void*,const void*);
   void* reg_indice;
}t_indice;

///________LISTA________________________________________________________________________________________________///
void crear_lista(t_lista* pl);
int insertar_en_lista_ord(t_lista* pl,void* elem, size_t tam,int(*cmp)(const void*,const void*));

///_________INDICE_______________________________________________________________________________________________///

int crear_indice(t_indice* ind,size_t tam,int (*cmp)(const void*,const void*));
int insertar_en_indice(t_indice* ind,void* clave, unsigned num_reg);




#endif // INDICE_H_INCLUDED
