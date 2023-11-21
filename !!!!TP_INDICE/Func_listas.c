#include "Lista.h"
#include "func.h"
///PRIMITIVAS DE LISTA
void crearLista(t_lista *pl)
{
    *pl = NULL;
}
int insertarEnOrdenLista(t_lista *pl, size_t tam, const void *elem, int(*cmp)(const void*,const void*))
{
    t_nodo *nue;
    nue = (t_nodo*)malloc(sizeof(t_nodo));
    if(!nue)
    {
        return 0;
    }
    nue->info = malloc(tam);
    if(!nue->info)
    {
        free(nue);
        return 0;
    }
    while(*pl && cmp(elem,(*pl)->info)>0)
    {
        pl = &(*pl)->sig;
    }
    memcpy(nue->info,elem,tam);
    nue->tam = tam;
    nue->sig = *pl;
    *pl = nue;
    return 1;

}
int eliminarElementoLista(t_lista *pl, size_t tam, void *elem, int(*cmp)(const void*,const void*))
{
    t_nodo *elim;
    int comp;
    if(!*pl)
    {
        return 0;
    }
    while(*pl && (comp = cmp(elem,(*pl)->info))!=0)  ///ME MUEVO HASTA EL DATO O HASTA QUE NO HAYA DATOS
    {
        pl = &(*pl)->sig;
    }
    if(comp!=0)  ///ME FIJO SI EXISTE EL EMENTO
    {
        return 0;
    }
    elim = *pl; ///GUARDO EL NODO A ELIMINAR
    *pl = elim->sig; ///ENLAZO LA LISTA
    memcpy(elem,elim->info,(tam>elim->tam)?(elim->tam):(tam)); ///ELIMINO
    free(elim->info);
    free(elim);
    return 1;
}
int verElementoDeLista(const t_lista *pl, size_t tam, void *elem, int (*cmp)(const void*, const void*))
{
    t_nodo *buscado;
    int comp;
    while(*pl && (comp = cmp(elem,(*pl)->info))!=0)
    {
        pl = &(*pl)->sig;
    }
    if(comp!=0)
    {
        return 0;
    }
    buscado = *pl;
    memcpy(elem, buscado->info, (buscado->tam>tam)?(tam):(buscado->tam));
    return 1;
}
int verPrimeroDeLista(const t_lista *pl, size_t tam, void *elem)
{
    if(!*pl)
    {
        return 0;
    }
    memcpy(elem,(*pl)->info,((*pl)->tam>tam)?(tam):((*pl)->tam));
    return 1;
}
void vaciarLista(t_lista *pl)
{
    t_nodo *elim;
    while(*pl)
    {
        elim = *pl;
        *pl = elim->sig;
        free(elim->info);
        free(elim);
    }
}
int recorrerLista(const t_lista *pl, void (*accion)(const void*,unsigned, void*), void *parametro)
{
    int r=1;
    if(!*pl)  ///SI NO HAY LISTA LE AVISA ACA Y SALE
    {
        return 0;
    }
    while(*pl && r)  ///RECORRE TODA LA LISTA
    {
        accion((*pl)->info,(*pl)->tam, parametro);
        pl = &(*pl)->sig;
    }
    return 1;
}
int eliminarPrimeroLista(t_lista* pl,size_t tam,void* elem)
{
    t_nodo* elim;

    elim = (*pl);
    if(!*pl)
        return 0;
    memcpy(elem,elim->info,tam<elim->tam?tam:elim->tam);

    *pl = elim->sig;
    free(elim->info);
    free(elim);



    return 1;
}
int ordenarListaInsercion(t_lista *pl, int (*cmp)(const void*, const void*)){
    t_nodo* nodo;
    t_lista listOrd = NULL; ///LISTA AUXILIAR
    t_lista* plord = &listOrd; ///Apunto el punteroAux al primer elemento de mi lista Aux
    while(*pl){ ///Mientras queden elementos en mi lista desordnada
        nodo = *pl; ///Desengancho
        *pl = nodo->sig; ///Piso el dato
        while(*plord && cmp((*plord)->info, nodo->info)> 0){  ///Busco la posicion para insertar
            plord = &(*plord)->sig;
        }
        nodo->sig = *plord;  ///Engancho
        *plord = nodo;///Pongo el elemnto en la posicion que deberia estar
        *plord = listOrd; ///Apunto el punteroAux al primer elemento de mi lista Aux
    }
    *pl = listOrd; ///Apunto la lista orginial a la lista ordenada
    return 1;
}
