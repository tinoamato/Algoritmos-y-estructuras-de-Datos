#include "funciones.h"

void crear_cola(t_cola *pc)
{
    pc->pri=NULL;
    pc->ult=NULL;
}


int poner_en_cola(t_cola *pc,const void *pd, size_t tam)
{
    t_nodo *nue=(t_nodo*)malloc(sizeof(t_nodo));

    if(!nue)
        return 0; // COLA LLENA
    nue->info=malloc(tam);

    if(!nue->info)
    {
        free(nue);
        return 0; //COLA LLENA
    }
    nue->tam=tam;
    memcpy(nue->info,pd,tam);
    nue->sig=NULL;

    if(pc->ult)
        pc->ult->sig=nue;
    else pc->pri=nue;


    pc->ult=nue;
    return 1;
}

int sacar_de_cola(t_cola *pc, void* pd, size_t tam)
{
    t_nodo *elim=pc->pri;

    if(!pc->pri)
        return 0;

    memcpy(pd,elim->info,MIN(tam,elim->tam));

    pc->pri=elim->sig;
    free(elim->info);
    free(elim);

    if(!pc->pri)
    {
        pc->ult=NULL;
    }

    return 1;
}

int cola_llena(t_cola *pc, size_t tam)
{
    t_nodo *Nodo= malloc(tam);

    if(!Nodo)
        return 1;

    else
    {
        free(Nodo);
        return 0;
    }

}

int cola_vacia(t_cola *pc)
{
    if(!pc->ult)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int frente_de_cola(t_cola *pc, void* elem, size_t tam)
{
    t_nodo *frente=pc->pri;
    if(!pc->pri)
        return 0; // COLA VACIA

    if(!frente->info)
    {
        free(frente);
        return 0;
    }
    memcpy(elem,frente->info,MIN(tam,frente->tam));

    return 1;
}

void vaciar_cola(t_cola *pc)
{
    t_nodo *elim=pc->pri;
    while(pc->pri)
    {
        pc->pri=elim->sig;
        free(elim->info);
        free(elim);
        elim=pc->pri;
    }
    pc->ult=NULL;
}
