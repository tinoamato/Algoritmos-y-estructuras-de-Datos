#include "indice.h"
#include "Lista.h"
#include "func.h"

///PRIMITIVAS INDICE
void ind_crear (t_indice* ind, size_t tam_clave, int (*cmp)(const void*, const void*))
{
    ind->cmp = cmp;
    ind->tamClave = tam_clave;
    crearLista(&(ind->lista));
    ind->reg_indice = malloc(tam_clave+sizeof(unsigned));
    if(!ind->reg_indice)
    {
        return;
    }
}
int ind_insertar (t_indice* ind, void *clave, unsigned nro_reg)
{
    int estado; ///Var aux para guardar si hubo problemas insertando el dato
    memcpy((ind->reg_indice),&(nro_reg),sizeof(unsigned));
    memcpy(ind->reg_indice+sizeof(unsigned),clave,ind->tamClave);
    estado = insertarEnOrdenLista(&(ind->lista),ind->tamClave+sizeof(unsigned),ind->reg_indice,ind->cmp);
    return estado;
}
int ind_eliminar (t_indice* ind, void *clave, unsigned *nro_reg)
{
    int estado;
    memcpy((ind->reg_indice)+sizeof(unsigned), clave, ind->tamClave);
    estado = eliminarElementoLista(&(ind->lista),sizeof(unsigned),(ind->reg_indice), ind->cmp);
    memcpy(&nro_reg,ind->reg_indice,sizeof(unsigned));
    return estado;

}
int ind_buscar (const t_indice* ind, void *clave, unsigned *nro_reg)
{
    int estado;
    void *aux;
    aux = malloc(ind->tamClave+sizeof(unsigned));
    if(!aux)
    {
        return 0;
    }
    memcpy((aux)+sizeof(unsigned), clave, ind->tamClave);
    estado = verElementoDeLista(&(ind->lista),sizeof(unsigned), aux, ind->cmp);
    memcpy(nro_reg,(aux),sizeof(unsigned));
    return estado;
}
int ind_recorrer (const t_indice* ind, void (*accion)(const void *, unsigned, void *),void* param)
{
    int estado;
    estado = recorrerLista(&(ind->lista),accion,param);
    return estado;

}
int ind_cargar (t_indice* ind, const char* path)
{
    FILE *pf;
    int estado = 1;
    void* aux=malloc(ind->tamClave+sizeof(unsigned));
    pf = fopen(path,"rb");
    if(!pf)
    {
        return 0;
    }
    fread(aux, ind->tamClave+sizeof(unsigned), 1, pf);
    while(!feof(pf) && estado)  ///Tal vez estado no va
    {
        estado = insertarEnOrdenLista(&(ind->lista),ind->tamClave+sizeof(unsigned), &aux, ind->cmp);
        fread(aux, ind->tamClave+sizeof(unsigned), 1, pf);
    }
    fclose(pf);
    return estado;
}
int ind_grabar (const t_indice* ind, const char* path)
{
    FILE *pf;
    int estado;
    pf = fopen(path, "wb");
    if(!pf)
    {
        return 0;
    }
    estado = recorrerLista(&(ind->lista),grabarArch,pf);
    fclose(pf);
    return estado;
}
void ind_vaciar (t_indice* ind)
{
    vaciarLista(&(ind->lista));
    free(ind->reg_indice);
}
