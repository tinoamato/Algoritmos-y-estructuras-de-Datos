#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM_COLA 100
#define MENOR(a,b) ((a)<(b)?(a):(b))



typedef struct
{
    char vec[TAM_COLA];
    int frente;
    int fondo;
    int tam_disp;
}t_cola;


int poner_en_cola(t_cola *pc,const void* pd, size_t tam);
int sacar_de_cola(t_cola* pc,void*pd,size_t tam);


#endif // FUNCIONES_H_INCLUDED
