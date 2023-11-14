#include "practica_arbol.h"

void p_crear_arbol(t_arbol* pa)
{
    *pa = NULL;
}

int p_insertar_en_arbol(t_arbol* pa,void* elem,size_t tam,int (*cmp)(const void*,const void*))
{
    t_nodoa* nue;
    int comp;


    while(*pa)
    {
        if((comp = cmp(elem,(*pa)->info))>0)
            pa = &(*pa)->izq;
        else if(comp < 0)
            pa = &(*pa)->der;
        else
            return 0; //duplicado
    }


    nue=(t_nodoa*)malloc(sizeof(t_nodoa));
    if(!nue)
        return 0;

    nue->info=malloc(tam);
    if(!nue->info)
    {
        free(nue);
        return 0;
    }

    nue->tam=tam;
    nue->izq=nue->der=NULL;
    memcpy(nue->info,elem,tam);

    *pa=nue;
    return 1;
}
int p_r_insertar_en_arbol(t_arbol* pa,void* elem,size_t tam,int (*cmp)(const void*,const void*))
{
    t_nodoa* nue;
    int comp;


    if(*pa)
    {
        if((comp = cmp(elem,(*pa)->info))>0)
            return p_r_insertar_en_arbol(&(*pa)->izq,elem,tam,cmp);
        else if(comp < 0)
            return p_r_insertar_en_arbol(&(*pa)->der,elem,tam,cmp);
        else
            return 0; //duplicado
    }


    nue=(t_nodoa*)malloc(sizeof(t_nodoa));
    if(!nue)
        return 0;

    nue->info=malloc(tam);
    if(!nue->info)
    {
        free(nue);
        return 0;
    }

    nue->tam=tam;
    nue->izq=nue->der=NULL;
    memcpy(nue->info,elem,tam);

    *pa=nue;
    return 1;
}

void recorrer_arbol_en_orden(t_arbol* pa,int(*accion)(const void*,void*),void* param)
{
    if(!*pa)
        return;

    recorrer_arbol_en_orden(&(*pa)->izq,accion,param);
    accion((*pa)->info,param);
    recorrer_arbol_en_orden(&(*pa)->der,accion,param);

}

void vaciar_arbol(t_arbol *pa)
{
    if(!*pa)
        return;

    vaciar_arbol(&(*pa)->izq);
    vaciar_arbol(&(*pa)->der);

    free((*pa)->info);
    free(*pa);
    *pa=NULL;


}

void podar_hasta_nivel(t_arbol* pa,int n)
{
    if(!*pa)
        return;

    podar_hasta_nivel(&(*pa)->izq,n-1);
    podar_hasta_nivel(&(*pa)->der,n-1);

    if(n<0)
    {
        free((*pa)->info);
        free((*pa));
        *pa = NULL;
    }

}

int contar_nodos(t_arbol* pa)
{
    if(!*pa)
        return 0;
    return contar_nodos(&(*pa)->izq) +  contar_nodos(&(*pa)->der)+ 1;
}
int contar_nodos_hasta_nivel(t_arbol* pa,int n)
{
    if(!*pa || n<0)
        return 0;
    return contar_nodos_hasta_nivel(&(*pa)->izq,n-1) +  contar_nodos_hasta_nivel(&(*pa)->der,n-1)+ 1;
}

int altura_arbol(t_arbol* pa)
{
    int hi,hd;

    if(!*pa)
        return 0;

    hi = altura_arbol(&(*pa)->izq);
    hd = altura_arbol(&(*pa)->der);

    return hi>hd?hi:hd + 1;
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
int eliminar_raiz(t_arbol* pa,void* elem,size_t tam)
{
    int hi,hd;
    t_nodoa* elim;
    t_arbol* reemp;

    if(!*pa)
        return 0;

    memcpy(elem,(*pa)->info,MEN(tam,(*pa)->tam));
    free(((*pa)->info));

    if(!(*pa)->izq && !(*pa)->der)
    {
        free(*pa);
        *pa=NULL;
        return 1;
    }

    hi = altura_arbol(&(*pa)->izq);
    hd = altura_arbol(&(*pa)->der);

    reemp = hi>hd? mayor_nodo(&(*pa)->izq): menor_nodo(&(*pa)->der);

    elim = *reemp;

    (*pa)->info = elim->info;
    (*pa)->tam = elim->tam;

    *reemp = elim->izq ? elim->izq: elim->der;
    free(elim);
    return 1;


}
int copiar_dato_arch(void* dest,void* orig,size_t tam,int pos)
{
    FILE* pf = (FILE*)orig;

    fseek(pf,tam*pos,SEEK_SET);

    if((fread(dest,tam,1,pf))!=tam)
        return 0;
    return 1;
}
int cargar_arbol_rec_gen(t_arbol* pa,void* orig,size_t tam,int li,int ls, int(*copiar_dato_orig)(void* dest,void* orig,size_t tam,int pos))
{
    int m = ((li+ls)/2);
    t_nodoa* nue;
    int r;


    if(ls<li)
        return 1;

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
    nue->der = nue->izq = NULL;

    ///copiar dato
    if((r = copiar_dato_orig(nue->info,orig,tam,m))!=1)
        return 0;

    *pa = nue;

    if((r = cargar_arbol_rec_gen(&(*pa)->izq,orig,tam,li,m-1,copiar_dato_orig))!=1)
        return 0;
    return cargar_arbol_rec_gen(&(*pa)->der,orig,tam,m+1,ls,copiar_dato_orig);

}
int cargar_arbol_desde_arch(t_arbol* pa,char* path,size_t tam)
{
    int cant_reg;
    int r;

    FILE* pf = fopen(path,"rb");
    if(!pf)
        return 0;

    fseek(pf,0,SEEK_END);
    cant_reg = (ftell(pf)/tam);

    r = cargar_arbol_rec_gen(pa,pf,tam,0,cant_reg,copiar_dato_arch);
    fclose(pf);

    return r;


}
