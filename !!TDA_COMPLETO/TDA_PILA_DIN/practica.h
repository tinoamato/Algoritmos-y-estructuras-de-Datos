#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEN(x,y) ((x)<(y)?(x):(y))

typedef struct s_nodo
{
    void* info;
    size_t tam;
    struct s_nodo* sig;
}t_nodo;

typedef t_nodo* t_pila;

void p_crear_pila(t_pila* pp);
int p_poner_en_pila(t_pila* pp, void* elem,size_t tam);
int p_sacar_de_pila(t_pila* pp,void* elem,size_t tam);
void p_ver_tope_de_pila(t_pila* pp,void* elem,size_t tam);
int p_pila_vacia(t_pila*pp);
int p_pila_llena(t_pila *pp,size_t tam);
