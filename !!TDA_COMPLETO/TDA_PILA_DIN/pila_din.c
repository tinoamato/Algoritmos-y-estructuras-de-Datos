#include "pila_din.h"

void crear_pila(t_pila* pp)
{
    *pp = NULL;
}
int poner_en_pila(t_pila* pp, void* elem,size_t tam)
{
    t_nodo* nue;

    nue = (t_nodo*)malloc(sizeof(t_nodo));
    if(!nue)
        return 0;

    nue->info = malloc(tam);
    if(!nue->info)
    {
        free(nue);
        return 0;
    }

    nue->tam = tam;
    memcpy(nue->info,elem,tam);
    nue->sig = *pp;

    *pp = nue;

    return 1;
}
int sacar_de_pila(t_pila* pp,void* elem,size_t tam)
{
    t_nodo* elim;

    if(!*pp)
        return 0;

    elim = *pp;
    *pp = elim->sig;

    memcpy(elem,elim->info,MEN(elim->tam,tam));

    free(elim->info);
    free(elim);

    return 1;
}
int ver_tope_pila(t_pila* pp,void*elem,size_t tam)
{
    t_nodo* tope;

    if(!*pp)
        return 0;
    tope = *pp;

    memcpy(elem,tope->info,MEN(tope->tam,tam));
    return 1;
}

int pila_vacia(t_pila* pp)
{
    if(*pp == NULL)
        return 1;
    return 0;
}
int pila_llena(t_pila* pp,size_t tam)
{
    t_nodo* nue = malloc(sizeof(t_nodo)+tam);
    if(!nue)
        return 1;

    free(nue);

    return 0;
}

