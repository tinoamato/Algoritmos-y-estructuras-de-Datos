#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define MENOR(a,b) ((a)<(b) ? (a):(b))
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ARCH "pedidos.dat"

typedef struct s_nodo
{
    void* info;
    size_t tam;
    struct s_nodo* sig;
}t_nodo;

typedef struct
{
    t_nodo* pri;
    t_nodo* ult;
}t_cola;

typedef struct
{
    int nro_pedido;
    char cod_prod[50];
    int cant;
    float precio;
}tPedido;

void crear_cola (t_cola* pc);
int poner_en_cola(t_cola* pc,const void* pd, size_t tam);
int sacar_de_cola (t_cola* pc, void* pd,size_t tam);
void crear_lote(const char* nomArch);
void mostrar_archivo(const char* nomArch);




#endif // FUNCIONES_H_INCLUDED
