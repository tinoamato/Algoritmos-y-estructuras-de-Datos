#include "funciones.h"


void crear_lote(const char* nomArch)
{
    t_producto prod[]= {

                        {7,'A',6},
                        {1,'B',50},
                        {2,'A',10.5},
                        {3,'A',5},
                        {4,'A',7},
                        {5,'B',20},
                        {6,'A',6}






                        };
    FILE* pf = fopen(nomArch,"wb");

    if(!pf)
    {
        printf("\nError al crear el archivo...");
        exit(1);
    }

    fwrite(&prod,sizeof(prod),1,pf);

    fclose(pf);
}
void crear_pila(t_pila* pp)
{
    *pp = NULL;
}

int apilar(t_pila* pp, const void* elem, size_t tamElem)
{
    t_nodo *nue = malloc(sizeof(t_nodo));
    void* elemNodo = malloc(tamElem);

    if(!nue || !elemNodo)
    {
        free(nue);
        free(elemNodo);
        return 0;
    }

    nue->elem = elemNodo;
    nue->tamElem = tamElem;
    memcpy(elemNodo,elem,tamElem);

    nue->sig = *pp;
    *pp = nue;

    return 1;
}
int desapilar(t_pila* pp, void* elem, size_t tamElem)
{
    t_nodo* nae;

    if(!*pp)
        return 0;

    nae = *pp;
    *pp = nae->sig;

    memcpy(elem,nae->elem,MENOR(tamElem,nae->tamElem));

    free(nae->elem);
    free(nae);

    return 1;
}

int ver_tope_pila(const t_pila* pp,void* elem)
{
    t_nodo* tope;
    if(!*pp)
        return 0;

    tope = *pp;
    memcpy(elem,tope->elem,tope->tamElem);
    return 1;

}
int pila_vacia(const t_pila* pp)
{
    if(!*pp)
        return 1;

    return 0;
}
