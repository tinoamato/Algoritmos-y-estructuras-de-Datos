#ifndef FUNCT_H_INCLUDED
#define FUNCT_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM_VEC 100
#define MENOR(x,y) ((x)<(y) ? (x) : (y))

typedef struct
{
    char vec[TAM_VEC];
    unsigned tope;
}t_pila;

int poner_en_pila (t_pila *pp, const void *pd, size_t tam);
int sacar_de_pila(t_pila *pp, void *pd, size_t tam);
void crear_pila (t_pila *pp);                        // inicializar_pila
void vaciar_pila(t_pila *pp);                     // descartar todos los elementos indiscriminadamente
int ver_tope(const t_pila *pp, void* pd, size_t tam);
int pila_llena( const t_pila *pp,size_t tam);                                            // preg si hay lugar
int pila_vacia(const t_pila *pp);



#endif // FUNCT_H_INCLUDED
