#include "arbol_bin.h"

void crear_arbol(t_arbol* pa)
{
    pa = NULL;
}
int insertar_en_arbol(t_arbol* pa,void* elem,size_t tam,int cmp (const void*,const void*))
{
    t_nodoa* nue;
    int comp;

    while(*pa)
    {
        if((comp = cmp((*pa)->info,elem))>0)
            pa = &(*pa)->izq;
        else if(comp < 0)
            pa = &(*pa)->der;
        else //comp = 0
            return 0; //duplicado
    }

    nue = (t_nodoa*)malloc(sizeof(t_nodoa));
    if(!nue)
        return 0;
    nue->info = malloc(tam);
    if(!nue->info)
    {
        free(nue);
        return 0;
    }

    nue->tam = tam;
    nue->izq = nue->der = NULL;
    memcpy(nue->info,elem,tam);

    *pa = nue;
    return 1;
}

int r_insertar_en_arbol(t_arbol* pa,void* elem,size_t tam,int cmp (const void*,const void*))
{
    t_nodoa* nue;
    int comp;

    while(*pa)
    {
        if((comp = cmp((*pa)->info,elem))>0)
            return r_insertar_en_arbol(&(*pa)->izq,elem,tam,cmp);
        else if(comp < 0)
            return r_insertar_en_arbol(&(*pa)->der,elem,tam,cmp);
        else
            return 0;//duplicado
    }

    nue = (t_nodoa*)malloc(sizeof(t_nodoa));
    if(!nue)
        return 0;
    nue->info = malloc(tam);
    if(!nue->info)
    {
        free(nue);
        return 0;
    }

    nue->tam = tam;
    nue->izq = nue->der = NULL;
    memcpy (nue->info,elem,tam);

    *pa = nue;
    return 1;
}
void recorrer_arbol_en_orden(t_arbol* pa,void accion(void*,void*),void* param)
{
        if(!*pa)
            return;

        recorrer_arbol_en_orden(&(*pa)->izq,accion,param);
        accion((*pa)->info,param);
        recorrer_arbol_en_orden(&(*pa)->der,accion,param);
}

void recorrer_arbol_pos_orden(t_arbol* pa,void accion(void*,void*),void* param)
{
        if(!*pa)
            return;

        recorrer_arbol_en_orden(&(*pa)->izq,accion,param);
        recorrer_arbol_en_orden(&(*pa)->der,accion,param);
        accion((*pa)->info,param);
}

void vaciar_arbol(t_arbol* pa)
{
    t_nodoa* elim;

    if(!*pa)
        return;

    vaciar_arbol(&(*pa)->izq);
    vaciar_arbol(&(*pa)->der);
    elim = *pa;
    free(elim->info);
    free(elim);

    *pa = NULL;
}
void podar_hasta_nivel(t_arbol* pa,unsigned n)
{
    t_nodoa* elim;

    if(*pa)
        return;

    podar_hasta_nivel(&(*pa)->izq,n-1);
    podar_hasta_nivel(&(*pa)->der,n-1);

    if(n<0)
    {
        elim = (*pa);
        free(elim->info);
        free(elim);
        *pa = NULL;
    }
}

int contar_nodos(t_arbol* pa)
{
    if(!*pa)
        return 0;
    return contar_nodos(&(*pa)->izq) + contar_nodos(&(*pa)->der) + 1;
}

int contar_nodos_hasta_nivel(t_arbol* pa,unsigned n) ///CONSULTAR
{
    if(!*pa || !n--)
        return 0;
    return contar_nodos(&(*pa)->izq) + contar_nodos(&(*pa)->der) + 1;
}

int altura_arbol(t_arbol* pa)
{
    int hi,hd;

    if(!*pa)
        return 0;

    hi = altura_arbol(&(*pa)->izq);
    hd = altura_arbol(&(*pa)->der);

    return MAX(hi,hd)+1;

}
t_nodoa** mayor_nodo(t_arbol* pa)
{
    if(!*pa)
        return NULL;
    while((*pa)->der)
        pa = &(*pa)->der;
    return pa;
}

t_nodoa** menor_nodo(t_arbol* pa)
{
    if(!*pa)
        return NULL;
    while((*pa)->izq)
        pa = &(*pa)->izq;
    return pa;
}
void eliminar_raiz(t_arbol* pa,void* elem,size_t tam)
{

}

