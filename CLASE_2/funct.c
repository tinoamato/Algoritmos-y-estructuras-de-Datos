#include "funct.h"

int poner_en_pila (t_pila *pp, const void *pd, size_t tam)
{

    ///si tope < tam + sizeof(size_t)-->return *error pila llena*
    ///tope-=tam
    ///copio(vec+tome,pd,tam)
    ///tope-=sizeof(size_t)
    ///copio(vec+tope,tam,sizeof(size_t))
    ///return ok


    if(pp->tope<(tam+(sizeof(size_t))))
        return 0;
    pp->tope-=tam;
    memcpy((pp->vec+(pp->tope)),pd,tam);
    pp->tope-=sizeof(size_t);
    memcpy(pp->vec+(pp->tope),&tam,sizeof(size_t));
    return 1;


}
int sacar_de_pila(t_pila *pp, void *pd, size_t tam)
{

    /// if(tope==tam_vec)--->return pila_vacia
    /// copio(&tam_dato_pila,vec+tope,sizeof(size_t)) //guarda el tamaño del dato siguiente
    ///tope+=sizeof(size_t)                          //muevo el tope
    ///copio(pd,vec+tope,menor(tam,tam_dato_pila);
    ///tope+=tam_dato_pila

    size_t tam_dato_pila;

    if(pp->tope == TAM_VEC)
        return 0;

    memcpy(&tam_dato_pila,pp->vec+pp->tope,sizeof(size_t));

    pp->tope+= sizeof(size_t);

    memcpy(pd,pp->vec+pp->tope,MENOR(tam,tam_dato_pila));

    pp->tope+=tam_dato_pila;

    return 1;

}
void crear_pila (t_pila *pp)                        // inicializar_pila
{
    pp->tope = TAM_VEC;

}

