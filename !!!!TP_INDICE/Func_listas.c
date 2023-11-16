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
    // long aux_a;
    //memcpy(&aux_a,elem+sizeof(unsigned),sizeof(long));
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
//       r = accion((*pl)->info,, parametro); ///FALLA GENRICO?
        pl = &(*pl)->sig;
    }
    return r;
}
