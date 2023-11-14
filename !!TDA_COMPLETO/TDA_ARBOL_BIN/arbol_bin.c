#include "arbol_bin.h"

void crear_arbol(t_arbol* pa)
{
    *pa = NULL;
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

int r_insertar_en_arbol(t_arbol* pa,void* elem,size_t tam,int cmp(const void*,const void*))
{
    int comp;
    t_nodoa* nue;

    if(*pa)
    {
        if((comp = cmp(elem,(*pa)->info))>0)
            return r_insertar_en_arbol(&(*pa)->der,elem,tam,cmp);
        else if(comp < 0)
            return r_insertar_en_arbol(&(*pa)->izq,elem,tam,cmp);
        else
            return 0;

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

    memcpy(nue->info,elem,tam);
    nue->tam = tam;
    nue->der = nue->izq = NULL;

    *pa = nue;
    return 1;
}
void recorrer_arbol_en_orden(t_arbol* pa,int accion(void*,void*),void* param)
{
    if(!*pa)
        return;

    recorrer_arbol_en_orden(&(*pa)->izq,accion,param);
    accion((*pa)->info,param);
    recorrer_arbol_en_orden(&(*pa)->der,accion,param);
}

void recorrer_arbol_pos_orden(t_arbol* pa,int accion(void*,void*),void* param)
{
    if(*pa)
    {
        recorrer_arbol_pos_orden(&(*pa)->izq,accion,param);
        recorrer_arbol_pos_orden(&(*pa)->der,accion,param);
        accion((*pa)->info,param);
    }


    return;
}
void recorrer_arbol_pre_orden(t_arbol*pa, int accion(void*,void*),void* param)
{
    if(!*pa)
        return;

    accion((*pa)->info,param);
    recorrer_arbol_pre_orden(&(*pa)->izq,accion,param);
    recorrer_arbol_pre_orden(&(*pa)->der,accion,param);

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
void podar_hasta_nivel(t_arbol* pa,int n)
{
    t_nodoa* elim;

    if(!*pa)
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

int contar_nodos_hasta_nivel(t_arbol* pa,int n) ///CONSULTAR
{
    if(!*pa || (n)<0)
        return 0;
    return contar_nodos_hasta_nivel(&(*pa)->izq,n-1) + contar_nodos_hasta_nivel(&(*pa)->der,n-1) + 1;
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
int compINT(const void* a, const void*b)
{
    int* arg1 = (int*)a;
    int* arg2 = (int*)b;

    return *arg1 - *arg2;
}
int printear(void* elem,void* param)
{
    int* n = (int*)elem;
    printf("%d,",*n);
    return 0;
}
int eliminar_raiz(t_arbol* pa,void* elem,size_t tam)
{
    t_nodoa* elim;
    t_arbol* reemp;
    int hi,hd;

    if(!*pa)
        return 0;

    memcpy(elem,(*pa)->info,tam<(*pa)->tam?tam:(*pa)->tam);
    free((*pa)->info);

    if(!(*pa)->izq && !(*pa)->der)///si no tiene hijos
    {
        //free((*pa)->info);
        free(*pa);
        *pa = NULL;
        return 1;

    }


    hi = altura_arbol(&(*pa)->izq);
    hd = altura_arbol(&(*pa)->der);

    reemp = hi>hd?mayor_nodo(&(*pa)->izq):menor_nodo(&(*pa)->der);

    elim = *reemp;

    (*pa)->info = elim->info;
    (*pa)->tam = elim->tam;

    *reemp = elim->izq ? elim->izq: elim->der;

    free(elim);
    return 1;

}
///-----------------------------------------------------------------------------------------------///

int copiar_dato_arch(void* dest,void*orig,size_t tam,int pos)
{
    int r;
    FILE* pf =(FILE*)orig;

    fseek(pf,pos*tam,SEEK_SET);

    r = fread(dest,tam,1,pf);

    if(r!=tam)
        return 0; //no copio el dato
    return 1;
}
int copiar_dato_vec(void* dest,void* orig,size_t tam,int pos)
{
    memcpy(dest,orig+(tam*pos),tam);
    return 1;
}

///-----------------------------------------------------------------------------------------------///
int cargar_datos_rec_gen(t_arbol* pa,void* orig,size_t tam,int li,int ls,int copiar_dato(void* dest,void*orig,size_t tam,int pos))
{
    int m = (ls+li)/2;
    int r;
    t_nodoa* nue;

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

    nue->izq = nue->der = NULL;
    nue->tam = tam;

    if((r = copiar_dato(nue->info,orig,tam,m)) != 1)
        return r;
    *pa = nue;

    if((r = cargar_datos_rec_gen(&(*pa)->izq,orig,tam,li,m-1,copiar_dato))!=1)
        return r;
    return cargar_datos_rec_gen(&(*pa)->der,orig,tam,m+1,ls,copiar_dato);

}
///-----------------------------------------------------------------------------------------------///
int cargar_arbol_arch(t_arbol* pa,char* path,size_t tam)
{
    int cant_reg,r;

    FILE* pf = fopen(path,"rb");

    if(!pf)
        return 0;

    fseek(pf,0,SEEK_END);
    cant_reg = ftell(pf)/tam;

    r = cargar_datos_rec_gen(pa,pf,tam,0,cant_reg,copiar_dato_arch);

    fclose(pf);
    return r;

}
int cargar_arbol_vec(t_arbol* pa,void* vec,int ce,size_t tam)
{
    int r;

    r = cargar_datos_rec_gen(pa,vec,tam,0,ce-1,copiar_dato_vec);
    return r;
}

///-----------------------------------------------------------------------------------------------///
 t_nodoa** buscar_nodo(t_arbol* pa,void* info, int cmp (const void*,const void*))
 {
    int comp = 1;

    if(!*pa)
        return NULL; //esta vacia

    while(*pa && comp)
    {
        if((comp = cmp(info,(*pa)->info)) == 0)
            return pa;
        else if(comp < 0)
            pa = &(*pa)->izq;
        else
            pa = &(*pa)->der;

    }
    return NULL; //no lo encontro

 }

t_nodoa** buscar_nodo_no_clave(t_arbol *pa,void* elem, int (*cmp)(void*, void*))
{ 
    t_nodoa** buscado=NULL;
    int comp;


    if(!*pa) 
        return NULL;

    if((comp=cmp((*pa)->info,elem)) == 0) //lo encontro
    {
        return pa;
    }


    if(!(buscado=buscar_nodo_no_clave(&(*pa)->izq,elem,cmp)))
        buscado=buscar_nodo_no_clave(&(*pa)->der,elem,cmp);
    return buscado;

}