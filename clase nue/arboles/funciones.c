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

 int cargar_datos_ord_arbol_rec(t_arbol* pa,void* orig,size_t tam, int li, int ls)
 {
     int m = (li + ls)/2;
     int r;
     t_nodoa *nue;

     if(ls < li)
        return 1; //OK

    ///insertar el dato
     nue = (t_nodo*)malloc(sizeof(t_nodoa));
     if(!nue)
        return 0; //sin mem
     nue->info = malloc(tam);
     if(!nue->info)
     {
         free(nue);
         return 0 //sin mem
     }
     nue->izq = nue->der = NULL;
     nue->tam = tam;

     memcpy(nue->info,orig+(tam*m),tam);
     *pa = nue;

     ///
     if((r = cargar_datos_ord_arbol_rec(&(*pa)->izq,orig,tam,li,m-1))!= 1); //!= ok
        return r;
    return cargar_datos_ord_arbol_rec(&(*pa)->der,orig,tam,m+1,ls);
 }
int cargar_datos_ord_arbol_rec_gen(t_arbol* pa,void* orig,size_t tam, int li, int ls,int (*copiar_dato_orig)(void* dest, void* orig,size_t tam,int pos) )
 {
     int m = (li + ls)/2;
     int r;
     t_nodoa *nue;

     if(ls < li)
        return 1; //OK

    ///insertar el dato
     nue = (t_nodo*)malloc(sizeof(t_nodoa));
     if(!nue)
        return 0; //sin mem
     nue->info = malloc(tam);
     if(!nue->info)
     {
         free(nue);
         return 0 //sin mem
     }
     nue->izq = nue->der = NULL;
     nue->tam = tam;

     if((r = copiar_dato_orig(nue->info,orig,tam,m)) == 0 )
        return r;
     *pa = nue;

     ///
     if((r = cargar_datos_ord_arbol_rec(&(*pa)->izq,orig,tam,li,m-1))!= 1); //!= ok
        return r;
    return cargar_datos_ord_arbol_rec(&(*pa)->der,orig,tam,m+1,ls);
 }
int copiar_dato_vec(void* dest, void* orig,size_t tam,int pos)
{
    memcpy(dest,(char*)orig+pos*tam,tam);
    return 1;

}
int copiar_dato_arch(void* dest, void* orig,size_t tam,int pos)
{
    int r;
    FILE *pf = (FILE*)orig;

    fseek(pf,pos*tam,SEEK_SET);

    r = fread(dest,tam,1,pf);

    if(r!=tam)
        return 0; //error
    return 1;
}
int cargar_arbol_arch(t_arbol* pa,char *path,size_t tam)
{
    FILE *pf = fopen(path,"rb");
    int cant_reg,r;

    if(!pf)
        return 0 // error_arch;

    fseek(pf,0L,SEEK_END);

    cant_reg = ftell(pf)/tam;

    r = cargar_datos_ord_arbol_rec_gen(pa,pf,0,cant_reg-1,copiar_dato_arch);

    fclose(pf);
    return r;
}

int arbol_completo_hasta_nivel(t_arbol* pa,int n)
{

    if(n<0)
        return 1;

    return *pa!=NULL && arbol_completo_hasta_nivel(&(*pa)->izq,n-1) && arbol_completo_hasta_nivel(&(*pa)->der,n-1);


}
int arbol_completo(t_arbol*pa)
{
    int h = altura_arbol(pa);
    return arbol_completo_hasta_nivel(pa,h-1);
}
int arbol_balanceado(t_arbol*pa)
{
    int h = altura_arbol(pa);
    return arbol_completo_hasta_nivel(pa,h-2);
}

int arbol_avl(t_arbol* pa)
{
    int hi,hd;

    if(!*pa)
        return 1;

    hi = altura_arbol(&(*pa)->izq);
    hd = altura_arbol(&(*pa)->der);

    if(mod(hi-hd)>1)
        return 0;
    return arbol_avl(&(*pa)->izq) && arbol_avl(&(*pa)->der);
}
int arbol_avl_rec(t_arbol* pa)
{
    int hi,hd;

    if(!*pa)
        return 0;

    hi = arbol_avl_rec(&(*pa)->izq);
    hd = arbol_avl_rec(&(*pa)->der);

    if(hi == -1 || hd== -1 || mod(hi-hd)>1 )
        return -1;
    return (hi>hd?hi:hd)+1;
}
int arbol_avl_v2(t_arbol *pa)
{
    return arbol_avl_rec(pa)!= -1;
}

///hacer   buscar_nodo_no_clave
///hacer   mayor_nodo_no_clave
