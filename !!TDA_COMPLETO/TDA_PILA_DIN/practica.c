#include "practica.h"

void p_crear_pila(t_pila* pp)
{
    *pp = NULL;
}
int p_poner_en_pila(t_pila* pp,void* elem,size_t tam)
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
    
   
    memcpy(nue->info,elem,tam);
    nue->tam = tam;
    nue->sig = *pp;
    *pp = nue;
    return 1;

}
void p_sacar_de_pila(t_pila*pp, void* elem,size_t tam)
{
    t_nodo* elim;

    if(!*pl)    //si la pila esta vacia
        return;

    elim = *pp;
    *pp = elim->sig;

    memcpy(elem,elim->info,MEN(tam,elim->tam));

    free(elim->info);
    free(elim);

    return 1;
}
void p_ver_tope_de_pila(t_pila* pp,void* elem,size_t tam)
{

    if(!*pp)
        return;

    memcpy(elem,(*pp)->info,MEN(tam,(*pp)->tam));
    

}
int p_pila_vacia(t_pila*pp)
{
    if(!*pp)
        return 1;
    return 0;
}
int p_pila_llena(t_pila *pp,size_t tam)
{
    t_nodo* nue;
    nue = (t_nodo*)malloc(sizeof(t_nodo)+tam);
    if(!nue)
        return 1;
    return 0;


}
