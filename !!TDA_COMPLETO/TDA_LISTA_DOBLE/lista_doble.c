#include "lista_doble.h"

void crear_lista(t_listad* pl)
{
    *pl = NULL;
}
void vaciar_lista(t_listad* pl)
{
    t_nodo* elim;
    t_nodo* aux_ant,*aux_sig;

    aux_ant = aux_sig = *pl;

    if(!*pl)
        return;

    while(aux_ant)
    {
        elim = aux_ant;
        aux_ant = aux_ant->ant;
        free(elim->info);
        free(elim);
        
    }
    while(aux_sig)
    {
        elim = aux_sig;
        aux_sig = aux_sig->sig;
        free(elim->info);
        free(elim);
        
    }

   *pl = NULL;

}

int instertar_en_listad_ordenado(t_listad* pl,void* elem,size_t tam,int (*cmp)(const void*, const void*))
{
    t_nodo* nue;
    t_nodo* aux_ant;
    t_nodo* aux_sig;
    int comp1,comp2;


    aux_sig = *pl;
    aux_ant = aux_sig ? aux_sig->ant: NULL;

    while(aux_ant && (comp1 = cmp(aux_ant->info,elem))>0)
        {
            aux_sig = aux_ant;
            aux_ant = aux_ant->ant;
            
        }

    
    while ( aux_sig && (comp2 = cmp(aux_sig->info,elem))<0)
        {
             aux_ant = aux_sig;
             aux_sig = aux_sig->sig;
        } 
    if(comp1  == 0 || comp2 == 0)
        return 0; ///duplicado


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


    nue->ant = aux_ant;
    nue->sig = aux_sig;

    if(aux_ant)
        aux_ant->sig = nue;
    if(aux_sig)
        aux_sig->ant = nue;
    
    return 1;

}
int eliminar_de_lista(t_listad* pl, void*elem,size_t tam,int (*cmp)(const void*,const void*))
{
    t_nodo* elim;
    t_nodo* aux_ant;
    t_nodo aux_sig;


}

