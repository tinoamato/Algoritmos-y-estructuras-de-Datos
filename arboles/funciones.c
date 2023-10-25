#include "funciones.h"


int insertar_arbol(t_arbol* pa,void* info,size_t tam, int (*cmp)(const void*,const void*))
{
    int comp;

    t_nodoa* nue;
    while(*pa)
    {
        if((comp = (cmp(info,(*pa)->info)))<0)
            pa = &(*pa)->izq;
        else if(comp>0)
            pa = &(*pa)->der;
        else
            return 0; ///duplicado
    }
    nue = (t_nodoa*)malloc(sizeof(t_nodoa));
    if(!nue)
        return 0; /// sin memoria
    nue->info = malloc(tam);
    if(!nue->info)
    {
        free(nue);
        return 0; ///sin memoria
    }
    memcpy(nue->info,info,tam);
    nue->tam = tam;
    nue->izq = nue->der = NULL;
    *pa = nue;

    return 1;

}

int r_insertar_arbol(t_arbol* pa,void* info,size_t tam, int (*cmp)(const void*,const void*))
{
    int comp;

    t_nodoa* nue;
    if(*pa)
    {
        if((comp = (cmp(info,(*pa)->info)))<0)
            return insertar_arbol(&(*pa)->izq,info,tam,cmp);
        else if(comp>0)
            return insertar_arbol(&(*pa)->der,info,tam,cmp);
        else
            return 0; ///duplicado
    }
    nue = (t_nodoa*)malloc(sizeof(t_nodoa));
    if(!nue)
        return 0; /// sin memoria
    nue->info = malloc(tam);
    if(!nue->info)
    {
        free(nue);
        return 0; ///sin memoria
    }
    memcpy(nue->info,info,tam);
    nue->tam = tam;
    nue->izq = nue->der = NULL;
    *pa = nue;

    return 1;

}
void recorrer_arbol_en_orden(const t_arbol* pa,void(*accion)(void*,void*),void* param)
{
    if(!*pa) //no existe arbol o es la hoja
        return;
    recorrer_arbol_en_orden(&(*pa)->izq,accion,param);
    accion((*pa)->info,param);
    recorrer_arbol_en_orden(&(*pa)->der,accion,param);
}
void recorrer_arbol_pos_orden(const t_arbol* pa,void(*accion)(void*,void*),void* param)
{
    if(!*pa) //no existe arbol o es la hoja
        return;
    recorrer_arbol_en_orden(&(*pa)->izq,accion,param);
    recorrer_arbol_en_orden(&(*pa)->der,accion,param);
    accion((*pa)->info,param);

}
void vaciar_arbol(t_arbol *pa)
{
    if(!*pa)
        return;
    vaciar_arbol(&(*pa)->izq);
    vaciar_arbol(&(*pa)->der);

    free((*pa)->info);
    free(*pa);
    *pa = NULL;

}
void podar_nivel (t_arbol *pa,int n)
{
    if(!*pa)
        return;
    podar_nivel(&(*pa)->izq,n-1);
    podar_nivel(&(*pa)->der,n-1);
    if(n<0)
    {
        free((*pa)->info);
        free(*pa);
        *pa = NULL;
    }
}
int contar_nodos(t_arbol *pa)
{
    if(!*pa)
        return 0;
    return contar_nodos(&(*pa)->izq)+contar_nodos(&(*pa)->der)+1;
}
 /// hacer contar hastas cierto nivel
 int altura_arbol(t_arbol* pa)
 {
     int hi,hd;

     if(!*pa)
        return 0;
    hi = altura_arbol(&(*pa)->izq);
    hd = altura_arbol(&(*pa)->der);

    return MAX(hi,hd)+1;
    ///return (hi>hd?hi:hd)+1;
 }
 t_nodoa** mayor_nodo(t_arbol* pa,void* info,size_t tam)
 {
     if(!*pa)
        return NULL; ///error
     while((*pa)->der);
        pa = &(*pa)->der;
    return pa;
 }
 void eliminar_raiz(t_arbol* pa,void* info,size_t tam)
 {
     int hi,hd;
     t_arbol* reemp;
     t_nodoa* elim;

     if(!*pa)
        return 0; ///ARBOL_VACIO

    memcpy(info,(*pa)->info,MIN((*pa)->tam,tam));
    free((*pa)->info);

     if(!(*pa)->izq && !(*pa)->der)
     {
         free((*pa)->info);
         free((*pa));
         *pa = NULL;
         return 1; ///OK
     }

     hi = altura_arbol(&(*pa)->izq);
     hd = altura_arbol(&(*pa)->der);

     reemp = hi>hd?mayor_nodo(&(*pa)->izq):menor_nodo(&(*pa)->der); //hacer menor_nodo

     elim = *reemp;
     (*pa)->info = elim->info;
     (*pa)->tam = elim->tam;

     *reemp = elim->izq ? elim->izq:elim->der;
     free(elim);
     return 1;
 }
