#include "indice.h"

void crear_lista(t_lista* pl)
{
    *pl = NULL;
}
int insertar_en_lista_ord(t_lista* pl,void* elem, size_t tam,int(*cmp)(const void*,const void*))
{
    t_nodo* nue;
    int comp;

    
    while(*pl && (comp = cmp(elem,(*pl)->info))>0)
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

    memcpy(nue->info,elem,tam);
    nue->tam = tam;

    nue->sig = (*pl)->sig;
    *pl = nue;

    return 1;
    
}
int eliminar_de_lista(t_lista* pl,void* elem,size_t elem,int (*cmp)(const void*,const void*))
{
    t_nodo* elim;
    int comp;

    while(*pl && (comp = cmp(elem,(*pl)->info))!=0)
        pl = &(*pl)->sig;
    
    if(comp!=0)
        return 0; //no lo encontro

    elim = *pl;
    *pl = elim->sig;

    memcpy(elem,elim->info,MIN(tam,elim->tam));
    free(elim->info);
    free(elim);
    return 1;

}
int buscar_en_lista(t_lista* pl, void* elem,size_t tam, int(*cmp)(const void*,const void*))
{
    t_nodo* elim;
    int comp;

    if(!*pl)
        return 0;

    while(*pl && (comp = cmp(elem,(*pl)->info))!=0)
        pl = &(*pl)->sig;
    
    if(comp != 0)
        return 0;

    elim = *pl;

    memcpy(elem,elim->info,tam);
    return 1;
}

///--------------------------------------------------------------------------------/// 
int crear_indice(t_indice* ind,size_t tam,int (*cmp)(const void*,const void*))
{
    ind->reg_indice = malloc(sizeof(unsigned)+tam);
    if(!ind->reg_indice)
        return 0;

    ind->tam_clave = tam;
    ind->cmp = cmp;
    crear_lista(ind->lista);
    return 1;
}
int insertar_en_indice(t_indice* ind,void* clave, unsigned num_reg)
{

    memcpy(ind->reg_indice,&num_reg,sizeof(unsigned));
    memcpy(ind->reg_indice+sizeof(unsigned),clave,ind->tam_clave);
    
    return insertar_en_lista(ind->lista,ind->reg_indice,sizeof(unsigned)+ind->tam_clave,ind->cmp);
}

int eliminar_de_indice(t_indice* ind,void* clave,unsigned *num_reg)
{
    memcpy(ind->reg_indice+sizeof(unsigned),clave,ind->tam_clave);
    if(eliminar_de_lista(ind->lista,ind->reg_indice,sizeof(unsigned)+ind->tam_clave,ind->cmp)!=1)
        return 0;
    memcpy(num_reg,ind->reg_indice,sizeof(unsigned));
    return 1;
    
}
int buscar_en_indice(t_indice* ind,void* clave,unsigned* num_reg)
{
    memcpy(ind->reg_indice+sizeof(unsigned),clave,ind->tam_clave);

    if(buscar_en_lista(ind->lista,ind->reg_indice,ind->tam_clave+sizeof(unsigned),ind->cmp)!=1)
        return 0;
    memcpy(num_reg,ind->reg_indice,sizeof(unsigned));
    return 1;
}

int cargar_indide_de_archivo(t_indice* ind,char* path)
{   

    FILE* pf = fopen (path,"rb");
    if(!pf)
        exit(-1);

    fread(ind->reg_indice,sizeof(unsigned)+ind->tam_clave,1,pf);

    while(!feof(pf))
    {
        insertar_en_lista_ord(&(ind->lista),&(ind->reg_indice),sizeof(unsigned)+ind->tam_clave,(ind->cmp));

        fread(ind->reg_indice,sizeof(unsigned)+ind->tam_clave,1,pf);
    }
    fclose(pf);
}
int cargar_ind_arch_desordenado(t_indice* ind,char* path,size_t tam, int (*copiar_clave)(void* dest,const void*orig,size_t tam))
{
    void* aux;
    void* aux_dato;
    unsigned cont = 0;
    FILE* pf = fopen(path,"rb");
    if(!pf)
        return 0;
 
    fread(aux,tam,1,pf);
    while(!feof(pf))
    {
        
        memcpy(ind->reg_indice,&cont,sizeof(unsigned));
        copiar_clave(ind->reg_indice+sizeof(unsigned),aux,ind->tam_clave);

        insertar_en_lista_ord(&(ind->lista),&(ind->reg_indice),sizeof(unsigned)+ind->tam_clave,ind->cmp);

        fread(aux,tam,1,pf);
        cont++;
    }

}