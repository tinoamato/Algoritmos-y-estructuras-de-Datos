#include "funciones.h"

int poner_al_final_lista (t_lista* pl, void* pd,size_t tam)
{
    t_nodo* nue;

    while (*pl)
    {
        pl = &(*pl)->sig;
    }
    nue = (t_nodo*)malloc(sizeof(t_nodo));
    if(!nue)
        return 0; ///lista llena
    nue->info = malloc(tam);
    if(!nue->info)
    {
        free(nue);
        return 0; ///lista llena
    }

    nue->sig = NULL;
    nue->tam = tam;
    memcpy(nue->info,pd,tam);

    *pl = nue;
    return 1;


}
int poner_en_pos_lista (t_lista* pl, void* pd,size_t tam, unsigned pos)
{
    t_nodo* nue;

    while (*pl && pos--)
    {
        pl = &(*pl)->sig;
    }
    nue = (t_nodo*)malloc(sizeof(t_nodo));
    if(!nue)
        return 0; ///lista llena
    nue->info = malloc(tam);
    if(!nue->info)
    {
        free(nue);
        return 0; ///lista llena
    }

    nue->sig = *pl;
    nue->tam = tam;
    memcpy(nue->info,pd,tam);

    *pl = nue;
    return 1;


}
int poner_en_orden_lista (t_lista* pl, void* pd,size_t tam, int(*cmp)(const void*, const void*))
{
    t_nodo* nue;
    int comp;


    while (*pl && (comp = cmp(pd,(*pl)->info))>0)
    {
        pl = &(*pl)->sig;
    }
    if(*pl && !comp)
        nue = (t_nodo*)malloc(sizeof(t_nodo));
    if(!nue)
        return 0; ///lista llena
    nue->info = malloc(tam);
    if(!nue->info)
    {
        free(nue);
        return 0; ///lista llena
    }

    nue->sig = *pl;
    nue->tam = tam;
    memcpy(nue->info,pd,tam);

    *pl = nue;
    return 1;


}
/* para no ordenada
while(*pl && cmp(pd,(*pl)->info !=0)
        pl = &(*pl)->sig;
    if(!*pl)
        return 0; //no existe
*/
int sacar_elem_lista_ordenada(t_lista* pl, void* pd,size_t tam,int(*cmp)(const void*, const void*))
{
    int comp;
    t_nodo* elim;


    while (*pl && (comp = cmp(pd,(*pl)->info))>0) ///!=0 si la lista no esta ordenada
    {
        pl = &(*pl)->sig;
    }

    if(!*pl || comp)
        return 0; //no existe

    elim = *pl;
    *pl = elim->sig;
    memcpy(pd,elim->info,MEN(tam,elim->tam));
    free(elim->info);
    free(elim);

    return 1;

}
//hacer mostrar sin free ni cambiar *pl
//crear /vaciar/ lista -> pila list
