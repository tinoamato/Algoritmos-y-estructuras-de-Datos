#include "funciones.h"


void crear_pila(pila* pp)
{
    *pp = NULL;
}
bool apilar (pila* pp, const void* elem, size_t tamElem)
{
    t_nodo* nue = malloc(sizeof(t_nodo));
    void* elemNodo = malloc(tamElem);

    if(!nue || !elemNodo)
    {
        free(nue);
        free(elemNodo);
        return false;
    }

    nue->elem = elemNodo;
    nue->tamElem = tamElem;
    memcpy(elemNodo,elem,tamElem);

    nue->sig = *pp; ///1
    *pp = nue;      ///2

    return true;

}
bool desapilar (pila* pp,void* elem,size_t tamElem)
{
    if(!*pp)
        return false;


    t_nodo* nae = *pp; ///1
    *pp = nae->sig;    ///2

    memcpy(elem,nae->elem,MIN(tamElem,nae->tamElem));

    free(nae->elem);
    free(nae);

    return true;
}
bool ver_tope_de_pila(const pila* pp, void* elem,size_t tamElem)
{
    if(!*pp)
        return false;

    t_nodo* tope = *pp; ///1

    memcpy(elem,tope->elem,MIN(tamElem,tope->tamElem));

    return true;
}
bool pila_vacia(const pila* pp)
{
    return !*pp;
}
bool pila_llena(const pila* pp, size_t tamElem)
{
    void* nodo = malloc(sizeof(t_nodo));
    void* elemNodo = malloc(tamElem);

    free(nodo);
    free(elemNodo);

    return !nodo || !elemNodo;
}
void vaciar_pila(pila* pp)
{
    t_nodo* nae;

    while(*pp)
    {
        nae = *pp;      ///1
        *pp = nae->sig; ///2
        free(nae->elem);
        free(nae);

    }
}
 int max_mov(int anillos)
 {
     int i;
     int total=1;
     for(i=0;i<anillos;i++)
     {
        total*=2;
     }
     if(anillos%2 ==0)
        return total-1;
     else
        return total-2;

 }

void mostrarPilaEnteros(pila *pp)
{
    pila aux;
    int elem;

    crear_pila(&aux);

    while(!pila_vacia(pp))
    {
        desapilar(pp, &elem, sizeof(int));
        printf("\t %d \n", elem);
        apilar(&aux,&elem, sizeof(int));
    }

    while(!pila_vacia(&aux))
    {

        desapilar(&aux, &elem, sizeof(int));
        apilar(pp,&elem, sizeof(int));
    }

}


