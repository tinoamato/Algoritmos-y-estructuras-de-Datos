#include "funciones.h"
int map_lista (const t_lista *pl,int(*accion)(void*,void*),void* param)
{
    int r;

    while(*pl)
    {
        r = accion((*pl)->info,param);
        pl = &(*pl)->sig;
    }

    return r;
}

int grabar_archivo_bin(void *info, void *vInfo,void *vPf)
{
    int r;
    FILE* pf = (FILE*)vPf;

    r = fwrite(vInfo,sizeof(int),1,pf);

    return r!=0;
}


void filter_lista (t_lista *pl, int (*filtro) (const void*, void*),void* param)
{
    while(*pl)
    {
        if(!filtro((*pl)->info,param))
        {
            t_nodo *elim = pl;
            *pl = elim->sig;
            free(elim->info);
            free(elim);
        }
        else
        {
            pl = &(*pl)->sig;
        }
    }
}

int reduce_lista(const t_lista *pl, void* ret, int(*reduccion)(const void*,void*,void*),void* param)
{
    int r = 1;

    while(*pl && r)
    {
        r = reduccion((*pl)->info,ret,param);
        pl = &(*pl)->sig;


    }
    return r;
}

int promedio_alu(const void* valu,void* vprom,void* vcant_alu) //mal copiada
{
    t_alumno *alu = (t_alumno*)valu;

    int* prom = (int*)vprom,*vcant_alu = (int*)vcant_alu;
    *prom = ((*prom)*(*vcant_alu)+alu->prom)/(*vcant_alu+1);
    (*vcant_alu)++;

    return 1;

}

///-------------------------------------------------------------------------------------------///

///lista circular

//se inserta en el segundo nodo
//se saca en el segundo pq es el tope

int poner_en_pila (t_pilac *pp, void *info,size_t tam)
{
    t_nodo* nue = (t_nodo*)malloc(sizeof(t_nodo));

    if(!nue)
        return 0; //lista llena

    nue->info = malloc(tam);

    if(!nue->info)
    {
        free(nue);
        return 0; //pila llena
    }

    memcpy(nue->info,info,tam);
    nue->tam = tam;

    if(!*pp)
        *pp = nue;
    else
        nue->sig = (*pp)->sig;

    (*pp)->sig = nue;


    return 1;


}
int sacar_de_pila(t_pilac *pp,void *info,size_t tam)
{
    t_nodo* elim;
    if(!pp)
        return 0; //pila vacia

    elim = (*pp)->sig;

    if(elim == elim->sig)
        *pp = NULL;
    else
        (*pp)->sig = elim->sig;

    memcpy(info,elim->info,MEN(elim->tam,tam));
    freem(elim->info);
    free(elim);
    return 1;
}
/////]]
