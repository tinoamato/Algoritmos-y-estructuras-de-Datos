#ifndef INDICE_H_INCLUDED
#define INDICE_H_INCLUDED
#include "Lista.h"

typedef struct
{
    size_t tamClave;
    t_lista lista;
    int(*cmp)(const void*, const void*);
    void *reg_indice; ///HACER VOID DEL TAM DE LOS DOS
} t_indice;

///PRIMITIVAS INDICE
void ind_crear (t_indice* ind, size_t tam_clave, int (*cmp)(const void*, const void*));
int ind_insertar (t_indice* ind, void *clave, unsigned nro_reg);
int ind_eliminar (t_indice* ind, void *clave, unsigned *nro_reg);
int ind_buscar (const t_indice* ind, void *clave, unsigned *nro_reg);
int ind_cargar (t_indice* ind, const char* path);
int ind_grabar (const t_indice* ind, const char* path);
void ind_vaciar (t_indice* ind);
int ind_recorrer (const t_indice* ind, void (*accion)(const void *, unsigned, void *),void* param);

#endif // INDICE_H_INCLUDED
