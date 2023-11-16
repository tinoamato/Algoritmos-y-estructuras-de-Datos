#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



typedef struct s_nodo
{
    void *info;
    size_t tam;
    struct s_nodo *sig;
} t_nodo;

typedef t_nodo *t_lista;

///PRIMITIVAS LISTA
void crearLista(t_lista *pl);
int listaLlena(t_lista *pl, size_t tam);
int listaVacia(t_lista *pl);
int insertarPrimeroLista(t_lista *pl, size_t tam, const void *elem);
int insertarEnOrdenLista(t_lista *pl, size_t tam, const void *elem, int(*cmp)(const void*,const void*));
int insertarEnPosicionlLista(t_lista *pl, size_t tam, const void *elem, unsigned pos);
int insertarFinalLista(t_lista *pl, size_t tam, const void *elem);
int eliminarPrimeroLista(t_lista *pl, size_t tam, void *elem);
int eliminarElementoLista(t_lista *pl, size_t tam, void *elem, int(*cmp)(const void*,const void*));
int verPrimeroDeLista(const t_lista *pl, size_t tam, void *elem);
int verElementoDeLista(const t_lista *pl, size_t tam, void *elem, int (*cmp)(const void*, const void*)); ///PREGUNTAR SI ESTA BIEN ESTA PRIMITIVA O NO LA PUEDO CREAR
int recorrerLista(const t_lista *pl, void (*accion)(const void*,unsigned, void*), void *parametro);
void vaciarLista(t_lista *pl);



#endif // LISTA_H_INCLUDED
