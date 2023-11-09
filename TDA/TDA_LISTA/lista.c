#include "lista.h"

void crear_lista(t_lista* pl)
{
    *pl = NULL;
}

int lista_vacia(t_lista* pl)
{
    if(*pl == NULL)
        return 0;
    return 1;
}
void vaciar_lista(t_lista* pl)
{
    t_nodo *elim = *pl;
    while(*pl)
    {
        *pl = elim->sig;

        free(elim->info);
        free(elim);
    }
}
int insertar_ordenado_lista(t_lista* pl, void* elem, size_t tam,int cmp(const void*,const void*))
{
    t_nodo* nue;
    int comp;

    while(*pl && ((comp = cmp(elem,(*pl)->info))>0))
    {
        pl = &(*pl)->sig;
    }
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
    nue->sig = *pl;
    memcpy(nue->info,elem,tam);
    (*pl) = nue;

    return 1;
}

int sacar_elemento_lista_ordenado(t_lista* pl,void* elem,size_t tam, int cmp(const void*,const void*))
{
   t_nodo* elim;
   int comp;

   while(*pl && (comp = cmp(elem,(*pl)->info))<0)
         pl = &(*pl)->sig;

    if(!*pl || comp!=0)
        return 0;

   elim = *pl;
   *pl = elim->sig;
    memcpy(elem,elim->info,MEN(tam,elim->tam));

    free(elim->info);
    free(elim);

    return 1;
}
int poner_en_pos_lista(t_lista* pl,void* elem,size_t tam, unsigned pos)
{
    t_nodo* nue;

    while(*pl && pos--)
        pl = &(*pl)->sig;

    nue = (t_nodo*)malloc(sizeof(t_nodo));
    if(!nue)
        return 0;
    nue->info = malloc(tam);
    if(!nue->info)
    {
        free(nue);
        return 0;
    }

    nue->sig = *pl;
    nue->tam = tam;
    memcpy(nue->info,elem,tam);
    *pl = nue;

    return 1;
}

