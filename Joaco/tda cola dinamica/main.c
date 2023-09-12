#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int main()
{
    t_cola cola;
    int i=1;
    int j=2;
    int h=3;

    int sacado;
    int frente;


    crear_cola(&cola);
    poner_en_cola(&cola,&i,sizeof(int));
    poner_en_cola(&cola,&j,sizeof(int));
    poner_en_cola(&cola,&h,sizeof(int));


    printf("\nCOLA VACIA: %d",cola_vacia(&cola));


    vaciar_cola(&cola);

    printf("\nCOLA VACIA: %d",cola_vacia(&cola));
    return 0;
}
