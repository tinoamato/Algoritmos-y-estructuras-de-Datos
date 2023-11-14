#include "practica.h"

void p_crear_cola(t_cola* pc)
{
    pc->pri = pc->ult = NULL;
}
int p_poner_en_cola(t_cola* pc,void* elem,size_t tam)
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
    memcpy (nue->info,elem,tam);
    nue->tam = tam;
    nue->sig = NULL;

    if(pc->ult)
        pc->ult->sig = nue;
    else
        pc->pri = nue;

    pc->ult = nue;
    
    return 1;
}

int p_sacar_de_cola(t_cola* pc,void* elem,size_t tam)
{
    t_nodo* elim;

    if(!(pc)->pri)
        return 0;

    elim = pc->pri;
    memcpy(elem,elim->info,MEN(tam,elim->tam));
    pc->pri = elim->sig;

    if(!pc->pri)
        pc->ult = NULL;

    free(elim->info);
    free(elim);

    return 1;
}
int  p_cola_llena(t_cola* pc,size_t tam)
{
    t_nodo* nue;
    nue = (t_nodo*)malloc(sizeof (t_nodo)+tam);
    if(!nue)
        return 1;

    free(nue);
    return 0;

}
int p_cola_vacia(t_cola* pc)
{
    if(!pc->pri)
        return 1;
    return 0;
}
void p_vaciar_cola(t_cola*pc)
{
    t_nodo* elim;
    
    elim = pc->pri;
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
int p_frente_de_cola(t_cola* pc,void* elem,size_t tam)
{
    t_nodo* frente = pc->pri;

    if(!frente)
        return 0;

    memcpy(elem,frente->info,MEN(tam,frente->info));

    return 1;
}



