#include "funct.h"

///CLASE 2 22/08
/*
TDA-> propiedades (datos)
      comportamiento (funciones)
      ***Al usuario NO le interesa como esta implementado***


Estructura de datos
    -conjunto de datos organizados de cierta manera. Ej vector, grafo, pila


Interfaz para
!!!!!No hay que relevar la composicion interna (en la firma por ejemplo)

*/
///Pila
///1 solo punto de acceso (tope de la pila/arriba)
/*
***t_pila***
----------primitivas de TDA (las que usa el usuario)
*/
/// 1)int poner_en_pila (t_pila *pp, const void *pd, size_t tam);
/// 2)int sacar_de_pila(t_pila *pp, void *pd, size_t tam);
/// 3)void crear_pila (t_pila *pp);                        // inicializar_pila
/// 4)void vaciar_pila(t_pila *pp);                     // descartar todos los elementos indiscriminadamente
/// 5)int ver_tope(const t_pila *pp, void* pd, size_t tam);
/// 6)int pila_llena( const t_pila *pp,size_t tam);                                            // preg si hay lugar
/// 7)int pila_vacia(const t_pila *pp)

///para llamar por ej sacar_de_pila(&pila,&dato,5)


/*
1 y 2 van en el mismo punto de acceso
cuando se inicializa la pila se hace con la cant de elementos del vector
TAM_VEC 20

tope<tam ---> error pila llena
tope-=tam
copy(&vec[tope],pd,tam)
tope-=sizeof(size_t)
copy(&vec[tope],tam,sizeof(size_t))


*/





int main()
{
    /*int *p = (int*)malloc(3);
///borra del heap pero no puede borrar el stack
    printf("%p",p);
    free(p);
    printf("\n%p",p);*/


    t_pila pila;
    int dato = 5;
    int dato2 = 6;
    int dato3 = 7;
    int dato4 = 8;
    int dato_sacado;

    crear_pila(&pila);
    poner_en_pila(&pila,&dato,sizeof(dato));
    poner_en_pila(&pila,&dato2,sizeof(dato2));
    poner_en_pila(&pila,&dato3,sizeof(dato3));
    poner_en_pila(&pila,&dato4,sizeof(dato4));

    sacar_de_pila(&pila,&dato_sacado,sizeof(dato_sacado));
    printf("\nDATO SACADO: %d",dato_sacado);
    sacar_de_pila(&pila,&dato_sacado,sizeof(dato_sacado));
    printf("\nDATO SACADO: %d",dato_sacado);
    sacar_de_pila(&pila,&dato_sacado,sizeof(dato_sacado));
    printf("\nDATO SACADO: %d",dato_sacado);
    sacar_de_pila(&pila,&dato_sacado,sizeof(dato_sacado));
    printf("\nDATO SACADO: %d",dato_sacado);











    return 0;
}
