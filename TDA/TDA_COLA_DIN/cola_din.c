#include "cola_din.h"

void crear_cola(t_cola* pc)
{
    pc->pri = pc->ult = NULL;
}
int poner_en_cola(t_cola* pc,const void* elem, size_t tam)
{
    t_nodo* nue;

    if(!pc)
        return 0;

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
    nue->sig = NULL;

    if(pc->ult)//esta vacia
        pc->ult->sig = nue;
    else
        pc->pri = nue;

    pc->ult = nue;

    return 1;
}
int sacar_de_cola(t_cola *pc, void* elem,size_t tam)
{
    t_nodo* elim = pc->pri;

    if(!pc->pri)
        return 0;

    memcpy(elem,elim->info,MEN(tam,elim->tam));

    pc->pri = elim->sig;

    if(!pc->pri)
        pc->ult = NULL;

    free(elim->info);
    free(elim);

    return 1;
}
int cola_llena(t_cola* pc,size_t tam)
{
    t_nodo* nue = malloc(sizeof(t_nodo)+tam);

    if(!nue)
        return 1;

    free(nue);
    return 0;
}
int cola_vacia(t_cola* pc)
{
    if(!pc->pri)
        return 1;
    return 0;
}
void vaciar_cola(t_cola* pc)
{
    t_nodo* elim = pc->pri;

    if(!elim)
        return;
    while(elim)
    {
        pc->pri = elim->sig;
        free(elim->info);
        free(elim);
        elim = pc->pri;
    }
    pc->ult = NULL;

}
int frente_de_cola(t_cola* pc,void* elem,size_t tam)
{
    t_nodo* frente;

    if(!pc->pri)
        return 0;
    frente = pc->pri;
    memcpy(elem,frente->info,MEN(tam,frente->tam));
    return 1;
}
